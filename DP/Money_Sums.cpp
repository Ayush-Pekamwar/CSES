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

int f(int i, int target, vector<ll>& a) {
    if (i == a.size()) {
        return target == 0;
    }
    if (dp[i][target] != -1) {
        return dp[i][target];
    }

    bool notpick = f(i + 1, target, a);
    bool pick = 0;
    if (target - a[i] >= 0) {
        pick = f(i + 1, target - a[i], a);
    }

    return dp[i][target] = pick || notpick;
}
void solve() {
    int n;
    cin >> n;
    vector<ll> a(n, 0);
    for (int i = 0; i < n; i++) cin >> a[i];

    ll total = accumulate(a.begin(), a.end(), 0LL);
    dp.assign(n, vector<int>(total + 1, -1));

    vector<int> ans;
    for (int target = 1; target <= total; target++) {   
        if(f(0,target,a)){
            ans.push_back(target);
        }
    }

    cout<<ans.size()<<'\n';
    for(auto&x: ans) cout<<x<<" ";
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