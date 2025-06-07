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
    long long maximumProfit(vector<int>& prices, int k) {
        ll n = prices.size();
        // if(n<2){
        //     return 0;
        // }

        vll prev(n,0);
        forimn(1,k){
            vll cur(n,0);
            ll lg = -2e18;
            ll sh = -2e18;

            forj(1,n){
                ll p = 0;
                if(j > 1){
                    p = prev[j-2];
                }
                lg = max(lg,p-prices[j-1]);
                sh = max(sh,p+prices[j-1]);

                ll curp = max(prices[j]+lg,sh-prices[j]);
                cur[j] = max(cur[j-1],curp);
            }

            prev = cur;
        }

        return prev[n-1];
    }
};
