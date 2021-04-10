#include <bits/stdc++.h>
using namespace std;

void addTwoNumber(unsigned long long a, unsigned long long b) {  // Thuật toán xử lý với công số lớn.
    unsigned long long a1 = a/10;
    unsigned long long a0 = a%10;
    unsigned long long b1 = b/10;
    unsigned long long b0 = b%10;
    unsigned long long c0 = (a0 + b0)%10;
    unsigned long long c1 = (a0 + b0)/10;
    c1 = a1 + b1 + c1;
    if(c1 > 0) cout << c1;
    cout << c0;
}

int main(){
    unsigned long long a, b;
    cin >> a >> b;
    addTwoNumber(a, b);
   return 0;
}
