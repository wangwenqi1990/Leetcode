class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int res = 0;
        for(auto num: nums){
            if(s.count(num)){
                s.erase(num);
                int tp =1, num1 =num-1, num2=num+1;
                while(s.count(num1)) {++tp;s.erase(num1);--num1;}
                while(s.count(num2)) {++tp;s.erase(num1);++num2;}
                res = max(res, tp);
            }
        }
        return res;
    }
};