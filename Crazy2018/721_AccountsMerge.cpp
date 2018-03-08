class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        // emails->person: compiutationL O(nk), space O(nk)
        unordered_map<string, vector<int>> m;
        for(int i=0; i<n; ++i){
            for(int j=0; j<accounts[i].size();++j){
                m[accounts[i][j]].push_back(i);
            }
        }
        
        // computation: O(nk) space: O(nk)
        vector<bool> visited(n, false);
        vector<vector<string>> res;
        for(int i=0; i<n; ++i){
            if(visited[i])  continue;
            queue<int> q{{i}};      // the ith user candidates
            set<string> s;          // the set of unique mails
            // user->mails
            while(!q.empty()){
                int t = q.front(); q.pop();
                visited[t]=true;
                vector<string> mails(accounts[t].begin()+1, accounts[t].end());     // skip the first one, which is the name
                for(string mail: mails){
                    s.insert(mail);
                    for(int user: m[mail]){
                        if(visited[user])   continue;
                        q.push(user);
                        visited[user]=true;
                    }
                }
            }
            vector<string> out(s.begin(), s.end());
            out.insert(out.begin(), accounts[i][0]);
            res.push_back(out);
        }
        return res;
    }
};
