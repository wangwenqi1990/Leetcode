class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        if (edges.size()!=(n-1))    return false;   // n nodes need to have n-1 edges
        vector<int> guid(n, -1);
        for(auto e: edges){
            int start = find(guid, e.first), end = find(guid, e.second);
            if(start == end)    return false;
            guid[start]=end;
        }
        return true;
    }
    int find(vector<int>& guid, int e){
        while(guid[e]!=-1)  e= guid[e];
        return e;
    }
};
