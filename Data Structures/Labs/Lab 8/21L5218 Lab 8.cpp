#include <iostream>


using namespace  std;

struct Node
{	

	int data;
	Node*left;
	Node *right;
	Node()
	{
		data = 0;
		left = nullptr;
		right = nullptr;
	}
	Node(int d)
	{
		data = d;
		left = nullptr;
		right = nullptr;
	}


};

class BST
{
	
	Node* root;
public:
	//Q1(a)
	BST()
	{
		root = nullptr;
	}
	//Q1 (b)
	bool insert(int d)
	{
		return insert(root, d);
	}
	bool insert(Node*& node, int d)
	{
		
		if (node == nullptr)
		{
			node = new Node(d);
			return true;
		}
		else if (node->data > d)
		{
			insert(node->left, d);
		}
		else 
			insert(node->right, d);
		return false;
	}
	//Q1(d)
	void preorderPrint() const
	{
		preorderPrint(root);
	}
	void preorderPrint(Node* node) const
	{
		if (node)
		{
			cout << node->data << endl;
			preorderPrint(node->left);
			preorderPrint(node->right);

		}
	}
	//Q1(e)
	void inorderPrint() const
	{
		inorderPrint(root);
	}
	void inorderPrint(Node* node) const
	{
		if (node)
		{
		
			inorderPrint(node->left);
			cout << node->data << endl;
			inorderPrint(node->right);

		}
	}
	//Q1(f)
	void postorderPrint() const
	{
		postorderPrint(root);
	}
	void postorderPrint(Node* node) const
	{
		if (node)
		{
			
			postorderPrint(node->left);
			postorderPrint(node->right);
			cout << node->data << endl;

		}
	}
	//Q1 (g)
	bool search(int key)
	{
		return search(root, key);
	}
	bool search(Node* node, int d)
	{

		if (node)
		{

			if (node->data>d)

				search(node->left, d);

			else if (node->data<d)

				search(node->right, d);

			else
				return true;

		}
		else
			return false;

	}
	//Q1(h)
	int length() 
	{
		return length(root);
	}
	int length(Node* node)
	{

		if (node == nullptr)
			return 0;

		else

			return length(node->left) + length(node->right) + 1;

	}

	Node* Root() const
	{
		return root;
	}
	BST(const BST& bst)
	{
		copyConstructorBST(bst.Root());

		
	}
	void copyConstructorBST(Node* node)
	{
		if (!node) return;

		insert(node->data);
		copyConstructorBST(node->left);
		copyConstructorBST(node->right);
	}

	//Q1(i)
	int leafCount() 
	{
		return leafCount(root);
	}
	int leafCount(Node* node)
	{
		if (!node)
		{
			return 0;
		}
		if (!node->left&&!node->right)
		{
			return 1;
		}
		return (leafCount(node->left) + leafCount(node->right) );
	}


	//Q1(j)
	~BST()
	{
		destroy(root);
	}
	void destroy(Node*& node)
	{
		if (node)
		{

			destroy(node->left);
			destroy(node->right);
			delete node;

		}
	}
};


int main()
{
	BST tree;
	tree.insert(500);
	tree.insert(1000);
	tree.insert(1); tree.insert(600);
	tree.insert(700);
	tree.insert(10);
	tree.insert(30);
	tree.insert(9000);
	tree.insert(50000);
	tree.insert(20);
	cout<<"Printing data using recursive inorder traversal : ";
	tree.inorderPrint();
	cout << "\nCOPY CONSTRUCTOR\n";
	BST tree1(tree);
	cout << "\n Preorder Traversal \n";
	tree1.preorderPrint();
	cout << "\n Inorder Traversal \n";
	tree1.inorderPrint();
	cout << "\n Postorder Traversal \n";
	tree1.postorderPrint();

	cout << "\nSEARCH\n";
	tree.search(1);
	tree.search(30);
	tree.search(50);

	cout <<"\nTree Length : " << tree.length() <<endl <<endl;
	cout << "\n Tree Leaf Nodes : " << tree.leafCount() << "\n";
	cout << endl;
	system(" pause");
}