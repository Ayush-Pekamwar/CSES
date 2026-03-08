#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 1e9 + 7;

// CUSTOM HASH
// unordered_map<int, int, custom_hash> mp;
// unordered_set<int, custom_hash> st;
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};


const ll INF = 1e15;
vector<ll> dp;
ll f(int i, int j, vector<ll>& c) {
    if (i == 0) {
        return 1;
    }
    if (j >= c.size()) return 0;

    ll ways = 0;
    ll cur = i;
    while (cur - c[j] >= 0) {
        ways += f(cur - c[j], j + 1, c);
    }

    return ways;
}
void solve() {
    ll n; cin >> n;
    ll x; cin >> x;
    vector<ll> c(n);
    for (int i = 0; i < n; i++) cin >> c[i];

    dp.assign(x + 1, INF);

    cout << f(x, 0, c);
}


/* Main()  function */
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
/* Main() Ends Here */