#include <bits/stdc++.h>
using namespace std;

const double PI = acos(-1.0);

const int MAX = 1e5 + 10;

int N, F;
int V[MAX];
double ans;

bool check(double val) {
    int sum = 0;
    for(int i = 1; i <= N; i++) {
        sum += floor(V[i]/val);
    }
    return sum > F+1;
}

void solve() {
    int T;
    cin >> T;
    for(int i = 1; i <= T; i++) {
        cin >> N >> F;
        for(int j = 1; j <= N; j++) {
            double p;
            cin >> p;
            V[i] = p*p*PI;
        }

        sort(V+1, V+N+1);
        double L, R;
        L = 0;
        R = V[N];
        while(R-L > 1e-6) {
            double M = (R+L)/2;
            if(check(M)) {
                ans = M;
                L = M;
            }
            else {
                R = M;
            }
        }
        printf("%6lf\n", ans);
    }

}

bool check(int v, int k) {

}

int main(){
    solve();
   return 0;
}
