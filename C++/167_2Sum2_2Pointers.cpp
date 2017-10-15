#include "package_wwq.cpp"
/*
Computational complexity: O(n)
Space: O(1)
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int l=0, r=n-1;
        vector<int> res;
        
        while(l<r){
            int s = numbers[l]+numbers[r];
            if (s>target){
                r--;
            }
            else if(s< target){
                l++;
            }
            else{
                res.push_back(l+1);
                res.push_back(r+1);
                return res;
            }
        }
        return res;
    }
};

int main(){
    vector<int> numbers{2, 7, 11, 15};
    int target = 9;
    
    vector<int> res = Solution().twoSum(numbers, target);
    for (int i=0; i< res.size(); i++)
        cout << res[i] << ',';
    cout << endl;
}