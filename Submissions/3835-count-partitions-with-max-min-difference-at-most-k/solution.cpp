  /*
███╗░░░███╗███████╗███████╗████████╗
████╗░████║██╔════╝██╔════╝╚══██╔══╝
██╔████╔██║█████╗░░█████╗░░░░░██║░░░
██║╚██╔╝██║██╔══╝░░██╔══╝░░░░░██║░░░
██║░╚═╝░██║███████╗███████╗░░░██║░░░
╚═╝░░░░░╚═╝╚══════╝╚══════╝░░░╚═╝░░░ */
    
 
#include<bits/stdc++.h>
#include<fstream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<vector>
#include<cmath>
#include<math.h>
using namespace std;
#define Meet_Andharia ios_base :: sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long int
#define lld long double
#define pii pair<int,int>
#define pb push_back
#define vi vector<int>
#define vll vector<long long int>
#define fori1(l,n) for(int i=1;i<n;i++)
#define fori(o,n) for(ll i=0;i<n;i++)
#define forii(l,r) for(ll i=l;i<r;i++)
#define forimn(m,n) for(int i=m;i<=n;i++)
#define forj(m,n) for(int j=m;j<n;j++)
#define forir(m,n) for(int i=n-1;i>=m;i--)
#define forjr(m,n) for(int j=n-1;j>=m;j--)
#define forje(m,n) for(int j=m;j<=n;j++)
#define fork(m,n) for(int k=m;k<n;k++)
#define forl(m,n) for(int l=m;l<n;l++)
#define loopi(v) for(auto i:v)
#define fi first
#define se second
#define in(n) int n;cin>>n;
#define inll(n) ll n;cin>>n;
#define instr(n) string n;cin>>n;
#define inarr(arr,n) long long int arr[n];for(int i=0;i<n;i++)cin>>arr[i];
#define outarr(arr,n) for(int i=0;i<n;i++){cout<<arr[i]<<" ";}cout<<endl;
#define pyes cout<<"YES\n";
#define pno cout<<"NO\n";
#define pneg1 cout<<"-1\n";
#define p0 cout<<"0\n";
#define CASE(x) cout<<"Case #"<<x<<": ";
#define all(v)  v.begin(),v.end()

const ll MOD = 1000000007LL;
const ll MOD2= 998244353;
const ll inf=1e18;
const int N=120;

class Solution {
public:
    int countPartitions(vector<int>& nums, int k) {
        ll n = nums.size();
        vll ans(n+1), pre(n+1);
        ans[0] = 1;
        pre[0] = 1;

        deque<ll> maxi,mini;
        ll j=0;
        forimn(1,n){
            while(!maxi.empty() && maxi.back()<nums[i-1]){
                maxi.pop_back();
            }
            maxi.pb(nums[i-1]);

            while(!mini.empty() && mini.back()>nums[i-1]){
                mini.pop_back();
            }
            mini.pb(nums[i-1]);
            
            while(j<i){
                ll maxe = maxi.front();
                ll mine = mini.front();
                if(maxe-mine > k){
                    if(maxe==nums[j]){
                        maxi.pop_front();
                    }
                    if(mine==nums[j]){
                        mini.pop_front();
                    }
                    j++;
                }
                else{
                    break;
                }
            }

            if(j!=0) ans[i] = (((pre[i-1]-pre[j-1])%MOD)+MOD)%MOD;
            else ans[i] = pre[i-1]%MOD;
        
            pre[i] = (pre[i-1]+ans[i])%MOD;
        }

        return ans[n];
    }
};
