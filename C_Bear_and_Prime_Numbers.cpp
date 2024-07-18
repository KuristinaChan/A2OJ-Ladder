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
ll maxN = 1e7+1;
vector<pii> cnt(maxN,{0,1});
vi prefix(maxN,0);
void sieve(){
    for(ll i=2;i<maxN;i++){
        if(cnt[i].ss && 1ll*i*i<=maxN){
            for(ll j=i*2;j<maxN;j+=i){
                cnt[j].ss = 0;
                cnt[i].ff+=cnt[j].ff;
            }
        }
    }
    for(ll i=2;i<maxN;i++){
        prefix[i]+=(cnt[i].ff*cnt[i].ss);
    }
    for(ll i=2;i<maxN;i++){
        prefix[i]+=prefix[i-1];
    }
}
void solve(){
    int n;
    cin>>n;
    rep(i,0,n){
        ll x;
        cin>>x;
        cnt[x].ff++;
    }
    sieve();
    ll m,x,y;
    cin>>m;
    while(m--){
        cin>>x>>y;
        if(x>=maxN){
            cout<<0<<ln;
            continue;
        }
        y = min((ll)1e7,y);
        cout<<prefix[y]-prefix[x-1]<<ln;
    }
    return;
}
int32_t main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
solve();
return 0;}