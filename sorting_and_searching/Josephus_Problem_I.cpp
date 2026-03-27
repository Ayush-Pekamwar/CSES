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

void f(vector<int>& arr){
    if(arr.size()==1){
        cout<<arr[0]<<' ';
        return;
    }

    for(int i=1; i<arr.size(); i+=2){
        cout<<arr[i]<<' ';
    }

    vector<int> narr;
    if(arr.size()%2){
        narr.push_back(arr.back());
        for(int i=0; i<arr.size()-1; i+=2){
            narr.push_back(arr[i]);
        }
    }
    else{
        for (int i = 0; i < arr.size(); i += 2) {
            narr.push_back(arr[i]);
        }
    }

    f(narr);
}
void solve() {
    int n;
    cin >> n;
    vector<int> a(n,0);
    for(int i=0; i<n; i++){
        a[i] = i+1;
    }

    f(a);
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