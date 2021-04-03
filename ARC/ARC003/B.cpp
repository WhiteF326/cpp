#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int n; cin >> n;
    vector<string> t(n);
    for(int i = 0; i < n; i++){
        cin >> t[i];
        reverse(t[i].begin(), t[i].end());
    }
    sort(t.begin(), t.end());
    for(int i = 0; i < n; i++){
        reverse(t[i].begin(), t[i].end());
        cout << t[i] << endl;
    }
}