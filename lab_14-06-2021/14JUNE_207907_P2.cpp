// author: Amrit Pandey, 207907
// date: xx-xx-2021

#include <iostream>
using namespace std;

#define INT_MIN -2147483648
#define QUEUE_MAX 100

struct BTNode
{
  struct BTNode *left;
  struct BTNode *right;
  int data;
  BTNode() : data(0), left(nullptr), right(nullptr) {}
  BTNode(int x) : data(x), left(nullptr), right(nullptr) {}
  BTNode(int x, BTNode *left, BTNode *right) : data(x), left(left), right(right) {}
};

int menu();
void printTree(struct BTNode *t)
{
  if (t)
  {
    printTree(t->left);
    cout << t->data << " ";
    printTree(t->right);
  }
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

class BST
{
private:
  struct BTNode *root, *tmp;

public:
  BST()
  {
    this->root = NULL;
  }
  bool insertKey(int);
  struct BTNode *deleteKey(struct BTNode *, int);
  int height(struct BTNode *p);
  int findMax();
  int findMin();
  bool searchKey(int);
  struct BTNode *search(struct BTNode *, int);
  struct BTNode *predecessor(struct BTNode *);
  struct BTNode *successor(struct BTNode *);
  void print();
  void runWizard();
};

bool BST::insertKey(int key) // iterative function
{
  struct BTNode *t, *r, *p;
  p = new BTNode(key, NULL, NULL);

  if (root == NULL)
  {
    root = p;
    return true;
  }

  t = root;
  while (t != NULL)
  {
    r = t;
    if (key < t->data)
    {
      t = t->left;
    }
    else if (key > t->data)
    {
      t = t->right;
    }
    else
    {
      cout << "[OUT] : Insert ABORT: " << key << " was already found in tree." << endl;
      return false;
    }
  }

  if (key < r->data)
  {
    r->left = p;
  }
  else
  {
    r->right = p;
  }
  return true;
}

int BST::height(struct BTNode *p)
{
  int x, y;
  if (p == NULL)
  {
    return 0;
  }
  x = height(p->left);
  y = height(p->right);
  return x > y ? x + 1 : y + 1;
}

int BST::findMin()
{
  if (root == NULL)
  {
    cout << "[OUT] : Tree is empty." << endl;
    return INT_MIN;
  }
  struct BTNode *tmp = root;
  while (tmp->left != NULL)
  {
    tmp = tmp->left;
  }
  return tmp->data;
}

int BST::findMax()
{
  if (root == NULL)
  {
    cout << "[OUT] : Tree is empty." << endl;
    return INT_MIN;
  }
  struct BTNode *tmp = root;
  while (tmp->right != NULL)
  {
    tmp = tmp->right;
  }
  return tmp->data;
}

struct BTNode *BST::predecessor(struct BTNode *p)
{
  while (p && p->right != NULL)
  {
    p = p->right;
  }
  return p;
}

struct BTNode *BST::successor(struct BTNode *p)
{
  while (p && p->left != NULL)
  {
    p = p->left;
  }
  return p;
}

struct BTNode *BST::deleteKey(struct BTNode *p, int key)
{
  if (p == NULL)
  {
    return NULL;
  }
  if (p->left == NULL && p->right == NULL)
  {
    if (p == root)
    {
      root = NULL;
    }
    delete p;
    return p;
  }
  if (key < p->data)
  {
    p->left = deleteKey(p->left, key);
  }
  else if (key > p->data)
  {
    p->right = deleteKey(p->right, key);
  }
  else
  {
    if (height(p->left) > height(p->right))
    {
      struct BTNode *q = predecessor(p->left);
      p->data = q->data;
      p->left = deleteKey(p->left, q->data);
    }
    else
    {
      struct BTNode *q = successor(p->right);
      p->data = q->data;
      p->right = deleteKey(p->left, q->data);
    }
  }
  return p;
}

void BST::print()
{
  if (root == NULL)
  {
    cout << "[OUT] : Tree is empty." << endl;
    return;
  }

  Queue q;
  BTNode *tmp;
  q.enqueue(root);
  cout << "[OUT] : ";
  while (!q.isEmpty())
  {
    tmp = q.dequeue();
    cout << tmp->data << " ";
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

bool BST::searchKey(int key)
{
  if (root == NULL)
  {
    cout << "[OUT] : List is empty." << endl;
    return false;
  }

  struct BTNode *t;
  t = root;

  while (t != NULL)
  {
    if (key == t->data)
    {
      return true;
    }
    else if (key < t->data)
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

BTNode *BST::search(BTNode *p, int key)
{
  if (p == NULL)
  {
    return NULL;
  }

  if (key == p->data)
  {
    return p;
  }
  else if (key < p->data)
  {
    return search(p->left, key);
  }
  else
  {
    return search(p->right, key);
  }
}

void BST::runWizard()
{
  int x, y;
  while (true)
  {
    cout << endl;
    switch (menu())
    {
    case 0:
    {
      cout << "Exiting Program ... BYE" << endl;
      exit(0);
    }
    case 1:
    {
      cout << "[ENTER VALUE] : ";
      cin >> x;
      insertKey(x) ? cout << "[OUT] : " << x << " was inserted successfully!" << endl : cout << "[OUT] : Failed to insert " << x << endl;
      break;
    }
    case 2:
    {
      cout << "[ENTER KEY] : ";
      cin >> x;
      deleteKey(root, x) != NULL ? cout << "[OUT] : " << x << " was successfully removed." << endl : cout << "[OUT] : Failed to delete " << x << endl;
      break;
    }
    case 3:
    {
      x = findMin();
      if (x != INT_MIN)
      {
        cout << "[OUT] :  Minimum = " << x << endl;
      }
      break;
    }
    case 4:
    {
      x = findMax();
      if (x != INT_MIN)
      {
        cout << "[OUT] :  Maximum = " << x << endl;
      }
      break;
    }
    case 5:
    {
      cout << "[ENTER KEY] : ";
      cin >> x;
      struct BTNode *q = predecessor(search(root, x));
      if (q != NULL)
      {
        cout << "[OUT] : Predecessor of " << x << " = " << q->data << endl;
      }
      break;
    }
    case 6:
    {
      cout << "[ENTER KEY] : ";
      cin >> x;
      struct BTNode *q = successor(search(root, x));
      if (q != NULL)
      {
        cout << "[OUT] : Successor of " << x << " = " << q->data << endl;
      }
      break;
    }
    case 7:
    {
      print();
      break;
    }
    case 8:
    {
      cout << "[ENTER VALUE] : ";
      cin >> x;
      searchKey(x) ? cout << "[OUT] : " << x << " was found in the tree!" << endl : cout << "[OUT] : Cannot find " << x << endl;
      break;
    }
    default:
    {
      cout << "[OUT] : Invalid choice, try again!" << endl;
      break;
    }
    }
  }
}

int menu()
{
  int n;
  cout << "[OUT] : PROGRAM: BST IMPLEMENTATION" << endl;
  cout << "[1] Insert" << endl;
  cout << "[2] Delete" << endl;
  cout << "[3] Minimum" << endl;
  cout << "[4] Maximum" << endl;
  cout << "[5] Predecessor" << endl;
  cout << "[6] Successor" << endl;
  cout << "[7] Print" << endl;
  cout << "[8] Search" << endl;
  cout << "[0] Exit" << endl;
  cout << "[IN] : ";
  cin >> n;
  return n;
}
int main()
{
  // code goes here
  BST bst;
  bst.runWizard();
}
