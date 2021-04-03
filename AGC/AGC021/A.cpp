#include <bits/stdc++.h>
using namespace std;

int main(){
  //input
  long long s; cin >> s; long long t = 0;
  int l = (long long)ceil(log10(s + 1));
  //現在の合計を取得する
  for(int i = 0; i < l; i++){
    t += stoi(to_string(s).substr(i, 1));
  }
  //先頭が9でないとき、先頭を-1しそれ以外を9で埋める
  long long ans = 0;
  if((s % (long long)pow(10, l - 1)) != 9){
    ans = ((l - 1) * 9) + (s / (long long)pow(10, l - 1)) - 1;
  }else{
  //先頭が9でかつ以降の桁に9未満の数があるとき、前の桁を-1しその桁以降を9にする
    bool nflg = false;
    for(int i = 0; i < l; i++){
      if(nflg || (s % (long long)pow(10, i)) / 10 == 9){
        ans += 9;
      }else{
        ans += (s % (long long)pow(10, i)) / 10 - 1;
        nflg = true;
      }
    }
  }
  ans = (long long)max(ans, t);				//(任意)+9999……
  cout << ans << endl;
}