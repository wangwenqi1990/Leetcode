class Solution {
public:
    string simplifyPath(string path) {
        // check the component between '/' and produce a content vector, which later transforms into res
        vector<string> v;
        int i=0;
        while(i<path.size()){
            // find the substring s
            while(i< path.size() && path[i]=='/')    ++i;    // non '/' entries
            if (i == path.size()) break;                     // early stop if reaches the end
            int start = i;
            while(i< path.size() && path[i] != '/')     ++i;
            int end = i-1;
            string s = path.substr(start, end-start+1);
            // check the substring s
            if(s=="..")     {if(!v.empty())  v.pop_back();}
            else if(s!=".") {v.push_back(s);}
        }
        if(v.empty())   return "/";
        string res;
        for(auto t: v){
            res += '/' + t;
        }
        return res;
    }
};
