#include <bits/stdc++.h>
using namespace std;
#define M 200000
int n, b;
int a[M];
int maxPrefix[M];
int maxSuffix[M];
int ans = 0;

int signal(int n) {

    if(n < 3) return -1;

    maxPrefix[0] = a[0];
    maxSuffix[0] = a[n-1];
    for(int i = 1; i < n; i++) {
        maxPrefix[i] = max(a[i], maxPrefix[i-1]);
    }
    for(int i = n-2; i >= 0; i--) {
        maxSuffix[i] = max(a[i], maxSuffix[i+1]);
    }
    for(int i = 1; i < n-1; i++) {
        if(maxPrefix[i-1] - a[i] >= b && maxSuffix[i+1] - a[i] >= b) {
            ans = max(ans, maxPrefix[i-1] - a[i] + maxSuffix[i+1] - a[i]);
        }
    }
    return ans;
}

int main(){
    cin >> n >> b;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << signal(n);
   return 0;
}
