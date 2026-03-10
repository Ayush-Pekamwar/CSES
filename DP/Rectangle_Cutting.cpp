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

ll dp[501][501];
void solve() {
    int a, b;
    cin >> a >> b;
    memset(dp, 0, sizeof(dp));

    for (int i = 1; i <= a; i++) {
        for (int j = 1; j <= b; j++) {
            // cut along len
            if (i == j) {
                dp[i][j] = 0;
                continue;
            }

            ll minMoves = INT_MAX;
            for (int c = 1; c < i; c++) {
                minMoves = min(minMoves, 1 + dp[c][j] + dp[i - c][j]);
            }

            // cut along breath(b)
            for (int c = 1; c < j; c++) {
                minMoves = min(minMoves, 1 + dp[i][c] + dp[i][j - c]);
            }

            dp[i][j] = minMoves;
        }
    }

    cout << dp[a][b];
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