#include <iostream>

using namespace std;

template <typename T>
struct Node
{
	int data;
	Node<T>* left;
	Node<T>* right;
};

template <typename T>
class Tree
{
	Node<T>* root;
	Node<T>*found;

public:
	Tree():root(NULL) {}
	~Tree()
	{
		destroy (root);
	}

	void destroy(Node<T>* node)
	{
		if (node == NULL) return;
		destroy(node->left);
		destroy(node->right);
		cout << node->data << "����" << endl;
		delete node;
	}

	Node<T>* get_root() { return root; }
	void set_root(T data)
	{
		root = new Node<T>;
		root->data = data;
	}

	void find_node(Node<T>* node, T data)
	{
		if(node == NULL)
		{
			return;
		}
		if (node->data == data)
		{
			found = node;
			return;
		}
		find_node(node->left, data);
		find_node(node->right, data);
	}

	/* p: �θ����� ������, dir: 0,1 ����, ������, data: �߰��� ������*/
	void add(T p, int dir, T data)
	{
		Node<T>* node = new Node<T>;
		node->data = data;
		found = NULL;
		find_node(root, p);
		if (found == NULL)
		{
			cout << "�˻����� (" << p << ")" << endl;
		}
		else
		{
			cout << "�˻�����: " << found->data << endl;
			if (dir == 0) found->left = node;
			else found->right = node;
		}
	}

	
	void preorder(Node<T>* node)
	{
		if (node == NULL) return;
		cout << node->data << endl;
		preorder(node->left); 
		preorder(node->right);
	}

	void inorder(Node<T>* node)
	{
		if (node == NULL) return;
		inorder(node->left);
		cout << node->data << endl;
		inorder(node->right);
	}
	
	void postorder(Node<T>* node)
	{
		if (node == NULL) return;
		postorder(node->left);
		postorder(node->right);
		cout << node->data << endl;
	}
};

/*
template <typename T>
void preorder (Node<T>* node) //���� ��ȸ
{
	if (node == NULL) return;
	cout << node->data << " ";//���� ����� ���� ���� Ž��
	preorder(node->left); //�� �Ŀ� left�� �˻�
	preorder(node->right); //�� �Ŀ� right�� �˻�
}

template <typename T>
void inorder(Node<T>* node) //���� ��ȸ
{
	if (node == NULL) return;
	inorder(node->left);
	cout << node->data << " ";
	inorder(node->right); 
}

template <typename T>
void postorder(Node<T>* node)
{
	if (node == NULL) return;
	postorder(node->left);
	postorder(node->right);
	cout << node->data << " ";
}
*/

int main()
{
	//Tree (Binary Tree ����Ʈ��) �ڷᱸ��
	//����Ʈ��: �ڽ��� ��尡 �ִ� 2���� Ʈ�� (left���� (������), right����(������))

	//����Ʈ���� ���� �ڷ��� ��ȸ�� ���� �˰����� �����Ѵ�. (�����Ͱ� ������ ġ�� �ֱ� ������ �˻�/���� �Ϸ��� �� ������ �������� �˻��ؾ��Ѵ�)
	/*
	���� ��ȸ(preorder traversal); ������ -> ���� -> ������
	���� ��ȸ(Inorder traversal): ���� -> ������ -> ������
	���� ��ȸ(Postorder traversal) ���� -> ������ -> ������
	

	Node root;	root.data = 2;
	Node n7;	n7.data = 7; root.left = &n7;

	Node n2;	n2.data = 2;	 n7.left = &n2;			n2.left = n2.right = NULL;
	Node n6;	 n6.data = 6;	 n7.right = &n6;

	Node n5;	n5.data = 5;	 n6.left = &n5;			n5.left = n5.right = NULL;
	Node n11;	n11.data = 11;	 n6.right = &n11;		n11.left = n11.right = NULL;

	Node n_5;	 n_5.data = 5;	 root.right = &n_5;		n_5.left = NULL;
	Node n9;	 n9.data = 9;	 n_5.right = &n9;		n9.right = NULL;

	Node n4;	 n4.data = 4;	 n9.left = &n4;			n4.left = n4.right = NULL;


	//preorder(&root); //���ּ�ȸ
	
	//inorder(&root);

	//postorder(&root);
	*/

	//Ŭ���� ���ø� Tree�� �����ϰ� 3���� Ž������� �Լ��� ����.
	//�߰��ϴ� �Լ��� �ۼ� (���� add(2, 0, 7) 2�� ��� ���ʿ� 7��带 �߰��϶�)

	Tree<int> tree;
	tree.set_root(11);

	tree.add(11, 0, 12);
	tree.add(12, 0, 14);
	tree.add(12, 1, 15);
	tree.add(11, 1, 13);
	tree.add(13, 0, 16);
	tree.add(16, 1, 17);
	tree.add(17, 0, 18);
	
	tree.postorder(tree.get_root());
	cout << endl;

	return 0;
}