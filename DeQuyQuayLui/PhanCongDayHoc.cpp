#include <bits/stdc++.h>
using namespace std;
#define MAX_N 100
#define MAX_M 30

int N;   // so mon hoc
int M;   // so giao vien
int sz[MAX_N];   // sz[c] so giao vien co the day mon hoc thu i
int t[MAX_N][MAX_M];   //  t[c][i] giao vien thu i day mon hoc c
int h[MAX_N];    // so gio hoc trong 1 tuan cua mon hoc
int A[MAX_N][MAX_N];   // A[i][j]=1 la xung dot giua 2 mon hoc i va j
int f[MAX_M];
int cnt;
int X[MAX_N];

void input() {
    cin >> N >> M;
    for(int i = 1; i <= N; i++) {
        cin >> h[i];
    }
    for(int i = 1; i <= N; i++) {
        cin >> sz[i];
        for(int j = 0; j < sz[i]; j++) {
            cin >> t[i][j];
        }
    }
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++)
            cin >> A[i][j];
    }
}

int check(int v, int k) {
    for(int i = 1; i <= k-1; i++) {
        if(A[i][k] && v == X[i]) return 0;
    }
    return 1;
}

void solution(){
    cnt++;
    cout << "solution " << cnt << endl;
    for(int t = 1; t <= M; t++){
        cout << "course of teacher " << t << ": ";
        for(int i = 1; i <= N; i++) if(X[i] == t) cout << i << ", ";
            cout << " hour = " << f[t] << endl;
    }
    cout << "--------------------" << endl;
}

void TRY(int k) {
    for(int i = 0; i < sz[k]; i++) {  //  duyet so luong giao vien co the day cua 1 mon hoc
        int v = t[k][i];
        if(check(v, k)) {
            X[k] = v;
            f[v] += h[k];
            if(k == N) {
                solution();
            }
            else {
                TRY(k+1);
            }
            f[v] -= h[k];
        }
    }
}

void solve(){
    for(int i = 1; i <= M; i++) f[i] = 0;
    cnt = 0;
    TRY(1);
}
int main(){
    input();
    solve();
    return 0;
}
