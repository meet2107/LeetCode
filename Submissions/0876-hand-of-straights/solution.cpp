class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n % groupSize != 0){
            return false;
        }

        map<int,int> m;
        for(auto i : hand){
            m[i]++;
        }

        sort(hand.begin(),hand.end());
        for(int num : hand){
            if(m[num] > 0){
                for(int i=num+1;i<num+groupSize;i++){
                    if(m[i] == 0){
                        return false;
                    }
                    m[i]--;
                }
                m[num]--;
            }
        }

        return true;
    }
};
