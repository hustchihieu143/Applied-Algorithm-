#include <bits/stdc++.h>
using namespace std;

bool isSubArray(vector<int> a, vector<int> b) {
    int length = b.size();
    bool flag = true;
    for(int i = 0; i < length; i++) {
        if(count(a.begin(), a.end(), b[i]) <= 0) return false;
    }
    return true;
}

int main(){
    int n, m;
    cin >> n ;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> m;
    vector<int> b(m);
    for(int j = 0; j < m; j++) {
        cin >> b[j];
    }
    cout << isSubArray(a, b);

   return 0;
}
