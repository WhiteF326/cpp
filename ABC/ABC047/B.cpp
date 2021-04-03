#include <bits/stdc++.h>
using namespace std;

int fact(int x) { return x <= 1 ? 1 : x * fact(x - 1); }

int main(){
    int w, h; cin >> w >> h;
    int n; cin >> n;
    vector<vector<bool>> cells(w, vector<bool>(h, false));
    for(int i = 0; i < n; i++){
        int x, y, a; cin >> x >> y >> a;
        switch(a){
        case 1:
            for(int j = 0; j < x; j++){
                for(int k = 0; k < h; k++){
                    cells[j][k] = true;
                }
            }
            break;
        case 2:
            for(int j = x; j < w; j++){
                for(int k = 0; k < h; k++){
                    cells[j][k] = true;
                }
            }
            break;
        case 3:
            for(int j = 0; j < w; j++){
                for(int k = 0; k < y; k++){
                    cells[j][k] = true;
                }
            }
            break;
        case 4:
            for(int j = 0; j < w; j++){
                for(int k = y; k < h; k++){
                    cells[j][k] = true;
                }
            }
            break;
        }
    }
    int ans = 0;
    for(int i = 0; i < w; i++){
        for(int j = 0; j < h; j++){
            ans += !cells[i][j];
        }
    }
    cout << ans << endl;
}