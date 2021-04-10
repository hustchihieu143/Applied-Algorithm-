#include <bits/stdc++.h>
using namespace std;

#define MAX 1000
int n, k;
int c[MAX][MAX];
int marked[MAX];
int cur;   // luu tong do dai cac doan duong da di
int ans;   // tra ve  ket qua nho nhat
int x[MAX];

void input() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> c[i][j];
        }
    }
}

void TRY(int k) {
    for(int v = 1; v < n; v++) {
        if(!marked[v]) {
            x[k] = v;
            cur += c[x[k-1]][x[k]];
            marked[k] = 1;
            if(k == n-1) {
                if(cur + c[x[n-1]][x[0]] < ans) {
                    ans = cur + c[x[n-1]][x[0]];
                }
            }
            else TRY(k+1);
            cur -= c[x[k-1]][x[k]];
            marked[k] = 0;
        }
    }
}

void solve() {
    ans = 1000;
    cur = 0;
    for(int i = 0; i < n; i++) {
        marked[i] = 0;
    }
    TRY(1);
    cout << ans;
}




int main(){

    input();
    solve();
   return 0;
}
