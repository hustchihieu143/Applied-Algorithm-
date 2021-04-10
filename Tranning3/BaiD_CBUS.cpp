#include <bits/stdc++.h>
using namespace std;

#define MAX 100
int n, k;
int c[MAX][MAX];
int marked[MAX];
int cur;   // luu so khach hien tai
int ans;   // tra ve  ket qua nho nhat
int x[MAX];
int s;     // luu quang duong


void input() {
    cin >> n >> k;
    for(int i = 1; i <= 2*n+1; i++) {
        for(int j = 1; j <= 2*n+1; j++) {
            cin >> c[i][j];
        }
    }
}

void solution() {
    for(int i = 1; i <= 2*n; i++) {
        cout << x[i] << " ";
    }
    cout << endl;
}

bool check(int v) {
    if(marked[v]) return false;  // da den roi
    else {
        if(v <= n) {              // dang don khach
            if(cur >= k) return false;  // so luong khach vuot muc cho phep
        }
        else {
            if(!marked[v-n]) return false;    // den cho tra khach ma ko thay khach dau
        }
    }
    return true;
}

void TRY(int i) {
   for(int v = 2; v <= 2*n; v++) {
        if(check(v)) {
            x[i] = v;
            marked[v] = 1;
            if(v <= n) cur++; else cur--;

            s += c[x[i-1]][x[i]];
            if(i == 2*n) {
                if(s + c[x[i]][x[1]] < ans) {
                    ans = s + c[x[i]][x[1]];
                }

            }
            else TRY(i+1);
            marked[v] = 0;
            if(v <= n) cur--; else cur++;
            s -= c[x[i-1]][x[i]];
        }
   }
}

void solve() {
    ans = 1000;
    s = 0;
    cur = 1;
    for(int i = 1; i <= 2*n; i++) {
        marked[i] = 0;
    }
    marked[1] = 1;
    x[1] = 1;
    TRY(2);
    cout << ans;
}




int main(){
    input();
    solve();
   return 0;
}
