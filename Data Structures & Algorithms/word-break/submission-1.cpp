#include <cstring>
class Solution {
public:
int dp[101];
bool check( unordered_map <string , int>&u ,string &s, int index ){
    if(index>= s.length()){
        return true;
    }
    if(dp[index]!=-1)return dp[index];
if(u.find(s)!=u.end())return true;
    for(int i= index ; i<s.length() ; i++){
        string temp = s.substr(index , i - index + 1);
        if(u.count(temp) && check(u , s , i+1)){
            return dp[index]=true;
        }
    }
    return dp[index]= false;
}

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map <string , int>u ;
        for(int i=0 ; i<wordDict.size() ;i++){
            u[wordDict[i]]=i;
        }
memset(dp , -1 , sizeof(dp));
        return check(u , s ,0);
    }
};
