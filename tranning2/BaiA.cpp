#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> matrix = {};

int findMin(vector<int> arr) {
    int n = arr.size();
    int ans = INT_MAX;
    for(int i = 0; i < n; i++) {
        ans = min(ans, arr[i]);
    }
    return ans;
}

void input(int n) {
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    matrix.push_back(arr);
}

int maxRectangle(vector<int> a) {
    int n = a.size();
    int maxRec = INT_MIN;
    vector<int> v = {};
    for(int i = 0; i < n; i++) {
        if(i-1 < 0) {
            if(a[i+1] == findMin(a)) {
                v.push_back(i);
            }
        }
        if(i+1 == n-1) {
            if(a[i-1] == findMin(a)) {
                v.push_back(i);
            }
        }
        if(i-1 >= 0 && i+1 < n-1) {
            if(a[i+1] == findMin(a) || a[i-1] == findMin(a)) {
                v.push_back(i);
            }
        }
    }
    int ans = 0;
    int length = v.size();
    for(int i = 0; i < length - 1; i++) {
        if(v[i] != v[i+1] - 1) {
            ans = max(ans, a[v[i]]);
        }
        else {
            ans = max(ans, 2*min(a[v[i]], a[v[i+1]]));
        }
        maxRec = max(ans, maxRec);
    }
    maxRec = max(maxRec, a[v[length - 1]]);
    return maxRec;
}


int main(){
    int option;
    do {
        cin >> option;
        input(option);
    } while(option != 0);
    for(int i = 0; i < matrix.size(); i++) {
        cout << maxRectangle(matrix[i]) << endl;
    }
   return 0;
}
