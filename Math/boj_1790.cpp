#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<string>
using namespace std;
int N, K;
typedef long long ll;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;
	int tmp = K;
	int num = 0;
	for (int i = 0; i < 9; i++) {
		ll tmp_value = (pow(10, i)*9)*(i+1);	//�� �ڸ������� �� �ʿ��� �ڸ����� ���
		if (tmp <= tmp_value) {
			//���° �������� üũ
			int value = ceil((double)tmp / (double)(i + 1));
			num += value;
			string str_num = to_string(num);	
			if (num <= N) {
				int index = tmp % (i + 1);
				index +=i;
				cout << str_num[index%(i+1)] << '\n';
				break;
			}
			else {	// �������� ���ڰ� �ʰ��ϸ� -1�� ����Ѵ�.
				cout << -1 << '\n';
				break;
			}
		}
		else {
			tmp -= tmp_value;		  
			num += (pow(10, i) * 9); //�� �ڸ������� ���� ������ ��� ���Ѵ�
		}
	}
	return 0;
}