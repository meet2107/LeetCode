class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        stack<int> s;

        for(int i=0;i<n;i++){
            int ast = abs(asteroids[i]);
            while(!s.empty() && (s.top()>0 && asteroids[i]<0) && (s.top()<ast)){
                s.pop();
            }

            if(!s.empty() && (s.top()>0 && asteroids[i]<0) && (s.top()==ast)){
                s.pop();
            }
            else if(s.empty() || !(s.top()>0 && asteroids[i]<0)){
                s.push(asteroids[i]);
            }
        }

        vector<int> ans;
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
