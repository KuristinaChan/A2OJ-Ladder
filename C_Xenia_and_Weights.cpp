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
vi seq;
int m;
vi weights;
bool dfs(int prev,vi &seq,int step,int bal){
    if(step == m){
        return true;
    }
    for(auto w:weights){
        if(w==prev)continue;
        int new_balance = (step%2)?bal+w:bal-w;
        if(bal==0 || (new_balance>0 && bal<0)||(new_balance<0 && bal>0)){
            seq.pb(w);
            if(dfs(w,seq,step+1,new_balance)){
                return true;
            }
            seq.pop_back();
        }
    }
    return false;
}
void solve(){
    string s;
    cin>>s;
    rep(i,1,11){
        if(s[i-1]=='1'){
            weights.pb(i);
        }
    }
    cin>>m;
    if(!dfs(0,seq,0,0)){
        cout<<"NO"<<ln;
        return;
    }
    cout<<"YES"<<ln;
    for(auto i:seq){
        cout<<i<<" ";
    }
}
int32_t main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
solve();
return 0;}