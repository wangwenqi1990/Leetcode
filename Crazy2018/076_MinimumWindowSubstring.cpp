class Solution {
public:
    string minWindow(string S, string T) {
        if (T.size() > S.size()) return "";
        string res = "";
        int left = 0, count = 0, minLen = INT_MAX;
        // m stores the number of char occurance in T
        unordered_map<char, int> m;
        for (int i = 0; i < T.size(); ++i) {
            if (m.find(T[i]) != m.end()) ++m[T[i]];
            else m[T[i]] = 1;
        }
        
        for (int right = 0; right < S.size(); ++right) {
            if (m.find(S[right]) != m.end()) {
                // if exists, number of qualfied character increases
                if (m[S[right]]-- >= 1) ++count;  
                // if count meet requirements
                while (count == T.size()) {
                    // update results
                    if (right - left + 1 < minLen) {
                        minLen = right - left + 1;
                        res = S.substr(left, minLen);
                    }
                    // update and check if affects qualification
                    if (m.find(S[left]) != m.end()) {
                        ++m[S[left]];
                        if (m[S[left]] > 0) --count;  
                    }
                    // update left pointer
                    ++left;
                }
            }
        }
        return res;
    }
};

// same logic but more concise
class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> map(128,0); // harsh table
        for(auto c: t) map[c]++;
        int counter=t.size(), begin=0, end=0, d=INT_MAX, head=0;
        while(end<s.size()){
            if(map[s[end++]]-->0) counter--;
            while(counter==0){
                if(end-begin<d)  d=end-(head=begin);
                if(map[s[begin++]]++==0) counter++;  // check this line
            }
        }
        return d==INT_MAX? "":s.substr(head, d);
    }
};
