class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> res(n, 0);
        stack<int> s;
        int pre = 0, idx = 0, cur = 0;
        char type[10];  // to store the type of log, either start or end
        for(auto log: logs){
            sscanf(log.c_str(), "%d:%[^:]:%d", &idx, type, &cur);
            // if start, update the previous log and push the new id into the stack
            if(type[0]=='s'){
                if(!s.empty()){res[s.top()] += cur-pre;}
                s.push(idx);
            } 
            // if end, update the cur log and remove id from the stack
            else{
                res[s.top()] += ++cur-pre;
                s.pop();
            }
            pre = cur;
        }
        return res;
    }
};