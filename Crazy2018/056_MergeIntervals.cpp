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
    static bool compare(Interval a, Interval b){
        return a.start < b.start;
    }
    
    vector<Interval> merge(vector<Interval>& intervals) {
        // computation: O(nlogn), space: O(1)
        vector<Interval> res;
        if(intervals.size()==0) return res;
        sort(intervals.begin(), intervals.end(), compare);  
        res.push_back(intervals[0]);
        for(int i=1; i< intervals.size(); i++){
            if(res.back().end< intervals[i].start)
                res.push_back(intervals[i]);
            else
                res.back().end = max(intervals[i].end, res.back().end);
        }
        return res;
        
    }
};