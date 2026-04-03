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


bool dfs(int cur, int reqcolor, vector<vector<int>>& adj , vector<int>& color){
    if(color[cur] != -1){
        return reqcolor == color[cur];
    }
    color[cur] = reqcolor;
    
    for(auto& child: adj[cur]){
        if(dfs(child, reqcolor^1, adj, color) == false) return false;
    }

    return true;
}

void solve(){
    int n; cin>>n;
    int m; cin>>m;

    vector<vector<int>> adj(n);
    for(int i=0; i<m; i++){
        int u,v; cin>>u>>v;
        u--,v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> color(n,-1);
    bool ok = 1;
    for(int i=0 ; i<n; i++){
        if(color[i]==-1){
            ok&=dfs(i,0,adj, color);
        }
    }

    if(ok){
        for(int i=0; i<n; i++){
            cout<<color[i]+1<<' ';
        }
    }
    else{
        cout<<"IMPOSSIBLE\n";
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