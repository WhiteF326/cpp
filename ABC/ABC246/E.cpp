#ifdef _DEBUG
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define all(x) x.begin(), x.end()
#define fs(n) fixed << setprecision(n)
using ll = long long;
using ld = long double;
#define query(t) while(t--)
#define aryin(a, n) for(int i = 0; i < n; i++) cin >> a[i];
#define chmin(a, b) a = min(a, b)
#define chmax(a, b) a = max(a, b)


int n;
int toIdx(const int& x, const int& y){
	return x * n + y;
}
pair<int, int> toIdx(const int& p){
	return make_pair(p / n, p % n);
}

int toWay(int x, int y){
	return ((x > 0) * 2) + (y > 0);
}

int main(){
	cin >> n;
	int ax, ay, bx, by; cin >> ax >> ay >> bx >> by;
	ax--, ay--, bx--, by--;

	vector<vector<int>> stage(n, vector<int>(n, 0));
	for(int i = 0; i < n; i++){
		string s; cin >> s;
		for(int j = 0; j < n; j++){
			if (s[j] == '#') stage[i][j] = 1;
		}
	}

	deque<pair<int, int>> q;
	for(int i = 0; i < 4; i++){
		q.push_back({toIdx(ax, ay), i});
	}

	vector<vector<vector<int>>> depth(n, vector<vector<int>>(n, vector<int>(4, 1 << 30)));
	for(int v = 0; v < 4; v++) depth[ax][ay][v] = 1;

	while(!q.empty()){
		int dest, vect;
		tie(dest, vect) = q.front();
		q.pop_front();
		int cx, cy;
		tie(cx, cy) = toIdx(dest);

		for(int mx = -1; mx <= 1; mx++){
			for(int my = -1; my <= 1; my++){
				if(!mx || !my) continue;
				if(cx + mx < 0 || cx + mx >= n || cy + my < 0 || cy + my >= n) continue;
				if(stage[cx + mx][cy + my]) continue;
				
				int c = 0, t = toWay(mx, my);

				if(vect != t){
					c = 1;
				}
				if(depth[cx + mx][cy + my][t] > depth[cx][cy][vect] + c){
					depth[cx + mx][cy + my][t] = depth[cx][cy][vect] + c;	
					if(vect == t){
						q.push_front({toIdx(cx + mx, cy + my), t});
					}else{
						q.push_back({toIdx(cx + mx, cy + my), t});
					}
				}
			}
		}
	}
	// for(int i = 0; i < n; i++){
	// 	for(int j = 0; j < n; j++){
	// 		cout << *min_element(all(depth[i][j])) << " ";
	// 	}cout << endl;
	// }

	int ans = INT_MAX;
	for(int i = 0; i < 4; i++){
		chmin(ans, depth[bx][by][i]);
	}
	if(ans == 1 << 30){
		cout << -1 << endl;
	}else{
		cout << ans << endl;
	}
}
