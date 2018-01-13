class Solution {
public:
    string reverseString(string s) {
    	// computation: O(n) space: O(1)
        for(int i=0, j=s.size()-1; i<j;)
            swap(s[i++], s[j--]);
        return s;
    }
};