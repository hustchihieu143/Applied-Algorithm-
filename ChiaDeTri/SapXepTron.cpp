#include <bits/stdc++.h>
using namespace std;

#define MAX 100

int n;
int a[MAX];
int ta[MAX];

void input() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
}

void print(){
    for(int i = 1; i <= n; i++) cout << a[i] << " ";
}

void merge(int l, int m, int r) {
    int i = l;
    int j = m+1;
    for(int k = l; k <= r; k++) {
        if(i > m) {
            ta[k] = a[j];
            j++;
        }
        else if(j > r) {
            ta[k] = a[i];
            i++;
        }
        else {
            if(a[i] < a[j]) {
                ta[k] = a[i];
                i++;
            }
            else{
                ta[k] = a[j];
                j++;
            }
        }
    }
    for(int k = l; k <= r; k++) {
        a[k] = ta[k];
    }
}

void mergeSort(int l, int r) {
    if(l == r) return;
    int m = (l+r)/2;
    mergeSort(l, m);
    mergeSort(m+1, r);
    merge(l, m, r);
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    input();
    mergeSort(1,n);
    print();
    return 0;
}
