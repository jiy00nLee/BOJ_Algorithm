#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string.h>
#include<stdlib.h>

using namespace std;
#define MAX 1002
int N, M, K;
char board[MAX][MAX];
int visited[11][MAX][MAX];
int m_xy[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
typedef struct {
	int c;
	int x;
	int y;
}Info;


int bfs() {
	queue<Info> q;
	q.push({ 0,0,0 });
	visited[0][0][0] = 1;
	while (!q.empty()) {
		Info c_info = q.front();
		
		//�������� ���������Ƿ� 
		if (c_info.x == M - 1 && c_info.y == N-1) {
			return visited[c_info.c][c_info.y][c_info.x];
		}

		q.pop();
		for (int i = 0; i < 4; i++) {
			Info n_info = { c_info.c,c_info.x + m_xy[i][0],c_info.y + m_xy[i][1] };
			int n_move_cnt = visited[c_info.c][c_info.y][c_info.x] + 1;

			if (n_info.x < 0 || n_info.y < 0 || n_info.x >= M || n_info.y >= N) continue;
			
			//���� ��ǥ�� ���� �ƴ� ��� �湮�� ���߰ų� , �̵�Ƚ���� �� �۴ٸ�
			if (board[n_info.y][n_info.x] == '0' && (visited[n_info.c][n_info.y][n_info.x]==0||visited[n_info.c][n_info.y][n_info.x]>n_move_cnt)) {
				visited[n_info.c][n_info.y][n_info.x] = n_move_cnt;
				q.push(n_info);
			}
			//���� ��ǥ�� ���� ��� ������� �μ� ���� ������ K ���� �۴ٸ� �μ��� ������
			else if (board[n_info.y][n_info.x] == '1'&& K > c_info.c) {
				n_info.c = c_info.c + 1;//���� �μ��� �̵�
				if (visited[n_info.c][n_info.y][n_info.x] == 0 || visited[n_info.c][n_info.y][n_info.x] > n_move_cnt) {
					visited[n_info.c][n_info.y][n_info.x] = n_move_cnt;
					q.push(n_info);
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

	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
		}
	}
	cout<<bfs()<<'\n';

	return 0;
}
