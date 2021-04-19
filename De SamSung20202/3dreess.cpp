#include <bits/stdc++.h>
using namespace std;

#define MAX 100
int n, m;
int cost[MAX];
bool marked[MAX];
int quanHe[MAX][MAX];
int x[MAX];
int cur;
int ans;

void input() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> cost[i];
    }
    int u, v;
    for(int i = 1; i <= m; i++) {
        cin >> u >> v;
        quanHe[u][v] = 1;
    }
}

void TRY(int k) {
    for(int v = 1; v <= n; v++) {
        if(!marked[v]) {
            x[k] = v;
            if(quanHe[x[k-1]][x[k]]) {
                cur += cost[x[k]];
            }
            marked[v] = true;
            if(k == 3) {
                if(quanHe[x[k]][x[k-2]] && quanHe[x[k-2]][x[k-1]] && quanHe[x[k-1]][x[k]]) {
                    ans = min(ans, cur + cost[x[k-2]]);
                }
            }
            else TRY(k+1);
            marked[v] = false;
            if(quanHe[x[k-1]][x[k]]) {
                cur -= cost[v];
            }
        }
    }
}

void solve() {
    cur = 0;
    x[0] = 0;
    ans = INT_MAX;
    TRY(1);
    if(ans == INT_MAX) cout << "-1";
    else cout << ans;
}

int main(){
    input();
    solve();
   return 0;
}
