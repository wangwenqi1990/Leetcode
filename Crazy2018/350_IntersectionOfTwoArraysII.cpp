class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        // memory: O(k), computation: O(m+n)
        int n1=nums1.size(), n2=nums2.size();
        unordered_map<int, int>m;
        vector<int> res;
        if(n1>n2) return intersect(nums2, nums1);
        for(int i=0; i< n1; i++){
            if(m.find(nums1[i]) != m.end())
                m[nums1[i]]+=1;
            else
                m[nums1[i]]=1;
        }
        
        for(int i=0; i<n2;i++){
            if(m.find(nums2[i]) != m.end() && m[nums2[i]]>0){
                m[nums2[i]]-=1;
                res.push_back(nums2[i]);
            }
        }
        return res;
    }
};