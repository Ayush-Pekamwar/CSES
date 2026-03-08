#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 1e9+7;

// ------------Ordered_Set-------------
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <class T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
// st.order_of_key(x): number of elements strictly smaller than x
// st.find_by_order(k): iterator to k-th smallest element (0-indexed)
// for descending order : change less<long long> to greater<long long>


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


// Fast exponentiation with MOD
long long modpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

// Modular inverse using Fermat's Little Theorem
long long modinv(long long a) {
    return modpow(a, MOD - 2);
}

// Computes C(n, k) % MOD
long long compute_nCnk(long long n, long long k) {
    long long res = 1;
    for (long long i = 1; i <= k; i++) {
        long long num = (n - k + i) % MOD;
        res = res * num % MOD;
        res = res * modinv(i) % MOD;
    }
    return res;
}

void solve() {
    int n; cin >> n;
    vector<ll> a(n, 0);
    for (int i = 0; i < n; i++) cin >> a[i];



}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}