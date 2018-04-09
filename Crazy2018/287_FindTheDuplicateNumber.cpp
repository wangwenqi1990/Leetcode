// reference: http://bookshadow.com/weblog/2015/09/28/leetcode-find-duplicate-number/
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // computation: O(n)
        // space: O(1)
        int l = 0, r = 0, m= 0, s=0;
        while(true){
            l = nums[l];
            r = nums[nums[r]];
            if(l==r) break;
        }
        while(true){
            l = nums[l];
            s = nums[s];
            if(s==l) break;
        }
        return s;
    }
};

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // computation: O(nlogn)
        // space: O(1)
        int l = 1, r = nums.size();
        while(l<r){
            int m = l+ (r-l)/2;
            int cnt = 0;
            for(auto t: nums){
                if(t<= m) ++cnt;// m not nums[m]
            }
            if(cnt>m) r = m;
            else      l = m+1;
        }
        return l;
    }
};