#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 1e9 + 7;


class BalancedHeaps {
public:
    // lst = k/2 elements
    // rst = k/2 + (k%2) elements
    // thus median at rst.begin();
    multiset<ll> lst, rst;
    ll lsum = 0, rsum = 0;

    void rebalance() {
        while (lst.size() > rst.size()) {
            ll v = *lst.rbegin();
            lst.erase(lst.find(v));
            rst.insert(v);
            lsum -= v;
            rsum += v;
        }

        while (rst.size() > lst.size() + 1) {
            ll v = *rst.begin();
            rst.erase(rst.begin());
            lst.insert(v);

            rsum -= v;
            lsum += v;
        }
    }

    void add(ll v) {
        if (rst.empty() || v >= *rst.begin()) {
            rst.insert(v);
            rsum += v;
        }
        else {
            lst.insert(v);
            lsum += v;
        }
        rebalance();
    }

    void remove(ll v) {
        if (!rst.empty() && v >= *rst.begin()) {
            rst.erase(rst.find(v));
            rsum -= v;
        }
        else {
            lst.erase(lst.find(v));
            lsum -= v;
        }
        rebalance();
    }

    ll getCost() {
        ll M = *rst.begin();
        return lst.size() * M - lsum + rsum - rst.size() * M;
    }
};


void solve() {
    int n; cin >> n;
    int k; cin >> k;
    vector<ll> a(n, 0);
    for (int i = 0; i < n; i++) cin >> a[i];

    BalancedHeaps bh;
    int i = 0;
    for (int j = 0; j < n; j++) {
        bh.add(a[j]);

        if (j - i + 1 < k) continue;

        cout << bh.getCost() << ' ';
        bh.remove(a[i]);
        i++;
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