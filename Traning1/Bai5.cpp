#include <bits/stdc++.h>
using namespace std;

#define M 1000000007
int n;

int subseq(int a, int b) {
    return ( (a%M) + (b%M) ) % M;
}
int main(){
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];


    int ans = 0;
    for(int i = 0; i < n; i++) {
        ans = subseq(ans, a[i]);
    }
    cout << ans;

   return 0;
}
