class Solution {
public:
    int maximumSwap(int num) {
        string str = to_string(num);
        vector<int> candidate(10);
        // find the location that can offer a large number for swapping
        for(int i=0; i<str.size();++i){
            candidate[str[i]-'0']=i;
        }
        // for each digit try to find a candidate from the candidates that is larger than itself.
        for(int i=0; i<str.size(); ++i){
            for(int c=9; c > str[i]-'0'; c--){
                if(candidate[c] <=i ) continue;
                swap(str[i], str[candidate[c]]);
                return stoi(str);
            }
        }
        return num;
    }
};
