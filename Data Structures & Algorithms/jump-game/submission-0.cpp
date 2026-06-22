class Solution {
public:
    vector<int> dp;

    bool check(int i, vector<int>& nums) {
        if(i == nums.size() - 1) return true;
        if(i >= nums.size()) return false;

        if(dp[i] != -1) return dp[i];

        bool maxi = false;

        for(int j = 1; j <= nums[i]; j++) {
            maxi = maxi || check(i + j, nums);
        }

        return dp[i] = maxi;
    }

    bool canJump(vector<int>& nums) {
        dp.assign(nums.size(), -1);
        return check(0, nums);
    }
};