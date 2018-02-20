class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        BFS(res, nums, 0);
        return res;
    }
    void BFS(vector<vector<int>> &res, vector<int> &nums, int idx){
        if(idx>=nums.size()){
            res.push_back(nums);
            return;
        }
        for(int i= idx; i< nums.size(); ++i){
            swap(nums[idx], nums[i]);
            BFS(res, nums, idx+1);
            swap(nums[idx], nums[i]);
        }
    }
};