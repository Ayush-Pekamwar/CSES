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
    int n;
    cin >> n;
    int m;
    cin >> m;
    vector<ll> arr(n, 0);
    unordered_map<int, int, custom_hash> pos;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        pos[arr[i]] = i;
    }

    int rounds = 1;
    for (int i = 2; i <= n; i++) {
        if (pos[i-1] > pos[i]) {
            rounds++;
        }
    }

    while (m--) {
        int i, j;
        cin >> i >> j;
        i--,j--;
        if (i > j) swap(i, j);

        int x = arr[i], y = arr[j];

        if (i < pos[x - 1] && pos[x - 1] < j) rounds--;
        if (i < pos[x + 1] && pos[x + 1] < j) rounds++;
        if (i < pos[y - 1] && pos[y - 1] < j) rounds++;
        if (i < pos[y + 1] && pos[y + 1] < j) rounds--;

        if (x == y + 1) rounds--;
        if (x == y - 1) rounds++;

        cout << rounds << '\n';

        swap(arr[i], arr[j]);
        pos[x] = j;
        pos[y] = i;
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