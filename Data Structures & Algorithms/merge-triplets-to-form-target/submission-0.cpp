class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<int> ans(3, 0);  

        for (int j = 0; j < triplets.size(); j++) {
            int n = 0;
            while (n < 3) {
                if (max(ans[n], triplets[j][n]) > target[n]) {
                    break; 
                }
                n++;
            }
            if (n == 3) {
              
                ans[0] = max(ans[0], triplets[j][0]);
                ans[1] = max(ans[1], triplets[j][1]);
                ans[2] = max(ans[2], triplets[j][2]);
            }
        }

        return ans == target;
    }
};
