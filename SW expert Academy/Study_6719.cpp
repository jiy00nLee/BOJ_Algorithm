#include<iostream>
#include<math.h>
#include<vector>
#include<algorithm>
using namespace std;
bool cmp(double a, double b) {
	return (a > b) ? true : false;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout << fixed;	//�Ҽ����� ������Ų��.
	cout.setf(ios::showpoint);	//���� 0���� ǥ��
	cin.precision(6);	//n��e������ ǥ��
	int testCase;
	cin >> testCase;
	for (int tc = 1; tc <= testCase; tc++) {
		vector<double>v;
		int n, k;
		cin >> n >> k;
		for (int i = 0; i < n; i++) {
			double num;
			cin >> num;
			v.push_back(num);
		}
		sort(v.begin(), v.end(),cmp);
		double res = 0.0;
		for (int j = k - 1; j >= 0; j--) {
			res = (res + v[j]) / 2;
		}
		cout << '#' << tc << ' ' <<res<< '\n';
	}
	return 0;
}