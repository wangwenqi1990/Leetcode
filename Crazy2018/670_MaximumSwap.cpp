class Solution {
public:
    int maximumSwap(int num) {
        string str = to_string(num);
        // buckets store the most right location of each digits
        vector<int> buckets(10, 0);
        for (int i = 0; i < str.size(); ++i) {
            buckets[str[i] - '0'] = i;
        }
        // find the largest digit that is after i and is larger than num[i]
        for (int i = 0; i < str.size(); ++i) {
            for (int k = 9; k > str[i] - '0'; --k) {    // larger than num[i]
                if (buckets[k] <= i) continue;          // after i
                swap(str[i], str[buckets[k]]);
                return stoi(str);
            }
        }
        return num;
    }
};