#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<long long>

#define rep(i,a,b) for(int i=a;i<b;i++)
#define ln '\n'

ll binp(ll x, ll y, ll m){
    if(y == 0){
        return 1;
    }
    ll res = 1;
    while(y > 0){
        if(y & 1) res = res * x % m;
        x = x * x % m;
        y >>= 1;
    }
    return res % m;
}

void solve(){
    string s;
    ll a, b;
    cin >> s;
    cin >> a >> b;

    int n = s.size();
    vll rema(n), remb(n);

    // Calculate remainders for prefixes
    rema[0] = (s[0] - '0') % a;
    rep(i, 1, n) {
        rema[i] = (rema[i - 1] * 10 + (s[i] - '0')) % a;
    }

    // Calculate remainders for suffixes
    remb[n - 1] = (s[n - 1] - '0') % b;
    for (int i = n - 2; i >= 0; i--) {
        remb[i] = ((s[i] - '0') * binp(10, n - 1 - i, b) + remb[i + 1]) % b;
    }

    // Find the valid position to cut the number
    bool found = false;
    int index = -1;
    rep(i, 0, n - 1) {
        if (rema[i] == 0 && remb[i + 1] == 0 && s[i + 1] != '0') {
            found = true;
            index = i;
            break;
        }
    }

    if (found) {
        cout << "YES" << ln;
        rep(i, 0, index + 1) {
            cout << s[i];
        }
        cout << ln;
        rep(i, index + 1, n) {
            cout << s[i];
        }
        cout << ln;
    } else {
        cout << "NO" << ln;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
