#include <bits/stdc++.h>
using namespace std;

void textCollapse(vector<string> arr) {
    string text = "";
    for(int i = 0; i < arr.size(); i++) {
        if(arr[i].size() > 10) {
            text = arr[i][0] + to_string(arr[i].size() - 2) + arr[i][arr[i].size() - 1];
        }
        else text = arr[i];
        cout << text << endl;
    }
}

int main(){
    int n;
    cin >> n;
    vector<string> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    textCollapse(arr);
   return 0;
}
