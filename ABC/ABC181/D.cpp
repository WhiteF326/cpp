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
  //下3桁だけで8の倍数になるかわかる
  string s; cin >> s;
  sort(s.begin(), s.end()); reverse(s.begin(), s.end());
  map<int, int> appearance;
  for(int i = 0; i < s.length(); i++){
    appearance[stoi(s.substr(i, 1))]++;
  }
  if(s.length() <= 3){
    for(int i = 0; i < 3 - s.length(); i++){
      appearance[0]++;
    }
  }
  for(int i = 0; i < 125; i++){
    if(s.length() <= 3){
      if((ll)i * 8ll > stoll(s)) break;
    }
    string t_oct = to_string(i * 8);
    while(t_oct.length() < 3) t_oct = "0" + t_oct;
    map<int, int> oct_ap;
    for(int j = 0; j < t_oct.length(); j++){
      oct_ap[stoi(t_oct.substr(j, 1))]++;
    }
    bool flg = true;
    for(auto itr = oct_ap.begin(); itr != oct_ap.end(); itr++){
      if(appearance[itr->first] < itr->second) flg = false;
    }
    if(flg){
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
}