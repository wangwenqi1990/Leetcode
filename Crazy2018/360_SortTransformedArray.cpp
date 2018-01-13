class Solution {
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        vector<int> res;
        // priority queue
        priority_queue<int, vector<int>, greater<int>> q;
        for(int i=0; i<nums.size(); i++){
            q.push(a*nums[i]*nums[i]+ b * nums[i] + c);
        }
        while(!q.empty()){
            res.push_back(q.top());
            q.pop();
        }
        return res;
    }
};