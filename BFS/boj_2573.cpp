#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
#include<string.h>
using namespace std;

#define MAX 302
int board[MAX][MAX];
int diff_board[MAX][MAX];
int m_xy[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
bool visited[MAX][MAX];
int N, M;
vector<Point> ices;

typedef struct {
	int x;
	int y;
}Point;

void ice_melt() {
	
	memset(diff_board, 0, sizeof(diff_board));

	//������ �ϳ��� ������.
	for (int i = 0; i < ices.size(); i++) {
		Point cur_pos = ices[i];
		
		int sea_cnt = 0;
		//�ֺ��� �ٴٰ� � �ִ��� üũ����
		for (int j = 0; j < 4; j++) {
			Point next_pos = { cur_pos.x + m_xy[j][0],cur_pos.y + m_xy[j][1] };
			
			if (next_pos.x < 0 || next_pos.y < 0 || next_pos.x >= M || next_pos.y >= N) continue;
			
			if (board[next_pos.y][next_pos.x] == 0) sea_cnt++;
		}
			
		//������ ���� �����Ѵ�.
		diff_board[cur_pos.y][cur_pos.x] = sea_cnt;
	
	}

	//���� ������Ʈ ���ش�.
	for (int i = 0; i < ices.size(); i++) {
		Point pos = ices[i];
		board[pos.y][pos.x] -= diff_board[pos.y][pos.x];
		if (board[pos.y][pos.x] <= 0) {
			board[pos.y][pos.x] = 0;
		}
	}
	ices.clear();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (board[i][j] > 0) ices.push_back({ j,i });
		}
	}


}

int solve() {
	memset(visited, false, sizeof(visited));
	queue<Point>q;
	int cnt = 0;
	for (int k = 0; k < ices.size(); k++) {
		if (!visited[ices[k].y][ices[k].x]) {
			q.push(ices[k]);
			visited[ices[k].y][ices[k].x] = true;
			cnt++;
			while (!q.empty()) {
				Point cur_pos = q.front();
				q.pop();

				for (int i = 0; i < 4; i++) {
					Point next_pos = { cur_pos.x + m_xy[i][0],cur_pos.y + m_xy[i][1] };

					if (next_pos.x < 0 || next_pos.y < 0 || next_pos.x >= M || next_pos.y >= N)continue;

					if (!visited[next_pos.y][next_pos.x]&&board[next_pos.y][next_pos.x]>0) {
						visited[next_pos.y][next_pos.x] = true;
						q.push(next_pos);
					}
				}

			}
		}
	}
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
		{
			cin >> board[i][j];
			if (board[i][j] != 0) {
				ices.push_back({ j,i });
			}
		} 
	}
	
	int time=0;

	while(true){

		//������ �ѵ�����
		int cnt = solve();
		//�ε��
		if (cnt > 1) break;
		//�����ٳ���
		if (cnt == 0) {
			time = 0;
			break;
		}

		time++;
		//������ ���δ�.
		ice_melt();
	}

	cout << time << '\n';

	return 0;
}