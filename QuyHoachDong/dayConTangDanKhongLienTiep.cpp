#include <bits/stdc++.h>
using namespace std;
#define MAX 100

int n;
int a[MAX];
int s[MAX];
int ans;

void input() {
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
}
int process(int a[]) {
    s[1] = 1;
    ans = s[1];
    for(int i = 2; i <= n; i++) {
        s[i] = 1;
        for(int j = 1; j <= i-1; j++) {
            if(a[j] < a[i]) {
                if(s[i] < s[j] + 1) {
                    s[i] = s[j] + 1;
                }
            }
        }
        if(s[i] > ans) ans = s[i];
    }
    return ans;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    input();
    cout << process(a);
   return 0;
}
