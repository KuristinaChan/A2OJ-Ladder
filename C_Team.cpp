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
bool can(ll n,ll m){
    return m>=n-1 && m<=(2*n+2);
}
void solve(){
    ll n,m;
    cin>>n>>m;
    if(!can(n,m)){
        cout<<-1<<ln;
        return;
    }
    if(m==n-1 || m==n){
        int s = 0;
        rep(i,0,n+m){
            cout<<s;
            s^=1;
        }
        return;   
    }
    ll p = n,q=m;
    rep(i,0,n){
        if(q>p){
            cout<<1<<1;
            --q;--q;
        }else{
            cout<<1;
            --q;
        }
        cout<<0;--p;
    }
    while(q--){
        cout<<1;
    }
    cout<<ln;
    return;
}
int32_t main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
solve();
return 0;}