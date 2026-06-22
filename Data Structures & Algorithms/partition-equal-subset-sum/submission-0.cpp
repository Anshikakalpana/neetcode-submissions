#include <cstring>
class Solution {
public:
    int dp[101][5001];
    
   
    bool check(vector<int>& nums, int i, int n, int sum) {
        if (sum == n) {
            return true;
        }
        if (i >= nums.size() || sum > n) {
            return false;
        }
        
     
        if (dp[i][sum] != -1) {
            return dp[i][sum];
        }
        
       
        bool take = check(nums, i + 1, n, sum + nums[i]);
        bool skip = check(nums, i + 1, n, sum);
        
        return dp[i][sum] = take || skip;
    }
    
    bool canPartition(vector<int>& nums) {
       
        int n_sum = accumulate(nums.begin(), nums.end(), 0);
        
       
        if (n_sum & 1) {
            return false;
        }
        
        int n = n_sum / 2;
        
       
        memset(dp, -1, sizeof(dp));
        
        
        return check(nums, 0, n, 0);
    }
};
