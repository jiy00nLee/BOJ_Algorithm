#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
#define WATER 0	// ��
#define NO 1	// ���� �Ѹ� �� ���� ��
#define YES 2	// ���� �Ѹ� �� �ִ� ��
#define RED 8	// ���� ����
#define GREEN 9	// �ʷ� ����
#define F 10	// ��
#define MAX 52
int N, M, G, R;
int total;
int board[MAX][MAX];
typedef struct {
	int x;
	int y;
}Point;
typedef struct {
	int x;
	int y;
	int type;
	int time;
}Info;
vector<Point> pos;
Info tmp_board[MAX][MAX];
int m_xy[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };

int bfs(vector<int> arr) {
	int answer = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			tmp_board[i][j].x = j; tmp_board[i][j].y = i;
			tmp_board[i][j].time = 0; tmp_board[i][j].type = board[i][j];
		}
	}
	int r_cnt = 0, g_cnt = 0;
	queue<Info>q;
	for (int i = 0; i < pos.size(); i++) {
		if (arr[i] == RED) {
			r_cnt++;
			tmp_board[pos[i].y][pos[i].x].type = RED;
			q.push(tmp_board[pos[i].y][pos[i].x]);
		}
		else if (arr[i] == GREEN) {
			g_cnt++;
			tmp_board[pos[i].y][pos[i].x].type = GREEN;
			q.push(tmp_board[pos[i].y][pos[i].x]);
		}
	}
	if (g_cnt != G || r_cnt != R) return 0;

	while (!q.empty()) {
		Info cur_pos = q.front();
		q.pop();
		if (tmp_board[cur_pos.y][cur_pos.x].type != F){
			for (int i = 0; i < 4; i++) {
				Info next_pos = { cur_pos.x + m_xy[i][0],cur_pos.y + m_xy[i][1],cur_pos.type,cur_pos.time + 1 };

				//�̵� �Ұ����� �����̶�� ��Ƽ��
				if (next_pos.x < 0 || next_pos.y < 0 || next_pos.x >= M || next_pos.y >= N || tmp_board[next_pos.y][next_pos.x].type == WATER) continue;

				//�̵��Ϸ��� ���� �̵� ������ ���̶��
				if (tmp_board[next_pos.y][next_pos.x].type == NO || tmp_board[next_pos.y][next_pos.x].type == YES) {
					tmp_board[next_pos.y][next_pos.x].type = next_pos.type;
					tmp_board[next_pos.y][next_pos.x].time = next_pos.time;
					q.push(next_pos);
				}
				//�̵��Ϸ��� ���� �ð��� ���� Ÿ���� ���� �ٸ��ٸ� ���� �����.
				else if (tmp_board[next_pos.y][next_pos.x].time == next_pos.time && ((next_pos.type == RED && tmp_board[next_pos.y][next_pos.x].type == GREEN) || (next_pos.type == GREEN && tmp_board[next_pos.y][next_pos.x].type == RED))) {
					tmp_board[next_pos.y][next_pos.x].type = F;
					tmp_board[next_pos.y][next_pos.x].time = next_pos.time;
					answer++;
				}
			}
		}
	}
	return answer;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> G >> R;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
			if (board[i][j] == YES) {
				pos.push_back({ j,i });
			}
		}
	}
	
	total = G + R;
	int answer = 0;
	vector<int> arr(10-total,0);
	for (int i = 0; i < G; i++) {
		arr.push_back(GREEN);
	}
	for (int j = 0; j < R; j++) {
		arr.push_back(RED);
	}
	sort(arr.begin(), arr.end());
	do {
		answer = max(answer, bfs(arr));
	} while (next_permutation(arr.begin(), arr.end()));

	cout << answer << '\n';

	return 0;
}