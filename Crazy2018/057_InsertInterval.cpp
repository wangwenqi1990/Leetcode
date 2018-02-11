/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> res;
        int n = intervals.size();
        if(n==0){res.push_back(newInterval); return res;}
        bool ins=false;
        for(int i=0; i< n; i++){
            if(newInterval.start > intervals[i].end){
                res.push_back(intervals[i]);
            }
            else if (newInterval.end<intervals[i].start){
                if(!ins)  {res.push_back(newInterval);ins=true;}    // check if has been inserted
                res.push_back(intervals[i]);
            }
            else{
                newInterval.start = min(newInterval.start, intervals[i].start);
                newInterval.end   = max(newInterval.end,    intervals[i].end);
            }
        }
        if(!ins) res.push_back(newInterval);                          // check if has been inserted
        return res;
    }
};