#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
using namespace std;

int A, B, C, D, E;	//���� �µ�, ��ǥ �µ�, ��� �ִ� ��� 1�� ����µ� C , ��� �ִ� ��� �ص��ϴ� �� �ɸ��� �ð� D, ��� ���� ���� ��⸦ 1�� ����µ� E
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> A >> B >> C >> D >> E;
	
	int time = 0;
	
	while (A != B) {
		if (A < 0) {
			time += C;
			A += 1;
		}
		else if (A == 0) {
			time += (D+E);
			A += 1;
		}
		else {
			time += E;
			A += 1;
		}
	}
	cout << time << '\n';
	
	return 0;
}