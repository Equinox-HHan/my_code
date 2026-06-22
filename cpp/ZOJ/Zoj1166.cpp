#include<bits/stdc++.h>
using namespace std;

vector<string> dict;
int dict_sig[2005][26];
int phrase_sig[26];
int cur_sig[26];
vector<int> chosen;
vector<string> orig_words;
unordered_set<string> dead_ends;

// Encode current signature as a string for memoization
string encode_sig()
{
    string s;
    for (int i = 0; i < 26; i++)
    {
        if (cur_sig[i] > 0)
            s += char('A' + i) + to_string(cur_sig[i]);
    }
    return s;
}

string make_key(int idx, const string &sig)
{
    return to_string(idx) + "|" + sig;
}

bool dfs(int idx)
{
    // Check completion
    bool complete = true;
    for (int i = 0; i < 26; i++)
    {
        if (cur_sig[i] != phrase_sig[i])
        {
            complete = false;
            break;
        }
    }
    if (complete)
    {
        if (chosen.size() != orig_words.size())
        {
            // Different size, not original
        }
        else
        {
            vector<string> sorted_chosen;
            for (int i : chosen) sorted_chosen.push_back(dict[i]);
            sort(sorted_chosen.begin(), sorted_chosen.end());
            bool same = true;
            for (int i = 0; i < (int)sorted_chosen.size(); i++)
            {
                if (sorted_chosen[i] != orig_words[i])
                {
                    same = false;
                    break;
                }
            }
            if (same) return false; // skip original set
        }
        return true; // found a valid solution (will be printed by caller)
    }

    if (idx >= (int)dict.size()) return false;

    string sig = encode_sig();
    string key = make_key(idx, sig);
    if (dead_ends.count(key)) return false;

    // Check if remaining words can cover remaining letters
    // (simple check: for each letter, check if any remaining word has it)
    bool can_cover = true;
    int remaining[26];
    for (int i = 0; i < 26; i++) remaining[i] = phrase_sig[i] - cur_sig[i];
    for (int i = 0; i < 26 && can_cover; i++)
    {
        if (remaining[i] <= 0) continue;
        bool has_letter = false;
        for (int j = idx; j < (int)dict.size(); j++)
        {
            if (dict_sig[j][i] > 0)
            {
                has_letter = true;
                break;
            }
        }
        if (!has_letter) can_cover = false;
    }
    if (!can_cover)
    {
        dead_ends.insert(key);
        return false;
    }

    bool found_any = false;

    // Try using dict[idx]
    bool can_use = true;
    for (int i = 0; i < 26; i++)
    {
        if (cur_sig[i] + dict_sig[idx][i] > phrase_sig[i])
        {
            can_use = false;
            break;
        }
    }
    if (can_use)
    {
        chosen.push_back(idx);
        for (int i = 0; i < 26; i++) cur_sig[i] += dict_sig[idx][i];
        if (dfs(idx + 1)) found_any = true;
        for (int i = 0; i < 26; i++) cur_sig[i] -= dict_sig[idx][i];
        chosen.pop_back();
    }

    // Try skipping dict[idx]
    if (dfs(idx + 1)) found_any = true;

    if (!found_any)
    {
        dead_ends.insert(key);
    }

    return found_any;
}

