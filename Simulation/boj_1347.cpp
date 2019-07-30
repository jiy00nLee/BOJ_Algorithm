#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

#define MAX 105

char board[MAX][MAX];
vector<char>cmd;
bool visited[MAX][MAX];
char res[MAX][MAX];


typedef struct {
	int x;
	int y;
	int dir;
}Info;

typedef struct {
	int x;
	int y;
}Point;


int m_xy[4][2] = { {0,-1},{1,0},{0,1},{-1,0} };
int sx, sy,dx,dy;

vector<Point> movePos;

void print() {
	sx = MAX, sy = MAX, dx = 0, dy = 0;
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			if (visited[i][j]) {	//������ġ�� ���Ѵ�.
				if (j < sx) sx = j;
				if (i < sy) sy = i;
				if (j > dx) dx = j;
				if (i > dy) dy = i;
			}
		}
	}
}

void moveFunction() {
	
	//�ʱ� ����
	Info hong = { 50,50,2 };

	for (int i = 0; i < cmd.size(); i++) {
		//��
		if (cmd[i] == 'F') {
			hong.x += m_xy[hong.dir][0];
			hong.y += m_xy[hong.dir][1];
		}
		//��
		else if (cmd[i] == 'R') {
			hong.dir++;
			if (hong.dir == 4) hong.dir = 0;
		}
		//��
		else {
			hong.dir--;
			if (hong.dir == -1) hong.dir = 3;
		}
		//�湮�� ���ߴٸ� �湮üũ�� �ϰ� ��ǥ�� �����Ѵ�.
		if (!visited[hong.y][hong.x]) 
			visited[hong.y][hong.x] = true;
		
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		char ch;
		cin >> ch;
		cmd.push_back(ch);
	}

	visited[50][50] = true;
	
	//��ɿ� ���� �̵���Ų��.
	moveFunction();
	
	//������ġ�� x,y �ִ���̸� ���Ѵ�.
	print();


	for (int i = sy; i <= dy; i++) {
		for (int j = sx; j <= dx; j++) {
			if (visited[i][j]) cout << '.';
			else cout << '#';
		}cout << '\n';
	}

	return 0;
}
