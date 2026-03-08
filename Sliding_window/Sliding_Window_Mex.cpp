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
    int n; cin >> n;
    int k; cin >> k;
    vector<int> a(n, 0);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<int> freq(k, 0);
    set<int> missing;
    for (int i = 0; i <= k; i++) {
        missing.insert(i);
    }

    for (int i = 0; i < k; i++) {
        if (a[i] >= k) continue;
        freq[a[i]]++;
        if (freq[a[i]] == 1) {
            missing.erase(a[i]);
        }
    }
    cout << *missing.begin() << " ";

    for (int i = k; i < n; i++) {
        if(a[i] < k){
            freq[a[i]]++;
            if (freq[a[i]] == 1) {
                missing.erase(a[i]);
            }
        }
        if(a[i-k] < k){
            freq[a[i - k]]--;
            if (freq[a[i - k]] == 0) {
                missing.insert(a[i - k]);
            }
        }
        cout << *missing.begin() << " ";
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