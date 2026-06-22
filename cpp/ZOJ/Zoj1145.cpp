#include<bits/stdc++.h>
using namespace std;

// Parse the expression into a tree structure
// expr = vector of items, each item is either a number or a sub-expression
struct Node
{
    bool isLeaf;
    int val;              // if leaf
    vector<Node> children; // if not leaf
};

int target;
string result;
bool found;

// Parse tokens starting from index pos, until ')' or end
// Returns the parsed Node and updates pos
Node parse(const vector<string> &tokens, int &pos)
{
    Node node;
    node.isLeaf = false;

    while (pos < (int)tokens.size())
    {
        string tok = tokens[pos];
        if (tok == "(")
        {
            pos++; // skip '('
            Node child = parse(tokens, pos);
            node.children.push_back(child);
            // pos now points to ')', skip it
            if (pos < (int)tokens.size() && tokens[pos] == ")")
                pos++;
        }
        else if (tok == ")")
        {
            // Don't advance pos, let caller handle ')'
            break;
        }
        else
        {
            // It's a number
            Node leaf;
            leaf.isLeaf = true;
            leaf.val = stoi(tok);
            node.children.push_back(leaf);
            pos++;
        }
    }

    // If only one child and it's a leaf, convert to leaf
    if (node.children.size() == 1 && node.children[0].isLeaf)
    {
        node.isLeaf = true;
        node.val = node.children[0].val;
        node.children.clear();
    }

    return node;
}

// Compute all possible (value, string) pairs for a node
// Returns a map: value -> one representative string
unordered_map<long long, string> compute_values(Node &node);

unordered_map<long long, string> compute_values(Node &node)
{
    if (node.isLeaf)
    {
        unordered_map<long long, string> m;
        m[node.val] = to_string(node.val);
        return m;
    }

    // Compute values for all children
    vector<unordered_map<long long, string>> child_vals;
    for (Node &child : node.children)
    {
        child_vals.push_back(compute_values(child));
    }

    unordered_map<long long, string> result_map;
    int nc = node.children.size();

    // Enumerate all operator combinations
    // 0: +, 1: -, 2: *
    int num_ops = nc - 1;
    int total_combos = 1;
    for (int i = 0; i < num_ops; i++) total_combos *= 3;

    // For small number of children, enumerate all combinations
    // Use DFS to enumerate value combinations
    function<void(int, long long, string)> enumerate;
    vector<int> chosen_vals(nc);

    for (int op_mask = 0; op_mask < total_combos; op_mask++)
    {
        // Extract operators
        vector<int> ops(num_ops);
        int tmp = op_mask;
        for (int i = 0; i < num_ops; i++)
        {
            ops[i] = tmp % 3;
            tmp /= 3;
        }

        // Now enumerate value combinations from children
        function<void(int)> dfs_vals = [&](int idx) {
            if (idx == nc)
            {
                // Evaluate left to right
                long long val = chosen_vals[0];
                string expr = child_vals[0][chosen_vals[0]];
                for (int i = 0; i < num_ops; i++)
                {
                    long long right = chosen_vals[i + 1];
                    if (ops[i] == 0)
                    {
                        val = val + right;
                        expr += "+";
                    }
                    else if (ops[i] == 1)
                    {
                        val = val - right;
                        expr += "-";
                    }
                    else
                    {
                        val = val * right;
                        expr += "*";
                    }
                    expr += child_vals[i + 1][right];
                }

                // Only keep one representative string per value
                if (result_map.find(val) == result_map.end())
                {
                    result_map[val] = expr;
                }
                return;
            }

            for (auto &[v, s] : child_vals[idx])
            {
                chosen_vals[idx] = v;
                dfs_vals(idx + 1);
            }
        };
        dfs_vals(0);
    }

    return result_map;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string line;
    int eq_num = 0;
    while (getline(cin, line))
    {
        if (line == "0") break;

        eq_num++;

        // Parse left side and right side
        size_t eq_pos = line.find('=');
        string left_str = line.substr(0, eq_pos);
        string right_str = line.substr(eq_pos + 1);

        // Trim spaces
        while (!left_str.empty() && left_str.back() == ' ') left_str.pop_back();
        while (!left_str.empty() && left_str.front() == ' ') left_str = left_str.substr(1);

        target = stoi(left_str);

        // Tokenize right side: split by spaces AND separate parentheses from numbers
        vector<string> tokens;
        string cur;
        for (char c : right_str)
        {
            if (c == '(' || c == ')')
            {
                if (!cur.empty()) { tokens.push_back(cur); cur.clear(); }
                tokens.push_back(string(1, c));
            }
            else if (c == ' ')
            {
                if (!cur.empty()) { tokens.push_back(cur); cur.clear(); }
            }
            else
            {
                cur += c;
            }
        }
        if (!cur.empty()) tokens.push_back(cur);

        if (tokens.empty())
        {
            cout << "Equation #" << eq_num << ":" << endl;
            cout << "Impossible" << endl;
            cout << endl;
            continue;
        }

        int pos = 0;
        Node root = parse(tokens, pos);

        // Handle single number case
        if (root.isLeaf)
        {
            cout << "Equation #" << eq_num << ":" << endl;
            if (root.val == target)
            {
                cout << target << "=" << root.val << endl;
            }
            else
            {
                cout << "Impossible" << endl;
            }
            cout << endl;
            continue;
        }

        auto vals = compute_values(root);

        cout << "Equation #" << eq_num << ":" << endl;
        if (vals.find(target) != vals.end())
        {
            cout << target << "=" << vals[target] << endl;
        }
        else
        {
            cout << "Impossible" << endl;
        }
        cout << endl;
    }

    return 0;
}
