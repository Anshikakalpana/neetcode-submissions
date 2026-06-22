// class Solution {
// public:
// int dp[11][10001];
// long long a = INT_MAX;
// int check(vector<int>& coins, int amount, int i , int sum ){
//          int take = a, skip = a;
//     if(i<0) return a;
//     if(sum==0){
//         return 0;
//     }
//     if(dp[i][sum]!=-1) return dp[i][sum];
//     if(coins[i]<=amount){
//         take =1+ check(coins , amount , i , sum-coins[i]);
//     }
//     skip= check(coins , amount , i-1 , sum);
//     return dp[i][sum] = min(take,skip);
// }
//     int coinChange(vector<int>& coins, int amount) {
//         memset(dp,-1 , sizeof(dp));
//         int ans= check(coins , amount , coins.size()-1 , amount);
//         if(ans!=a) return ans;
//         return -1;

        
// //     }
// // };
// #include <cstring>  
// class Solution {
// public:
//     int dp[11][10001];
//     long long a = INT_MAX;  

//     int check(vector<int>& coins, int amount, int i, int sum) {
//         int take = a, skip = a;

//         if (i < 0) return a;          
//         if (sum == 0) return 0;

//         if (dp[i][sum] != -1) return dp[i][sum];

//         if (coins[i] <= sum) {    
//             take = 1 + check(coins, amount, i, sum - coins[i]);
//         }

//         skip = check(coins, amount, i - 1, sum);

//         return dp[i][sum] = min(take, skip);
//     }

//     int coinChange(vector<int>& coins, int amount) {
//         sort(coins.begin() , coins.end());
//         memset(dp, -1, sizeof(dp));
//         int ans = check(coins, amount, coins.size() - 1, amount);
//         if (ans>=0 && ans<=10001) return ans;
//         return -1;
//     }
// };
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

class Solution {
public:
    int dp[11][10001];
    const int INF = 1e9;   

    int check(vector<int>& coins, int amount, int i, int sum) {
        int take = INF, skip = INF;

        if (i < 0) return INF;          
        if (sum == 0) return 0;

        if (dp[i][sum] != -1) return dp[i][sum];

        if (coins[i] <= sum) {    
            take = 1 + check(coins, amount, i, sum - coins[i]);
        }

        skip = check(coins, amount, i - 1, sum);

        return dp[i][sum] = min(take, skip);
    }

    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end());
        memset(dp, -1, sizeof(dp));
        int ans = check(coins, amount, coins.size() - 1, amount);
        if (ans == INF) return -1;   
        return ans;
    }
};

