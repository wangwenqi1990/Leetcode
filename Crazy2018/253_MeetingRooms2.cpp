#include<iostream>
#include<vector>
using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<int> start, end;
        int n = intervals.size(), res=0, tp=0;
        for(int i=0; i< n; i++){
            start.push_back(intervals[i].start);
            end.push_back(intervals[i].end);
        }
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        for(int i=0; i<n; i++){
            cout << (start[i]<end[tp]);
            if(start[i]<end[tp])
                res++;
            else
                tp++;
        }
        return res;
        
    }
};


int main(){
    vector<Interval> intervals;
    intervals.push_back(Interval(1,3));
    intervals.push_back(Interval(2,5));
    intervals.push_back(Interval(4,6));
    cout << Solution().minMeetingRooms(intervals) << endl;
}