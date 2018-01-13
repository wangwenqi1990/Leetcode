class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        // refer this as m problem, and each is Largest Rectangle in Histogram;
        int m = matrix.size();  if(m==0) return 0;
        int n=matrix[0].size(); if(n==0) return 0;
        int res = 0;
        for(int i=0; i<m;i++){
            vector<int> tp(n,0);
            for(int j=0; j<n; j++){
                if(matrix[i][j]=='1'){
                    int tmp =1;
                    for(int z=i-1;z>=0;z--){
                        if(matrix[z][j]=='1')   tmp++;
                        else break;
                    }
                    tp[j]=tmp;
                }
            }
            res = max(res, maxR(tp)); 
        }
        return res;
    }
    
    int maxR(vector<int> h){
        // computation: O(n^2), space: O(1)
        int n= h.size(), res=0;
        for(int i=0; i< n; i++){
            if(i+1< n && h[i+1]>=h[i])
                continue;
            int minH = h[i];
            for(int j=i;j>=0;j--){
                minH=min(minH, h[j]);
                res = max(res, (i-j+1) * minH);
            }
        }
        return res;
    }
};


class Solution {
public:
int maximalRectangle(vector<vector<char> > &matrix) {
    // centered with matrix[i][j]
    // height[i][j],    the height above matrix[i][j]
    // right[i][j],     considering the row before, the right index of 1
    // left[i][j],      considering the row before, the left index of 1
    
    if(matrix.empty()) return 0;
    const int m = matrix.size(), n = matrix[0].size();
    int left[n]={0}, right[n], height[n]={0}, maxA = 0;
    fill_n(right,n,n); 

    for(int i=0; i<m; i++) {
        int cur_left=0, cur_right=n; 
        // compute height (can do this from either side)
        for(int j=0; j<n; j++) { 
            if(matrix[i][j]=='1') 
                height[j]++; 
            else 
                height[j]=0;
        }
        // compute left (from left to right)
        for(int j=0; j<n; j++) { 
            if(matrix[i][j]=='1') 
                left[j]=max(left[j],cur_left);
            else {
                left[j]=0; 
                cur_left=j+1;
            }
        }
        // compute right (from right to left)
        for(int j=n-1; j>=0; j--) {
            if(matrix[i][j]=='1') 
                right[j]=min(right[j],cur_right);
            else {
                right[j]=n; 
                cur_right=j;
            }    
        }
        
        // compute the area of rectangle (can do this from either side)
        for(int j=0; j<n; j++)
            maxA = max(maxA,(right[j]-left[j])*height[j]);
    }
    return maxA;
}
};