#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<string>
int alphaCnt[26];
using namespace std;
typedef pair<int, char> pic;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string str;
	//char������ 5000���ڸ� ������ �����÷ο�߻��Ѵ�...
	while (getline(cin,str)) {
		int len = str.length();
		for (int i = 0; i < len; i++) {
			alphaCnt[str[i] - 97]++;
		}
	}
	vector<pic>v;//�������ϰ�츦 ����ؼ� ���Ϳ� �����Ѵ�.
	char ch = 'a';
	int max = 0;
	for (int i = 0; i < 26; i++) {
		if (max < alphaCnt[i])
			max = alphaCnt[i];
		v.push_back(make_pair(alphaCnt[i], ch));
		ch++;
	}
	for (int i = 0; i < v.size(); i++) {
		if (max == v[i].first)
			cout << v[i].second;
	}
	return 0;
}