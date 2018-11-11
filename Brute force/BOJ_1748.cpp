#include<iostream>
#include<math.h>
using namespace std;
typedef long long ll;
ll dp[9];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n;
	cin >> n;
	ll resTemp = n;
	//�ش� �ڸ����� �ڸ��� ������ ���ϴ� �ݺ���
	for (int i = 0; i < 9; i++) {
		ll a = pow(10, i);
		ll b = pow(10, i + 1);
		dp[i] = (b - a)*(i+1);
	}
	int idx = 0;
	//�Է¹��� �� �ڸ��� ���ϴ� �ݺ���
	while (resTemp / 10 != 0) {
		idx++;
		resTemp /= 10;
	}
	int res = 0;
	//�Է¹��� �� ���� �ڸ����� ��� ���Ѵ�.
	for (int i = 0; i < idx; i++) {
		res += dp[i];
	}

	int value = pow(10, idx);	//
	int tmp =(n-value)+1;		//
	res += (tmp*(idx + 1));
	cout << res << '\n';
	return 0;
}