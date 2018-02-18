class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        vector<vector<string>> res;
        int n = accounts.size();
        vector<int> visited(n, 0);
        // build a harsh table m that maps all mails to person name. O(mn)
        unordered_map<string, vector<int>> m;
        for (int i = 0; i < n; ++i) {
            for (int j = 1; j < accounts[i].size(); ++j) {
                m[accounts[i][j]].push_back(i);
            }
        }
        
        // For each user
        // build a set to sort all the sorted unique email address
        // build a queue to sort all the users that share the same email address
        for (int i = 0; i < n; ++i) {
            if (visited[i] != 0) continue;
            queue<int> q{{i}};
            set<string> s;
            while (!q.empty()) {
                int t = q.front(); q.pop();
                visited[t] = 1;     // sets account t as visited
                vector<string> mails(accounts[t].begin() + 1, accounts[t].end());
                for (string mail : mails) {
                    s.insert(mail);         
                    for (int user : m[mail]) {
                        if (visited[user] != 0) continue;
                        q.push(user);
                        visited[user] = 1;
                    }
                }
            }
            vector<string> out(s.begin(), s.end());
            out.insert(out.begin(), accounts[i][0]);// insert username to the front
            res.push_back(out);
        }
        return res;
    }
}; 