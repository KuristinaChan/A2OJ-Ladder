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
    vll s(n+1,0);
    vi s1;
    vi s2;
    rep(i,0,n){
        int x;
        cin>>x;
        s[i+1] = s[i]+x;
    }
    if(s[n]%3){
        cout<<0<<ln;
        return;
    }
    rep(i,1,n){
        if(s[i]==(s[n]/3))s1.pb(i);
        if(s[i]==(2*s[n]/3))s2.pb(i);
    }
    ll cnt = 0;
    for(auto i : s1){
        int k = upper_bound(all(s2),i)-s2.begin();
        cnt+=(s2.size()-k);
    }
    cout<<cnt<<ln;
    return;
}
int32_t main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
solve();
return 0;}