class Solution {
public:
    string minWindow(string S, string T) {
        if (T.size() > S.size()) return "";
        string res = "";
        int left = 0, count = 0, minLen = INT_MAX;
        // m stores the number of char occurance in T
        unordered_map<char, int> m;
        for (int i = 0; i < T.size(); ++i) {
            if (m.find(T[i]) != m.end()) ++m[T[i]];
            else m[T[i]] = 1;
        }
        
        for (int right = 0; right < S.size(); ++right) {
            if (m.find(S[right]) != m.end()) {
                // if exists, number of qualfied character increases
                if (m[S[right]]-- >= 1) ++count;  
                // if count meet requirements
                while (count == T.size()) {
                    // update results
                    if (right - left + 1 < minLen) {
                        minLen = right - left + 1;
                        res = S.substr(left, minLen);
                    }
                    // update and check if affects qualification
                    if (m.find(S[left]) != m.end()) {
                        ++m[S[left]];
                        if (m[S[left]] > 0) --count;  
                    }
                    // update left pointer
                    ++left;
                }
            }
        }
        return res;
    }
};