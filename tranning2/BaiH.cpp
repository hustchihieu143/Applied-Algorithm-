#include <bits/stdc++.h>
using namespace std;

int n;
bool test(string str) {
    stack<char> s;
    int n;
    char x;

    int length = str.size();
    for(int i = 0; i < length; i++) {
        if(str[i] == '(' || str[i] == '[' || str[i] == '{') {
            s.push(str[i]);
            continue;
        }
        if(s.empty()) return false;
        switch(str[i]) {
            case ')':
                x = s.top();
                s.pop();
                if(x == '[' || x == '{') return false;
                break;

            case ']':
                x = s.top();
                s.pop();
                if(x == '(' || x == '{') return false;
                break;

            case '}':
                x = s.top();
                s.pop();
                if(x == '[' || x == '(') return false;
                break;


        }
    }
    return s.empty();
}


int main(){

    cin >> n;
    cin.ignore(32767, '\n');
    vector<string> str(n);
    for(int i = 0; i < n; i++) {
        getline(cin, str[i]);
    }
    for(int i = 0; i < n; i++) {
        cout << test(str[i]) << endl;
    }

   return 0;
}
