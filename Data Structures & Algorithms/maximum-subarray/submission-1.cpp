class Solution {
public:
int check(vector<int>& nums){
  int maxi=INT_MIN;
    for(int i=0 ; i<nums.size() ; i++){
       
        
        maxi = max(maxi ,nums[i] );

    }
   return maxi;
    
}
    int maxSubArray(vector<int>& nums) {
        int maxi= INT_MIN;
        int sum=0;
        int j=0;
int a = check(nums);
if(a<0) {return a;}
        while(j<nums.size()){
            sum+=nums[j];
            maxi= max(maxi , sum);
            if(sum<=0){
                sum=0;
            }
           
           j++;
        }
return maxi;
    }
};
