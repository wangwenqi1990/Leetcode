class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // Computation: O(n)
        // Space: O(1)
        int i=0,j=numbers.size()-1;
        int tp;
        vector<int> res;
        while(i<j){
            tp = numbers[i]+numbers[j];
            if(tp<target)
                i++;
            else if(tp>target)
                j--;
            else{
                res.push_back(i+1);
                res.push_back(j+1);
                return res;
            }
        }
        return res;
    }
};