#include <bits/stdc++.h>
using namespace std;
#define MAX 100
int n;
int x[MAX];
int value;

void input() {
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> x[i];
}

int binarySearch(int l, int r, int value) {
    int m = (r+l)/2;
    if(value < x[m]) return binarySearch(l, m-1, value);
    if(value > x[m]) return binarySearch(m+1, r, value);
    if(value == x[m]) return m;
}

void solve() {
    value = 4;
    cout << binarySearch(1, n, value);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    input();
    solve();

   return 0;
}
