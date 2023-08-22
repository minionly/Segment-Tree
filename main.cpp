#include <bits/stdc++.h>
using namespace std;

long long tree[400005],lazy[400005];
const long long MOD = 1e9 + 7;

void build(int id, int l, int r){
    if(l == r){
        tree[id] = 1;
        return;
    }
    int mid = l + r >> 1;
    build(2*id,l,mid);
    build(2*id+1,mid+1,r);

    tree[id] = (tree[2*id] + tree[2*id+1]) % MOD;
}

void propagate(int id, int l, int r){
    if(lazy[id] == 1){
        return;
    }
    tree[id]  = (tree[id] % MOD) * (lazy[id] % MOD) % MOD;
    if(l != r){
        lazy[2*id]  = (lazy[2*id] % MOD) * (lazy[id] % MOD) % MOD;
        lazy[2*id+1]  = (lazy[2*id+1] % MOD) * (lazy[id] % MOD) % MOD;
    }
    lazy[id] = 1;
}

void update(int id, int l, int r, int u, int v, int val){
    propagate(id,l,r);
    if(v < l || u > r){
        return;
    }
    if(u <= l && r <= v){
        lazy[id]  = (lazy[id] % MOD) * (val % MOD) % MOD;
        propagate(id,l,r);
        return;
    }

    int mid = l+r >> 1;
    update(2*id,l,mid,u,v,val);
    update(2*id+1,mid+1,r,u,v,val);

    tree[id] = (tree[2*id] + tree[2*id+1]) % MOD;
}

long long get(int id, int l, int r, int u, int v){
    propagate(id,l,r);
    if(v < l || u > r){
        return 0;
    }
    if(u <= l && r <= v){
        return tree[id];
    }
    
    int mid = l + r >> 1;
    return get(2*id,l,mid,u,v) + get(2*id+1,mid+1,r,u,v);
}   

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("main.inp","r",stdin);
    freopen("main.out","w",stdout);

    int n,m;

    cin>>n>>m;
    fill(lazy,lazy+400000,1);

    build(1,1,n);

    while(m--){
        int task;
        cin>>task;
        if(task == 1){
            int l,r,v;
            cin>>l>>r>>v;
            l++;
            update(1,1,n,l,r,v);
        }
        else{
            int l,r;
            cin>>l>>r;
            l++;
            cout<<get(1,1,n,l,r) % MOD<<endl;
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