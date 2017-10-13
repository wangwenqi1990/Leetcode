#include "package_wwq.cpp"

/*
Computaional complexity: O(n)
Space Complexity: O(n)
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        vector<int> res;
        
        int n = nums.size();
        for (int i=0; i< n; i++){
            if( m.find(target-nums[i])!=m.end()){
                res.push_back(m[target-nums[i]]);
                res.push_back(i);
                return res;
            }
            else
                m[nums[i]]=i;
        }
        
        return res;
    }
};

int main(){
    vector<int> nums;
    nums.push_back(2);
    nums.push_back(7);
    nums.push_back(11);
    nums.push_back(15);
    int target = 9;
    
    vector<int> result = Solution().twoSum(nums, target);
    for (int i=0; i<result.size(); i++)
        cout << result[i] << ',' ;
    cout << endl;
}