#include<bits/stdc++.h>
using namespace std;

int board_len, saw_width;
vector<int> parts;
int best;

void dfs(int idx, vector<int> &boards)
{
    if ((int)boards.size() >= best) return;
    if (idx == (int)parts.size())
    {
        best = boards.size();
        return;
    }

    int p = parts[idx];

    for (int i = 0; i < (int)boards.size(); i++)
    {
        if (boards[i] == board_len)
        {
            if (p <= board_len)
            {
                boards[i] -= p;
                dfs(idx + 1, boards);
                boards[i] += p;
            }
        }
        else
        {
            int need = p + saw_width;
            if (boards[i] >= need)
            {
                boards[i] -= need;
                dfs(idx + 1, boards);
                boards[i] += need;
            }
        }
    }

    if (p <= board_len)
    {
        boards.push_back(board_len - p);
        dfs(idx + 1, boards);
        boards.pop_back();
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string line;
    vector<vector<int>> jobs;

    while (getline(cin, line))
    {
        if (line.empty()) continue;
        stringstream ss(line);
        vector<int> nums;
        int x;
        while (ss >> x) nums.push_back(x);
        if (!nums.empty()) jobs.push_back(nums);
    }

    for (int ji = 0; ji < (int)jobs.size(); ji++)
    {
        auto &job = jobs[ji];
        board_len = job[0];
        saw_width = job[1];
        parts.clear();
        for (int i = 2; i < (int)job.size(); i++)
            parts.push_back(job[i]);

        sort(parts.begin(), parts.end(), greater<int>());

        best = parts.size();
        vector<int> boards;
        dfs(0, boards);

        cout << endl;
        printf("Board length            = %6d\n", board_len);
        printf("Saw width               = %6d\n", saw_width);
        printf("Number of boards needed = %6d\n", best);
    }

    return 0;
}
