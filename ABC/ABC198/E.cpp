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
  vector<int> colors(n);
  for(int i = 0; i < n; i++) cin >> colors[i];
  vector<vector<int>> tr(n, vector<int>(0));
  for(int i = 0; i < n - 1; i++){
    int a, b; cin >> a >> b;
    tr[a - 1].push_back(b - 1);
    tr[b - 1].push_back(a - 1);
  }

  //dfsして経路復元
  vector<int> prev(n, -1);
  vector<bool> visited(n, false);
  visited[0] = true;
  queue<int> q;
  q.push(0);
  while(q.size()){
    int d = q.front(); q.pop();
    for(int i = 0; i < tr[d].size(); i++){
      if(visited[tr[d][i]] == false){
        prev[tr[d][i]] = d;
        q.push(tr[d][i]);
        visited[tr[d][i]] = true;
      }
    }
  }
  cout << 1 << endl;
  for(int i = 1; i < n; i++){
    bool flg = true;
    int omitcolor = colors[i];
    int pos = i;
    do{
      pos = prev[pos];
      if(colors[pos] == omitcolor){
        flg = false; break;
      }
    }while(prev[pos] != -1);
    if(flg) cout << i + 1 << endl;
  }
}