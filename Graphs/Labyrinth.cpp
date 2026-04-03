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

int n, m;
int level[1001][1001];
vector<string> s;

bool canVisit(int i, int j) {
    if (i < 0 || j < 0 || i >= n || j >= m || level[i][j] != 0 || s[i][j] == '#')
        return false;
    else
        return true;
}
bool inBounds(int i, int j) {
    if (i < 0 || j < 0 || i >= n || j >= m)
        return false;
    else
        return true;
}

void solve() {
    n, m;
    cin >> n >> m;
    s.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    queue<pair<int, int>> q;
    memset(level, 0, sizeof(level));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i][j] == 'A') {
                q.push({i, j});
                level[i][j] = 1;
            }
        }
    }

    int i = -1, j = -1;
    while (!q.empty()) {
        auto [curx, cury] = q.front();
        q.pop();

        if (s[curx][cury] == 'B') {
            // cout<<"YES\n"<<cur.path.size()<<'\n'<<cur.path;
            i = curx, j = cury;
            break;
        }
        if (canVisit(curx - 1, cury)) {
            q.push({curx - 1, cury});
            level[curx - 1][cury] = level[curx][cury] + 1;
        }
        if (canVisit(curx + 1, cury)) {
            q.push({curx + 1, cury});
            level[curx + 1][cury] = level[curx][cury] + 1;
        }
        if (canVisit(curx, cury - 1)) {
            q.push({curx, cury - 1});
            level[curx][cury - 1] = level[curx][cury] + 1;
        }
        if (canVisit(curx, cury + 1)) {
            q.push({curx, cury + 1});
            level[curx][cury + 1] = level[curx][cury] + 1;
        }
    }

    if (i == -1 && j == -1) {
        cout << "NO";
        return;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (level[i][j] == 0) {
                level[i][j] = 1e9;
            }
            // cout<<level[i][j]<<' ';
        }
        // cout<<'\n';
    }

    string path;
    vector<pair<int, int>> dir = {
        {-1, 0},
        {1, 0},
        {0, -1},
        {0, 1}};

    while (level[i][j] != 1) {
        int didx = 0;
        int mnlvl = level[i][j];
        int k = 0;
        for (auto& d : dir) {
            if (inBounds(i + d.first, j + d.second) && level[i + d.first][j + d.second] < mnlvl) {
                mnlvl = level[i + d.first][j + d.second];
                didx = k;
            }
            k++;
        }

        if (didx == 0) {
            path += 'D';
        }
        else if (didx == 1) {
            path += 'U';
        }
        if (didx == 2) {
            path += 'R';
        }
        if (didx == 3) {
            path += 'L';
        }

        i += dir[didx].first;
        j += dir[didx].second;
    }

    reverse(path.begin(), path.end());
    cout << "YES\n";
    cout << path.size() << '\n';
    cout << path;
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