#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string.h>
using namespace std;

#define MAX 51
#define EMPTY 0
#define WALL 1
#define VIRUS 2
#define USE 555
#define INF 98765432
typedef struct {
	int x;
	int y;
}Point;

int board[MAX][MAX];		//��
int visited[MAX][MAX];		//�̵� �ð� üũ�ϴ� ����
bool useVirus[11];			//����� ���̷��� üũ�ϴ� ����
int m_xy[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
int N, M,answer;

vector<Point> v;	//���̷��� �ִ� ����

typedef pair<int, Point>pip;		// ī��Ʈ , ��ǥ


bool restCheckFunction() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (board[i][j] == EMPTY && visited[i][j] == 0) {
				return false;
			}
		}
	}
	return true;
}


int bfs() {
	queue<pip>q;
	int res = 0;
	for (int i = 0; i < v.size(); i++) {
		//���̷����� �߿��� ����ҷ��� ���̷����� ť�� �ִ´�.
		if (useVirus[i]) {
			Point pos = { v[i].x,v[i].y };
			q.push(make_pair(0, pos));
			visited[pos.y][pos.x] = USE;
		}
	}
	while (!q.empty()) {
		int cc = q.front().first;
		Point cPos = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			Point nPos = { cPos.x + m_xy[i][0],cPos.y + m_xy[i][1] };
			int nc = cc + 1;
			if (nPos.x < 0 || nPos.y < 0 || nPos.x >= N || nPos.y >= N) continue;
				
			//�湮�� ���߰� ����ִ� �����̶��
			if (visited[nPos.y][nPos.x]==0&& board[nPos.y][nPos.x] == EMPTY) {
				visited[nPos.y][nPos.x] = nc;
				res = max(res, nc);
				q.push(make_pair(nc, nPos));
			}
			if (visited[nPos.y][nPos.x] != USE && board[nPos.y][nPos.x] == VIRUS) {
				visited[nPos.y][nPos.x] = USE;
				q.push(make_pair(nc, nPos));
			}
		}
	}
	return res;
}


void backTracking(int index,int cnt) {

	if (cnt == M) {
		int tmp = bfs();
		if (answer > tmp&&restCheckFunction()) {
			answer = tmp;
		}
		memset(visited, 0, sizeof(visited));
		return;
	}
	if (index == v.size()) return;

	for (int i = index; i < v.size(); i++) {
		//0�� ����ϰ�
		useVirus[i] = true;
		backTracking(i + 1, cnt + 1);
		//0�� �����ϰ�
		useVirus[i] = false;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	answer = INF;
	cin >> N>>M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
			if (board[i][j] == VIRUS) {
				Point pos = { j,i };
				v.push_back(pos);
			}
		}
	}
	
	backTracking(0,0);
	if (answer == INF) cout << -1 << '\n';
	else cout << answer << '\n';
	return 0;
}