#include<iostream>
#include<queue>
#include<functional>
#include<algorithm>
#include<vector>
#include<string.h>
#include<string>
using namespace std;
#define MAX 126
int board[MAX][MAX];
bool visited[MAX][MAX];
int n;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0, };
typedef pair<int, pair<int, int>>piii;
/*
	����
	�켱����ť�� �����ؼ� ���� ���� ��� ��ǥ�� ������ �湮�Ѵ�.
*/
void initFunc() {
	memset(board, 0, sizeof(board));
	memset(visited, false, sizeof(visited));
}
int bfs() {
	priority_queue<piii,vector<piii>,greater<piii>>pq;	//����, x��ǥ y��ǥ
	pq.push(make_pair(board[0][0], make_pair(0, 0)));
	visited[0][0] = true;
	while (!pq.empty()) {
		int curRupy = pq.top().first;
		int curPosX = pq.top().second.first;
		int curPosY = pq.top().second.second;
		//cout << "r :" << curRupy << " x: " << curPosX << " y : " << curPosY << '\n';
		pq.pop();
		if (curPosX == n - 1 && curPosY == n - 1) {//���� �����ߴٸ�
			return curRupy;
		}
		else {
			for (int i = 0; i < 4; i++) {
				int nextPosX = curPosX + dx[i];
				int nextPosY = curPosY + dy[i];
				if (nextPosX >= 0 && nextPosY >= 0 && nextPosX < n&&nextPosY < n) {
					if (!visited[nextPosY][nextPosX]) {
						int nextRupy = curRupy + board[nextPosY][nextPosX];
						visited[nextPosY][nextPosX] = true;
						pq.push(make_pair(nextRupy, make_pair(nextPosX, nextPosY)));
					}
				}
			}
		}
	}
	return -1;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tc = 1;
	cin >> n;
	if (n != 0) {
		do {
			initFunc();
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					cin >> board[i][j];
				}
			}
			int res = bfs();
			cout << "Problem " << tc++ << ": " << res << '\n';
			cin >> n;
		} while (n != 0);
	}
	return 0;
}