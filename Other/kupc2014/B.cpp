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


int main(){
  vector<bool> cnd(1000, true);
  int nPrime = 1;
  for(int i = 0; i <= 200; i++){
    nPrime = NextPrime(nPrime);
    //エラトステネスの篩で答えきれない
    if(nPrime > 1000){
      break;
    }
    cout << "? " << nPrime << endl;
    string res; cin >> res;
    // Yが帰って来たら
    if(res == "Y"){
      //nPrimeが1009以上ならば! nPrimeで解
      if(nPrime >= 1009){
        cout << "! " << nPrime << endl;
        return 0;
      }else{
        // 二分探索に切り替える log2(2000) simeq 11なので問題なし
        int l = 1, h = 2000 / nPrime;
        int m = (l + h) / 2;
        
      }
    }

    for(int j = 1; j <= 1000; j++){
      if(j % nPrime == 0) cnd[j - 1] = false;
    }

    int tmp = 0;
    for(int j = 1; j <= 1000; j++){
      tmp += cnd[j - 1];
    }
    cout << tmp << endl;
    //解が判明した
    if(tmp == 1){
      for(int j = 1; j <= 1000; j++){
        if(cnd[j - 1]){
          cout << "! " << j << endl;
          return 0;
        }
      }
    }
  }
}