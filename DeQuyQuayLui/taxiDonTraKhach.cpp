#include <bits/stdc++.h>
#define MAX 100
using namespace std;
int N;
int X[MAX];// permutation 1,2,...,N
int appear[MAX];// appear[v] = 1 indicates that v has appeared
void solution(){
for(int i = 1; i <= N; i++)
cout << X[i] << " " << X[i] + N << " ";
cout << endl;
}
bool check(int v, int k){
return appear[v] == 0;
}
void TRY(int k){// thu gia tri cho X[k]
for(int v = 1; v <= N; v++){
if(check(v,k)){
X[k] = v;
appear[v] = 1;// update
if(k == N) solution();
else TRY(k+1);
appear[v] = 0;// recover
}
}
}
int main(){
N = 3;
for(int v = 1; v <= N; v++) appear[v] = 0;
TRY(1);
}
