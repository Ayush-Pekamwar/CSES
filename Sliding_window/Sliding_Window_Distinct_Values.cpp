#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 1e9 + 7;

// CUSTOM HASH
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
    int n; cin >> n;
    int k; cin >> k;
    vector<ll> a(n, 0);
    for (int i = 0; i < n; i++) cin >> a[i];

    unordered_map<int, int, custom_hash> mp;
    for (int i = 0; i < k; i++) {
        mp[a[i]]++;
    }

    int unq = mp.size();
    cout << unq << " ";

    for (int l = 0, r = k; r < n; r++, l++) {
        mp[a[l]]--;
        if (mp[a[l]] == 0) unq--;

        mp[a[r]]++;
        if (mp[a[r]] == 1) unq++;

        cout << unq << " ";
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