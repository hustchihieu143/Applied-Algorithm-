#include<bits/stdc++.h>
using namespace std;

const int MAX = 505;
int m, k;
int a[MAX];
int b[MAX];
int ans[MAX];
long long L, R, M;

bool check(long long max_val){
    memset(b,0, sizeof(b));
    long long cnt = 0;
    long long sum = 0;
    for(int i = m; i >= 1; i--){
        if(sum + a[i] <= max_val && i >= k-cnt) sum += a[i];
        else{
            cnt++;
            sum = a[i];
            b[i] = 1;
        }
    }
    if(cnt == k-1){
        for(int i = 1; i <= m; i++){
            ans[i] = b[i];
        }

        return true;
    }

    return false;
}

void printSolution(){
    for(int i = 1; i <= m; i++){
        if(ans[i] == 1) cout << a[i] << " / ";
        else cout << a[i] << " ";
    }
    cout << endl;
}

void solve(){
    int Test;
    cin >> Test;
    for(int t = 1; t <= Test; t++){
        cin >> m >> k;
        L = 0; R = 0;
        for(int i = 1;i <= m; i++){
            cin >> a[i];
            R += a[i];
            if(a[i] > L) L = a[i];
        }
        memset(ans,0, sizeof(ans));
        while(L <= R){
            M = (R + L)/2;
            if(check(M)){
                R = M-1;
            }else{
                L = M+1;
            }
        }

        printSolution();
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    solve();
    return 0;
}
