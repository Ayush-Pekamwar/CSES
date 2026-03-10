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

vector<vector<int>> dp;
int f(int i, int j, vector<int>& a, vector<int>& b) {
    if (i >= a.size() || j >= b.size()) {
        return 0;
    }
    if (dp[i][j] != -1) {
        return dp[i][j];
    }

    int pick = 0, notpick1 = 0, notpick2 = 0;
    if (a[i] == b[j]) {
        pick = 1 + f(i + 1, j + 1, a, b);
    }
    notpick1 = f(i + 1, j, a, b);
    notpick2 = f(i, j + 1, a, b);

    return dp[i][j] = max(pick, max(notpick1, notpick2));
}
void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n, 0);
    vector<int> b(m, 0);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    dp.assign(n, vector<int>(m + 1, -1));
    int ans = f(0, 0, a, b);
    cout << ans << '\n';

    int i = 0, j = 0;
    vector<int> lcs;
    while (lcs.size() < ans && i < n && j < m) {
        int pick = 0, notpick1 = 0, notpick2 = 0;
        if (a[i] == b[j]) {
            pick = 1 + f(i + 1, j + 1, a, b);
        }
        notpick1 = f(i + 1, j, a, b);
        notpick2 = f(i, j + 1, a, b);

        if (dp[i][j] == pick) {
            lcs.push_back(a[i]);
            i++, j++;
        }
        else if (dp[i][j] == notpick1) {
            i++;
        }
        else {
            j++;
        }
    }

    for (auto& x : lcs) {
        cout << x << " ";
    }
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