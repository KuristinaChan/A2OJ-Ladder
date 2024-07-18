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
vi adj[100001];
int lo[100001],ids[100001],id,n,m;
bool onStack[100001];
int cost[100001];
stack<int> st;
void dfs(int node){
    st.push(node);
    onStack[node]=true;
    lo[node]=ids[node]=++id;
    for(auto to:adj[node]){
        if(ids[to]==-1)dfs(to);
        if(onStack[to])lo[node]=min(lo[node],lo[to]);
    }
    if(ids[node]==lo[node]){
        while(!st.empty()){
            int v = st.top();
            st.pop();
            lo[v]=lo[node];
            onStack[v]=false;
            if(v==node)break;
        }
    }
}
void tarjans(){
    id = 0;
    memset(ids,-1,sizeof(ids));
    memset(lo,0,sizeof(lo));
    memset(onStack,0,sizeof(onStack));
    while(!st.empty())st.pop();
    rep(i,0,n){
        if(ids[i]==-1)dfs(i);
    }
}
void solve(){
    cin>>n;
    rep(i,0,n)adj[i].clear();
    rep(i,0,n)cin>>cost[i];
    cin>>m;
    while(m--){
        int u,v;
        cin>>u>>v;
        adj[--u].pb(--v);
    }
    tarjans();
    unordered_map<int,int> min_cost;
    unordered_map<int,int> ways;
    rep(i,0,n){
        int c = cost[i];
        int w = lo[i];
        if(min_cost.find(w)==min_cost.end() || min_cost[w]>c){
            min_cost[w]=c;
            ways[w]=1;
        }else if(min_cost[w]==c)ways[w]++;
    }
    ll a=0,b=1;
    for(auto [k,v]:min_cost){
        a+=v;
        b=(b*ways[k])%mod;
    }
    cout<<a<<" "<<b<<ln;
}
int32_t main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
solve();
return 0;}