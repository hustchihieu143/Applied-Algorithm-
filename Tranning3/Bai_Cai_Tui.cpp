#include <bits/stdc++.h>
using namespace std;

const int MAX = 35;
int n, b;            // số quà và trọng lượng lớn nhất có thể mang theo
int a[MAX], c[MAX];  // lưu trọng lượng và giá trị
int x[MAX];
int curVal, curW;
int ans;
int mark[MAX];

void input() {
    cin >> n >> b;
    for(int i = 1; i <= n; i++) {
        cin >> a[i] >> c[i];
    }
}
bool check(int v) {
    return a[v] + curW <= b;
}

void TRY(int k) {
    for(int v = 1; v <= n; v++) {
        if(check(v)) {
            //x[k] = v;
            mark[v] = 1;
            //update
            curVal += c[v];
            curW += a[v];
            if(curVal > ans) ans = curVal;
            TRY(k+1);

            // recover
            curVal -= c[v];
            curW -= a[v];
            mark[v] = 0;
        }
    }
}

void solve() {
    curVal = 0; curW = 0;
    ans = 0;
    x[0] = 0;
    for(int i = 1; i <= n; i++) {
       mark[i] = 0;
    }
    TRY(1);
    cout << ans;

}

int main(){
    input();

    solve();

   return 0;
}
