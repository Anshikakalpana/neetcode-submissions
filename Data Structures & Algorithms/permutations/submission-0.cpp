class Solution {
public:
    void check(vector<int>& nums , vector<vector<int>>& ans , vector<int>& temp , int index, vector<int>& visited){
        if(index >= nums.size()){
            if(temp.size() == nums.size()){
                ans.push_back(temp);
            }
            return;
        }

        for(int i=0 ; i<nums.size() ; i++){
            if(!visited[i]){
                visited[i] = 1;
                temp.push_back(nums[i]);

                check(nums , ans , temp , index+1 , visited);

           
                visited[i] = 0;
                temp.pop_back();
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        vector<int> visited(nums.size(),0);

        check(nums , ans , temp , 0 , visited);
        return ans;
    }
};
