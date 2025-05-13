class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        set<int> s;
        vector<int> ans;
        map<int,int> m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
            if(m[nums[i]] > n/3){
                s.insert(nums[i]);
            }
        }   
        
        return vector<int>(s.begin(),s.end());
    }
};
