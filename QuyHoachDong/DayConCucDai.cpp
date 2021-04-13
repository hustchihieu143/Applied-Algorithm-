#include <bits/stdc++.h>
using namespace std;
#define MAX 100

int n;
int a[MAX];
int S[MAX];
int ans;

void input() {
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
}

int findMax(int index) {
    if(S[index-1] > 0) return S[index-1] + a[index];
    return a[index];
}

int process() {
    S[1] = a[1];
    for(int i = 2; i <= n; i++) {
        S[i] = findMax(i);
        ans = max(ans, S[i]);
    }
    return ans;
}

void solve() {
    ans = INT_MIN;
    cout << process();
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    input();
    solve();
   return 0;
}
