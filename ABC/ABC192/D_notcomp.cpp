#include <bits/stdc++.h>
using namespace std;

int ctoi(char c) {
	if (c >= '0' && c <= '9') {
		return c - '0';
	}
	return 0;
}

int main(){
  string x; cin >> x; long long m; cin >> m;
  int mx = 0;
  char xc[x.length() + 1]; strcpy(xc, x.c_str());
  vector<int> xv(x.length());
  for(int i = 0; i < x.length(); i++){
    xv[i] = ctoi(xc[i]);
    mx = (long long)max(mx, xv[i]);
  }
  int ans = 0; long long tst; bool cflg = true;
  while(cflg){
    mx++; tst = m;
    //逆にmを基数変換する
    if(ceil(log(m) / log(mx)) > xv.size()){ans++; continue;}
    else if(ceil(log(m) / log(mx)) < xv.size()){break;}
    //桁数が同じときは判定
    vector<int> dx((int)ceil(log(m) / log(mx)));
    for(int i = 0; i < dx.size(); i++){
      dx[dx.size() - i - 1] = tst % mx;
      tst = tst / mx;
    }
    for(int i = 0; i < dx.size(); i++){
      if(xv[i] > dx[i]){cflg = false; break;}
    }
    ans++;
  }
  cout << ans << endl;
}