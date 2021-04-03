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
	int n; cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];

	map<int, int> dCnt;
	for(auto itr = a.begin(); itr != a.end(); itr++){
		if(*itr % 4 == 0) dCnt[4]++;
		else if(*itr % 2 == 0) dCnt[2]++;
		else dCnt[1]++;
	}
	for(auto itr = dCnt.begin(); itr != dCnt.end(); itr++){
		cout << itr->first << " " << itr->second << endl;
	}
	if(dCnt[4] - dCnt[1] >= -(n % 2)) cout << "Yes" << endl;
	else cout << "No" << endl;
}