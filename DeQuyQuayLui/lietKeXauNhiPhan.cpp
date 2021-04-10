#include <bits/stdc++.h>
using namespace std;

#define MAX 1000
int n;
int x[MAX];

void solution() {
    for(int i = 1; i <= n; i++) {
        cout << x[i];
    }
    cout << endl;
}

void TRY(int k) {
    for(int v = 0; v <= 1; v++) {
        x[k] = v;
        if(k == n) solution();
        else TRY(k+1);
    }
}
int main(){
    cin >> n;
    TRY(1);
   return 0;
}
