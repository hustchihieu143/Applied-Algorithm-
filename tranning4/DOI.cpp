#include <bits/stdc++.h>
using namespace std;
#define MAX 100005
int n;
int a[MAX];
int doCao = 0;
int doSau = 0;
int ansDoi = INT_MIN;
int ansThungLung = INT_MIN;

void input() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
}

void process() {
    for(int i = 1; i <= n-2; i++) {
        bool isDoi = false;
        bool isThungLung = false;
        if(a[i] == a[i+1]) continue;

        int iThungLung = 0, jThungLung = 0, kThungLung = 0;
        int iDoi = 0, jDoi = 0, kDoi = 0;
        int startDoi = 0, endDoi = 0;
        int startThungLung = 0, endThungLung = 0;

        if(a[i] < a[i+1]) isDoi = true;
        if(a[i] > a[i+1]) isThungLung = true;

        if(isDoi) {
            for(int j = i; j <= n-1; j++) {
                if(a[j] < a[j+1]) {
                    if(startDoi == 0) {
                        iDoi = j;
                        startDoi++;
                    }
                }
                if(a[j] > a[j+1]) {
                    if(endDoi == 0) {
                        jDoi = j;
                        endDoi++;
                    }
                    kDoi = j+1;
                }
            }
            doCao = min(jDoi-iDoi, kDoi-jDoi);
        }

        if(isThungLung) {
            for(int j = i; j <= n-1; j++) {
                if(a[j] > a[j+1]) {
                    if(startThungLung == 0) {
                        iThungLung = j;
                        startThungLung++;
                    }
                }
                if(a[j] < a[j+1]) {
                    if(endThungLung == 0) {
                        jThungLung = j;
                        endThungLung++;
                    }
                    kThungLung = j+1;
                }
            }
            doSau = min(jThungLung-iThungLung, kThungLung-jThungLung);
        }

        ansDoi = max(ansDoi, doCao);
        ansThungLung = max(ansThungLung, doSau);
    }

    cout << ansDoi << " " << ansThungLung;
}

int main(){
    input();
    process();
   return 0;
}
