#include <bits/stdc++.h>
using namespace std;

int fact(int x) { return x <= 1 ? 1 : x * fact(x - 1); }

int main(){
    //10^18の5乗根が3981程度なので全列挙で可能
    int x; cin >> x;
    const int absm = 3982;
    long long fifths[absm * 2 + 1];
    for(int i = -absm; i <= absm; i++){
        fifths[i + absm] = pow(i, 5);
    }
    for(int i = -absm; i <= absm; i++){
        for(int j = -absm; j <= absm; j++){
            if(fifths[i + absm] - fifths[j + absm] == x){
                cout << i << " " << j << endl;
                return 0;
            }
        }
    }
}
