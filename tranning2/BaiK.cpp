#include <bits/stdc++.h>
using namespace std;

//push các giá trị vào mảng. push_front();
//tạo 1 hàm findMin để tìm phần tử có giá trị thấp nhất trong mảng.
//Duyệt hàm từ bên phải sang bên trái
//Nếu a[i] <= a[i+1] => ok => -1
//Nếu a[i] > a[i+1] => push khoảng cách từ vị trí i đến vị trí của phần tử findMIn
//vừa tìm được.
int n;
int findMin(vector<int> v) {
    int minBest = INT_MAX;
    int ans = -1;
    for(int i = 0; i < n; i++) {
        if(v[i] < minBest) {
            minBest = v[i];
            ans = i;
        }
    }
    return ans;
}
void process(vector<int> v) {
    vector<int> ans(n);
    for(int i = n-1; i >= 0; i--) {
        if(i == n-1) ans[i] = -1;
        else {
            if(v[i] <= v[i+1]) ans[i] = -1;
            else {
                ans[i] = abs(i - findMin(v)) - 1;
            }
        }
    }
    for(int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
}

int main(){
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    process(v);
   return 0;
}
