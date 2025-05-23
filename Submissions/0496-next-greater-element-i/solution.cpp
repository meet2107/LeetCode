class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> m;
        stack<int> s;

        int n = nums2.size();
        for(int i=0;i<n;i++){
            while(!s.empty() && s.top()<nums2[i]){
                m[s.top()] = nums2[i];
                s.pop();
            }
            s.push(nums2[i]);
        }

        vector<int> ans;
        int mm = nums1.size();
        for(int i=0;i<mm;i++){
            if(m.count(nums1[i])){
                ans.push_back(m[nums1[i]]);
            }
            else{
                ans.push_back(-1);
            }
        }

        return ans;
    }
};
