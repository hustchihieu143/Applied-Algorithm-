#include <bits/stdc++.h>
using namespace std;

int ans = 0;
int a, b, c;
int binhA = 0, binhB = 0;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

void L1(int &binhA, int &binhB) {   // Nếu bình A đầy thì đổ hết nước trong bình A đi
    binhA = 0;
}

void L2(int &binhA, int &binhB) {   // Nếu bình B rỗng thì đổ đầy nước vào bình B
    binhB = b;
}
void L3(int &binhA, int &binhB) {   // Nếu bình A không đầy và bình B không rỗng thì đổ hết ? nước từ bình B vào bình A đến khi bình A đầy hoặc bình B hết nước.
    int binhAConThieu = a - binhA;
    if(binhB >= binhAConThieu) {
        binhA = binhA + binhAConThieu;
        binhB = binhB - binhAConThieu;
    }
    else {
        binhA = binhA + binhB;
        binhB = 0;
    }
}

int waterJug(int a, int b, int c) {
    if(c % gcd(a, b) != 0) return -1;
    else {
        while(binhA != c && binhB != c) {
            if(binhA == a) {
                L1(binhA, binhB);
                ans++;
            }
            if(binhB == 0) {
                L2(binhA, binhB);
                ans++;
            }
            if(binhA < a && binhB > 0) {
                L3(binhA, binhB);
                ans++;
            }
        }
        return ans;
    }
}
int main(){
    cin >> a >> b >> c;
    b = max(a, b);
    a = min(a, b);
    cout << waterJug(a, b, c);
   return 0;
}
