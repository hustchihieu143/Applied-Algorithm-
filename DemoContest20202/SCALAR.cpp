#include <bits/stdc++.h>
using namespace std;
#define MAX 1005
int test;
int n;
int x[MAX];
int y[MAX];
int ans = INT_MAX;

void solve() {
    cin >> test;
    for(int i = 1; i <= test; i++) {
        cin >> n;
        for(int j = 0; j < n; j++) {
            cin >> x[j];
        }
        for(int j = 0; j < n; j++) {
            cin >> y[j];
        }


        do {
            int cur = 0;
            for(int k = 0; k < n; k++) {
                cur = cur + x[k]*y[k];
            }
            ans = min(ans, cur);

        } while(next_permutation(y, y+n));
        cout << "Case #" << i <<": " << ans << endl;
    }
}



int main(){
    ios::sync_with_stdio(false);
    solve();
   return 0;
}
