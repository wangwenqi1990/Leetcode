class Solution {
public:
    string addBinary(string a, string b) {
        // computation: O(max(m,n))
        int m = a.size(), n= b.size(), carry =0;
        string res;
        while(m>0 || n>0){
            // from right to left
            int tp  = carry;
            if(m>0 && a[m-1]=='1') tp++;
            if(n>0 && b[n-1]=='1') tp++;
            carry = tp/2;
            // reverse append res
            string stp;
            stp = tp%2==0? "0" : "1";
            stp.append(res);
            res = stp;
            m--;
            n--;
        }
        if(carry){
            string stp = "1";
            stp.append(res);
            res = stp;
        }
        return res;
    }
};