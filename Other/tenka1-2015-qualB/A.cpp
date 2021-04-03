#include <bits/stdc++.h>
using namespace std;

int fact(int x) { return x <= 1 ? 1 : x * fact(x - 1); }

int main() {
    vector<int> sc(20);
    sc[0] = 100; sc[1] = 100; sc[2] = 200;
    for(int i = 3; i < 20; i++){
        for(int j = 1; j <= 3; j++){
            sc[i] += sc[i - j];
        }
    }
    cout << sc[19] << endl;
}