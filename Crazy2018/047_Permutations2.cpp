// better solution, sort frist then find the unique solution
class Solution1 {
public:
    // i is the start, j is the end
    void recursion(vector<int> num, int i, int j, vector<vector<int> > &res) {
        // if num->&num and add swap, then the results may have duplicates
        if (i == j) {
            res.push_back(num);
            return;
        }
        for (int k = i; k <= j; k++) {
            if (i != k && num[i] == num[k]) continue; 
            swap(num[i], num[k]);
            recursion(num, i+1, j, res);
        }
    }
    vector<vector<int> > permuteUnique1(vector<int> &num) {
        sort(num.begin(), num.end());   // nlong(n)
        vector<vector<int> >res;
        recursion(num, 0, num.size()-1, res);
        return res;
    }
};

// not sort, and then find the unique solution by set structure
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> res;
        permute(nums, 0, res);
        return vector<vector<int>> (res.begin(), res.end());
    }
    void permute(vector<int> &nums, int start, set<vector<int>> &res) {
        if (start >= nums.size()) res.insert(nums);
        for (int i = start; i < nums.size(); ++i) {
            if (i != start && nums[i] == nums[start]) continue;
            swap(nums[i], nums[start]);
            permute(nums, start + 1, res);
            swap(nums[i], nums[start]);
        }
    }
};