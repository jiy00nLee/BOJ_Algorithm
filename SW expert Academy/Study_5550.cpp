#include<iostream>
#include<string>
#include<string.h>
#include<algorithm>
#define MAX 501
#define INF 98765432
using namespace std;
int res;
int flogs[MAX];
int numCalc(char ch) {
	if (ch == 'c') return 0;
	else if (ch == 'r') return 1;
	else if (ch == 'o') return 2;
	else if (ch == 'a') return 3;
	else if (ch == 'k') return 4;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int test_case;
	int T;
	cin >> T;
	for (test_case = 1;res!=-1, test_case <= T; ++test_case)
	{
		memset(flogs, 0, sizeof(flogs));
		string str;
		res = 0;
		cin >> str;
		for (int i = 0;i < str.length(); i++) {
			int charNum = numCalc(str[i]);
			int cnt = 0;
			for(int idx=0;idx<MAX;idx++){
				int& ret = flogs[idx];
				if(charNum==0&&ret==0){
					ret |= (1 << charNum);
					cnt++;
					res = max(res, cnt);
					break;
				}
				else if (charNum ==0  && ret!=31) {
					cnt++;
				}
				else if (charNum == 0 && ret == 31) {
					cnt = 0;
					continue;
				}
				else if (charNum!=0&&((ret&(1 << charNum)) == 0)) {//���� ���ڸ��� ����ִ��� üũ
					if (ret == ((1 << charNum) - 1)) {//�������ڰ� �����ִ��� üũ
						ret |= (1 << charNum);
						break;
					}
					else {//��ä�����ִµ� ���ڸ��� ����ִٸ� �̻��Ѱ��̹Ƿ� 
						res = INF;
						break;
					}
				}
				else {//���� ���ڸ��� ������� �ʴٸ�
					continue;
				}
			}
			if (res == INF) {
				res = -1;
				break;
			}
		}
		for (int i = 0; i < MAX; i++) {// ����� ������ ������
			if (flogs[i] != 0 && flogs[i] != 31) {
				res = -1;
				break;
			}
		}
		cout << "#" << test_case << ' ' << res << '\n';
	}
	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}
