class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        // computation: O(32n) Space: O(1)
        int res = 0, n = nums.size();
        for(int i=0; i<32; ++i){
            int cnt = 0;
            for(auto num: nums) {if(num & (1<<i))    ++cnt;}
            res += cnt * (n-cnt);
        }
        return res;
    }
};
