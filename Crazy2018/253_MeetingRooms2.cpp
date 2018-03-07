class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        // computation: O(nlogn) space: O(n)
        // construct a start time vector and an end time vector
        vector<int> s, e;
        int n = intervals.size();
        for(auto i: intervals){
            s.push_back(i.start);
            e.push_back(i.end);
        }
        sort(s.begin(), s.end());
        sort(e.begin(), e.end());
        // go throuh the vector and updating cnt
        int cnt=0, res =0, j=0;
        for(int i=0; i< n; ){
            if(s[i]<e[j])   {++cnt;++i;}
            else{
                res = max(res, cnt);
                cnt--;++j;
            }
        }
        return max(res, cnt);
    }
};
