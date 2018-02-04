class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // queue, harsh-table, BFS
        unordered_set<string> dict(wordList.begin(), wordList.end());
        unordered_map<string, int> m; // string to count
        queue<string> q;
        
        m[beginWord] = 1;
        q.push(beginWord);
        while(!q.empty()){
            string word = q.front(); q.pop();
            for(int i=0; i< word.size(); i++){
                string newWord = word;
                for(char ch ='a'; ch<='z'; ch++){
                    newWord[i]=ch;
                    if(dict.count(newWord) && newWord == endWord) return m[word]+1;
                    if(dict.count(newWord) && !m.count(newWord)){
                        q.push(newWord);
                        m[newWord]=m[word]+1;
                    }
                }
            }
        }
        return 0;
    }
};