// author: Amrit Pandey, 207907
// date: 21-06-2021
// Design a program to implement an AVL tree with the following operations (using Linked representation), on integer data

// •Insert a new node with the given key value
// •Delete a node with the given key value
// •Search for a given key in the AVL tree, and return true if found, else returns false
// •Print the tree in inorder and
// •Print the tree in level order
// Use a menu in a loop, to call the various options/operations.

#include <iostream>
using namespace std;

#define QUEUE_MAX 100

int menu()
{
	int n;
	cout << "PROGRAM: AVL IMPLEMENTATION" << endl;
	cout << "[1] insertKey" << endl;
	cout << "[2] Delete" << endl;
	cout << "[3] Print Inorder" << endl;
	cout << "[4] Print Level Order" << endl;
	cout << "[5] Search" << endl;
	cout << "[0] Exit" << endl;
	cout << "[IN] : ";
	cin >> n;
	return n;
}

struct BTNode
{
	int key;
	int height;
	struct BTNode *left;
	struct BTNode *right;
	BTNode() : key(0), height(1), left(nullptr), right(nullptr) {}
	BTNode(int k) : key(k), height(1), left(nullptr), right(nullptr) {}
	BTNode(int k, int h) : key(k), height(h), left(nullptr), right(nullptr) {}
	BTNode(int k, BTNode *left, BTNode *right) : key(k), left(left), right(right) {}
};

int max(int x, int y)
{
	return x > y ? x : y;
}

class Queue
{
private:
	int front, rear;
	BTNode *list[QUEUE_MAX];

public:
	Queue()
	{
		front = rear = -1;
	}
	BTNode *getfront();
	bool enqueue(BTNode *);
	BTNode *dequeue();
	int size();
	BTNode *peek();
	bool isEmpty();
	bool isFull();
	void printlist();
	void runwizard();
	void clean();
};

BTNode *Queue::getfront()
{
	return list[front];
}

bool Queue::enqueue(BTNode *v)
{
	if (isFull())
	{
		// cout << "ERROR: overflow, queue if full." << endl;
		return false;
	}
	if (isEmpty())
	{
		front++;
	}
	list[++rear] = v;
	return true;
}

BTNode *Queue::dequeue()
{
	if (isEmpty())
	{
		// cout << "ERROR: underflow, queue is empty." << endl;
		return NULL;
	}
	BTNode *res;
	if (front == rear)
	{
		res = list[front];
		front = rear = -1;
		return res;
	}
	return list[front++];
}

int Queue::size()
{
	if (front == rear == -1)
	{
		return 0;
	}
	return rear - front + 1;
}

BTNode *Queue::peek()
{
	if (isEmpty())
	{
		cout << "ERROR: list is empty." << endl;
		return NULL;
	}
	return list[rear];
}

bool Queue::isEmpty()
{
	return front == -1 && rear == -1;
}

bool Queue::isFull()
{
	return (rear == QUEUE_MAX - 1);
}

class AVL
{
private:
	struct BTNode *root;

public:
	AVL()
	{
		root = NULL;
	}
	int height(struct BTNode *);
	int height()
	{
		height(root);
	}
	struct BTNode *rightRotate(struct BTNode *);
	struct BTNode *leftRotate(struct BTNode *);
	int getBalance(struct BTNode *);
	struct BTNode *insertKey(struct BTNode *, int);
	struct BTNode *insertKey(int k)
	{
		insertKey(root, k);
	}
	struct BTNode *minValNode(struct BTNode *);
	struct BTNode *deleteKey(struct BTNode *, int);
	struct BTNode *deleteKey(int key)
	{
		deleteKey(root, key);
	}
	void inOrder(struct BTNode *);
	void inOrder()
	{
		inOrder(root);
	}
	void levelOrder(struct BTNode *);
	void levelOrder()
	{
		levelOrder(root);
	}
	bool search(struct BTNode *, int);
	bool search(int key)
	{
		search(root, key);
	}
	void run();
};

int AVL::height(struct BTNode *s)
{
	if (!s)
	{
		return 0;
	}
	return s->height;
}

void AVL::inOrder(struct BTNode *p)
{
	if (p)
	{
		inOrder(p->left);
		cout << p->key << " ";
		inOrder(p->right);
	}
}

void AVL::levelOrder(struct BTNode *p)
{
	if (p)
	{
		Queue q;
		BTNode *tmp;
		q.enqueue(p);
		cout << "[OUT] : ";
		while (!q.isEmpty())
		{
			tmp = q.dequeue();
			cout << tmp->key << " ";
			if (tmp->left)
			{
				q.enqueue(tmp->left);
			}
			if (tmp->right)
			{
				q.enqueue(tmp->right);
			}
		}
		cout << endl;
	}
}

