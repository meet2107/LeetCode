class Solution {
public:
    int maximumLength(vector<int>& nums) {
        /*int n = nums.size();
        if(n < 2){
            return n;
        }
        if(n == 2 && (nums[0] + nums[1])%2 == 0){
            return n;
        }
        int cnt1 = 0;
        int cnt2 = 0;

        int ans = 0;

        for(int i=0;i<nums.size();i++){
            if(nums[i] %2 == 0){
                cnt2 = max(cnt2,cnt1+1);
            }
            else{
                cnt1 = max(cnt1,cnt2+1);
            }

            ans = max(ans,max(cnt1,cnt2));
        }

        return ans;*/

        /* int n = nums.size();
         if(n < 2){
             return n;
         }

         int ans = 1;
         int cur = 1;

         for(int i=1;i<n;i++){
             if((nums[i] + nums[i-1])%2 == 1){
                 cur++;
             }
             else{
                 cur = 1;
             }
             ans = max(ans,cur);
         }

         return ans;*/

        int n = nums.size();
        int t1=0,t2=0,t3=0,t4=0;

        for(int i=0;i<n;i++){
            if(t1%2==0){
                if(nums[i]%2==0) t1++;
            }
            else{
                if(nums[i]%2==1) t1++;
            }

            if(t2%2==0){
                if(nums[i]%2==1) t2++;
            }
            else{
                if(nums[i]%2==0) t2++;
            }

            if(nums[i] % 2) t3++;
            if(nums[i]%2==0) t4++;
        }

        return max({t1,t2,t3,t4});
    }
};
