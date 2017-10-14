#include "package_wwq.cpp"
/* Build a harsh table using two sum
search the possiblilityes afterwards

Computational complexity: O(n^4)
Space complexity: O(n^2)
*/
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        unordered_map<int, vector< vector<int>> > m;
        int n = nums.size();
        set< vector<int> > pre;
        vector< vector<int> > res;
        sort(nums.begin(), nums.end());
        
        // build the harsh table
        for(int i=0; i< n-1; i++){
            for(int j=i+1;j<n; j++){
                int tp = nums[i] + nums[j];
                if(m.find(tp) != m.end()){
                    vector<int> p;p.push_back(i);p.push_back(j);
                    m[tp].push_back(p);
                }
                else{
                    vector<int> p;p.push_back(i);p.push_back(j);
                    vector< vector<int> > tp1;
                    tp1.push_back(p);
                    m[tp] = tp1;
                }
            }
        }
        // search
        for(int i=0; i< n-3;i++){
            for(int j=i+1;j<n-2;j++){
                int tp = nums[i]+ nums[j];
                if(m.find(target-tp) != m.end()){
                    for (int k=0; k<m[target-tp].size(); k++ ){
                        if (m[target-tp][k][0] > j){
                            vector<int> tmp{nums[i], nums[j], nums[m[target-tp][k][0]], nums[m[target-tp][k][1]]};
                            sort(tmp.begin(), tmp.end());
                            pre.insert(tmp);
                        }
                    }
                }
            }
        }
        
        for(auto i=pre.begin(); i!= pre.end(); i++)
            res.push_back(*i);
        
        return res;
    }
};

int main(){
    vector<int> nums{1, 0, -1, 0, -2, 2};
    int target = 0;
    vector< vector<int> > TBD= Solution().fourSum(nums,target);
    for (int i=0; i< TBD.size(); i++){
        for (int j=0; j< 4; j++)
            cout << TBD[i][j] << ',';
        cout << endl;
    }

}