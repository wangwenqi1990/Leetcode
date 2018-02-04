class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> res;
        unordered_set<string> dict(wordList.begin(), wordList.end());
        vector<string> p{beginWord};
        queue<vector<string>> paths;paths.push(p);      
        unordered_set<string> words;                    
        int level=1, minLevel = INT_MAX;
        
        while(!paths.empty()){
            auto t = paths.front(); paths.pop();
            if(t.size()>level){
                for(string w: words)    dict.erase(w);
                words.clear();
                level = t.size();
                if(level> minLevel) break;
            }
            string last = t.back();
            for(int i=0; i< last.size(); i++){
                string newLast = last;
                for(char ch='a'; ch<='z'; ch++){
                    newLast[i]=ch;
                    if(!dict.count(newLast)) continue;
                    words.insert(newLast);
                    vector<string> newPath = t;
                    newPath.push_back(newLast);
                    if(newLast==endWord){
                        res.push_back(newPath);
                        minLevel=level;
                    }
                    else
                        paths.push(newPath);
                }
            }
        }
        return res;
    }
};