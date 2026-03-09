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
ll dp1[N], dp2[N];
/* Main()  function */
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    memset(dp1, 0, sizeof(dp1));
    memset(dp2, 0, sizeof(dp2));

    dp1[1] = 1;
    dp2[1] = 1;

    for (int i = 2; i < N; i++) {
        dp1[i] = (4 * dp1[i - 1] + dp2[i - 1]) % MOD;
        dp2[i] = (2 * dp2[i - 1] + dp1[i - 1]) % MOD;
    }

    int t = 1;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << (dp1[n] + dp2[n]) % MOD << '\n';
    }
    return 0;
}
/* Main() Ends Here */