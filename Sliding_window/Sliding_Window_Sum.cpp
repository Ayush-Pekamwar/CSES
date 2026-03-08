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
    ll cursum = 0;
    for (int i = 0; i < k; i++) {
        cursum += arr[i];
    }
    ans = cursum;

    // for (int i = 0; i < n; i++) {
    //     cout << arr[i] << " ";
    // }
    // cout << '\n';

    int l = 0;
    for (int r = k; r < n; r++) {
        cursum += arr[r];
        cursum -= arr[l++];

        ans ^= cursum;
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