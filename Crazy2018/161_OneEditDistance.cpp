class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int ls = s.size(), lt = t.size();
        int check =0;
        if(ls<lt)   return isOneEditDistance(t, s); //ls>=lt
        if(ls - lt >1) return false;
        if(ls-lt==0){
            for(int i=0; i< ls; ++i){
                if(s[i]!=t[i]){
                    if(!check){check=1; continue;}
                    else    return false;
                }
            }
        }
        if(ls-lt==1){
            for(int i=0; i<ls; ++i){
                if(s[i+check]!=t[i]){
                    if(!check)  {check=1;--i;}
                    else        return false;
                }
            }
        }
        return true && check==1;
    }
};