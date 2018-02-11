class Solution {
public:
    string simplifyPath(string path) {
        // computation: O(n) Space O(1)
        vector<string> v;   // simplified string
        int i = 0;
        while (i < path.size()) {
            // find first non-'/' entry
            while (path[i] == '/' && i < path.size()) ++i;  
            if (i == path.size()) break;
            // find the substring betweein two '/'
            int start = i;
            while (path[i] != '/' && i < path.size()) ++i;
            int end = i - 1;
            string s = path.substr(start, end - start + 1);
            // check the content of substring
            if (s == "..") {
                if (!v.empty()) v.pop_back(); 
            } 
            else if (s != ".") {
                v.push_back(s);
            }
        }
        if (v.empty()) return "/";
        // product results
        string res;
        for (int i = 0; i < v.size(); ++i) {
            res += '/' + v[i];
        }
        return res;
    }
};