// Collect and print all solutions
void find_all(int idx, const string &phrase, bool &has_output)
{
    // Check completion
    bool complete = true;
    for (int i = 0; i < 26; i++)
    {
        if (cur_sig[i] != phrase_sig[i])
        {
            complete = false;
            break;
        }
    }
    if (complete)
    {
        if (chosen.size() == orig_words.size())
        {
            vector<string> sorted_chosen;
            for (int i : chosen) sorted_chosen.push_back(dict[i]);
            sort(sorted_chosen.begin(), sorted_chosen.end());
            bool same = true;
            for (int i = 0; i < (int)sorted_chosen.size(); i++)
            {
                if (sorted_chosen[i] != orig_words[i])
                {
                    same = false;
                    break;
                }
            }
            if (same) return; // skip original set
        }

        has_output = true;
        cout << phrase << " =";
        for (int i : chosen)
        {
            cout << " " << dict[i];
        }
        cout << endl;
        return;
    }

    if (idx >= (int)dict.size()) return;

    // Pruning: check if remaining words can cover remaining letters
    int remaining[26];
    for (int i = 0; i < 26; i++) remaining[i] = phrase_sig[i] - cur_sig[i];
    for (int i = 0; i < 26; i++)
    {
        if (remaining[i] <= 0) continue;
        bool has_letter = false;
        for (int j = idx; j < (int)dict.size(); j++)
        {
            if (dict_sig[j][i] > 0)
            {
                has_letter = true;
                break;
            }
        }
        if (!has_letter) return;
    }

    // Try using dict[idx]
    bool can_use = true;
    for (int i = 0; i < 26; i++)
    {
        if (cur_sig[i] + dict_sig[idx][i] > phrase_sig[i])
        {
            can_use = false;
            break;
        }
    }
    if (can_use)
    {
        chosen.push_back(idx);
        for (int i = 0; i < 26; i++) cur_sig[i] += dict_sig[idx][i];
        find_all(idx + 1, phrase, has_output);
        for (int i = 0; i < 26; i++) cur_sig[i] -= dict_sig[idx][i];
        chosen.pop_back();
    }

    find_all(idx + 1, phrase, has_output);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Read dictionary
    string word;
    while (getline(cin, word))
    {
        if (word == "#") break;
        dict.push_back(word);
    }

    for (int i = 0; i < (int)dict.size(); i++)
    {
        memset(dict_sig[i], 0, sizeof(dict_sig[i]));
        for (char c : dict[i])
        {
            if (c >= 'A' && c <= 'Z')
                dict_sig[i][c - 'A']++;
        }
    }

    // Read phrases
    string phrase;
    while (getline(cin, phrase))
    {
        if (phrase == "#") break;

        memset(phrase_sig, 0, sizeof(phrase_sig));
        for (char c : phrase)
        {
            if (c >= 'A' && c <= 'Z')
                phrase_sig[c - 'A']++;
        }

        // Pre-filter dictionary words: only keep words that are subsets of the phrase
        vector<string> filtered_dict;
        vector<int> filtered_idx;
        for (int i = 0; i < (int)dict.size(); i++)
        {
            bool ok = true;
            for (int j = 0; j < 26; j++)
            {
                if (dict_sig[i][j] > phrase_sig[j])
                {
                    ok = false;
                    break;
                }
            }
            if (ok)
            {
                filtered_idx.push_back(i);
            }
        }

        // Backup original dict and use filtered version
        vector<string> orig_dict = dict;
        int orig_dict_sig[2005][26];
        for (int i = 0; i < (int)dict.size(); i++)
            for (int j = 0; j < 26; j++)
                orig_dict_sig[i][j] = dict_sig[i][j];

        vector<string> filtered;
        for (int idx : filtered_idx)
            filtered.push_back(dict[idx]);

        dict = filtered;
        for (int i = 0; i < (int)filtered.size(); i++)
        {
            memset(dict_sig[i], 0, sizeof(dict_sig[i]));
            for (char c : filtered[i])
                if (c >= 'A' && c <= 'Z')
                    dict_sig[i][c - 'A']++;
        }

        // Parse original phrase words
        orig_words.clear();
        stringstream ss(phrase);
        string w;
        while (ss >> w) orig_words.push_back(w);
        sort(orig_words.begin(), orig_words.end());

        bool has_output = false;
        memset(cur_sig, 0, sizeof(cur_sig));
        chosen.clear();
        dead_ends.clear();

        find_all(0, phrase, has_output);

        // Restore original dict
        dict = orig_dict;
        for (int i = 0; i < (int)orig_dict.size(); i++)
            for (int j = 0; j < 26; j++)
                dict_sig[i][j] = orig_dict_sig[i][j];
    }

    return 0;
}
