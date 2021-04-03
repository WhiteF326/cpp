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

string nico_s(int x){
	string ret = "";
	for(int i = 0; i < x; i++) ret += "25";
	return ret;
}

int main(){
	string s; cin >> s;
	vector<int> nico_con(0);
	for(int i = 0; i < s.length(); i++){
		int nicocnt = 1;
		if(s.substr(i, 2) != "25") continue;
		while(i + 2 * nicocnt <= s.length()){
			if(s.substr(i, 2 * nicocnt) != nico_s(nicocnt)){
				nico_con.push_back(nicocnt - 1);
				i += (2 * (nicocnt - 1));
				break;
			}else if(i + 2 * nicocnt == s.length()){
				nico_con.push_back(nicocnt);
				i += 9999999;
				break;
			}else{
				nicocnt++;
			}
		}
	}
	int ans = 0;
	for(auto itr = nico_con.begin(); itr != nico_con.end(); itr++){
		ans += (int)floor(((*itr + 1) * *itr) / 2);
	}
	cout << ans << endl;
}