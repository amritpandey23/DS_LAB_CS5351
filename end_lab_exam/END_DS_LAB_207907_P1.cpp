// author: Amrit Pandey, 207907
// date: 08/07/2021
// MCA II SEM Data Structure END LAB Exam

#include <iostream>
using namespace std;

#define QUEUE_MAX 100

int menu()
{
    int n;
    cout << endl;
    cout << "[1] Insert" << endl;
    cout << "[2] Print" << endl;
    cout << "[3] Get Depth" << endl;
    cout << "[4] Get Leaf Count" << endl;
    cout << "[5] Get Size" << endl;
    cout << "[0] Exit" << endl;
    cout << "[IN] : ";
    cin >> n;
    return n;
}

struct node
{
    int data;
    struct node *lptr;
    struct node *rptr;
};

std::ostream &operator<<(std::ostream &os, node const &m)
{
    return os << m.data;
}

template <class T>
class Queue
{
private:
    int front, rear;
    T que[QUEUE_MAX];

public:
    Queue()
    {
        front = rear = -1;
    }
    T getfront();
    int length();
    T peek();
    bool enqueue(T);
    T dequeue();
    bool isEmpty();
    bool isFull();
    void print();
};

template <class T>
T Queue<T>::getfront()
{
    return que[front];
}

template <class T>
bool Queue<T>::enqueue(T v)
{
    if (isFull())
    {
        return false;
    }

    if (isEmpty())
    {
        front++;
    }

    que[++rear] = v;
    return true;
}

template <class T>
T Queue<T>::dequeue()
{
    if (isEmpty())
    {
        return NULL;
    }

    T res;
    if (front == rear)
    {
        res = que[front];
        front = rear = -1;
        return res;
    }

    return que[front++];
}

template <class T>
int Queue<T>::length()
{
    if (front == rear == -1)
    {
        return 0;
    }

    return rear - front + 1;
}

template <class T>
T Queue<T>::peek()
{
    if (isEmpty())
    {
        return NULL;
    }

    return que[rear];
}

template <class T>
bool Queue<T>::isEmpty()
{
    return front == -1 && rear == -1;
}

template <class T>
bool Queue<T>::isFull()
{
    return (rear == QUEUE_MAX - 1);
}

template <class T>
void Queue<T>::print()
{
    if (isEmpty())
    {
        return;
    }

    for (int i = front; i <= rear; i++)
    {
        cout << *que[i] << " ";
    }
}

class BST
{
private:
    struct node *root;

public:
    BST()
    {
        this->root = NULL;
    }
    struct node *createNewNode(int, struct node *, struct node *);
    struct node *createNewNode(int);
    bool insert(int);                                               // Insert
    void print();                                                   // Print
    int getDepth(struct node *);                                    // getDepth
    int getLeafCount(struct node *);                                // getLeafCount
    int getSize(struct node *);                                     // getSize
    struct node *search(struct node *, int);
    struct node *search(int);
    void runWizard();
};

struct node *BST::createNewNode(int k, struct node *lptr, struct node *rptr)
{
    struct node *e = new struct node;
    e->data = k;
    e->lptr = lptr;
    e->rptr = rptr;
    return e;
}

struct node *BST::createNewNode(int k)
{
    return createNewNode(k, NULL, NULL);
}

bool BST::insert(int key)
{
    struct node *t, *r, *p;
    p = createNewNode(key);

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
            t = t->lptr;
        }
        else if (key > t->data)
        {
            t = t->rptr;
        }
        else
        {
            cout << "[OUT] : Insert ABORT: " << key << " was already found in tree." << endl;
            return false;
        }
    }

    if (key < r->data)
    {
        r->lptr = p;
    }
    else
    {
        r->rptr = p;
    }
    return true;
}

void BST::print()
{
    if (root == NULL)
    {
        cout << "[OUT] : Tree is empty." << endl;
        return;
    }

    Queue<struct node *> q;
    node *tmp;
    q.enqueue(root);
    cout << "[PRINT] : ";
    while (!q.isEmpty())
    {
        tmp = q.dequeue();
        cout << *tmp << " ";
        if (tmp->lptr)
        {
            q.enqueue(tmp->lptr);
        }
        if (tmp->rptr)
        {
            q.enqueue(tmp->rptr);
        }
    }
    cout << endl;
}

int BST::getDepth(struct node *p)
{
    int x, y;
    if (p == NULL)
    {
        return 0;
    }
    x = getDepth(p->lptr);
    y = getDepth(p->rptr);
    return x > y ? x + 1 : y + 1;
}

int BST::getLeafCount(struct node *p)
{
    if (p == NULL)
    {
        return 0;
    }
    if (p->lptr == NULL && p->rptr == NULL)
    {
        return 1;
    }
    else
    {
        return getLeafCount(p->lptr) + getLeafCount(p->rptr);
    }
}

int BST::getSize(struct node *p)
{
    if (p == NULL)
    {
        return 0;
    }
    else
    {
        return 1 + getSize(p->lptr) + getSize(p->rptr);
    }
}

node *BST::search(node *p, int key)
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
        return search(p->lptr, key);
    }
    else
    {
        return search(p->rptr, key);
    }
}

struct node *BST::search(int key)
{
    return search(root, key);
}

void BST::runWizard()
{
    int x, y;
    struct node *tmp;
    while (true)
    {
        switch (menu())
        {
        case 0:
        {
            exit(0);
        }
        case 1:
        {
            cout << "[Enter Value] : ";
            cin >> x;
            cout << "[OUT] : ";
            insert(x) ? cout << x << " was inserted successfully!" : cout << "Failed to insert " << x;
            cout << endl;
            break;
        }
        case 2:
        {
            print();
            break;
        }
        case 3:
        {
            cout << "[Enter key value] : ";
            cin >> x;
            tmp = search(x);
            if (tmp == NULL)
            {
                cout << "[OUT] : Node with value " << x << " was not found!" << endl;
            }
            else
            {
                y = getDepth(tmp);
                cout << "[OUT] : Depth of " << x << " = " << y << endl;
            }
            break;
        }
        case 4:
        {
            cout << "[Enter key value] : ";
            cin >> x;
            tmp = search(x);
            if (tmp == NULL)
            {
                cout << "[OUT] : Key with value " << x << " was not found!" << endl;
            }
            else
            {
                y = getLeafCount(tmp);
                cout << "[OUT] : Total leaf of node with value " << x << " = " << y << endl;
            }
            break;
        }
        case 5:
        {
            cout << "[Enter key value] : ";
            cin >> x;
            tmp = search(x);
            if (tmp == NULL)
            {
                cout << "[OUT] : Key with value " << x << " was not found!" << endl; 
            }
            else
            {
                y = getSize(tmp);
                cout << "[OUT] : Size of tree with Node of value " << x << " = " << y << endl;
            }
            break;
        }
        default:
        {
            cout << "[OUT] : Invalid operation! Try again." << endl;
            break;
        }
        }
    }
}

int main()
{
    BST bst;
    bst.runWizard();
}
