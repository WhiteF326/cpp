#include <bits/stdc++.h>
using namespace std;
 
#define fs(n) fixed << setprecision(n)
using ll = long long;

int fact(int x) { return x <= 1 ? 1 : x * fact(x - 1); }

int sign(int x){
  return (x > 0) - (x < 0);
}

bool isLeapYear(int y, int m){
  return (y % 400 == 0 || (y % 4 == 0 && y % 100)) && m == 2;
}
 
vector<int> AllDivs(int d){
	vector<int> resDivs(0);
	for(int i = 1; i < (int)sqrt(d); i++){
		if(d % i == 0){
			resDivs.push_back(i);
			resDivs.push_back(d / i);
		}
	}
	sort(resDivs.begin(), resDivs.end());
	return resDivs;
}
 
bool IsPrime(int num){
	bool ans = true;
	if(num < 2) return false;
	else if (num == 2) return true;
	else{
		for(int i = 2; i <= (int)sqrt(num); i++){
			if(num % i == 0){
					ans = false;
			}
		}
	}
	return ans;
}
 
int NextPrime(int d){
	int ans = d;
	while(true){
		ans++;
		if(IsPrime(ans)) break;
	}
	return ans;
}
 
vector<int> Dec2Bin(int x, int len){
	vector<int> res(len, 0);
	int d = 1, pt = len - 1;
	while(d <= x){
		res[pt] = (x & d ? 1 : 0);
		d *= 2; pt--;
	}
	return res;
}
 
int avg(int a, int b){
  return (a + b) / 2;
}

int main(){
  int h, w; cin >> h >> w;
  int n; cin >> n;
  vector<int> a(n);
  for(int i = 0; i < n; i++) cin >> a[i];
  vector<vector<int>> ans(h, vector<int>(w));
  int xv = 1, colorP = 0, x = 0, y = 0;
  for(int i = 0; i < h * w; i++){
    ans[x][y] = colorP + 1;
    a[colorP]--;
    if(a[colorP] == 0) colorP++;
    x += xv;
    if(x >= h){x--; xv = -1; y++;}
    if(x < 0){x++; xv = 1; y++;}
  }
  for(int i = 0; i < h; i++){
    for(int j = 0; j < w; j++){
      cout << ans[i][j];
      if(j != w - 1) cout << " ";
    }
    cout << endl;
  }
}