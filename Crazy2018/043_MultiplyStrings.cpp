class Solution {
public:
    string multiply(string num1, string num2) {
        string res;
        int n1 = num1.size(), n2 = num2.size();
        vector<int> v(n1+n2, 0);
        int idx = n1+n2-2;
        // O(n^2) to get a table
        for(int i=0; i< n1; i++){
            for(int j=0; j<n2; j++){
                v[idx -i-j] += (num1[i]-'0') * (num2[j]-'0');
            }
        }
        // O(n) to recover digit from table
        int carry = 0;
        for(int i=0; i<n1+n2;i++){
            v[i] += carry;
            carry = v[i]/10;
            v[i] = v[i]%10;
        }
        // O(n) to remove zeros
        int i= n1+n2-1;
        while(v[i]==0) i--;
        if(i<0) return "0";
        while(i>=0) res.push_back(v[i--]+'0');
        return res;
    }
};