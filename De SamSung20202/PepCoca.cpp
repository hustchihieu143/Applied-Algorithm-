#include <bits/stdc++.h>
using namespace std;

#define MAX 100000
int n;
vector<int> x = {};
int q;
int m[MAX];
int ans;

void input() {
    cin >> n;
    int a;
    for(int i = 0; i < n; i++) {
        cin >> a;
        x.push_back(a);
    }
    cin >> q;
    for(int i = 0; i < q; i++) {
        cin >> m[i];
    }
}

//void swap(int &a, int &b) {
//    int tmp = a;
//    a = b;
//    b = tmp;
//}
//
//int partition(int arr[], int low, int high) {
//    int i = low - 1;
//    int pivot = arr[high];
//    for(int j = low; j <= high-1; j++) {
//        if(arr[j] < pivot) {
//            i++;
//            swap(arr[i], arr[j]);
//        }
//    }
//    swap(arr[i+1], arr[high]);
//    return i+1;
//}
//
//void quickSort(int arr[], int low, int high) {
//    if(low < high) {
//
//        int pi = partition(arr, low, high);
//
//        quickSort(arr, low, pi-1);
//        quickSort(arr, pi+1, high);
//
//    }
//}


void process() {
    sort(x.begin(), x.end());
    for(int i = 0; i < q; i++) {
        for(int j = 0; j < n; j++) {
            if(m[i] >= x[j]) ans++;
            else break;
        }
        cout << ans << endl;
        ans = 0;
    }
}

void solve() {
    ans = 0;
    //quickSort(x, 0, n-1);
    process();
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    input();
    solve();
   return 0;
}
