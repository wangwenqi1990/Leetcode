#include "package_wwq.cpp"
/*
Computational complexity: O(n^2), where the sorting takes O(nlog(n)) is tiny
Space complexity: O(1)
*/
class Solution {
public:
    vector< vector<int> > threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector< vector<int> > res;
        int n = nums.size();
        
        int i =0;
        while (i<n-2){
            int l = i+1;
            int r = n-1;
            int target = -nums[i];
            
            while(l< r){
                int sum = nums[l] + nums[r];
                // if less, then move l to right till the first number that is not the same
                if (sum<target){
                    int curL = nums[l];
                    while(l< r && nums[l]==curL)
                        l++;
                }
                // if more, then move r to left till the first number that is not the same
                else if(sum>target){
                    int curR = nums[r];
                    while(l< r && nums[r]==curR)
                        r--;
                }
                else{
                    vector<int> triplet;
                    triplet.push_back(nums[i]);
                    triplet.push_back(nums[l]);
                    triplet.push_back(nums[r]);
                    res.push_back(triplet);
                    while(l< r && nums[l] == triplet[1])
                        l++;
                    while(l< r && nums[r] == triplet[2])
                        r--;
                }
            }
            int curNum = nums[i];
            while( i< n-2 && nums[i]==curNum)
                i++;
        }
        return res;
    }
};

int main(){
    vector<int> nums;
    nums.push_back(-1);
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(-1);
    nums.push_back(-4);
    vector< vector<int> > res = Solution().threeSum(nums);
    for (int i =0; i< res.size(); i++){
        for(int j=0; j< 3;j++)
            cout << res[i][j] << ',';
        cout << endl;
    }
}


