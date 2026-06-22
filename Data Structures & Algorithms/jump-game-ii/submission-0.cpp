class Solution {
public:
    vector<int> dp;

    int check(int i, vector<int>& nums) {
        if(i >= nums.size()-1) return 0;

        if(dp[i] != -1) return dp[i];

        int mini = INT_MAX/2;

        for(int j = 1; j <= nums[i]; j++) {
            mini = min(mini, 1 + check(i + j, nums));
        }

        return dp[i] = mini;
    }

    int jump(vector<int>& nums) {
        dp.assign(nums.size(), -1);
        return check(0, nums);
    }
};