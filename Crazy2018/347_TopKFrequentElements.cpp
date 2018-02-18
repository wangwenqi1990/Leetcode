class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // harsh table & priority queue
        // O(n) complexity and O(clogc) for priority queue
        unordered_map<int, int> m;
        priority_queue<pair<int, int>> q;
        vector<int> res;
        for(auto n: nums) ++m[n];
        for(auto it: m)     q.push({it.second, it.first});
        for(int i=0; i< k; ++i){
            res.push_back(q.top().second);
            q.pop();
        }
        return res;
    }
};