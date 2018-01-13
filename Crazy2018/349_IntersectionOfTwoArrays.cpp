class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2=nums2.size();
        if(n1>n2) return intersection(nums2, nums1);
        unordered_map<int, int> m;
        vector<int> res;
        for(int i=0; i<n1; i++){
                m[nums1[i]]=0;
        }
        for(int i=0; i<n2; i++){
            if(m.find(nums2[i])!=m.end() && m[nums2[i]]==0){
                res.push_back(nums2[i]);
                m[nums2[i]]=1;
            }
        }
        return res;        
    }
};