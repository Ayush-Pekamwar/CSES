// TC = O(N^2log(N)) -> does not pass due to tight bounds on CSES but is solutions is cleaverly good enough
// can be further optimized by reducing constant factors , but i am too lazy to do that

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
    vector<string> grid(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    const int INF = 1e8;
    vector<vector<int>> priority(n, vector<int>(n, INF));
    priority[n - 1][n - 1] = 1;

    vector<pair<int, int>> startpoints;
    for (int j = n - 2; j >= 0; j--) {
        startpoints.push_back({n - 1, j});
    }
    for (int i = n - 2; i >= 0; i--) {
        startpoints.push_back({i, 0});
    }

    for (auto [r, c] : startpoints) {
        vector<pair<pair<char, int>, pair<int, int>>> v;
        while (r >= 0 && c < n) {
            int mnp = INF;
            if (r + 1 < n) {
                mnp = min(mnp, priority[r + 1][c]);
            }
            if (c + 1 < n) {
                mnp = min(mnp, priority[r][c + 1]);
            }

            v.push_back({{grid[r][c], mnp}, {r, c}});
            r--, c++;
        }

        sort(v.begin(), v.end());
        int p = 1;
        priority[v[0].second.first][v[0].second.second] = p;
        for (int i = 1; i < v.size(); i++) {
            if (v[i].first != v[i - 1].first) p++;
            priority[v[i].second.first][v[i].second.second] = p;
        }
    }

    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         cout << priority[i][j] << " ";
    //     }
    //     cout << '\n';
    // }

    string ans;
    int i = 0, j = 0;
    while (i < n && j < n) {
        // cout << i << " " << j << '\n';
        ans += grid[i][j];
        if (i + 1 < n && j + 1 < n) {
            if (priority[i + 1][j] < priority[i][j + 1]) {
                i++;
            }
            else {
                j++;
            }
        }
        else if (i + 1 < n) {
            i++;
        }
        else {
            j++;
        }
    }

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