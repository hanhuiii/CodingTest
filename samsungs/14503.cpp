#include <iostream>

using namespace std;

int map[50][50];
int N, M;
const int dx[] = { -1, 0, 1, 0 };
const int dy[] = { 0, 1, 0, -1 };

int ans = 0;

void dfs(int x, int y, int d) {
	if (map[x][y] == 0) {
		map[x][y] = 2;
		ans++;
	}
	for (int i = 0; i < 4; i++) {
		int nd = (d+3-i)%4;
		int nx = x + dx[nd];
		int ny = y + dy[nd];
		if (nx < 0 || ny < 0 || nx >= N || ny >= M) {
			continue;
		}
		if (map[nx][ny] == 0) {
			dfs(nx, ny, nd);
		}
	}
	int bx = x - dx[d];
	int by = y - dy[d];
	if (map[bx][by] == 1) {
		cout << ans << '\n';
		exit(0);
	}
	dfs(bx, by, d);
}

int main() {
	int r, c, d;
	cin >> N >> M;
	cin >> r >> c >> d;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	dfs(r, c, d);
	return 0;
}
