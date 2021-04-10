#include <bits/stdc++.h>
using namespace std;
#define MAX 30

int di[8] = {1, 1, 2, 2, -1, -1, -2, -2};
int dj[8] = {2, -2, 1, -1, 2, -2, 1, -1}; // tinh tien cac nuoc di

int marked[MAX][MAX];
int N, i, j;
int Xi[MAX], Xj[MAX];

void solution() {
    for(int k = 1; k <= 25; k++) {
        cout << "(" << Xi[k] << "," << Xj[k] << ")";
    }
    cout << endl;
}

bool check(int r, int c) {
    if(r < 1 || r > N) return false;
    if(c < 1 || c > N) return false;
    return !marked[r][c];
}

void TRY(int k) {
    for(int v = 0; v < 8; v++) {
        if(check(Xi[k-1]+di[v], Xj[k-1]+dj[v])) {
            Xi[k] = Xi[k-1]+di[v];
            Xj[k] = Xj[k-1]+dj[v];
            marked[Xi[k]][Xj[k]] = 1; // update
            if(k == N*N) solution();
            else TRY(k+1);
            marked[Xi[k]][Xj[k]] = 0;  // recover
        }
    }
}


int main(){
    cin >> N >> i >> j;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            marked[i][j] = 0;
        }
    }
    Xi[1] = i; Xj[1] = j;
    marked[i][j] = 1;
    TRY(2);

   return 0;
}
