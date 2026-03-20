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

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<ll> a(n, 0), b(m, 0);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    // for (int i = 0; i < n; i++) cout << a[i] << " ";
    // cout << '\n';
    // for (int i = 0; i < m; i++) cout << b[i] << " ";

    int i = 0, j = 0;
    int cnt = 0;
    while (i < n && j < m) {
        // cout<<i<<" "<<j<<'\n';
        if (a[i] - k <= b[j] && b[j] <= a[i] + k) {
            cnt++;
            i++, j++;
        }
        else if (b[j] < a[i] - k) {
            j++;
        }
        else {
            i++;
        }
    }

    cout << cnt;
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