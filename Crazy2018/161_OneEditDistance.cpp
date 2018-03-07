class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        if(s.size()>t.size())           return isOneEditDistance(t, s);
        if(t.size()-s.size()>=2)        return false;
        bool check = false, replace = t.size()==s.size()? true:false;
        for(int i=0, j=0; i< t.size(); ++i, ++j){
            if(s[j]!=t[i]){
                if(check)   return false;
                check = true;
                if(replace) continue;
                else        --j;
            }
        }
        return check;
    }
};
