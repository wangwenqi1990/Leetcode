class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int m = wall.size();
        unordered_map<int, int> M;
        for(int i=0; i<m;++i){
            int tp = 0;
            int n = wall[i].size();
            for(int j=0; j<n-1; ++j){
                tp+=wall[i][j];
                if(M.find(tp)!=M.end()) M[tp]+=1;
                else                    M[tp]=1;
            }
        }
        int res = 0;
        for(auto t: M){
            res = max(res, t.second);
        }
        return m-res;
    }
};