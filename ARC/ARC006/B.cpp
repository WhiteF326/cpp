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
  int n, l; cin >> n >> l;
  vector<string> amida(l);
  for(int i = 0; i < l; i++){
    getline(cin, amida[i]);
  }
  for(int i = 0; i < l; i++){
    cout << amida[i] << endl;
  }
  string y;
  getline(cin, y);
  //y文字列を〇の位置数字へコンバート
  int yPos;
  for(int i = 0; i < y.length(); i++){
    if(y.substr(i, 1) == "o"){
      yPos = i / 2; break;
    }
  }
  vector<vector<int>> amiVal(l, vector<int>(n, 0));
  //左に横線は-1, 右に横線は1と保持する
  for(int i = 0; i < l; i++){
    for(int j = 0; j < n; j++){
      if(j != 0){
        if(amida[i].substr(2 * j - 1, 1) == "-"){
          amiVal[i][j] = -1;
        }
      }
      if(j != n - 1){
        if(amida[i].substr(2 * j + 1, 1) == "-"){
          amiVal[i][j] = 1;
        }
      }
    }
  }
  //当然ながら逆から見る
  for(int depth = l - 1; depth >= 0; depth--){
    yPos += amiVal[depth][yPos];
  }
  cout << yPos << endl;
}