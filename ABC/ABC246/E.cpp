#include <deque>
#include <iostream>
using namespace std;
const int inf = 1012345678;
const int dx[4] = { 1, 1, -1, -1 };
const int dy[4] = { 1, -1, 1, -1 };
int N, sx, sy, gx, gy, dist[1509][1509][4]; char S[1509][1509];
struct state {
	int x, y, dir;
};
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cin >> N >> sx >> sy >> gx >> gy;
	--sx, --sy, --gx, --gy;
	for (int i = 0; i < N; ++i) {
		cin >> S[i];
	}
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			dist[i][j][0] = inf;
			dist[i][j][1] = inf;
			dist[i][j][2] = inf;
			dist[i][j][3] = inf;
		}
	}
	deque<state> deq;
	for (int i = 0; i < 4; ++i) {
		dist[sx][sy][i] = 0;
		deq.push_back({ sx, sy, i });
	}
	while (!deq.empty()) {
		state u = deq.front(); deq.pop_front();
		for (int i = 0; i < 4; ++i) {
			int tx = u.x + dx[i], ty = u.y + dy[i], cost = dist[u.x][u.y][u.dir] + (u.dir != i ? 1 : 0);
			if (0 <= tx && tx < N && 0 <= ty && ty < N && S[tx][ty] == '.' && dist[tx][ty][i] > cost) {
				dist[tx][ty][i] = cost;
				if (u.dir != i) deq.push_back({ tx, ty, i });
				else deq.push_front({ tx, ty, i });
			}
		}
	}
	int answer = inf;
	for (int i = 0; i < 4; ++i) {
		answer = min(answer, dist[gx][gy][i]);
	}
	if(answer == inf){
        cout << -1 << endl;
    }else{
        cout << answer + 1 << endl;
    }
	return 0;
}