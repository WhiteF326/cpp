#include <bits/stdc++.h>
using namespace std;

int fact(int x) { return x <= 1 ? 1 : x * fact(x - 1); }

int main(){
    int h, w; cin >> h >> w;
    vector<string> m(h);
    int vect[4][2] = { {-1, 0}, {0, -1}, {0, 1}, {1, 0} };

    if(h == 1 && w == 1){cout << "No" << endl; return 0;}
    for(int i = 0; i < h; i++) cin >> m[i];
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(m[i].substr(j, 1) == ".") continue;
            bool mflg = false;
            for(int k = 0; k < 4; k++){
                if(i + vect[k][0] >= 0 && i + vect[k][0] < h && j + vect[k][1] >= 0 && j + vect[k][1] < w){
                    if(m[i + vect[k][0]].substr(j + vect[k][1], 1) == "#"){mflg = true; break;}
                }
            }
            if(!mflg){
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
}