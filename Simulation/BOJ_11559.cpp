#include<iostream>
#include<string.h>
#include<algorithm>
#include<stdlib.h>
#include<string>
#include<queue>
using namespace std;
#define WIDTH 6
#define HEIGHT 12
string map[HEIGHT];
bool visited[HEIGHT][WIDTH];		
int cnt;
typedef pair<int, int> pii;		//y ,x
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,-1,1 };

bool bfs() {
	queue<pii>q;
	bool chainBoom = false;
	for (int i = 0; i < HEIGHT; i++){
		for (int j = 0; j < WIDTH; j++) {
			// i , j �� ��ǥ�� ���ڰ� �������� üũ 
			bool charCheck = (map[i][j] == 'R') || (map[i][j] == 'P') || (map[i][j] == 'Y') || (map[i][j] == 'B') || (map[i][j] == 'G');
			if (charCheck&&!visited[i][j]) {//�����̰� �湮�� ���ߴٸ� ť�� �߰��Ѵ�.
				vector<pii>boom;
				int charCnt = 0;	//�湮�� ���ڿ��� ī�����ϴ� ����
				q.push(make_pair(i, j));
				while (!q.empty()) {
					//ť �Ǿտ� ��ǥ�� ������.
					int currentY = q.front().first;	
					int currentX = q.front().second;
					char currentChar = map[currentY][currentX];	//ť �Ǿտ� ��ǥ�� ���� ����
					boom.push_back(make_pair(currentY, currentX));	//��Ʈ�� ���ڿ� ��ǥ�� ���Ϳ� ����
					charCnt++;	
					visited[currentY][currentX] = true;		//�湮üũ
					q.pop();
					for (int i = 0; i < 4; i++) {	//�̵� ������ 4������ Ž��
						int nextY = currentY + dy[i];
						int nextX = currentX + dx[i];
						//���� ��ǥ�� �� �����ȿ� �ִ��� üũ
						bool range = (nextY >= 0) && (nextY < HEIGHT) && (nextX >= 0) && (nextX < WIDTH);
						//�ʾȿ� �ְ�, ���� ��ǥ ���ڶ� ���� ��ǥ ���ڰ� ���� �湮�� ���� ��ǥ��� ť�� �ִ´�.
						if (range&&currentChar == map[nextY][nextX] && !visited[nextY][nextX]) {
							q.push(make_pair(nextY, nextX));
						}
					}
				}
				if (charCnt >= 4) {
					for (int i = 0; i < boom.size(); i++) {
						map[boom[i].first][boom[i].second] = '.';		//��Ʈ���� ��ĭ���� �ٲ۴�.
					}
					chainBoom = true;
				}
			}
		}
	}
	return chainBoom ? true : false;		//4���̻� ��Ʈ���� �ִٸ� true ���ٸ� false
}
void update() {
	for (int i = 0; i < WIDTH; i++) {
		int emptyCnt = 0;
		for (int j = HEIGHT - 1; j >= 0; j--) {	//y����� �̵�
			if (map[j][i] == '.')		//����ִٸ� ī��Ʈ
				emptyCnt++;
			else {
				map[j + emptyCnt][i] = map[j][i];
				if(emptyCnt!=0)	//����ִ�ĭ�� 0�̾ƴ϶��  �� ��ġ�� �����.
					map[j][i] = '.';
			}
		}
	}
	//�湮 �ʱ�ȭ
	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++) {
			visited[i][j] = false;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 0; i < 12; i++) {
		cin >> map[i];
	}
	memset(visited, false, sizeof(visited));


	while (bfs()) {
		update();//��� ��ġ �̵��� �湮 �ʱ�ȭ�� ����ߵȴ�.
		cnt++;	//���� Ƚ�� ī��Ʈ
	}
	cout << cnt << '\n';
	return 0;
}