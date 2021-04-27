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

ll ans = 0;
int n, m;
vector<vector<int>> g(20, vector<int>(0));
vector<vector<bool>> usableColor(20, vector<bool>(3, true));
vector<bool> checked(20, false);
int depth = 0;
vector<int> res(0);

void dfs(int ptr){
  if(checked[ptr]) return;
  int usableColorCnt = 0;
  vector<int> usableColorPtr(0);
  for(int i = 0; i < 3; i++){
    if(usableColor[ptr][i]){
      usableColorCnt++;
      usableColorPtr.push_back(i);
    }
  }
  if(g[ptr].size() == 0){
    //最後の頂点を塗れる
    for(int i = 0; i < res.size(); i++){
      cout << res[i];
    }
    for(int i = 0; i < usableColorPtr.size(); i++){
      cout << usableColorPtr[i];
    }
    cout << endl;
    ans += usableColorCnt;
    return;
  }
  //最後以外の頂点を塗れる
  checked[ptr] = true;
  depth++;
  for(int i = 0; i < usableColorCnt; i++){
    res.push_back(usableColorPtr[i]);
    usableColor[ptr][usableColorPtr[i]] = false;
    for(int j = 0; j < g[ptr].size(); j++){
      usableColor[g[ptr][j]][usableColorPtr[i]] = false;
    }
    for(int j = 0; j < g[ptr].size(); j++){
      dfs(g[ptr][j]);
    }
    for(int j = 0; j < g[ptr].size(); j++){
      usableColor[g[ptr][j]][usableColorPtr[i]] = true;
    }
    usableColor[ptr][usableColorPtr[i]] = true;
    res.pop_back();
  }
  depth--;
  checked[ptr] = false;
}

int main(){
  cin >> n >> m;
  if(m == 0){
    cout << fs(0) << pow(3, n) << endl;
    return 0;
  }
  for(int i = 0; i < m; i++){
    int a, b; cin >> a >> b;
    a--; b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  dfs(0);

  cout << ans << endl;
}