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

const ll INF = 1e9;
void solve() {
    ll n; cin >> n;
    vector<ll> dp(n + 1, INF);
    dp[0] = 0;

    for (int i = 1; i <= n; i++) {
        unordered_set<int> digits;
        int numcpy = i;
        while (numcpy > 0) {
            int d = numcpy % 10;
            numcpy /= 10;
            digits.insert(d);
        }

        for (auto& d : digits) {
            if (i - d >= 0) {
                dp[i] = min(dp[i], dp[i - d] + 1);
            }
        }
    }

    cout << dp[n];
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