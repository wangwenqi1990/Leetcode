class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> res;
        queue<int> q;
        // the cnt vector for the constraint of each class;
        vector<int> cnt(numCourses, 0);
        // priority course -> list of courses contrainted by this class, important
        vector<vector<int>> m(numCourses, vector<int>(0));
        for(auto &p: prerequisites){
            m[p.second].push_back(p.first);
            ++cnt[p.first];
        }
        for(int i=0; i< numCourses; ++i){
            if(cnt[i]==0)
                q.push(i);
        }
        while(!q.empty()){
            int tp = q.front(); q.pop();
            res.push_back(tp);
            for(auto a: m[tp]){
                --cnt[a];
                if(cnt[a]==0)
                    q.push(a);
            }
        }
        if(res.size()!=numCourses) res.clear();
        return res;
    }
};
