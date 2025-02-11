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
vll dp(1e6+1,1e9+1);
vi c = {4,7};
void start(){
    dp[0]=0;
    rep(i,4,1e6+1){
        rep(j,0,2){
            if(i-c[j]>=0 && dp[i-c[j]]!=1e9+1){
                dp[i]=min(dp[i-c[j]],dp[i])+1;
            }
        }
    }
}
void solve(){
    start();
    int n;
    cin>>n;
    if(dp[n]==1e9+1){
        cout<<-1<<ln;
        return;
    }
    ll s = dp[n];
    rep(i,0,s){
        if(dp[n-4]==s-i-1){
            cout<<4;
            n=n-4;
            if(n==0){
                break;
            }
        }else{
            cout<<7;
            n-=7;
            if(n==0){
                break;
            }
        }
    }
    cout<<ln;
}
int32_t main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
solve();
return 0;}