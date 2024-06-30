class Solution {
public:
    int maxHeightOfTriangle(int red, int blue) {
        int r = red;
        int b = blue;

        int i = 1;
        int ans = INT_MIN;
        int count = 0;

        while(true){
            if(i%2 == 1){
                if(r >= i){
                    count++;
                    r -= i;
                }
                else{
                    break;
                }
            }
            else{
                if(b >= i){
                    count++;
                    b-=i;
                }
                else{
                    break;
                }
            }
            i++;
        }

        ans = max(ans,count);
        i = 1;
        count = 0;

        while(true){
            if(i % 2 ==1){
                if(blue >= i){
                    count++;
                    blue -= i;
                }
                else{
                    break;
                }
            }
            else{
                if(red >= i){
                    count++;
                    red -= i;
                }
                else{
                    break;
                }
            }

            i++;
        }

        ans = max(ans,count);
        return ans;
    }
};
