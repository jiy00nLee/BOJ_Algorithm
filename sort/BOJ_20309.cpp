#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define MAX 300002
vector<pair<int, int>> arr;	//��, �ε���
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	for (int i = 0;i < N;i++) {
		int num;
		cin >> num;
		arr.push_back({ num,i });
	}
	sort(arr.begin(), arr.end());
	bool succ = true;
	for (int i = 0;i < N;i++) {
		int index = arr[i].second;
		//¦��
		if (i % 2 == 0&& index % 2 !=0) {
			succ = false;
			break;
		}
		//Ȧ��
		else if (i % 2 == 1 && index % 2 != 1) {
			succ = false;
			break;
		}
	}
	
	if (succ) cout << "YES\n";
	else cout << "NO\n";

	return 0;
}