class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        // the goal is if find the incrasing triplets, we need to know the sequential 2 smallest nums
        // which solves by alternativing updating the first and second smallest entries
        int first = INT_MAX, second = INT_MAX;
        for(auto num: nums){
            if(num<=first)  // the equality is very important here
                first = num;
            else if(num<=second)
                second = num;
            else
                return true;
        }
        return false;
    }
};
