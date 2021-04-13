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
  vector<string> s(3);
  cin >> s[0] >> s[1] >> s[2];

  //数値化
  vector<vector<int>> posmp(3, vector<int>(0));
  map<string, int> usedStr; int nxt = 0;
  const string lst = "abcdefghijklmnopqrstuvwxyz";
  for(int i = 0; i < 26; i++) usedStr[lst.substr(i, 1)] = -1;
  for(int h = 0; h < 3; h++){
    for(int i = 0; i < s[h].length(); i++){
      if(usedStr[s[h].substr(i, 1)] == -1){
        usedStr[s[h].substr(i, 1)] = nxt;
        posmp[h].push_back(nxt);
        nxt++;
      }else{
        posmp[h].push_back(usedStr[s[h].substr(i, 1)]);
      }
    }
  }
  if(nxt > 10){
    cout << "UNSOLVABLE" << endl;
    return 0;
  }
  
  vector<ll> perm(10);
  for(int i = 0; i < 10; i++) perm[i] = i;
  do{
    //式の生成
    vector<ll> res = {0, 0};
    for(int h = 0; h < 2; h++){
      for(int i = 0; i < s[h].length(); i++){
        res[h] += perm[posmp[h][i]] * pow(10, s[h].length() - 1 - i);
      }
    }
    ll t = 0;
    for(int i = 0; i < s[2].length(); i++){
      t += perm[posmp[2][i]] * pow(10, s[2].length() - 1 - i);
    }
    bool flg = true;
    for(int lch = 0; lch < 2; lch++){
      if(floor(log10(res[lch])) + 1 != s[lch].length()) flg = false;
    }
    if(floor(log10(t)) + 1 != s[2].length()) flg = false;
    if(res[0] + res[1] == t && res[0] > 0 && res[1] > 0 && flg){
      cout << res[0] << endl;
      cout << res[1] << endl;
      cout << t << endl;
      return 0;
    }
  }while(next_permutation(perm.begin(), perm.end()));
  cout << "UNSOLVABLE" << endl;
}