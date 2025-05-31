class Solution {
public:

    int digit(int n){
        int ans = 0;
        while(n){
            ans += n%10;
            n /= 10;
        }

        return ans;
    }
    
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        //int ans = 0;

        vector<int> sorted = nums;
        sort(sorted.begin(),sorted.end(),[this](int a, int b){
            int suma = digit(a);
            int sumb = digit(b);

            if(suma == sumb){
                return a < b;
            }

            return suma < sumb;
        });

        map<int,int> m;
        for(int i=0;i<n;i++){
            m[nums[i]] = i;
        }

        int ans = 0;
        for(int i=0;i<n;i++){
            if(nums[i] != sorted[i]){
                int crt = sorted[i];
                int cpos = m[crt];

                m[nums[i]] = cpos;
                m[crt] = i;

                swap(nums[i],nums[cpos]);
                ans++;
            }
        }

        return ans;
    }
};
