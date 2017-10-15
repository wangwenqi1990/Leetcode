#include "package_wwq.cpp"
/*
Computation: O(n)
Space: O(n)
*/
class Solution {
public:
    bool isValid(string s) {
        int n=s.size();
        
        stack<char> stk;
        for(int i=0;i<n; i++){
            if(s[i]=='(' || s[i]=='[' || s[i]=='{')
                stk.push(s[i]);
            else{
                if (stk.empty() || !ismatch(stk.top(), s[i]))
                    return false;
                stk.pop();
            }
        }
        
        return stk.empty();
    }
    
    bool ismatch(char d, char c){
        if(c==')') return d=='(';
        if(c==']') return d=='[';
        if(c=='}') return d=='{';
    }
};

int main(){
    string s="()[]{}[{()}]";
    cout << Solution().isValid(s) << endl;
}