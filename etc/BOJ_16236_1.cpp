#include<iostream>
#include<queue>
#include<algorithm>
#include<string.h>
#include<vector>
#include<functional>
using namespace std;
#define MAX 21
typedef pair<int, int>pii;	//x,y
typedef pair<int, pair<int, int>>piii;		//�Ÿ� ��ǥ x,y
typedef pair<int, pair<int, pair<int, int>>> piiii; //�̵��Ÿ�, ��ǥ, ����� ũ��
int board[MAX][MAX];
bool visited[MAX][MAX];
pii startPos;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int n, sharkSize = 2, res = 0, eat = 0;
void update() {
	memset(visited, false, sizeof(visited));
}
/*
	���� : ���� �Ʊ��� ��ġ���� ���� �� �ִ� ����⸦ �����Ѵ�. (�Ÿ���,��ǥ)

	1.�켱����ť�� ��� (�Ÿ�,x��ǥ,y��ǥ) ����  �Ÿ��� ª���͵��� ������ ���� ��Ų��.
	2.���� ��ǥ�� ������ε� ���� �� �ִ� ������̰ų� �̵� �Ұ����� �������
	2-1.�Ʊ���� ���� ������� ���Ϳ� �ִ´�.
	2-2.�̵� ������ ��ǥ��� �湮���ߴٸ� ť�� �ִ´�.
	3. �Ÿ��� ����� ������ ����
	3-1 ���Ϳ��� �Ÿ��� ª�� ����� �ε����� ������Ʈ
	3-2 ª�� �Ÿ��� ���ٸ� �־��� ���ǿ� ������ �ε����� ������Ʈ (���� �ְ� ���ʿ� �ִ� �����)
	4. ���� ����Ⱑ �����Ѵٸ� �������ش�.
	5. ���� �������� �Ʊ��� ����� ���ٸ� �Ʊ�������� ������Ų��.
*/
bool bfs() {
	priority_queue<piii, vector<piii>, greater<piii>>pq;	//1
	pq.push(make_pair(0, make_pair(startPos.first, startPos.second)));
	visited[startPos.second][startPos.first] = true;
	vector<piiii> v;
	while (!pq.empty()) {
		int curDist = pq.top().first;
		int curPosX = pq.top().second.first;
		int curPosY = pq.top().second.second;
		pq.pop();
		if (board[curPosY][curPosX] != 0 && board[curPosY][curPosX] != 9 && board[curPosY][curPosX] != sharkSize) {//2
			if (sharkSize > board[curPosY][curPosX]) {//2-1
				v.push_back(make_pair(curDist, make_pair(curPosX, make_pair(curPosY, board[curPosY][curPosX]))));
			}
		}
		else {//2-2
			for (int i = 0; i < 4; i++) {
				int nextDist = curDist + 1;
				int nextPosX = curPosX + dx[i];
				int nextPosY = curPosY + dy[i];
				if (nextPosX >= 0 && nextPosY >= 0 && nextPosY < n&&nextPosX < n) {
					if (!visited[nextPosY][nextPosX] && sharkSize >= board[nextPosY][nextPosX]) {
						visited[nextPosY][nextPosX] = true;
						pq.push(make_pair(nextDist, make_pair(nextPosX, nextPosY)));
					}
				}
			}
		}
	}
	sort(v.begin(), v.end());	//3
	int min = 987654;
	int idx = -1;
	for (int i = 0; i < v.size(); i++) {
		if (min > v[i].first) {//3-1
			min = v[i].first;
			idx = i;
		}
		else if (min == v[i].first) {//3-2
			if (v[i].second.second.first < v[idx].second.second.first) {
				idx = i;
			}
			else if (v[i].second.second.first == v[idx].second.second.first) {
				if (v[i].second.first < v[idx].second.first) {
					idx = i;
				}
			}
		}
	}
	if (idx != -1) {	//4
		board[startPos.second][startPos.first] = 0;	//������ġ ����⸦ �����
		startPos.first = v[idx].second.first;	//���� ������ ������ġ ����
		startPos.second = v[idx].second.second.first;
		res += v[idx].first;	//�Ÿ� �߰�
		board[startPos.second][startPos.first] = 9;//������ġ 
		return true;
	}
	else {
		return false;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
			if (board[i][j] == 9) {
				startPos.first = j;		//x��ǥ
				startPos.second = i;	//y��ǥ
			}
		}
	}
	bool flag = true;
	while (flag) {
		if (bfs() == false) {//���̻� Ž���Ұ� �����Ƿ� ����
			flag = false;
		}
		else {//5
			eat++;
			if (eat == sharkSize) {
				eat = 0;
				sharkSize++;
			}
			update();
		}
	}
	cout << res << '\n';
	return 0;
}