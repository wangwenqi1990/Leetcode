class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin(),intervals.end(), cmp);
        if(intervals.size()==0) return true;
        for(int i=0; i<intervals.size()-1; i++ ){
            if(intervals[i+1].start < intervals[i].end)
                return false;
        }
        return true;
    }
    
    static bool cmp(Interval &i1, Interval &i2){
        return i1.start < i2.start;
    }
};