#include <cstring>
class Solution {
public:
    int dp[301][301];

    int check(int start, int end, vector<int>& nums) {
        if (start > end) return 0;

        if (dp[start][end] != -1)
            return dp[start][end];

        int maxi = 0;

        for (int i = start; i <= end; i++) {
            int x = nums[start - 1] * nums[i] * nums[end + 1];

            maxi = max(maxi,
                       x +
                       check(start, i - 1, nums) +
                       check(i + 1, end, nums));
        }

        return dp[start][end] = maxi;
    }

    int maxCoins(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));

        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        return check(1, nums.size() - 2, nums);
    }
};