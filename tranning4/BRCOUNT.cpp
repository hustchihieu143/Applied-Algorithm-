#include <bits/stdc++.h>
using namespace std;
string s;
string result;
int ans;
int cnt = 0;

bool isRight(string s) {
    stack<char> st;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '(') st.push(s[i]);
        else {
            if(s[i] == ')' && !st.empty() && st.top() == '(') st.pop();
            else return false;
        }
    }
    if(!st.empty()) return false;
    return true;
}

int demNgoac(string s) {
    int cnt = 0;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '?') cnt++;
    }
    return cnt;
}

void TRY(int k) {
    if(s[k] == '?') {
        for(int i = 0; i <= 1; i++) {
            if(i == 0) s[k] = '(';
            else s[k] = ')';
            cnt++;

            if(cnt == demNgoac(result)) {
                if(isRight(s)) {
                    ans++;
                }
            }
            else {
                TRY(k+1);
            }
            cnt--;
            s[k] = '?';
        }
    }
    else TRY(k+1);
}

int main(){
    cin >> s;
    result = s;
    TRY(0);
    cout << ans;
   return 0;
}
