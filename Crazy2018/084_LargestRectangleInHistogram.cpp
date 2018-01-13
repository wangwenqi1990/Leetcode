class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // dp
        // computation: O(n^2) space: O(1)
        int n= heights.size(), res=0;      
        for(int i=0; i< n; i++){
            // if heights[j+1]>=height[j], add is always better
            if (i + 1 < n && heights[i] <= heights[i + 1]){
                continue;
            }
            int min_h = heights[i];
            // check j in [0, i]
            for(int j=i;j>=0; j--){
                min_h=min(min_h, heights[j]);
                res = max(res, (i-j+1) * min_h);
            }
        }
        return res;
    }
};