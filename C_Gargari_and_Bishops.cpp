#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vll vector<long long>
#define si set<int>
#define sll set<long long>
#define sc set<char>
#define vc vector<char>

#define rep(i,a,b) for(int i=a;i<b;i++)
#define repb(i,a,b) for(int i=a;i<=b;i++)
#define all(x) x.begin(),x.end()
#define sz(x) (int)(x).size()
#define ff first
#define ss second
#define ln endl

#define mp make_pair
#define pqueue priority_queue
#define pb push_back

ll gcd(const ll a, const ll b){return(b==0?a:gcd(b,a%b));}
ll lcm(const ll a, const ll b){return a/gcd(a,b)*b;}
ll binpow(ll a,ll n){ll ans=1;for(;n;n/=2,a*=a)if(n&1)ans*=a;return ans;}
ll binpow(ll a,ll n,const ll&mod){ll ans=1;for(;n;n/=2,a=a*a%mod)if(n&1)ans=ans*a%mod;return ans;}
ll cdiv(const ll&a,const ll&b){return(a/b+((a^b)>0 && a%b));}
ll fdiv(const ll&a,const ll&b){return a/b-((a^b)<0 && a%b);}
const ll mod = 1000000007;
// const ll mod = 998244353;
void solve(){
    int n;
    cin>>n;
    vector<vll> a(n,vll(n,0));
    vll diag(2*n,0),rdiag(2*n,0);
    rep(i,0,n){
        rep(j,0,n){
            cin>>a[i][j];
            diag[i+j] += a[i][j];
            rdiag[n+i-j] += a[i][j];
        }
    }
    ll ev = -1;
    ll od = -1;
    ll o1,o2,e1,e2;
    rep(i,0,n){
        rep(j,0,n){
            ll nv = diag[i+j]+rdiag[n+i-j]-a[i][j];
            if((i+j) &1){
                if(nv>od){
                    od = nv;
                    o1 = i;
                    o2 = j;
                }
            }else{
                if(nv>ev){
                    ev = nv;
                    e1 = i;
                    e2 = j;
                }
            }
        }
    }
    cout<<(ev+od)<<ln;
    cout<<e1+1<<" "<<e2+1<<" "<<o1+1<<" "<<o2+1<<ln;
    return;
}
int32_t main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
solve();
return 0;}