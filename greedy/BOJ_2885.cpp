#include<iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int k;
	cin >> k;
	//ansSize : ���ݸ� �ּ�ũ�� splitCnt : ���ݸ� �ɰ��� ����
	//cnt : �Է¹��� k�� 1�� ���� temp : ���ݸ� �ּ�ũ�� �ӽ����� ���� 
	//cSize : �Է¹��� k �ӽ����� ���� oneCnt : 1�� ���� ī��Ʈ�ϴ� ����
	int ansSize = 1, splitCnt = 0, cnt = 0,temp=0,cSize=0,oneCnt=0;
	
	while (ansSize < k) {//���ݸ� �ּ� ũ�� ���ϱ�
		int i = 1;
		ansSize <<= i;
	}
	cSize = k; temp = ansSize;
	for (; k != 0; cnt++) {//1�� ���� ����
		k &= (k - 1);
	}
	//��Ʈ����
	while (cnt!=oneCnt) {
		if ((cSize&temp)!= 0)
			oneCnt++;
		splitCnt++;
		temp >>= 1;
	}
	cout << ansSize <<' '<<splitCnt-1<< '\n';
	return 0;
}