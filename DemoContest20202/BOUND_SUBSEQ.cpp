#include <bits/stdc++.h>
using namespace std;

#define MAX 20005
int n, m, M;
int a[MAX];
int ans;

void input() {
    cin >> n >> m >> M;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
}

void solve() {
    for(int i = 0; i < n; i++) {
        int cur = 0;
        for(int j = i; j < n; j++) {
            cur += a[j];
            if(cur >= m && cur <= M) {
                ans++;
//                cout << "cur: " << cur << endl;
            }
        }
    }
    cout << ans;
}



int main(){
    ios::sync_with_stdio(false);
    input();
    solve();
   return 0;
}
