class Solution1 {
public:
    int majorityElement(vector<int>& nums) {
        // harsh table
        unordered_map<int, int> m;
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(m.find(nums[i]) != m.end()) m[nums[i]]+=1;
            else m[nums[i]]=1;
            if(m[nums[i]] >n/2) return nums[i];
        }
        return 0;   
    }
};

class Solution2 {
public:
    int majorityElement(vector<int>& nums) {
        // Moore Voting
        int res = 0, cnt = 0;
        for (int num : nums) {
            if (cnt == 0)
                {res = num; ++cnt;}
            else 
                (num == res) ? ++cnt : --cnt;
        }
        return res;
    }
};

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // bit count
        int res = 0;
        for (int i = 0; i < 32; ++i) {
            int ones = 0, zeros = 0;
            for (int num : nums) {
                if ((num & (1 << i)) != 0) ++ones;
                else ++zeros;
            }
            if (ones > zeros) res |= (1 << i);
        }
        return res;
    }
};