#include <bits/stdc++.h>
using namespace std;
int n;
int ans;
vector<string> s = {};

void input() {
    cin >> n;
    string str;
    for(int i = 0; i < n; i++) {
        cin >> str;
        s.push_back(str);
    }
}

void process() {

    for(int i = 0; i < n; i++) {
        if(s[i] == "X++" || s[i] == "++X") ans++;
        else ans--;
    }
    cout << ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ans = 0;
    input();
    process();
   return 0;
}
