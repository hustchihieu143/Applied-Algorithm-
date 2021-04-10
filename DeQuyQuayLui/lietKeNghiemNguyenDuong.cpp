#include <bits/stdc++.h>
using namespace std;

#define MAX 100

int n, M;   // so nghiem va tong gia tri cac nghiem
int x[MAX];
int T;  // accumulated sum

// x1 + x2 +...+ x[k-1] = T;
// => x[k] = M - T - (Xk+1 - Xk+2 +...+ Xn) = M - T - ( n - k )

bool check(int v, int k) {
    if(k < n) return 1;
    return T + v == M;
}
void solution() {
    for(int i = 1; i <= n; i++) {
        cout << x[i];
    }
    cout << endl;
}

void TRY(int k) {
    for(int v = 1; v <= M-T-(n-k); v++) {
        if(check(v, k)) {
            x[k] = v;
            T += x[k];
            if(k == n) solution();
            else TRY(k+1);
            T = T - x[k];
        }
    }
}

int main(){
    n = 3; M = 6;
    T = 0;
    TRY(1);
   return 0;
}
