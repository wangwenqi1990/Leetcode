class Solution {
public:
    bool isValid(string s) {
        // stack
        // computation: O(n) space: O(1)
        int n= s.size();
        if(n%2==1) 
            return false;
        unordered_map<char, char> M;
        M[')']='(';
        M['}']='{'; 
        M[']']='[';
        
        stack<char> tp;
        tp.emplace(s[0]);
        for(int i=1; i<n;i++){
            if(M.find(s[i])!=M.end()){
                if(tp.top()==M[s[i]])
                    tp.pop();
                else
                    return false;
            }
            else
                tp.emplace(s[i]);
        }
        return tp.empty()? true:false;
    }
};