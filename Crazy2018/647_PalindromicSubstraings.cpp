class Solution {
public:
    int countSubstrings(string s) {
        // check palindromic starting from each location, odd or even
        int n = s.size(), res = 0;
        if(n==0) return 0;
        for(int i=0; i< n; ++i){
            add(s, i, i, res);
            add(s, i, i+1, res);
        }
        return res;
    }
    void add(string s, int i, int j, int &res){
        while(i>=0 && j< s.size() && s[i]==s[j]){
            ++res;--i;++j;
        }
    }
};
