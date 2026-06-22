class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
         
      int index = numbers.size()-1;  
      
          int start=0;
          int ans=-1;
          for(int i=0 ; i<numbers.size(); i++){
             start=i+1;
            int end= index;
            int n= target-numbers[i];
            while(start<=end){
        int        mid= (start+end)/2;
                if(numbers[mid]==n){
                     ans= mid;
                            return {i+1, ans+1}; 
                }
                else if(n<numbers[mid]){
                    end= mid-1;
                }
                else{
                    start=mid+1;
                }
            }
          }
         
         return {}; 
    }
};
