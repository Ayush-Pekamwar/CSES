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

    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // for (int i = 0; i < n; i++) {
    //     cout << "adj[] " << i << '\n';
    //     for (auto& child : adj[i]) {
    //         cout << child << ' ';
    //     }
    //     cout << '\n';
    // }

    queue<int> q;
    vector<int> par(n, -1);
    vector<int> level(n, -1);
    level[0] = 0;
    par[0] = -1;
    q.push(0);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        // cout<<cur<<'\n';
        if (cur == n - 1) {
            break;
        }

        for (auto& child : adj[cur]) {
            if (level[child] == -1) {
                level[child] = level[cur] + 1;
                par[child] = cur;
                q.push(child);
            }
        }
    }

    // for(int i=0; i<n; i++){
    //     cout<<par[i]<<' ';
    // }
    if (par[n - 1] == -1) {
        cout << "IMPOSSIBLE";
        return;
    }

    int x = n - 1;
    cout << level[n - 1]+1 << '\n';
    vector<int> path;
    while (x != -1) {
        path.push_back(x+1);
        x = par[x];
    }

    for(int i=path.size()-1; i>=0; i--){
        cout<<path[i]<<' ';
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