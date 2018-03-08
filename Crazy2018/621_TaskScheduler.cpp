class Solution {
public:    
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int>m;
        // find maximum occurance
        int cnt = 0;    
        for(auto e : tasks){m[e]++;}
        for(auto e : m) cnt = max(cnt, e.second);
        // inititial the intervial and update the interval
        int ans = (cnt-1)*(n+1);
        for(auto e : m) if(e.second == cnt) ans++;
        return max((int)tasks.size(), ans);
    }
};