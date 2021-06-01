#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(i, j) make_pair(i, j);
using ll = long long;
using ld = long double;

int main(){
  ll n; cin >> n;
	priority_queue<ll, vector<ll>, greater<ll>> q;
	for(ll i = 1; i <= ceil(sqrt(n)); i++){
		if(n % i == 0){
			q.push(i);
			q.push(n / i);
		}
	}
	set<ll> anslist;
	while(!q.empty()){
		anslist.insert(q.top());
		q.pop();
	}
	for(auto x : anslist){
		cout << x << endl;
	}
}