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


class DSU{
public:
    vector<int> par, sz;
    DSU(int n){
        par.assign(n,0);
        sz.assign(n,1);

        for(int i=0; i<n; i++){
            par[i] = i;
        }
    }

    int find(int i){
        if(i == par[i]) return i;
        else return par[i] = find(par[i]);
    }

    bool unite(int a, int b){
        a = find(a);
        b = find(b);

        if(sz[b]>sz[a]){
            swap(a,b);
        }
        if(a==b) return false;
        
        par[b] = a;
        sz[a] += sz[b];

        return true;
    }
};
void solve(){
    int n; cin>>n;
    int m; cin>>m;
    
    DSU dsu = DSU(n);
    for(int i=0; i<m; i++){
        int u,v; cin>>u>>v;
        u--,v--;
        dsu.unite(u,v);
    }

    set<int> st;
    for(int i=0; i<n; i++){
        st.insert(dsu.find(i));
    }

    vector<int> v;
    for(auto& ele : st){
        v.push_back(ele);
    }

    cout<<v.size()-1<<'\n';
    for(int i=1; i<v.size(); i++){
        cout<<v[i-1]+1<<" "<<v[i]+1<<'\n';
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