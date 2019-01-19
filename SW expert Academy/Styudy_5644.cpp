#include<iostream>
#include<queue>
#include<algorithm>
#include<string.h>
#include<string>
#include<vector>
using namespace std;
#define MAX 11
#define OVERLAP 10
#define EMPTY 0
int board[MAX][MAX];				//�ش� �ʿ� ������ ǥ�� x,y,bcs �ε���
bool visited[MAX][MAX];				//�� ������Ʈ�Ҷ� ���
int overlapBoard[MAX][MAX][9];		//�������� �ʿ� �ε��� ����
int dx[5] = { 0,0,1,0,-1 };
int dy[5] = { 0,-1,0,1,0 };
typedef pair<int,pair<int,pair<int,int>>>piiii;	//x,y,���� ����,ó����
typedef pair<int, pair<int, int>>piii;			//x,y,�̵�Ƚ��

//�ʱ�ȭ �Լ�
void init() {
	memset(board, 0, sizeof(board));
	memset(visited, false, sizeof(visited));
	memset(overlapBoard, 0, sizeof(overlapBoard));
}
//�Ѵ� �������ΰ��
int twoOverlap(int aStartX, int aStartY, int bStartX, int bStartY, vector<piiii>bcs) {
	int tmp = 0;
	for (int i = 0; i < 9; i++) {
		if (overlapBoard[aStartY][aStartX][i] != 0) {
			for (int j = 0; j < 9; j++) {
				int sumRes = 0;
				if (overlapBoard[bStartY][bStartX][j] != 0) {
					if (i == j) sumRes = bcs[i].second.second.second;
					else sumRes = bcs[i].second.second.second + bcs[j].second.second.second;
					tmp = max(tmp, sumRes);
				}
			}
		}
	}
	return tmp;
}
//���ʸ� �������ΰ��
int oneOverlap(int aStartX, int aStartY, int bStartX, int bStartY, vector<piiii>bcs) {
	int tmp = 0;
	if (board[aStartY][aStartX] == OVERLAP) {//a�� �������ΰ��
		for (int i = 1; i < 9; i++) {
			int sumRes = 0;
			if (overlapBoard[aStartY][aStartX][i] != 0) {
				if (i == board[bStartY][bStartX]) sumRes = bcs[i].second.second.second;
				else	sumRes = bcs[i].second.second.second + bcs[board[bStartY][bStartX]].second.second.second;
				tmp = max(tmp, sumRes);
			}
		}
	}
	else {//b�� �������ΰ��
		for (int i = 1; i < 9; i++) {
			int sumRes = 0;
			if (overlapBoard[bStartY][bStartX][i] != 0) {
				if (i == board[aStartY][aStartX]) sumRes = bcs[i].second.second.second;
				else sumRes = bcs[i].second.second.second + bcs[board[aStartY][aStartX]].second.second.second;
				tmp = max(tmp, sumRes);
			}
		}
	}
	return tmp;
}
//�Ѵ� �������� �ƴ� ���
int notOverlap(int aStartX, int aStartY, int bStartX, int bStartY, vector<piiii>bcs) {
	if (board[aStartY][aStartX] == board[bStartY][bStartX]) return bcs[board[aStartY][aStartX]].second.second.second;
	else return bcs[board[aStartY][aStartX]].second.second.second + bcs[board[bStartY][bStartX]].second.second.second;
}
int dfs(vector<int>aMoves,vector<int>bMoves,vector<piiii>bcs) {
	int ans=0,nextAPosX = 1, nextAPosY = 1, nextBPosX = 10, nextBPosY = 10;
	//������ġ ���� ����
	if (board[1][1] != OVERLAP && board[10][10] != OVERLAP)//�Ѵ� �������̾ƴѰ��
		ans = notOverlap(1, 1, 10, 10, bcs);

	else if ((board[1][1] == OVERLAP && board[10][10] != OVERLAP)|| (board[1][1] != OVERLAP && board[10][10] == OVERLAP))
		ans = oneOverlap(1, 1, 10, 10, bcs);

	else //�Ѵ� �������ΰ��
		ans=twoOverlap(1, 1, 10, 10, bcs);

	for (int i = 0; i < aMoves.size(); i++) {
		nextAPosX = nextAPosX+ dx[aMoves[i]];
		nextAPosY = nextAPosY + dy[aMoves[i]];
		nextBPosX = nextBPosX + dx[bMoves[i]];
		nextBPosY = nextBPosY + dy[bMoves[i]];
		if (board[nextAPosY][nextAPosX] ==OVERLAP&& board[nextBPosY][nextBPosX]==OVERLAP) //�Ѵ� ���������ִ°��
			ans += twoOverlap(nextAPosX, nextAPosY, nextBPosX, nextBPosY, bcs);
		
		else if (board[nextAPosY][nextAPosX] == OVERLAP || board[nextBPosY][nextBPosX] == OVERLAP) //���� �ϳ� ������ ���ִ� ���
			ans += oneOverlap(nextAPosX, nextAPosY, nextBPosX, nextBPosY, bcs);

		else 	//�� ���ǿ� �ش���� �ʴ´ٸ� ���Ѵ�.
			ans += notOverlap(nextAPosX, nextAPosY, nextBPosX, nextBPosY, bcs);
	}
	return ans;
}
//�ʿ� ���� ǥ���ϴ� �Լ�
void mapUpdate( vector<piiii>bcs) {
	int aStartX = 1, aStartY = 1, bStartX = 1, bStartY = 1;
	for (int i = 1; i < bcs.size(); i++)
	{
		memset(visited, false, sizeof(visited));
		queue<piii>q; //���� ��ǥ x,y,�̵�Ƚ�� 
		int startPosX = bcs[i].first;
		int startPosY = bcs[i].second.first;
		int startMove = bcs[i].second.second.first;
		int startP = bcs[i].second.second.second;
		visited[startPosY][startPosX] = true;
		if (board[startPosY][startPosX] == EMPTY) {//����ִٸ� ���� bcs��ȣ�� ǥ��
			board[startPosY][startPosX] = i;
		}
		else {//�ٸ� ������ �� �ִ°�� ���������� ǥ��
			if(board[startPosY][startPosX]!=OVERLAP)	overlapBoard[startPosY][startPosX][board[startPosY][startPosX]] = board[startPosY][startPosX];
			board[startPosY][startPosX] = OVERLAP;
			overlapBoard[startPosY][startPosX][i] = i;
		}
		q.push(make_pair(startPosX, make_pair(startPosY, 0)));
		while (!q.empty()) {
			int curPosX = q.front().first;
			int curPosY = q.front().second.first;
			int curMoveCnt = q.front().second.second;
			if (curMoveCnt == startMove) {
				break;
			}
			q.pop();
			for (int dir = 0; dir < 5; dir++) {
				int nextPosX = curPosX + dx[dir];
				int nextPosY = curPosY + dy[dir];
				if (nextPosX >= 1 && nextPosY >= 1 && nextPosX <= 10 && nextPosY <= 10) {
					if (!visited[nextPosY][nextPosX]) {
						visited[nextPosY][nextPosX] = true;
						if (board[nextPosY][nextPosX] == EMPTY) {//����ִٸ� ���� bcs��ȣ�� ǥ��
							board[nextPosY][nextPosX] = i;
						}
						else {//�ٸ� ������ �� �ִ°�� ���������� ǥ��
							if(board[nextPosY][nextPosX]!=OVERLAP)	overlapBoard[nextPosY][nextPosX][board[nextPosY][nextPosX]] = board[nextPosY][nextPosX];
							board[nextPosY][nextPosX] = OVERLAP;
							overlapBoard[nextPosY][nextPosX][i] = i;
						}
						q.push(make_pair(nextPosX, make_pair(nextPosY, curMoveCnt + 1)));
					}
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int testCase;
	cin >> testCase;
	for (int tc = 1; tc <= testCase; tc++) {
		int m, a;
		cin >> m >> a;
		init();
		vector<int>aMoves, bMoves;
		vector<piiii>bcs;
		for (int i = 0; i < m; i++) {
			int moveNum;
			cin >> moveNum;
			aMoves.push_back(moveNum);
		}
		for (int i = 0; i < m; i++) {
			int moveNum;
			cin >> moveNum;
			bMoves.push_back(moveNum);
		}
		bcs.push_back(make_pair(0, make_pair(0, make_pair(0, 0))));
		for (int i = 0; i < a; i++) {
			int x, y, c, p;
			cin >> x >> y >> c >> p;
			bcs.push_back(make_pair(x, make_pair(y, make_pair(c, p))));
		}
		mapUpdate(bcs);
		cout << '#' << tc << ' ' << dfs(aMoves, bMoves, bcs) << '\n';
	}
	return 0;
}
