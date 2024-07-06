class Solution {
public:

   /* bool check(vector<int> & colors, int ind, int k, int n){
        for(int i=0;i<k;i++){
            int l = (ind+i-1+n)%n;
            int c = (ind+i)%n;
            int r = (ind+i+1)%n;

            if(i>0 && i<k-1 && (colors[l] == colors[c] || colors[c] == colors[r])){
                return false;
            }

            //return true;
        }

        return true;
    } */

    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        /*int n = colors.size();

        int ans = 0;

        if(k > n) return 0;

        int temp = 1;
        for(int i=0;i<k-1;i++){
            if(colors[i] == colors[i+1]){
                temp = 0;
                break;
            }
        }

        if(temp) ans++;

        for(int i=1;i<n;i++){
            if(colors[(i+k-1)%n] == colors[(i+k)%n]){
                temp = 0;
            }
            if(colors[(i-1)%n] == colors[(i-2+n)%n]){
                temp = 0;
            }
            if((colors[(i+k-1)%n] != colors[(i+k)%n]) && (colors[(i-1)%n] != colors[(i-2+n)%n])){
                temp = 1;
            }

            if(temp) ans++;
        }

        //if(temp) ans++;

        return ans;*/

        int n = colors.size();

        for(int i=0;i<k-1;i++){
            colors.push_back(colors[i]);
        }

        vector<int> t(n+k+1,0);
        t[0]++;

        for(int i=1;i<n+k-1;i++){
            if(colors[i-1] == colors[i]){
                t[i] = 1;
            }
            else{
                t[i] = t[i-1] + 1;
            }
        }

        int ans = 0;

        for(int i=k-1;i<n+k-1;i++){
            if(t[i] >= k) ans++;
        }

        return ans;
    }
};
