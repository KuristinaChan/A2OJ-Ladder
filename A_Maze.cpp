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
    vector<pii> mov = {{-1,0},{0,-1},{1,0},{0,1}};
    int n,m,k;
    cin>>n>>m>>k;
    vector<vc> grid(n,vc(m,'.'));
    vector<vector<bool>> vis(n,vector<bool> (m,false));
    pii first;
    int s = 0;
    bool found = false;
    rep(i,0,n){
        rep(j,0,m){
            cin>>grid[i][j];
            s+=grid[i][j]=='.';
            if(!found && grid[i][j]=='.'){first = mp(i,j);found = true;}
        }
    }
    queue<pii> q;
    q.push(first);
    int cnt = 0;
    vis[first.ff][first.ss]=true;
    while(!q.empty()){
        auto [c,v] = q.front();
        q.pop();
        ++cnt;
        if(cnt>(s-k)){
            grid[c][v]='X';
        }
        rep(i,0,4){
            auto [x,y]=mov[i];
            if(c+x<n && c+x>-1 && v+y<m && v+y>-1 && !vis[c+x][v+y] && grid[c+x][v+y]=='.'){
                vis[c+x][v+y]=true;
                q.push({c+x,v+y});
            }
        }
    }
    rep(i,0,n){
        rep(j,0,m){
            cout<<grid[i][j];;
        }
        cout<<ln;
    }
}
int32_t main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
solve();
return 0;}