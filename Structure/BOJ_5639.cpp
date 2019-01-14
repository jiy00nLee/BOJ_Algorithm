#include<iostream>
#include<string>

using namespace std;
class Node {//����Ʈ��
private:
	int data;
	Node *left;	//���� �ڽ�
	Node *right;	//������ �ڽ�
public:
	Node(int data, Node*left, Node*right) {//������
		this->data = data;
		this->left = left;
		this->right = right;
	}
	void addItem(Node* node, int data) {//������ �߰�
		if (node->data==NULL) {//���� ��忡 �����Ͱ� ���ٸ� ����
			node->data = data;
		}
		else {//���� ��忡 �����Ͱ� �ִٸ� ũ�⸦ ���ؼ� ����,������ �ڽĿ� �����Ѵ�.
			if (node->data > data) {//����Ǿ� �ִ� �����ͺ��� �۴ٸ� �����ڽĿ� ����
				if (node->left == NULL) {//���� �ڽ� ��忡 �����Ͱ� �������� �ʴٸ� �����ڷ� ���� ����
					node->left = new Node(data, NULL, NULL);
				}
				else {//���� �Ѵٸ� �׳� �Ѱ��ش�
					addItem(node->left, data);
				}
			}
			else {//����Ǿ� �ִ� �����ͺ��� ũ�ٸ� ������ �ڽĿ� ����
				if (node->right == NULL) {
					node->right = new Node(data, NULL, NULL);
				}
				else {
					addItem(node->right, data);
				}
			}
		}
	}
	void printSubTree(Node* node) {//Ʈ�� ��� ���� ��ȸ �̹Ƿ� ����,������,��Ʈ ������ ����ϰڱ� ����
		if (node != nullptr) {
			printSubTree(node->left);
			printSubTree(node->right);
			cout << node->data << '\n';
		}
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	Node *tree=new Node(NULL,NULL,NULL);
	string num;
	while(getline(cin,num)){
		int n = atoi(num.c_str());
		tree->addItem(tree,n);
	}
	tree->printSubTree(tree);

	return 0;
}