class Solution {
public:

    void dfs(vector<vector<char>>& board, unordered_map<string, int>& u , unordered_set<string>& prefixSet,
             int i , int j , string &ans , vector<string>& temp , vector<vector<int>>& visited){
        int n = board.size(), m = board[0].size();
        if(i<0 || i>=n || j<0 || j>=m || visited[i][j]) return;

        ans.push_back(board[i][j]);
        if(prefixSet.find(ans) == prefixSet.end()){ 
            ans.pop_back(); 
            return;
        }

        if(u.count(ans)){
            temp.push_back(ans);
            u.erase(ans);
        }

        visited[i][j] = 1;
        vector<pair<int, int>> v={{-1,0},{1,0},{0,1},{0,-1}};
        for(auto dir:v){
            int a = i + dir.first;
            int b = j + dir.second;
            dfs(board , u , prefixSet, a , b , ans , temp , visited);
        }
        visited[i][j] = 0; 
        ans.pop_back();    
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        unordered_map<string, int> u;
        unordered_set<string> prefixSet;
        vector<string> temp;
        int n = board.size(), m = board[0].size();
        vector<vector<int>> visited(n, vector<int>(m,0));

        for(auto &w : words){
            u[w] = 1;
            for(int i=1;i<=w.size();i++) prefixSet.insert(w.substr(0,i));
        }

        string ans = "";
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                dfs(board, u, prefixSet, i, j, ans , temp , visited);
            }
        }
        return temp;
    }
};
