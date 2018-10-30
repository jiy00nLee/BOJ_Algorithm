#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<string.h>
using namespace std;
#define MAX 251
int r, c;
typedef pair<int, int>pii;	// x,y
vector<pii>vs,ks;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
char board[MAX][MAX];	//�׷��� ����
bool visited[MAX][MAX];	//�湮 üũ ����
int ansVCnt, ansKCnt;
void bfs() {
	queue<pii>q;
	for (int i = 0; i < vs.size(); i++) {
		int posX = vs[i].first;	//���� ��ǥ ����
		int posY = vs[i].second;
		int tmpVCnt = 0, tmpKCnt = 0;
		q.push(make_pair(posX, posY));
		while (!q.empty()) {
			int currentX = q.front().first;
			int currentY = q.front().second;
			q.pop();
			if (!visited[currentY][currentX]) {	
				visited[currentY][currentX] = true;
				if (board[currentY][currentX] == 'v')	//�湮 ���� ������ ī��Ʈ
					tmpVCnt++;
				if(board[currentY][currentX]=='k')	//�湮 ���� �� ī��Ʈ
					tmpKCnt++;
				for (int i = 0; i < 4; i++) {
					int nextX = currentX + dx[i];
					int nextY = currentY + dy[i];
					if (!visited[nextY][nextX]&&board[nextY][nextX] == '.') { //�湮 ���� ������� ���
						q.push(make_pair(nextX, nextY));
					}
					else if (!visited[nextY][nextX]&&board[nextY][nextX] == 'k') {	//�湮���� ���� ���
						q.push(make_pair(nextX, nextY));
					}
					else if (!visited[nextY][nextX]&&board[nextY][nextX] == 'v') {	//�湮 ���� ������ ���
						q.push(make_pair(nextX, nextY));
					}
				}
			}
		}
		//���̶� ���� ī��Ʈ ���ؼ� ���� ���� ����
		if (tmpVCnt >= tmpKCnt) {//���밡 �纸�� ���� ���ų� �������
			ansVCnt += tmpVCnt;
		}
		else {//���� ���뺸�� �������
			ansKCnt += tmpKCnt;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> board[i][j];
			if (board[i][j] == 'v') {	// ������ ��� ���� ����
				vs.push_back(make_pair(j, i));
			}
			else if (board[i][j] == 'k') {	// ���� ��� ���� ����
				ks.push_back(make_pair(j, i));
			}
		}
	}
	bfs();
	for (int i = 0; i < vs.size(); i++) {//�湮 ���� ���� üũ
		int posX = vs[i].first;
		int posY = vs[i].second;
		if (!visited[posY][posX])
			ansVCnt++;
	}
	for (int i = 0; i < ks.size(); i++) {//�湮 ���� �� üũ
		int posX = ks[i].first;
		int posY = ks[i].second;
		if (!visited[posY][posX])
			ansKCnt++;
	}
	cout << ansKCnt << ' ' << ansVCnt << '\n';
	return 0;
}