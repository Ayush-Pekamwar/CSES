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

long long modpow(long long a, long long b) {
    long long res = 1;
    while (b) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

vector<vector<ll>> dp;
ll f(int i, ll target) {
    if (i == 0) {
        return target == 0;
    }
    if (dp[i][target] != -1) {
        return dp[i][target];
    }

    ll notpick = f(i - 1, target);
    ll pick = 0;
    if (target - i >= 0) {
        pick = f(i - 1, target - i);
    }

    return dp[i][target] = (pick + notpick) % MOD;
}
void solve() {
    int n;
    cin >> n;
    ll total = (n * (n + 1)) / 2;
    if (total % 2) {
        cout << 0;
        return;
    }

    ll target = total / 2;
    dp.assign(n + 1, vector<ll>(target + 1, -1));
    ll ans = f(n, target);
    ans = ans * modpow(2, MOD - 2) % MOD;
    cout << ans;
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