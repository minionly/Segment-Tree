#include <bits/stdc++.h>
using namespace std;

int root[100005],sz[100005];

void make_sets(int n){
    for(int i=1;i<=n;i++){
        root[i] = i;
        sz[i] = 1;
    }
}

int find(int u){
    if(root[u] == u){
        return u;
    }
    return root[u] = find(root[u]);
}

void unify(int u, int v){
    int f1 = find(u);
    int f2 = find(v);

    if(f1 == f2){
        return;
    }

    if(sz[f2] <= sz[f1]){
        root[f2] = f1;
        sz[f1] += sz[f2];
    }
    else{
        root[f1] = f2;
        sz[f2] += sz[f1];
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("main.inp","r",stdin);
    freopen("main.out","w",stdout);

    int n,m,u,v;
    string s;
    
    cin>>n>>m;

    make_sets(n);
    
    while(m--){
        cin>>s>>u>>v;
        if(s == "union"){
            unify(u,v);
        }
        else{
            cout<<(find(u) == find(v) ? "YES" : "NO")<<endl;;
        }
    }
    return 0;
}
/**
⠀⠀⠀⠀⠀⠀⠀⠀ ⠀⠀⠀⣠⣴⣶⣿⣿⣷⣶⣄⣀⣀⠀⠀
⠀⠀⠀⠀⠀⠀⠀ ⠀⠀⣰⣾⣿⣿⡿⢿⣿⣿⣿⣿⣿⣿⣿⣷⣦⡀⠀⠀
⠀⠀⠀⠀⠀⠀ ⠀⢀⣾⣿⣿⡟⠁⣰⣿⣿⣿⡿⠿⠻⠿⣿⣿⣿⣿⣧
⠀⠀⠀⠀⠀ ⠀⠀⣾⣿⣿⠏⠀⣴⣿⣿⣿⠉⠀⠀⠀⠀⠀⠈⢻⣿⣿⣇
⠀⠀⠀⠀  ⣠⣼⣿⣿⡏⠀⢠⣿⣿⣿⠇⠀⠀⠀⠀⠀⠀⠀⠈⣿⣿⣿⡀
⠀⠀⠀ ⣰⣿⣿⣿⣿⣿⡇⠀⢸⣿⣿⣿⡀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⡇
⠀⠀ ⢰⣿⣿⡿⣿⣿⣿⡇⠀⠘⣿⣿⣿⣧⠀⠀⠀⠀⠀⠀⢀⣸⣿⣿⣿⠁
⠀  ⣿⣿⣿⠁⣿⣿⣿⡇⠀⠀⠻⣿⣿⣿⣷⣶⣶⣶⣶⣶⣿⣿⣿⣿⠃
  ⢰⣿⣿⡇⠀⣿⣿⣿⠀⠀⠀⠀⠈⠻⣿⣿⣿⣿⣿⣿⣿⣿⣿⠟⠁⠀
  ⢸⣿⣿⡇⠀⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀⠉⠛⠛⠛⠉⢉⣿⣿⠀⠀⠀⠀
  ⢸⣿⣿⣇⠀⣿⣿⣿⠀⠀⠀⠀⠀⢀⣤⣤⣤⡀⠀⠀⢸⣿⣿⣿⣷⣦⠀
   ⢻⣿⣿⣶⣿⣿⣿⠀⠀⠀⠀⠀⠈⠻⣿⣿⣿⣦⡀⠀⠉⠉⠻⣿⣿⡇
     ⠛⠿⣿⣿⣿⣿⣷⣤⡀⠀⠀⠀⠀⠈⠹⣿⣿⣇⣀ ⣠⣾⣿⣿⡇
          ⠹⣿⣿⣿⣿⣦⣤⣤⣤⣤⣾⣿⣿⣿⣿⣿⣿⣿⣿⡟⠀
              ⠉⠻⢿⣿⣿⣿⣿⣿⣿⠿⠋⠉⠛⠋⠉⠉⠁⠀
⠀                 ⠈⠉⠉⠉⠁
**/