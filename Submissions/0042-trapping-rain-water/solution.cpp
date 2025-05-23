class Solution {
public:
    int trap(vector<int>& a) {
        int n = a.size();
        int lmax=0,rmax=0,ans=0,l=0,r=n-1;

        while(l < r){
            if(a[l] <= a[r]){
                if(lmax > a[l]){
                    ans += lmax - a[l];
                }
                else{
                    lmax = a[l];
                }
                l++;
            }
            else{
                if(rmax > a[r]){
                    ans += rmax - a[r];
                }
                else{
                    rmax = a[r];
                }
                r--;
            }
        }
        return ans;
    }
};
