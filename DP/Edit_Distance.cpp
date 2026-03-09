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
int f(int i, int j, string& s1, string& s2) {
    if (i == s1.size() && j == s2.size()) {
        return 0;
    }
    if (i == s1.size()) {
        return s2.size() - j;
    }
    if (j == s2.size()) {
        return s1.size() - i;
    }
    if (dp[i][j] != -1) return dp[i][j];

    if (s1[i] == s2[j]) {
        return dp[i][j] = f(i + 1, j + 1, s1, s2);
    }

    int replace = 1 + f(i + 1, j + 1, s1, s2);
    int add = 1 + f(i, j + 1, s1, s2);
    int remove = 1 + f(i + 1, j, s1, s2);

    return dp[i][j] = min(replace, min(add, remove));
}
void solve() {
    string s1, s2;
    cin >> s1 >> s2;

    int n1 = s1.size();
    int n2 = s2.size();
    dp.assign(n1 + 1, vector<int>(n2 + 1, 0));

    // base cases
    dp[n1][n2] = 0;
    for (int j = 0; j < n2; j++) {
        dp[n1][j] = n2 - j;
    }
    for (int i = 0; i < n1; i++) {
        dp[i][n2] = n1 - i;
    }

    for (int i = n1 - 1; i >= 0; i--) {
        for (int j = n2 - 1; j >= 0; j--) {
            if (s1[i] == s2[j]) {
                dp[i][j] = dp[i + 1][j + 1];
                continue;
            }

            int replace = 1 + dp[i + 1][j + 1];
            int add = 1 + dp[i][j + 1];
            int remove = 1 + dp[i + 1][j];

            dp[i][j] = min(replace, min(add, remove));
        }
    }

    cout << dp[0][0];
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