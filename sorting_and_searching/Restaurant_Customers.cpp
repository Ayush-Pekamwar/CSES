#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 1e9+7;

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


void solve(){
    int n; cin>>n;
    vector<pair<int,int>> a(2*n);
    for(int i=0; i+1<2*n; i+=2){
        int x,y; cin>>x>>y;
        a[i] = {x,1};
        a[i+1] = {y,-1};
    }

    sort(a.begin(), a.end());
    int cnt = 0, mxcnt = 0;
    for(int i=0; i<a.size(); i++){
        cnt += a[i].second;
        mxcnt = max(mxcnt , cnt);
    }  

    cout<<mxcnt;

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