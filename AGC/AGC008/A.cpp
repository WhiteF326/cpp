#include <bits/stdc++.h>
using namespace std;

int fact(int x) { return x <= 1 ? 1 : x * fact(x - 1); }
int sign(int x){
    return (x > 0) -(x < 0);
}
// template <class T> T sign(T x){
//     assert(to_string(x).find_first_not_of("0123456789.") == string::npos);
//     return (x > 0) -(x < 0);
// }

int main() {
    //絶対値の差は< = >のいずれか
    int x, y; cin >> x >> y;
    if(abs(x) - abs(y) == 0){
        //x, yは相異なるので、必ず符号が違う
        cout << 1 << endl;
    }else{
        if(y == 0){
            if(sign(x) == 1)x++;        //雑
            cout << abs(x) << endl;
            return 0;
        }
        int ans = 0;
        //0の処理
        if(x == 0){ans++; x = 1;}
        if(abs(x) < abs(y)){
            //絶対値を上げるので符号を+にする
            ans += x < 0;
            x = abs(x);
            //絶対値を合わせる
            ans += abs(y) - abs(x);
        }else{
            //絶対値を下げるので符号を-にする
            ans += x > 0;
            x = -abs(x);
            //絶対値を合わせる
            ans += abs(x) - abs(y);
        }
        //符号を合わせる
        ans += (sign(x) != sign(y));
        cout << ans << endl;
    }
}