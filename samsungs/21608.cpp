#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 25

struct STUDENT {
	int index;
	int favorite[4];
};

struct POS {
	int x, y;
	int f, e;
};

int N,score;
int MAP[MAX][MAX];
STUDENT STUDENTS[MAX * MAX];
vector<STUDENT> Student;


const int dx[] = { -1,0,1,0};
const int dy[] = { 0,1,0,-1 };

bool compose(POS a, POS b) {
	if (a.f >= b.f) {
		if (a.f == b.f) {
			if (a.e >= b.e) {
				if (a.e == b.e) {
					if (a.x <= b.x) {
						if (a.x == b.x) {
							if (a.y < b.y) {
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
	return false;
}


void BFS() {
	for (int i = 0; i < Student.size(); i++) {
		vector<POS> pos;
		int index = Student[i].index;
		for (int x = 0; x < N; x++) {
			for (int y = 0; y < N; y++) {
				if (MAP[x][y] != 0) continue;
				int favorite_num = 0;
				int empty_num = 0;
				for (int d = 0; d < 4; d++) {
					int nx = x + dx[d];
					int ny = y + dy[d];
					if (nx < 0 || ny < 0 || nx >= N || ny >= N)	continue;
					if (MAP[nx][ny] == 0) {
						empty_num++;
					}
					else {
						for (int k = 0; k < 4; k++) {
							int num = Student[i].favorite[k];
							if (MAP[nx][ny] == num) {
								favorite_num++;
								break;
							}
						}
					}
				}
				pos.push_back({ x,y, favorite_num, empty_num });
			}
		}
		sort(pos.begin(), pos.end(), compose);
		int pos_x = pos[0].x;
		int pos_y = pos[0].y;
		MAP[pos_x][pos_y] = index;

	}
}


int CALCULATE(int f) {
	if(f == 0) return 0;
	if(f == 1) return 1;
	if(f == 2) return 10;
	if(f == 3) return 100;
	if(f == 4) return 1000;
}


void SCORE() {

	for (int x = 0; x < N; x++) {
		for (int y = 0; y < N; y++) {
			int favorite_num = 0;
			int index = MAP[x][y];
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx < 0 || ny < 0 || nx >= N || ny >= N)	continue;
				
				for (int k = 0; k < 4; k++) {
						int num = STUDENTS[index].favorite[k];
						if (MAP[nx][ny] == num) {
							favorite_num++;
							break;
						}
				}
			}
			score += CALCULATE(favorite_num);
		}
	}
}

int main(){
	cin >> N ;
	int a, b, c, d, e;
	for (int i = 0; i < N * N; i++) {
		cin >> a >> b >> c >> d >> e;
		Student.push_back({ a,{b,c,d,e} });
		STUDENTS[a].index = a;
		STUDENTS[a].favorite[0] = b;
		STUDENTS[a].favorite[1] = c;
		STUDENTS[a].favorite[2] = d;
		STUDENTS[a].favorite[3] = e;
	}

	BFS();
	SCORE();
	cout << score << '\n';
	return 0;
}