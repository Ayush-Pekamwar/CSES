#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 1e9 + 7;

class AggregatedStack {
public:
    stack<pair<ll, ll>> stk;

    bool empty() {
        return stk.empty();
    }

    bool size() {
        return stk.size();
    }

    void push(ll val) {
        if (stk.empty()) stk.push({ val,val });
        else stk.push({ val , stk.top().second | val });
    }

    void pop() {
        if (!stk.empty()) stk.pop();
    }

    pair<ll, ll> top() {
        if (!stk.empty()) return stk.top();
        else return { -1,-1 };
    }
};

class AggregatedQueue {
public:
    AggregatedStack IN, OUT;

    void push(ll val) {
        IN.push(val);
    }

    void pop() {
        if (OUT.empty()) {
            while (!IN.empty()) {
                OUT.push(IN.top().first);
                IN.pop();
            }
        }

        OUT.pop();
    }

    ll query() {
        if (IN.empty()) return OUT.top().second;
        if (OUT.empty()) return IN.top().second;

        return IN.top().second | OUT.top().second;
    }
};


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
    AggregatedQueue q;
    for (int i = 0; i < n; i++) {
        q.push(arr[i]);
        if (i < k - 1) continue;

        // cout << q.query() << " ";
        ans ^= q.query();
        q.pop();
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