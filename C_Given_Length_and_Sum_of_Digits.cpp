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
int sum;
bool isPossible(int x,int y){
    return y>=0 && y<=(9*x);
}
void solve(){
    cin>>n>>sum;
    if(n==1 && sum==0){
        cout<<"0 0"<<ln;
        return;
    }
    int s = sum;
    if(!(s>0 && s<=(9*n))){
        cout<<"-1 -1"<<ln;
        return;
    }
    rep(i,0,n){
        rep(j,0,10){
            if(j==0 && i==0){
                continue;
            }
            if(isPossible(n-i-1,s-j)){
                cout<<j;
                s = s-j;
                break;
            }
        }
    }
    s = sum;
    cout<<" ";
    rep(i,0,n){
        for(int j=9;j>=0;--j){
            if(i==0 && j==0){
                continue;
            }
            if(isPossible(n-i-1,s-j)){
                cout<<j;
                s = s-j;
                break;
            }
        }
    }
    cout<<ln;
    return;
}
int32_t main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
solve();
return 0;}