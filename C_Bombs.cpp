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
int n;
vector<pair<pll,pii>> bombs;
bool comp(pair<pll,pii> x, pair<pll,pii> y){
    if(x.ff.ff == y.ff.ff){
        return x.ff.ss<y.ff.ss;
    }
    return x.ff.ff<y.ff.ff;
}

void solve(){   
    cin>>n;
    bombs.resize(n);
    int cnt = 0;
    rep(i,0,n){
        cin>>bombs[i].ff.ff>>bombs[i].ff.ss;
        if(bombs[i].ff.ff==0 || bombs[i].ff.ss == 0){
            cnt++;
        }
        
        bombs[i].ss.ss = (bombs[i].ff.ss>=0?1:0);
        bombs[i].ss.ff = (bombs[i].ff.ff>=0?1:0);
        bombs[i].ff.ss = abs(bombs[i].ff.ss);
        bombs[i].ff.ff = abs(bombs[i].ff.ff);
    }
    cout<<6*n-2*cnt<<ln;
    sort(all(bombs),comp);
    rep(i,0,n){
        auto [c,v]=bombs[i].ff;
        int x = bombs[i].ss.ss;
        int y = bombs[i].ss.ff;
        if(c==0){
            cout<<1<<" "<<abs(v)<<" "<<((!x?"D":"U"))<<ln;
            cout<<2<<ln;
            cout<<1<<" "<<abs(v)<<" "<<(x?"D":"U")<<ln;
            cout<<3<<ln;
            continue;
        }else if(v==0){
            cout<<1<<" "<<abs(c)<<" "<<((!y?"L":"R"))<<ln;
            cout<<2<<ln;
            cout<<1<<" "<<abs(c)<<" "<<(y?"L":"R")<<ln;
            cout<<3<<ln;
            continue;
        }
        cout<<1<<" "<<abs(c)<<" "<<(!y?"L":"R")<<ln;
        cout<<1<<" "<<abs(v)<<" "<<(!x?"D":"U")<<ln;
        cout<<2<<ln;
        cout<<1<<" "<<abs(v)<<" "<<(x?"D":"U")<<ln;
        cout<<1<<" "<<abs(c)<<" "<<(y?"L":"R")<<ln;
        cout<<3<<ln;
    }   
}
int32_t main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
solve();
return 0;}