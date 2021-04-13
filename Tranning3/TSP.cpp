#include <bits/stdc++.h>
using namespace std;
const int MAX = 20;
int n, m;
int marked[MAX];   // đánh dấu là đã thăm
int ans;
int x[MAX];      //
int c[MAX][MAX];
int c_min = INT_MAX;
int cur;

void input() {
    cin >> n >> m;
    int a, b;
    for(int i = 1; i <= m; i++) {
        cin >> a >> b;
        cin >> c[a][b];
        c_min = min(c_min, c[a][b]);
    }
}



void TRY(int k) {
    if(cur + c_min * (n - k + 1) >= ans) return;
    for(int v = 2; v <= n; v++) {
        if(!marked[v]) {
            x[k] = v;
            marked[v] = 1;
            cur = cur + c[x[k-1]][x[k]];
            if(k == n) {
                if(cur + c[x[n]][x[1]] < ans && (cur + c[x[n]][x[1]]) != 0) {
                    ans = cur + c[x[n]][x[1]];
                }
            }
            else TRY(k+1);
            cur -= c[x[k-1]][x[k]];
            marked[v] = 0;
        }
    }
}

void solve() {
    ans = INT_MAX;
    cur = 0;
    x[1] = 1;
    TRY(2);
    cout << ans;
}

int main() {
    for(int v = 1; v <= n; v++)
        marked[v] = 0;
    input();
    solve();

    return 0;
}
