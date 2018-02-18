class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // mx conts the most frequent task, mxCnt is the corresponding times of occurance
        int mx = 0, mxCnt = 0;
        vector<int> cnt(26, 0);
        // O(n) to compute the occurance time of each task
        for (char task : tasks) {
            ++cnt[task - 'A'];
            if (mx == cnt[task - 'A']) {
                ++mxCnt;
            } 
            else if (mx < cnt[task - 'A']) {
                mx = cnt[task - 'A'];
                mxCnt = 1;
            }
        }
        int partCnt = mx - 1;
        int partLen = n - (mxCnt - 1);
        int emptySlots = partCnt * partLen;
        int taskLeft = tasks.size() - mx * mxCnt;
        int idles = max(0, emptySlots - taskLeft);
        return tasks.size() + idles;
    }
};