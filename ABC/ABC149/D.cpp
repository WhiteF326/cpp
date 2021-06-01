#include <bits/stdc++.h>
using namespace std;

int fact(int x) { return x <= 1 ? 1 : x * fact(x - 1); }

int main(){
    //stone r, scissors s, paper p
    int n, k; cin >> n >> k;
    vector<int> points(3);
    for(int i = 0; i < 3; i++) cin >> points[i];
    string t; cin >> t;
    unordered_map<string, int> towin;
    towin["r"] = 2;
    towin["s"] = 0;
    towin["p"] = 1;
    vector<vector<int>> select(n, vector<int>(3, 1));
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(select[i][towin[t.substr(i, 1)]] == 1){
            ans += points[towin[t.substr(i, 1)]];
            if(i + k < n){
                select[i + k][towin[t.substr(i, 1)]] = 0;
            }
        }
    }
    cout << ans << endl;
}