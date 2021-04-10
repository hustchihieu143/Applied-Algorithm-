#include <bits/stdc++.h>
using namespace std;
#define MAX 100

int N;  // so khach
int Q; // so khach cho phep tren bus
int marked[2*MAX+1];
int cur;   // so hanh khach tren xe hien tai
int x[2*MAX+1];

void solution() {
    for(int i = 1; i <= 2*N; i++) {
        cout << x[i] << " ";
    }
    cout << endl;
}

bool check(int v, int k) {
    if(marked[v]) return false;
    else {
        if(v <= N) {   // van dang nhan khach
            if(cur >= Q) return false;    // khong the nhan khach duoc nua
        }
        else {  // dang trong qua trinh tra khach
            if(!marked[v-N]) return false;   // khong ton tai thang khach de tra
        }
    }
    return true;
}

void TRY(int k) {
    for(int v = 1; v <= 2*N; v++) {
        if(check(v, k)) {
            x[k] = v;
            marked[v] = 1;
            if(v <= N) cur++; else cur--;
            if(k == 2*N) solution();
            else TRY(k+1);
            //recover
            if(v <= N) cur--; else cur++;
            marked[v] = false;

        }
    }
}

int main(){
    N = 3; Q = 2;
    cur = 0;
    TRY(1);
   return 0;
}
