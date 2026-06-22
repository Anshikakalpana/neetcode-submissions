class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {

        sort(hand.begin(),hand.end());
        unordered_map<int,int>u;
        for(int i=0 ; i<hand.size();i++){
            u[hand[i]]++;
        }

        for(int i=0 ; i<hand.size();i++){
            if(!u.count(hand[i]) || u[hand[i]]==0 )continue;
            for(int j=hand[i]; j<hand[i]+groupSize ; j++){
                if(!u.count(hand[i]) || u[j]==0)return false;
                u[j]--;
                
            }
        }
        return true;
    }
};
