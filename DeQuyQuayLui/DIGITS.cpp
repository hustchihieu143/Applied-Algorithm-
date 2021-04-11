#include <bits/stdc++.h>
using namespace std;

int x[9];  // x[1]=I, x[2]=C, x[3]=T, x[4]=H, x[5]=U, x[6]=S, x[7]=k;
int N;
int ans;
int marked[10];

void solution() {
    int T = x[1]*100 + x[2]*10 + x[3] - x[7]*100 - 62 + x[4]*1000 + x[5]*100 + x[6]*10 + x[3];
    if(T == N) {
        ans++;
    }
}
void init() {
    for(int i = 1; i <= 9; i++) {
        marked[i] = 0;
    }
}

void TRY(int k) {
    for(int v = 1; v <= 9; v++) {
        if(!marked[v]) {
            x[k] = v;
            marked[v] = 1;
            if(k == 7) solution();
            else TRY(k+1);
            marked[v] = 0;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    init();
    ans = 0;
    cin >> N;
    TRY(1);
    cout << ans;
   return 0;
}
