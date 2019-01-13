#include<iostream>
#include<cstring>
#include<cstdlib>

#define MAX 101
#define NEVER -1
#define USED 200
using namespace std;
int main() {
	int n;
	char **str = new char*[MAX];
	int arr[MAX][26];
	int groupWordCnt = 0;
	cin >> n;
		for (int i = 0; i < MAX; ++i) {
			str[i] = new char[MAX];
			memset(str[i], 0, sizeof(char)*MAX);	//�ʱ�ȭ �۾�
		}
		for (int i = 0; i < n; i++) {
			cin >> str[i];						//�ܾ� �Է¹ް�
			for (int j = 0; j < 26; j++) {	//üũ�� ���� �ʱ�ȭ
				arr[i][j] = NEVER;
			}
		}
		for (int i = 0; i < n; i++) { //Ž�� ����
			bool pass = true;
			for (int j = 0; j < strlen(str[i]); j++) {
				if (arr[i][(str[i][j] - 97)] == NEVER) {	//���ڸ� ��++���� ���ߴٸ� Used�� ǥ��
					arr[i][(str[i][j] - 97)] = USED;
				}
				else if (arr[i][(str[i][j] - 97)] == USED) {	//����� �ߴٸ�
					if (str[i][j] != str[i][j - 1]) {//���� �ܾ�� �ٸ��ٸ� �극��ũ
						pass = false;
						break;
					}
				}
			}
			if (pass) {
				groupWordCnt++;
			}
		}
		cout << groupWordCnt << endl;
		for (int i = 0; i < MAX; ++i) {
			delete[] str[i];
		}
	return 0;
}