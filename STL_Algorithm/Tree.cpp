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
		cout << node->data << "제거" << endl;
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

	/* p: 부모노드의 데이터, dir: 0,1 왼쪽, 오른쪽, data: 추가할 데이터*/
	void add(T p, int dir, T data)
	{
		Node<T>* node = new Node<T>;
		node->data = data;
		found = NULL;
		find_node(root, p);
		if (found == NULL)
		{
			cout << "검색실패 (" << p << ")" << endl;
		}
		else
		{
			cout << "검색성공: " << found->data << endl;
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
void preorder (Node<T>* node) //전휘 순회
{
	if (node == NULL) return;
	cout << node->data << " ";//현재 노드의 값을 먼저 탐색
	preorder(node->left); //그 후에 left를 검사
	preorder(node->right); //그 후에 right를 검사
}

template <typename T>
void inorder(Node<T>* node) //전휘 순회
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
	//Tree (Binary Tree 이진트리) 자료구조
	//이진트리: 자식의 노드가 최대 2개인 트리 (left가지 (포인터), right가지(포인터))

	//이진트리가 가진 자료의 순회를 위한 알고리즘이 존재한다. (데이터가 가지를 치고 있기 때문에 검색/삭제 하려면 각 가지를 빠짐없이 검사해야한다)
	/*
	전위 순회(preorder traversal); 현재노드 -> 왼쪽 -> 오른쪽
	중위 순회(Inorder traversal): 왼쪽 -> 현재노드 -> 오른쪽
	후위 순회(Postorder traversal) 왼쪽 -> 오른쪽 -> 현재노드
	

	Node root;	root.data = 2;
	Node n7;	n7.data = 7; root.left = &n7;

	Node n2;	n2.data = 2;	 n7.left = &n2;			n2.left = n2.right = NULL;
	Node n6;	 n6.data = 6;	 n7.right = &n6;

	Node n5;	n5.data = 5;	 n6.left = &n5;			n5.left = n5.right = NULL;
	Node n11;	n11.data = 11;	 n6.right = &n11;		n11.left = n11.right = NULL;

	Node n_5;	 n_5.data = 5;	 root.right = &n_5;		n_5.left = NULL;
	Node n9;	 n9.data = 9;	 n_5.right = &n9;		n9.right = NULL;

	Node n4;	 n4.data = 4;	 n9.left = &n4;			n4.left = n4.right = NULL;


	//preorder(&root); //전휘순회
	
	//inorder(&root);

	//postorder(&root);
	*/

	//클래스 템플릿 Tree를 정의하고 3가지 탐색기능의 함수를 선언.
	//추가하는 함수도 작성 (예시 add(2, 0, 7) 2번 노드 왼쪽에 7노드를 추가하라)

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