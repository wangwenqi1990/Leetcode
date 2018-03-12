class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> res;
        unordered_set<string> visited{{s}};
        queue<string> q{{s}};               // queue for candidates
        bool found = false;                 // minimum changes
        while(!q.empty()){
            string t = q.front(); q.pop();
            if(isValid(t)){
                res.push_back(t);              
                found = true;
            }
            if(found) continue;             // if find qualified, the added 1-removed candiates will automatics unsatisfy.
            // remove entries to prepre candidates
            for(int i=0; i<t.size(); ++i){
                if(t[i]!='(' && t[i]!=')')  continue;
                string str = t.substr(0,i)+t.substr(i+1);   // remove ith char
                if(!visited.count(str)){
                    q.push(str);            // candidates
                    visited.insert(str);    // avoid duplicate
                }
            }
        }
        return res;
    }
    bool isValid(string t){
        int cnt =0;
        for(int i=0; i<t.size(); ++i){
            if(t[i]=='(')   ++cnt;
            else if(t[i]==')' &&  --cnt<0) return false;
        }
        return cnt==0;
    }
};

// faster algo
class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> res;
        helper(s, 0, 0, {'(', ')'}, res);
        return res;
    }
    void helper(string s, int last_i, int last_j, vector<char> p, vector<string>& res) {
        // first check if ')' is too many;
        // reverse the qualified string and check if '(' is too many;
        int cnt = 0;
        for (int i = last_i; i < s.size(); ++i) {
            if (s[i] == p[0]) ++cnt;
            else if (s[i] == p[1]) --cnt;
            if (cnt >= 0) continue;
            // when encounter a failure, remove one ')' from previous step
            for (int j = last_j; j <= i; ++j) {
                if (s[j] == p[1] && (j == last_j || s[j] != s[j - 1])) {
                    helper(s.substr(0, j) + s.substr(j + 1), i, j, p, res);
                }
            }
            return; // start next search
        }
        string rev = string(s.rbegin(), s.rend());
        if (p[0] == '(') helper(rev, 0, 0, {')', '('}, res);
        else res.push_back(rev);
    }
};
