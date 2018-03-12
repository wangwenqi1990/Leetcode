class Solution {
public:
    int longestPalindrome(string s) {
        unordered_set<char> t;
        for (char c : s) {
            if (!t.count(c)) t.insert(c);
            else t.erase(c);
        }
        return s.size() - max(0, (int)t.size() - 1);
    }
};