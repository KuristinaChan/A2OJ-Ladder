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
    int n,p;
    cin>>n>>p;
    int cnt = 0;
    string s;
    cin>>s;
    int l = 0, r = sz(s)-1;
    int fin_l = -1;int fin_r = -1;
    int sta_l = -1;int sta_r = -1;
    bool start = false;
    while(l<r){
        int x = s[r]-'a';
        int y = s[l]-'a';
        int prev = cnt ;
        cnt+=min({abs(y-x),abs(26-y+x),abs(26-x+y)});
        if(cnt>prev){
            if(!start){
                sta_l = l+1;
                sta_r = r+1;
                start = true;
            }
            fin_l = l+1;
            fin_r = r+1;
        }
        // if(l==0 && r==sz(s)-1){cout<<min({abs(y-x),abs(26-y+x),abs(26-x+y)})<<ln;}
        l++;r--;
    }
    if(fin_l==-1){
        cout<<0<<ln;
        return;
    }
    if(p>(n+1)/2){
        n = sta_r;
        cnt += min(abs(sta_r-p),abs(p-fin_r))+sta_r-fin_r;
    }else{
        
        cnt += min(abs(fin_l-p),abs(p-sta_l))+fin_l-sta_l;
    }
    cout<<cnt<<ln;
    return;
}
int32_t main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
solve();
return 0;}