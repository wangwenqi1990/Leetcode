class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // computation: O(n^2)      Space: O(1)
        int res = 0, n = heights.size();
        for(int r=0; r< n; ++r){
            // early checks: if next one is higher, than adding is always efficient
            if(r+1<n && heights[r+1] >=heights[r])
                continue;
            // gready check every possible rectance ending at heights[r] by updating minH and res consecutively
            int minH = heights[r];
            for(int l=r; l>=0;--l){
                minH=min(minH, heights[l]);
                res =max(res, (r-l+1) * minH);
            }
        }
        return res;
    }
};

// faster algorithm than above
// altough logic is the same, but the stack is able to reduce non-application heights in each gready check steps.
class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        int res = 0;
        stack<int> s;
        height.push_back(0);
        for (int i = 0; i < height.size(); ++i) {
            if (s.empty() || height[s.top()] < height[i])
                s.push(i);
            // gready check and remove non-contributed heights
            else {
                int cur = s.top();  // cur = i-1
                s.pop();
                res = max(res, height[cur] * (s.empty() ? i : (i - s.top() - 1)));// s.top()=i-2;
                --i;
            }
        }
        return res;
    }
};
