#include <bits/stdc++.h>
using namespace std;

//( a + b) % c = ( ( a % c ) + ( b % c ) ) % c
int main(){
    int c = pow(10, 9) + 7;
    long long a, b;
    cin >> a >> b;
    cout << ((a%c) + (b%c)) % c;
   return 0;
}
