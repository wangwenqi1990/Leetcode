class Solution {
public:
    string alienOrder(vector<string>& words) {
        string res = "";
        set<pair<char, char> > s;   // character pair, char1 before char2
        unordered_set<char> ch;     // unique chars
        for(auto a : words) ch.insert(a.begin(), a.end());
        vector<int> in(256, 0);     // the number of constraints for each character
        queue<char> q;              // non-constraint characters
        
        // find character-level priority pairs
        for (int i = 0; i < words.size() - 1; ++i) {
            int mn = min(words[i].size(), words[i + 1].size()), j = 0;
            for (; j < mn; ++j) {
                if (words[i][j] != words[i + 1][j]) {
                    s.insert(make_pair(words[i][j], words[i + 1][j]));
                    break;
                }
            }
           if (j == mn && words[i].size() > words[i + 1].size()) return ""; // check if input correct
        }
        
        // conunt the contraints
        for (auto a : s) ++in[a.second];
        
        // update candidate chars into queue
        for (char a : ch) {if (in[a] == 0) {q.push(a);res += a;} }
        
        // course schedule
        while (!q.empty()) {
            char c = q.front(); q.pop();
            for (auto a : s) {
                if (a.first == c) {
                    --in[a.second];
                    if (in[a.second] == 0) {
                        q.push(a.second);
                        res += a.second;
                    }
                }
            }
        }
        return res.size() == ch.size() ? res : "";  // check if cycles by the results size
    }
};