class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums2.size();
        for(int i=0;i<m;i++){
            nums1.push_back(nums2[i]);
        }

        sort(nums1.begin(),nums1.end());
        int n = nums1.size();
        double ans;
        if(n%2){
            ans = nums1[n/2];
        }
        else{
            ans = (nums1[n/2] + nums1[n/2 - 1])/2.0;
        }

        return ans;
    }
};
