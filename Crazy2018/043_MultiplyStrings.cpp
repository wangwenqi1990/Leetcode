class Solution {
public:
    string multiply(string num1, string num2) {
        // space: O(n1+n2); computation: O(n1n2)
        string res(num1.size()+num2.size(), '0');
        // update the res from high position to low position
        for(int i=num1.size()-1; i>=0; --i){
            int carry = 0;
            for(int j= num2.size()-1; j>=0; --j){
                int tp = (res[i+j+1]-'0') + carry + (num1[i]-'0')* (num2[j]-'0');
                res[i+j+1] = tp%10+'0';
                carry = tp/10;
            }
            res[i]+=carry;
        }
        // find substring starting with non-zeros
        size_t startpos = res.find_first_not_of("0");
        if(string::npos != startpos)
            return res.substr(startpos);
        return "0";
        
    }
};
