#include <bits/stdc++.h>
using namespace std;

int fact(int x) { return x <= 1 ? 1 : x * fact(x - 1); }

int main(){
    int n; cin >> n;
    vector<int> a(n);
    int lavg = 0, gavg = 0;;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        lavg += a[i];
        gavg += a[i];
    }
    lavg = (int)floor(lavg / (double)n);
    gavg = (int)ceil(gavg / (double)n);
    int mcost = INT_MAX;
    for(int i = lavg; i <= gavg; i++){
        int tcost = 0;
        for(int j = 0; j < n; j++){
            tcost += (i - a[j]) * (i - a[j]);
        }
        mcost = min(mcost, tcost);
    }
    cout << mcost << endl;
}