#include<iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int r, b;
	cin >> r >> b;
	for (int i = 1; i < 5000; i++) {
		for (int j = 1; j < 5000; j++) {
			int res = (i * 2) + (j * 2 - 4);		//���� ���� ���ϱ�
			if (res > r) {
				break;
			}
			else if (res == r) {	//���� ������ res ������ ���ٸ�
				int tmp = (i - 2)*(j - 2);		//���� ���� ���ϱ�
				if (tmp == b) {
					if (i > j) {		// ū ���� L�� �ǵ��� ����
						cout << i << ' ' << j << '\n';
						return 0;
					}
					else {
						cout << j << ' ' << i << '\n';
						return 0;
					}
				}
			}
		}
	}

	return 0;
}