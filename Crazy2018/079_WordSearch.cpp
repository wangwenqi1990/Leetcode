class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        // standard dfs
        // computation: O(mnk), space: O(max(mn,k))
        if(word.empty()) return false;
        if(board.empty() || board.front().empty()) return false;
        int r = board.size(), c = board.front().size();
        vector<vector<bool>> visited(r, vector<bool>(c, false));
        for(int i=0; i< r; i++){
            for(int j=0; j< c ; j++){
                if(dfs(board, word, visited, 0, i, j))
                    return true;
            }
        }
        return false;
    }
    
    bool dfs(vector<vector<char>> &board, string word, vector<vector<bool>> &visited, int idx, int i, int j){
        if(idx==word.size()) return true;
        if(i<0||i>=board.size()||j<0||j>=board[0].size() || visited[i][j]||board[i][j]!=word[idx])
            return false;
        visited[i][j]=true;
        bool res = dfs(board, word,visited, idx+1, i-1, j)||
            dfs(board, word,visited, idx+1, i+1, j)||
            dfs(board, word,visited, idx+1, i, j-1)||
            dfs(board, word,visited, idx+1, i, j+1);
        visited[i][j]= false;
        return res;
    }
};