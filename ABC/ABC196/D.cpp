#include <bits/stdc++.h>
using namespace std;
 
#define fs(n) fixed << setprecision(n)
using ll = long long;

ll fact(ll x) { return x <= 1 ? 1 : x * fact(x - 1); }

//再帰処理で時間を食い過ぎるので階乗をメモ化する
map<ll, ll> factMemo;
ll memo_fact(ll x){
  if(factMemo[x] != 0) return factMemo[x];
  else return x <= 1 ? 1 : x * fact(x - 1);
}

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

ll permu(ll m, ll c){
  ll ans = 1;
  for(ll i = c; i <= m; i++){
    ans *= i;
  }
  return ans;
}

ll combi(ll m, ll c){
  ll mf = memo_fact(c);
  factMemo[c] = mf;
  return (permu(m, c) / mf);
}

ll choose_two(ll m){
  return m * (m + 1) / 2;
}

int h, w, a, b;
vector<vector<bool>> stage(16, vector<bool>(16, false));

int body(int ad, int bd, int px, int py){

  if(ad < 0 || bd < 0) return 0;
  if(px == w) px = 0, py += 1;
  if(py == h) return 1;

  if(stage[py][px]) return body(ad, bd, px + 1, py);

  int res = 0;
  stage[py][px] = true;
  // 半畳
  res += body(ad, bd - 1, px + 1, py);
  // 縦に
  if(py < h - 1 && !stage[py + 1][px]){
    stage[py + 1][px] = true;
    res += body(ad - 1, bd, px + 1, py);
    stage[py + 1][px] = false;
  }
  // 横に
  if(px < w - 1 && !stage[py][px + 1]){
    stage[py][px + 1] = true;
    res += body(ad - 1, bd, px + 1, py);
    stage[py][px + 1] = false;
  }
  stage[py][px] = false;
  return res;
}

int main(){

  cin >> h >> w >> a >> b; 
  // 使用しているマスについて接続を区別する必要はない

  cout << body(a, b, 0, 0) << endl;
}