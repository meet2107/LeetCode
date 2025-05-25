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
    long long minCuttingCost(int n, int m, int k) {
        if(n<=k && m<=k){
            return 0;
        }
        long long ans = LLONG_MAX;
        if(m<=k){
            for(int i=1;i<n;i++){
                int j=i,l=n-i;
                if(j<=k && l<=k){
                    ans = min(ans,1LL*j*l);
                }
            }
        }
        if(n<=k){
            for(int i=1;i<m;i++){
                int j=i,l=m-i;
                if(j<=k && l<=k){
                    ans = min(ans,1LL*j*l);
                }
            }
        }


        return ans;
    }
};
