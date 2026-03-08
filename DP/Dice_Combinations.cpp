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

const int N = 1e6 + 1;
int dp[N];
ll f(ll n) {
    if (n <= 1) return 1;
    if (dp[n] != -1) return dp[n];
    ll ways = 0;
    for (int i = 1; i <= min(n, 6LL); i++) {
        ways = (ways + f(n - i)) % MOD;
    }

    return dp[n] = ways % MOD;
}
void solve() {
    ll n; cin >> n;
    memset(dp, -1, sizeof(dp));
    cout << f(n);

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