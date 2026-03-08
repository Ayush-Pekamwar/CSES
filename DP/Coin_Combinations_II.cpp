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

int f(int amt, int j, vector<int>& c) {
    if (amt == 0) return 1;
    if (j >= c.size()) return 0;


    ll nottake = f(amt, j + 1, c);
    ll take = 0;
    if (amt - c[j] >= 0) {
        take = f(amt - c[j], j, c);
    }

    return (take + nottake) % MOD;
}

void solve() {
    ll n; cin >> n;
    ll x; cin >> x;
    vector<int> c(n);
    for (int i = 0; i < n; i++) cin >> c[i];

    int dp[x + 1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (int& coin : c) {
        for (int i = coin; i <= x; i++) {
            dp[i] = (dp[i] + dp[i - coin]) % MOD;
        }
    }

    cout << dp[x];
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