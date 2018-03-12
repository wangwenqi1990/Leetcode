class WordFilter {
public:
    WordFilter(vector<string> words) {
        // computation: O(NL^2), space: O(NL^2)
        for (int k = 0; k < words.size(); ++k) {
            for (int i = 0; i <= words[k].size(); ++i) {
                for (int j = 0; j <= words[k].size(); ++j) {
                    m[words[k].substr(0, i) + "#" + words[k].substr(words[k].size() - j)] = k;
                }
            }
        }
    }

    int f(string prefix, string suffix) {
        // search: computation: O(1), space: O(NL^2)
        return (m.count(prefix + "#" + suffix)) ? m[prefix + "#" + suffix] : -1;
    }

private:
    unordered_map<string, int> m;
};

class WordFilter {
public:
    WordFilter(vector<string> words) {
        // computation: O(NL) space: O(NL)
        for (int k = 0; k < words.size(); ++k) {
            for (int i = 0; i <= words[k].size(); ++i) {
                mp[words[k].substr(0, i)].push_back(k);
            }
            for (int i = 0; i <= words[k].size(); ++i) {
                ms[words[k].substr(words[k].size() - i)].push_back(k);
            }
        }
    }

    int f(string prefix, string suffix) {
        // computation: O(N), space: O(NL)
        if (!mp.count(prefix) || !ms.count(suffix)) return -1;
        vector<int> pre = mp[prefix], suf = ms[suffix]; // candiate for string
        int i = pre.size() - 1, j = suf.size() - 1;
        while (i >= 0 && j >= 0) {
            if (pre[i] < suf[j]) --j;
            else if (pre[i] > suf[j]) --i;
            else return pre[i];
        }
        return -1;
    }

private:
    unordered_map<string, vector<int>> mp, ms;
};