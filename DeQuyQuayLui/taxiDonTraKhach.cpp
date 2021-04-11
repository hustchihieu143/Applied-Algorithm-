#include <bits/stdc++.h>
#define MAX 100
using namespace std;
int N;
int X[MAX];// permutation 1,2,...,N
int appear[MAX];// appear[v] = 1 indicates that v has appeared
int c[MAX][MAX];
int cur;
int ans;
int s[MAX];

void input() {
    cin >> N;
    for(int i = 0; i < 2*N+1; i++) {
        for(int j = 0; j < 2*N+1; j++) {
            cin >> c[i][j];
        }
    }
}

void solution(){
    for(int i = 1; i <= N; i++)
        cout << X[i] << " " << X[i] + N << " ";
    cout << endl;
}
bool check(int v, int k){
    return appear[v] == 0;
}
void TRY(int k){// thu gia tri cho X[k]
    for(int v = 1; v <= N; v++){
        if(check(v,k)){
            X[k] = v;
            //cout << "X" << "[" << k << "]: " << X[k] << endl;
            appear[v] = 1;// update
            s[k] = X[k] + N;
            if(X[k-1] == 0) {
                cur = cur + c[X[0]][X[k]] + c[X[k]][s[k]];
            }
            else {
                cur = cur + c[s[k-1]][X[k]] + c[X[k]][s[k]];
            }
            if(k == N) {
                //solution();
                if(cur + c[s[k]][X[0]] < ans) ans = cur + c[s[k]][X[0]];
                //cout << "ans: " << ans << endl;
            }
            else TRY(k+1);
            appear[v] = 0;// recover
            if(X[k-1] == 0) {
                cur = cur - c[X[0]][X[k]] - c[X[k]][s[k]];
            }
            else {
                cur = cur - c[s[k-1]][X[k]] - c[X[k]][s[k]];
            }
        }
    }
}
int main(){
    cur = 0;
    ans = 1000;
    input();
    //N = 2;
    for(int v = 1; v <= N; v++) appear[v] = 0;
    // appear[1] = 1;
    X[0] = 0;
    TRY(1);
    cout << ans;
    return 0;
}
