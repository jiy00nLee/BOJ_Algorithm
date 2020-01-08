#include<iostream>
#include<vector>
#include<string>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<queue>
using namespace std;
#define MAX 52
#define W 9
#define H 10
#define D 11
int R, C;
char board[MAX][MAX];

int visited[MAX][MAX];

int m_xy[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
typedef struct {
	int x;
	int y;
	int type;
	int cnt;
}Point;
queue<Point>q;
vector<Point> waters;
Point h,dest;

void print() {
	cout << "===================================\n";
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cout << visited[i][j] << ' ';
		}cout << '\n';
	}
}

int solve() {

	//ť�� ������ �� �ְ�
	for (int i = 0; i < waters.size(); i++) {
		q.push(waters[i]);
	}
	q.push(h);
	while (!q.empty()) {
		//print();
		Point cur_pos = q.front();
		if (cur_pos.type == H&&cur_pos.x==dest.x&&cur_pos.y==dest.y) {
			return cur_pos.cnt;
		}
		q.pop();
		for (int i = 0; i < 4; i++) {
			Point next_pos;
			next_pos.x = cur_pos.x + m_xy[i][0];
			next_pos.y = cur_pos.y + m_xy[i][1];
			next_pos.type = cur_pos.type;
			
			//������ ������� üũ
			if (next_pos.x < 0 || next_pos.y < 0 || next_pos.x == C || next_pos.y == R) continue;
			
			//Ÿ���� ���ΰ��
			if (next_pos.type == W) {
				//����ִ� ���� �̵���Ų��.
				if ((visited[next_pos.y][next_pos.x] == 'H' || visited[next_pos.y][next_pos.x] == 0) && board[next_pos.y][next_pos.x] != 'X') {
					visited[next_pos.y][next_pos.x] = W;
					q.push(next_pos);
				}
			}
			//����ġ�ΰ��
			else {
				//����ֵ��� �̵��Ѵ�
				if ((visited[next_pos.y][next_pos.x] == 0||visited[next_pos.y][next_pos.x]==D)&&board[next_pos.y][next_pos.x]!='X') {
					visited[next_pos.y][next_pos.x] = H;
					next_pos.cnt = cur_pos.cnt + 1;
					q.push(next_pos);
				}
			}
		}
	}

	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	cin >> R >> C;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> board[i][j];
			if (board[i][j] == 'S') {
				h.x = j;
				h.y = i;
				h.type = H;
				visited[h.y][h.x] = H;
				h.cnt = 0;
			}
			else if (board[i][j] == '*') {
				Point tmp;
				tmp.x = j;
				tmp.y = i;
				tmp.type = W;
				waters.push_back(tmp);
				visited[tmp.y][tmp.x] = W;
			}
			else if (board[i][j] == 'D') {
				dest.x = j;
				dest.y = i;
				visited[dest.y][dest.x] = D;
			}
		}
	}
	int res=solve();
	if (res == -1) {
		cout << "KAKTUS\n";
	}
	else {
		cout << res << '\n';
	}

	return 0;
}