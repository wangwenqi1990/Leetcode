class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        // computation: O(n) Space: O(n)
        vector<pair<int, int>> h, res;
        // Multisets are containers that store elements following a specific order, and where multiple elements can have equivalent values.
        multiset<int> m;
        int pre = 0, cur = 0;
        // h is a candidate pool including both left and right edge
        for (auto &a : buildings) {
            h.push_back({a[0], -a[2]}); //left
            h.push_back({a[1], a[2]});  // right
        }
        sort(h.begin(), h.end());
        
        // sorted candidate
        m.insert(0);                   
        for (auto &a : h) {
            if (a.second < 0) m.insert(-a.second);  // push left edge as candidate
            else m.erase(m.find(a.second));         // erase left edge of the corresponding right edge
            
            cur = *m.rbegin();                      // highest candidate
            if (cur != pre) {
                res.push_back({a.first, cur});
                pre = cur;
            }
        }
        return res;
    }
};
