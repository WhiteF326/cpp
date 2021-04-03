#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<vector<int>> stage(9, vector<int>(9));
    for(int i = 0; i < 81; i++) cin >> stage[i / 9][i % 9];
    vector<vector<vector<int>>> usable(9, vector<vector<int>>(9, {1, 2, 3, 4, 5, 6, 7, 8, 9}));
    for(int x = 0; x < 9; x++){
        for(int y = 0; y < 9; y++){
            //xが同じ、yが同じ、3x3マス内の全てで除外
            
        }
    }
}
// abc168d double dots
    // 無向グラフを辿って1→1以外の全部屋にたどり着くルートの最短を求める