#include "package_wwq.cpp"

/*
Computational complexity: O(n^2)
Space complexity: O(1)
*/
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
    	int n = nums.size();
    	if(n <= 2)
    		return 0;

    	sort(nums.begin(), nums.end());
    	int res = nums[0] + nums[1] + nums[2];

    	int i =0;
    	while(i< n-2){
    		int l = i+1;
    		int r = n-1;

    		while(l< r){
    			int sum = nums[i] + nums[l] + nums[r];
    			if(abs(sum-target)<abs(res-target))
    				res = sum;

    			if( sum < target)
    				l++;
    			else if(sum > target)
    				r--;
    			else
    				return res;
    		}
    	int curNum = nums[i];
        while(i<n-2 && nums[i]==curNum)
        	i++;
    	}
    return res;
    }
};


int main(){
	vector<int> nums;
	nums.push_back(-1);
	nums.push_back(2);
	nums.push_back(1);
	nums.push_back(-4);
	int target = 1;

	cout << Solution().threeSumClosest(nums, target) << endl;
}