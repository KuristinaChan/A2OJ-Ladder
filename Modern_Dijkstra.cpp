#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>
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

ll gcd(const ll a,const ll b){return(b==0?a:gcd(b,a%b));}
ll lcm(const ll a,const ll b){return a/gcd(a,b)*b;}
ll binpow(ll a,ll n){ll ans=1;for(;n;n/=2,a*=a)if(n&1)ans*=a;return ans;}
ll binpow(ll a,ll n,const ll&mod){ll ans=1;for(;n;n/=2,a=a*a%mod)if(n&1)ans=ans*a%mod;return ans;}
ll cdiv(const ll&a,const ll&b){return(a/b+((a^b)>0&&a%b));}
ll fdiv(const ll&a,const ll&b){return a/b-((a^b)<0&&a%b);}
const ll mod=1000000007;
// const ll mod = 998244353;
void dijkstra(int N,vector<ll>&vertex_weights,vector<vector<pll>>&graph){
    vll dist(N+1,LLONG_MAX);
    dist[1]=vertex_weights[0];
    pqueue<pll,vector<pll>,greater<pll>>pq;
    pq.push({vertex_weights[0],1});
    while(!pq.empty()){
        auto [current_dist,u]=pq.top();
        pq.pop();
        if(current_dist>dist[u])continue;
        for(const auto&edge:graph[u]){
            int v=edge.ff;
            ll weight=edge.ss;
            ll new_dist=current_dist+weight+vertex_weights[v-1];
            if(new_dist<dist[v]){
                dist[v]=new_dist;
                pq.push({new_dist,v});
            }
        }
    }
    repb(i,2,N)cout<<dist[i]<<" ";
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N,M;
    cin>>N>>M;
    vector<ll>vertex_weights(N);
    rep(i,0,N)cin>>vertex_weights[i];
    vector<vector<pll>>graph(N+1);
    rep(i,0,M){
        int u,v;
        ll b;
        cin>>u>>v>>b;
        graph[u].pb({v,b});
        graph[v].pb({u,b});
    }
    dijkstra(N,vertex_weights,graph);
    return 0;
}
