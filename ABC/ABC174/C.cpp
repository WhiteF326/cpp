#include <bits/stdc++.h>
using namespace std;
 
#define fs(n) fixed << setprecision(n)
using ll = long long;

int main(){
	int k; cin >> k;
	int md = 7 % k;
  for(int i = 0; i <= k; i++){
		if(md){
			md *= 10;
			md += 7;
			md %= k;
		}else{
			cout << i + 1 << endl;
			return 0;
		}
	}
	cout << -1 << endl;
}