#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
#define MAX 3000
bool dp[MAX][MAX];
int arr[MAX];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string str;
	cin >> str;
	int len = str.length();
	/*
	i�� ����
	���� 1�� 2�� �ʱ�ȭ��Ų��.
	arr������ �Ӹ������ �����ϴ� �ε����� ����
	*/
	//���� 1¥�� �ʱ�ȭ
	for (int i = 0; i < len; i++) {
		dp[i][i] = true;
	}	
	//���� 2¥�� �ʱ�ȭ
	for (int i = 0; i < len-1; i++) {
		if (str[i] == str[i + 1]) {
			dp[i][i+1] = true;
		}
	}
	for (int i = 2; i <= len-1; i++) {//���� 3���� �����ؼ� �ִ� ���� ���̱���
		for (int j = 0; j < len - i; j++) {//�ش� ���̸�ŭ ���ڸ� Ž��
			if (str[j] == str[j + i] && dp[j + 1][j + i - 1]) {//�ȿ� ���ڰ� �Ӹ�����̰� �յڰ� ������ �Ӹ����
				dp[j][j + i] = true;
			}
		}
	}
	//dp�� �̿��Ͽ� i��° �ε������� ���ڿ��� ���� ���� �ּҰ��� ���ϵ��� �Ѵ�.
	for (int i = 0; i < len; i++) {//���� ���ε���
		arr[i] = i+1;	//i��° �ε����� �ʱ�ȭ �۾� ���� ���� ��ŭ
		for (int j = 0; j <= i; j++) {//���� �����ε���
			if (dp[j][i]) {//�Ӹ�����̶��
				if (arr[i] > arr[j-1] + 1) {//�Ӹ�����̹Ƿ� ������ġ ���� arr���̶� +1�ؼ� �� �۴ٸ� �װ����� �ʱ�ȭ
					arr[i] = arr[j-1] + 1;
				}
			}
		}
	}
	cout << arr[len-1] << '\n';
	return 0;
}