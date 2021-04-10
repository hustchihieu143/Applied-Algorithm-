#include <bits/stdc++.h>
using namespace std;


int findSumMaxChildSequence(vector<int> arr) {
    int best = INT_MIN;
    int n = arr.size();
    vector<int> s(n);
    s[0] = arr[0];
    for(int i = 1; i < n; i++) {
        if(s[i-1] > 0) s[i] = s[i-1] + arr[i];
        else s[i] = arr[i];
        best = max(s[i], best);
    }
    return best;
}

int main(){

    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << findSumMaxChildSequence(arr);
   return 0;
}
