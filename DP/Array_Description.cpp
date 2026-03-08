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

int n, m;
vector<vector<ll>> dp;
ll f(int i, int prev, vector<int>& a) {
    if (i >= a.size()) {
        return 1;
    }
    if (a[i] != 0) {
        if (i > 0 && abs(a[i] - prev) > 1) return 0;
        else return f(i + 1, a[i], a);
    }
    if (dp[i][prev] != -1) {
        return dp[i][prev];
    }

    ll ways = 0;
    if (prev == 0) {
        for (int j = 1; j <= m; j++) {
            ways += f(i + 1, j, a);
            ways %= MOD;
        }
    }
    else {
        ways += f(i + 1, prev, a);
        ways %= MOD;

        if (prev + 1 <= m) {
            ways += f(i + 1, prev + 1, a);
            ways %= MOD;
        }

        if (prev - 1 > 0) {
            ways += f(i + 1, prev - 1, a);
            ways %= MOD;
        }
    }

    return dp[i][prev] = ways % MOD;
}
void solve() {
    cin >> n >> m;
    vector<int> a(n, 0);
    for (int i = 0; i < n; i++) cin >> a[i];
    dp.assign(n + 1, vector<ll>(m + 1, -1));

    cout << f(0, 0, a);
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