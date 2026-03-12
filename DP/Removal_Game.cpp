#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n, 0);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<vector<ll>> dp(n, vector<ll>(n, 0));
    for (int l = n - 1; l >= 0; l--) {
        for (int r = l; r < n; r++) {
            if (r == l) {
                dp[l][r] = a[l];
            }
            else {
                dp[l][r] = max(a[l] - dp[l + 1][r], a[r] - dp[l][r - 1]);
            }
        }
    }
    ll total = accumulate(a.begin(), a.end(), 0LL);
    ll firstScore = (total + dp[0][n - 1]) / 2;
    cout << firstScore;
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