class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // harsh table
        // computation: O(nklogk)
        unordered_map<string, vector<string>> m;
        vector<vector<string>> res;
        for(string str: strs){
            string tp = str;
            sort(tp.begin(), tp.end()); // O(klogk)
            m[tp].push_back(str);
        }
        for(auto a: m){
            res.push_back(a.second);    // hash-table
        }
        return res;   
    }
};