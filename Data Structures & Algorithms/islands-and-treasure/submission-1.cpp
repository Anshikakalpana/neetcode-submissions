class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        long long num=2147483647;
        queue<pair<int,int>>q;
        for(int i=0 ; i< grid.size() ; i++){
            for(int j=0 ; j<grid[0].size() ; j++){
                if(grid[i][j]==0){
                    q.push({i,j});
                }
            }
        }
        vector<pair<int , int>>v={{-1, 0}, {1,0},{0,-1},{0,1}};

        while(!q.empty()){
         int   indexi= q.front().first;
         int   indexj= q.front().second;
            q.pop();
            for(auto dir:v){
                int a= indexi+dir.first;
                 int b= indexj+dir.second;
                 if(a>=0 && a< grid.size() && b>=0 && b<grid[0].size() &&grid[a][b]==num){
                 if(grid[a][b]>1+grid[indexi][indexj]) grid[a][b]=1+grid[indexi][indexj];
                    q.push({a,b});

                 }
            }

        }
        
    }
};
