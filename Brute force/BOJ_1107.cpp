#include<iostream>
#include<math.h>
#include<vector>
using namespace std;
#define MAX 1000000
int currentCh = 100,breackCnt,targetCh,min;
bool breakCh[10];
bool checkFunc(int num) {
	while (num / 10 != 0) {
		if (breakCh[num % 10] == true) {
			return false;
		}
		num /= 10;
	}
	if (breakCh[num % 10] == true)
		return false;
	else
		return true;
}
int cmdCountFunc(int num) {
	int cnt = 1;
	while ((num / 10) != 0) {
		cnt++;
		num /= 10;
	}
	return cnt;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> targetCh >> breackCnt;
	for (int i = 0; i < breackCnt; i++)
	{
		int n;
		cin >> n;
		breakCh[n] = true;
	}
	min = abs(targetCh - currentCh);//+ - �� �̵��� Ƚ��
	for (int i = 0; i <= MAX; i++) {
		if (checkFunc(i)) {//���峭 ��ư��� ������� �������� üũ�ϴ� �Լ�
			int currentCmd = cmdCountFunc(i);//���� i�� ��� �������� ī�����Լ�
			currentCmd += abs(targetCh - i);
			if (min > currentCmd)
				min = currentCmd;
		}
	}
	cout << min << '\n';
	return 0;
}