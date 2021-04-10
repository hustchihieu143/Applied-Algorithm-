#include <bits/stdc++.h>
using namespace std;



int typingCount(vector<vector<char>> matrix, string s) {
    int counter = 0;
    for(int z = 0; z < s.size(); z++) {
        if(s[z] == ' ') counter++;
        else {
            for(int i = 0; i < matrix.size(); i++) {
                for(int j = 0; j < matrix[i].size(); j++) {
                    if(s[z] == matrix[i][j]) {
                        counter += (j+1);
                        break;
                    }
                }
            }
        }
    }
    return counter;
}

int main(){
    vector<vector<char>> matrix = { {'a', 'b', 'c'},{'d', 'e', 'f'},
                        {'g', 'h', 'i'}, {'j', 'k', 'l'},
                        {'m', 'n', 'o'}, {'p' ,'q', 'r', 's'},
                        {'t', 'u', 'v'}, {'w', 'x', 'y', 'z'} };
    int n;
    cin >> n;
    cin.ignore(32767, '\n');
    vector<string> s(n);
    for(int i = 0; i < n; i++) {
        getline(cin, s[i]);
    }

    for(int i = 0; i < s.size(); i++) {
        cout << "Case #" << (i+1) << ": " << typingCount(matrix, s[i]) << endl;
    }
   return 0;
}
