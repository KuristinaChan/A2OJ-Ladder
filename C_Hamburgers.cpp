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
int ns, nb, nc;
int p_b, ps, pc;
ll r;
ll recb = 0, recc = 0, recs = 0;

bool check(ll x) {
    ll c1 = max(0LL, p_b * (x * recb - nb));
    ll c2 = max(0LL, ps * (x * recs - ns));
    ll c3 = max(0LL, pc * (x * recc - nc));
    return c1 + c2 + c3 <= r;
}

void solve() {
    string s;
    cin >> s;

    for (auto c : s) {
        recb += c == 'B';
        recc += c == 'C';
        recs += c == 'S';
    }

    cin >> nb >> ns >> nc;
    cin >> p_b >> ps >> pc;
    cin >> r;

    ll ini = LLONG_MAX;
    if (recb > 0) ini = min(ini, nb / recb);
    if (recc > 0) ini = min(ini, nc / recc);
    if (recs > 0) ini = min(ini, ns / recs);
    if (ini == LLONG_MAX) ini = 0;

    nb -= ini * recb;
    nc -= ini * recc;
    ns -= ini * recs;

    ll low = 0, high = 1e12;
    ll ans = 0;
    while (low <= high) {
        ll m = low + ((high - low) >> 1);
        if (check(m)) {
            ans = m;
            low = m + 1;
        } else {
            high = m - 1;
        }
    }
    cout << ans + ini << ln;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
