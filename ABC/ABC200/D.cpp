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
  vector<vector<pair<int, vector<int>>>> tbl(n + 1, vector<pair<int, vector<int>>>(200, pair<int, vector<int>>()));
  tbl[0][a[0] % 200].first++;
  tbl[0][a[0] % 200].second = {0};
  tbl[0][0].first++;
  tbl[0][0].second = {};

  for(int i = 0; i < n - 1; i++){
    for(int j = 0; j < 200; j++){
      if(tbl[i][j].first == 1){
        tbl[i + 1][(j + a[i + 1]) % 200].first++;
        if(tbl[i + 1][(j + a[i + 1]) % 200].first == 2 && tbl[i + 1][j].second.size() > 0){
          int blen = tbl[i + 1][(j + a[i + 1]) % 200].second.size();
          int clen = tbl[i][j].second.size();
          bool flg = true;
          for(int k = 0; k < min(blen, clen); k++){
            if(tbl[i + 1][(j + a[i + 1]) % 200].second[k] == tbl[i][j].second[k]){
              flg = false;
              break;
            }
          }
          if(flg){
            cout << "Yes" << endl;
            cout << blen << " ";
            for(int k = 0; k < blen - 1; k++){
              cout << tbl[i + 1][(j + a[i + 1]) % 200].second[k] + 1 << " ";
            }cout << tbl[i + 1][(j + a[i + 1]) % 200].second[blen - 1] + 1 << endl;
            cout << clen << " ";
            for(int k = 0; k < clen - 1; k++){
              cout << tbl[i][j].second[k] + 1 << " ";
            }cout << tbl[i][j].second[clen - 1] + 1 << endl;
            return 0;
          }
        }
        tbl[i + 1][(j + a[i + 1]) % 200].second = tbl[i][j].second;
        tbl[i + 1][(j + a[i + 1]) % 200].second.push_back(i + 1);

        tbl[i + 1][j].first++;
        if(tbl[i + 1][j].first == 2 && tbl[i + 1][j].second.size() > 0){
          int blen = tbl[i + 1][j].second.size();
          int clen = tbl[i][j].second.size();
          bool flg = true;
          for(int k = 0; k < min(blen, clen); k++){
            if(tbl[i + 1][j].second[k] == tbl[i][j].second[k]){
              flg = false;
              break;
            }
          }
          if(flg){
            cout << "Yes" << endl;
            cout << blen << " ";
            for(int k = 0; k < blen - 1; k++){
              cout << tbl[i + 1][j].second[k] + 1 << " ";
            }cout << tbl[i + 1][j].second[blen - 1] + 1 << endl;
            cout << clen << " ";
            for(int k = 0; k < clen - 1; k++){
              cout << tbl[i][j].second[k] + 1 << " ";
            }cout << tbl[i][j].second[clen - 1] + 1 << endl;
            return 0;
          }
        }
        tbl[i + 1][j].second = tbl[i][j].second;
      }
    }
  }
  cout << "No" << endl;
}