#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 1e9 + 7;

ll arr[10000001];
void solve() {
    ll n, k; cin >> n >> k;
    ll x, a, b, c;
    cin >> x >> a >> b >> c;

    arr[0] = x;
    for (int i = 1; i < n; i++) {
        arr[i] = (a * arr[i - 1] + b) % c;
    }

    ll ans = 0;
    deque<ll> dq;
    for (int i = 0; i < k; i++) {
        while (!dq.empty() && arr[dq.front()] >= arr[i]) {
            dq.pop_front();
        }
        dq.push_front(i);
    }

    if (!dq.empty()) ans ^= arr[dq.back()];

    for (int l = 0, r = k; r < n; r++, l++) {
        while (!dq.empty() && dq.back() <= l) {
            dq.pop_back();
        }
        while (!dq.empty() && arr[dq.front()] >= arr[r]) {
            dq.pop_front();
        }
        dq.push_front(r);

        if (!dq.empty()) ans ^= arr[dq.back()];
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