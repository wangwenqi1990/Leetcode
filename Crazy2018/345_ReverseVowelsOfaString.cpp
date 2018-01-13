class Solution {
public:
    string reverseVowels(string s) {
        // computation: O(n)
        // Space: O(1)
        unordered_set<char> m;
        m.emplace('a');
        m.emplace('e');
        m.emplace('i');
        m.emplace('o');
        m.emplace('u');
        
        int i=0, j=s.size()-1;
        while(i<j){
            while(m.find(tolower(s[i]))==m.end())   i++;
            while(m.find(tolower(s[j]))==m.end())   j--;
            if (i>=j)   break;
            swap(s[i++], s[j--]);
        }
        return s;
    }
};