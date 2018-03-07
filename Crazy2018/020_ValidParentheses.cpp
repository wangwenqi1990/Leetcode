class Solution {
public:
    bool isValid(string s) {
        if(s.size()%2==1) return false;
        stack<char> sta;
        unordered_map<char, char> m;
        m['(']=')';m['[']=']';m['{']='}';
        for(auto a: s){
            if(a=='('||a=='{'||a=='[')
                sta.emplace(a);
            else if (sta.empty() || m[sta.top()]!=a)
                return false;
            else
                sta.pop();
        }
        return sta.empty() ? true : false;
    }
};