struct BTNode *AVL::rightRotate(struct BTNode *p)
{
	struct BTNode *l = p->left;
	struct BTNode *lr = l->right;

	l->right = p;
	p->left = lr;

	p->height = max(height(p->left), height(p->right)) + 1;
	l->height = max(height(l->left), height(l->right)) + 1;

	return l;
}

struct BTNode *AVL::leftRotate(struct BTNode *p)
{
	struct BTNode *r = p->right;
	struct BTNode *rl = r->left;

	r->left = p;
	p->right = rl;

	p->height = max(height(p->left), height(p->right)) + 1;
	r->height = max(height(r->left), height(r->right)) + 1;

	return r;
}

int AVL::getBalance(struct BTNode *p)
{
	if (!p)
	{
		return 0;
	}
	return height(p->left) - height(p->right);
}

struct BTNode *AVL::insertKey(struct BTNode *p, int key)
{
	if (p == NULL)
	{
		return new BTNode(key);
	}

	if (key < p->key)
	{
		p->left = insertKey(p->left, key);
	}
	else if (key > p->key)
	{
		p->right = insertKey(p->right, key);
	}
	else
	{
		return p;
	}

	p->height = 1 + max(height(p->left), height(p->right));

	int bal = getBalance(p);

	if (bal > 1 && key < p->left->key)
	{
		return rightRotate(p);
	}

	if (bal < -1 && key > p->right->key)
	{
		return leftRotate(p);
	}

	if (bal > 1 && key > p->left->key)
	{
		p->left = leftRotate(p->left);
		return rightRotate(p);
	}

	if (bal < -1 && key < p->right->key)
	{
		p->right = rightRotate(p->right);
		return leftRotate(p);
	}

	return p;
}

struct BTNode *minValueNode(struct BTNode *p)
{
	struct BTNode *ptr = p;

	while (ptr->left != NULL)
	{
		ptr = ptr->left;
	}

	return ptr;
}

struct BTNode *AVL::deleteKey(struct BTNode *p, int key)
{
	if (p == NULL)
	{
		return p;
	}

	if (key < p->key)
	{
		p->left = deleteKey(p->left, key);
	}

	else if (key > p->key)
	{
		p->right = deleteKey(p->right, key);
	}

	else
	{
		if ((p->left == NULL) || (p->right == NULL))
		{
			struct BTNode *ptr = p->left ? p->left : p->right;

			if (ptr == NULL)
			{
				ptr = p;
				p = NULL;
			}
			else
			{
				*p = *ptr;
			}
			delete ptr;
		}
		else
		{
			struct BTNode *ptr = minValueNode(p->right);
			p->key = ptr->key;
			p->right = deleteKey(p->right, ptr->key);
		}
	}

	if (p == NULL)
	{
		return p;
	}

	p->height = 1 + max(height(p->left), height(p->right));

	int bal = getBalance(p);

	if (bal > 1 && getBalance(p->left) >= 0) // LL Imbalbance
	{
		return rightRotate(p);
	}

	if (bal > 1 && getBalance(p->left) < 0) // LR Imbalance
	{
		p->left = leftRotate(p->left);
		return rightRotate(p);
	}

	if (bal < -1 && getBalance(p->right) <= 0) // RR Imbalance
	{
		return leftRotate(p);
	}

	if (bal < -1 && getBalance(p->right) > 0) // RL Imbalance
	{
		p->right = rightRotate(p->right);
		return leftRotate(p);
	}

	return p;
}

bool AVL::search(struct BTNode *p, int key)
{
	if (p == NULL)
	{
		return false;
	}

	struct BTNode *t;
	t = p;

	while (t != NULL)
	{
		if (key == t->key)
		{
			return true;
		}
		else if (key < t->key)
		{
			t = t->left;
		}
		else
		{
			t = t->right;
		}
	}

	return false;
}

void AVL::run()
{
	int x, y;
	while (true)
	{
		cout << "\n\nEntries: ";
		inOrder();
		cout << "\n";
		switch (menu())
		{
		case 0:
		{
			exit(0);
		}
		case 1:
		{
			cout << "Enter key: ";
			cin >> x;
			root = insertKey(x);
			break;
		}
		case 2:
		{
			cout << "Enter key: ";
			cin >> x;
			if (!search(x))
			{
				cout << x << " was not found.\n";
			}
			else
			{
				root = deleteKey(x);
			}
			break;
		}
		case 3:
		{
			inOrder();
			break;
		}
		case 4:
		{
			levelOrder();
			break;
		}
		case 5:
		{
			cout << "Enter key: ";
			cin >> x;
			cout << x << " : ";
			search(x) ? cout << "found\n" : cout << "not found\n";
			break;
		}
		default:
		{
			break;
		}
		}
	}
}

int main()
{
	AVL t;
	t.run();
}