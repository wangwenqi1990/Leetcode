class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        int n= digits.size();
        if(n==0) return res;
        string dict[]={"abc", "def", "ghi", "jkl","mno","pqrs", "tuv","wxyz"};
        res.push_back("");
        for(int i=0; i<n; i++){
            int m = res.size();
            for(int j=0;j<m;j++){
                string tp = res.front(); res.erase(res.begin());
                string str = dict[digits[i]-'2'];
                for(int k=0;k<str.size(); k++)
                    res.push_back(tp+str[k]);
            }
        }
        return res;
    }
};

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        int n= digits.size();
        if(n==0) return res;
        string dict[]={"abc", "def", "ghi", "jkl","mno","pqrs", "tuv","wxyz"};
        combinations(digits, dict, 0, res, "");
        return res;
    }
    void combinations(string digits, string dict[], int k, vector<string>& res, string out){
        if(k==digits.size()) 
            res.push_back(out);
        // this else is necessary to avoid non-stop
        else{
            string tmp = dict[digits[k]-'2'];
            for(int i=0; i<tmp.size(); i++){
                out.push_back(tmp[i]);
                combinations(digits, dict, k+1, res, out);
                out.pop_back();
            }
        }
    }
};