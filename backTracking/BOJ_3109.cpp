#include<iostream>
using namespace std;
char board[10002][502];
bool visited[10002][502];
int cnt,r,c;
int dx[3] = { 1,1,1 };		//������ , ������ �� , ������ �Ʒ�
int dy[3] = { -1,0,1 };
int dfs(int x,int y) {
	visited[y][x] = 1;
	if (x == c - 1) return 1;
	for (int i = 0; i < 3; i++) {
		int nextX = x + dx[i];
		int nextY = y + dy[i];
		if (nextX >= 0 && nextX < c&&nextY >= 0 && nextY < r) {
			if (!visited[nextY][nextX] && board[nextY][nextX] != 'x') {
				int res = dfs(nextX, nextY);
				if (res) return res;	// 0�̶�� ������ �ٲ㼭 Ž���� �ϰ� 1�̶�� �ٷ� �����Ų��.(���� ���������Ƿ�)
			}
		}
	}
	return 0;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> board[i][j];
		}
	}
	for (int i = 0; i < r; i++) {
		cnt+=dfs(0, i);
	}
	cout << cnt << '\n';
	return 0;
}