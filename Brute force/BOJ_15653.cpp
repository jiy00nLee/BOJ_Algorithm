#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;
#define MAX 11
bool check[MAX][MAX][MAX][MAX];	//���� ��ǥ	 �� , ��
char board[MAX][MAX];
int m_xy[5][2] = { {0,0}, {0,1},{0,-1},{1,0},{-1,0} };
int N, M,answer = -1;

typedef struct {
	int x;
	int y;
}Point;

Point red_ball, blue_ball;

//��ǥ �̵���Ű�� �Լ�
Point ballCalc(Point ball, int dir) {
	Point next_ball = { ball.x + m_xy[dir][0],ball.y + m_xy[dir][1] };
	if (next_ball.y < 0 || next_ball.x < 0 || next_ball.x >= M || next_ball.y >= N) return ball;
	return next_ball;
}

//�� ��� �̵���Ű�� �Լ�
Point ballMove(Point ball, int dir) {
	Point next_ball, cur_ball = ball;
	while (true) {
		next_ball = ballCalc(cur_ball, dir);
		//���� ���
		if (board[next_ball.y][next_ball.x] == '#') {
			next_ball = cur_ball;
			break;
		}
		//Ȧ�� ���
		else if (board[next_ball.y][next_ball.x] == 'O') {
			break;
		}
		//�� ���
		else {
			cur_ball = next_ball;
		}
	}
	return next_ball;
}
bool sameBallCheck(Point red, Point blue, int dir) {
	//�������� �̵��ؾߵȴٸ� true
	//�Ķ����� �̵��ؾߵȴٸ� false
	
	if (dir == 1) {
		//�Ʒ� 
		//�������� �Ʒ� �ִ�.
		if (red.y > blue.y) return false;	//�Ķ����� �̵�
		else return true;
	}
	else if (dir == 2) {
		//��
		//�������� �Ʒ� �ִ�.
		if (red.y > blue.y) return true;
		else return false;
	}
	else if (dir == 3) {
		//��
		//�������� �����ʿ� �ִ�.
		if (red.x > blue.x) return false; //�Ķ����� �̵�
		else return true;
	}
	else if (dir == 4) {
		//��
		//�������� �����ʿ� �ִ�.
		if (red.x > blue.x) return true;
		else return false;
	}
}
void bfs() {
	queue<pair<int,pair<Point,Point>>>q;		//���� ���,
	q.push(make_pair(0,make_pair(red_ball, blue_ball)));
	check[red_ball.y][red_ball.x][blue_ball.y][blue_ball.x] = 0;
	while (!q.empty()) {
		int cur_cnt = q.front().first;
		Point cur_red = q.front().second.first;
		Point cur_blue = q.front().second.second;
		q.pop();

		//����, ��� ���� �̵���Ų��..
		for (int i = 1; i <= 4; i++) {
			Point next_red = ballMove(cur_red, i);
			Point next_blue = ballMove(cur_blue, i);
			
			//�����̶� �Ķ��� ��ġ�� ���
			if (next_red.x == next_blue.x && next_red.y == next_blue.y) {
				//�Ѵ� ���ۿ� �������
				if (board[next_red.y][next_red.x] == 'O') continue;

				//�̵��� ���⿡���� ��ĭ �и��� �Ѵ�.
				if (sameBallCheck(cur_red, cur_blue, i) == false) {
					//�Ķ����� �з��ߵȴ�.
					next_blue = { next_blue.x - m_xy[i][0],next_blue.y - m_xy[i][1] };
				}
				else {
					//�������� �з��ߵȴ�.
					next_red = { next_red.x - m_xy[i][0],next_red.y - m_xy[i][1] };
				}

			}
		
				if (board[next_red.y][next_red.x] == 'O'&&board[next_blue.y][next_blue.x] == '.') {
					//�������� ������ �Ķ����� �Ⱥ������
					answer = cur_cnt + 1;
					return;
				}
				else if (board[next_red.y][next_red.x] == '.' &&board[next_blue.y][next_blue.x] == 'O') {
					//�Ķ��� ������ ������ �Ⱥ������
					continue;
				}
				else {
					//�Ѵ� �� ������ ������ üũ�ؼ� ������ �湮�ߴ����� Ȯ���Ѵ�.
					if (!check[next_red.y][next_red.x][next_blue.y][next_blue.x]) {
						//cout << next_red.x << ' ' << next_red.y << ' ' << check[cur_red.y][cur_red.x][cur_blue.y][cur_blue.x] + 1 << '\n';
						check[next_red.y][next_red.x][next_blue.y][next_blue.x] =true;
						q.push(make_pair(cur_cnt+1,make_pair(next_red, next_blue)));
					}
				}
		
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
			if (board[i][j] == 'R') {
				red_ball = { j,i };
				board[i][j] = '.';
			}
			else if (board[i][j] == 'B') {
				blue_ball = { j,i };
				board[i][j] = '.';
			}

		}
	}
	bfs();
	cout << answer << '\n';

	return 0;
}