#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <stdio.h>

using namespace std;
#define MAX 25

struct BLOCK {
	int Size, Rainbow_cnt, x, y;
	vector<pair<int, int> > Block_pos;
};

int N, M, Answer;
int MAP[MAX][MAX];
bool VISIT[MAX][MAX];
bool R_VISIT[MAX][MAX];

const int dx[] = { -1, 0, 1, 0 };
const int dy[] = { 0, 1, 0, -1 };

bool compare(pair<int, int>a, pair<int, int> b) {
	if (a.first <= b.first) {
		if (a.first == b.first) {
			if (a.second < b.second) {
				return true;
			}
			return false;
		}
		return true;
	}
	return false;
}

bool compare_block(BLOCK a, BLOCK b) {
	if (a.Size <= b.Size) {
		if (a.Size == b.Size) {
			if (a.Rainbow_cnt <= b.Rainbow_cnt) {
				if (a.Rainbow_cnt == b.Rainbow_cnt) {
					if (a.x <= b.x) {
						if (a.x == b.x) {
							if (a.y > b.y)
								return true;
						}
						return false;
					}
					return true;
				}
				return false;
			}
			return true;
		}
		return false;
	}
	return true;
}

BLOCK BFS(int a, int b, int color) {
	memset(R_VISIT, false, sizeof(R_VISIT));
	vector<pair<int, int> > block;
	vector<pair<int, int> > general_block;
	queue<pair<int, int> > q;
	
	block.push_back(make_pair(a, b));
	general_block.push_back(make_pair(a, b));

	q.push(make_pair(a, b));

	VISIT[a][b] = true;
	int rainbow = 0;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && ny >= 0 && nx < N && ny < N) {
				if (MAP[nx][ny] == 0) {
					if (R_VISIT[nx][ny] == false) {
						R_VISIT[nx][ny] = true;
						block.push_back(make_pair(nx, ny));
						q.push(make_pair(nx, ny));
						rainbow++;
					}
				}
				if (MAP[nx][ny] == color) {
					if (VISIT[nx][ny] == false) {
						VISIT[nx][ny] = true;
						block.push_back(make_pair(nx, ny));
						q.push(make_pair(nx, ny));
						general_block.push_back(make_pair(nx, ny));
					}
				}
			}
		}
	}

	sort(general_block.begin(), general_block.end(), compare);
	BLOCK R_block;
	R_block.Size = block.size();
	R_block.Rainbow_cnt = rainbow;
	R_block.x = general_block[0].first;
	R_block.y = general_block[0].second;
	R_block.Block_pos = block;

	return R_block;
}

BLOCK Find_Biggest_Block() {
	memset(VISIT, false, sizeof(VISIT));
	BLOCK result;
	result.Size = -1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (VISIT[i][j] == true) continue;
			if (MAP[i][j] == -2 || MAP[i][j] == -1 || MAP[i][j] == 0) continue;
			BLOCK temp_result = BFS(i, j, MAP[i][j]);

			if (result.Size == -1) result = temp_result;
			else {
				if (compare_block(temp_result, result)) result = temp_result;
			}
		}
	}
	return result;
}

void Delete_Block(BLOCK result) {
	vector<pair<int, int> > pos = result.Block_pos;
	for (int i = 0; i < pos.size(); i++) {
		int x = pos[i].first;
		int y = pos[i].second;
		MAP[x][y] = -2;
	}
	Answer += (pos.size() * pos.size());
}

void Gravity() {
	for (int i = N - 2; i >= 0; i--) {
		for (int j = 0; j < N; j++) {
			if (MAP[i][j] == -2 || MAP[i][j] == -1) continue;
			int color = MAP[i][j];
			int nx = i + 1;
			while (1) {
				if (MAP[nx][j] != -2) break;
				
				if (nx == N) break;
				nx++;
			} 
			nx--;
			MAP[i][j] = -2;
			MAP[nx][j] = color;
		}
	}
}

void Rotate() {
	for (int i = 0; i < N / 2; i++) {
		int sx = i;
		int sy = i;
		int ex = N - 1 - i;
		int ey = N - 1 - i;

		int x_temp = ex;
		int y_temp = sy;
		int temp = 0;
		vector<int> TEMP;
		for (int x = ex; x > sx; x--) TEMP.push_back(MAP[x][sy]);
		for (int y = sy; y < ey; y++)MAP[x_temp--][sy] = MAP[sx][y];
		for (int x = sx; x < ex; x++)MAP[sx][y_temp++] = MAP[x][ey];
		for (int y = ey; y > sy; y--)MAP[x_temp++][ey] = MAP[ex][y];
		for (int y = ey; y > sy; y--)MAP[ex][y] = TEMP[temp++];
	}
}

int main() {

	//ios::sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);


	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> MAP[i][j];
		}
	}

	while (1) {
		BLOCK result = Find_Biggest_Block();
		if (result.Size < 2)break;
		Delete_Block(result);
		Gravity();
		Rotate();
		Gravity();
	}
	cout << Answer << '\n';
	return 0;
}