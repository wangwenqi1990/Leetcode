class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        // Computation: O(n)
        // Space: O(1)
        // each time sum is larger than s, move the left pointer to find the minimum length
        int Sum = 0, start = -1, length = INT_MAX;
        for(int i=0;i<nums.size();i++){
            Sum += nums[i];
            while(Sum >= s){
                length = min(length, i-start);
                Sum -= nums[++start];
            }
        }
        if(length== INT_MAX)
            length = 0;
        return length;
    }
};