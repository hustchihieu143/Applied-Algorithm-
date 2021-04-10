#include <bits/stdc++.h>
using namespace std;
#define MAX 100
int n;
int marked[MAX];
int x[MAX];

bool check(int v, int k) {
    return marked[v] == 0;
}

void solution() {
    for(int i = 1; i <= n; i++) {
        cout << x[i];
    }
    cout << endl;
}

void TRY(int k) {
    for(int v = 1; v <= n; v++) {
        if(check(v, k)) {
            x[k] = v;
            marked[v] = 1;
            if(k == n) solution();
            else TRY(k+1);
            marked[v] = 0;
        }
    }
}

int main(){
    n = 4;
    TRY(1);

   return 0;
}
