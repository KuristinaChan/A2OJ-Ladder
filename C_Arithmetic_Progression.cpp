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
    if(n==1){
        cout<<-1<<ln;
        return;
    }
    vll a;
    ll max_val = -1,min_val = 1e9;
    rep(i,0,n){
        ll x;
        cin>>x;
        a.pb(x);
        max_val = max(max_val,x);
        min_val = min(min_val,x);
    }
    if(min_val == max_val){
        cout<<1<<ln;
        cout<<min_val<<ln;
        return;
    }
    sort(all(a));
    multiset<ll> cnt;
    rep(i,1,n){
        cnt.insert(a[i]-a[i-1]);
    }
    int d1 = cnt.count(*cnt.begin());
    if(d1==n-1){
        if(n==2 && !(*cnt.begin()&1)){
            cout<<3<<ln;
            cout<<a[0]-*cnt.begin()<<" "<<((a[0]+a[1])>>1)<<" "<<a[1]+*cnt.begin();
            return;
        }
        cout<<2<<ln;
        cout<<min_val-*cnt.begin()<<" "<<max_val+*cnt.rbegin()<<ln;
        return;
    }
    if(d1!=n-2){
        cout<<0<<ln;
        return;
    }
    if(*cnt.rbegin()==2**cnt.begin()){
        rep(i,0,n-1){
            if(a[i+1]-a[i]==*cnt.rbegin()){
                cout<<1<<ln;
                cout<<((a[i]+a[i+1])>>1)<<ln;
                return;
            }
        }
    }else{
        cout<<0<<ln;return;
    }
}
int32_t main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
solve();
return 0;}
