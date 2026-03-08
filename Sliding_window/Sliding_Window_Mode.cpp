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
    int n, k; cin >> n >> k;
    vector<int> a(n, 0);
    for (int i = 0; i < n; i++) cin >> a[i];

    unordered_map<int, int, custom_hash> freq;
    map<int, set<int>> mp;

    for (int i = 0; i < n; i++) {
        if (freq[a[i]] > 0) {
            mp[freq[a[i]]].erase(a[i]);
            if (mp[freq[a[i]]].empty()) mp.erase(freq[a[i]]);
        }
        freq[a[i]]++;
        mp[freq[a[i]]].insert(a[i]);

        // cout << "debug map\n";
        // for (auto& [frq, st] : mp) {
        //     cout << frq << '\n';
        //     for (auto& x : st) {
        //         cout << x << " ";
        //     }
        //     cout << '\n';
        // }
        // cout << '\n';
        if (i < k - 1) continue;


        int mode = *(mp.rbegin()->second).begin();
        cout << mode << " ";

        mp[freq[a[i - k + 1]]].erase(a[i - k + 1]);
        if (mp[freq[a[i - k + 1]]].empty()) mp.erase(freq[a[i - k + 1]]);
        
        freq[a[i - k + 1]]--;
        if (freq[a[i - k + 1]] > 0) {
            mp[freq[a[i - k + 1]]].insert(a[i - k + 1]);
        }
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