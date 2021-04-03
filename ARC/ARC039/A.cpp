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

int retval(vector<int> arr){
  int ans = 0;
  for(int i = 0; i < arr.size(); i++){
    ans += pow(10, arr.size() - i - 1) * arr[i];
  }
  return ans;
}

int main(){
  int a, b; cin >> a >> b;
  int ans = a - b;

  vector<int> a_digit(3), b_digit(3);
  for(int i = 0; i < 3; i++){
    a_digit[i] = stoi(to_string(a).substr(i, 1));
    b_digit[i] = stoi(to_string(b).substr(i, 1));
  }
  // aの1
  for(int i = 1; i <= 9; i++){
    int tmpa = retval({i, a_digit[1], a_digit[2]});
    ans = max(ans, tmpa - b);
  }
  // aの2
  for(int i = 0; i <= 9; i++){
    int tmpa = retval({a_digit[0], i, a_digit[2]});
    ans = max(ans, tmpa - b);
  }
  // aの3
  for(int i = 0; i <= 9; i++){
    int tmpa = retval({a_digit[0], a_digit[1], i});
    ans = max(ans, tmpa - b);
  }
  // bの1
  for(int i = 1; i <= 9; i++){
    int tmpb = retval({i, b_digit[1], b_digit[2]});
    ans = max(ans, a - tmpb);
  }
  // bの2
  for(int i = 0; i <= 9; i++){
    int tmpb = retval({b_digit[0], i, b_digit[2]});
    ans = max(ans, a - tmpb);
  }
  // bの3
  for(int i = 0; i <= 9; i++){
    int tmpb = retval({b_digit[0], b_digit[1], i});
    ans = max(ans, a - tmpb);
  }
  cout << ans << endl;
}