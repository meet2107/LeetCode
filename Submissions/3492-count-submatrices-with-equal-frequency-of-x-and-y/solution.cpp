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

class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        ll n = grid.size();
        ll m = grid[0].size();

        vector<vll> x(n+1,vll(m+1,0));
        vector<vll> y(n+1,vll(m+1,0));

        fori(0,n){
            forj(0,m){
                x[i+1][j+1] = x[i][j+1]+x[i+1][j]-x[i][j];
                y[i+1][j+1] = y[i][j+1]+y[i+1][j]-y[i][j];

                if(grid[i][j] == 'X'){
                    x[i+1][j+1] += 1;
                }
                if(grid[i][j] == 'Y'){
                    y[i+1][j+1] += 1;
                }
            }
        }

        int ans = 0;
        fori(0,n){
            forj(0,m){
                if(i==0 && j==0){
                    fork(i,n){
                        forl(j,m){
                            int t1 = x[k+1][l+1]-x[k+1][j]+x[i][j]-x[i][l+1];
                            int t2 = y[k+1][l+1]-y[k+1][j]+y[i][j]-y[i][l+1];

                            if(t1 == t2)
                                if(t1 > 0)
                                    ans++;
                        }
                    }
                }
            }
        }

        return ans;
    }
};
