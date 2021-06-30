// author: Amrit Pandey, 207907
// date: 28-06-2021
// L8.2 Implement hashing using Open addressing method (with Quadratic probing).

#include <iostream>
#include <limits.h>
using namespace std;

int menu()
{
    int r;
    cout << "[1] Insert\n";
    cout << "[2] Search\n";
    cout << "[3] Print\n";
    cout << "[0] Exit\n";
    cout << "YOUR CHOICE >>> ";
    cin >> r;
    return r;
}

class HashTable
{
private:
    int *table;
    int n;

public:
    HashTable(int n)
    {
        this->n = n;
        this->table = new int[n];
        for (int i = 0; i < n; i++)
        {
            this->table[i] = INT_MIN;
        }
    }

    int hash(int k)
    {
        return k % n;
    }

    int probe(int k)
    {
        int idx = hash(k);
        int i = 0;
        while (table[(idx + i * i) % n] != INT_MIN)
        {
            i++;
        }
        return (idx + i * i) % n;
    }

    void insert(int k)
    {
        int idx = hash(k);
        if (table[idx] != INT_MIN)
        {
            idx = probe(k);
        }
        table[idx] = k;
    }

    int search(int k)
    {
        int ctr = 0;
        int idx = hash(k);
        int i = 0;
        while (table[(idx + i * i) % n] != k && ctr <= n)
        {
            i++;
            ctr++;
        }
        return table[(idx + i * i) % n] == INT_MIN ? INT_MIN : (idx + i * i) % n;
    }

    void printTable()
    {
        for (int i = 0; i < n; i++)
        {
            cout << i << " : " << table[i] << endl;
        }
    }

    ~HashTable()
    {
        delete table;
    }
};

void wizard()
{
    int s, t;
    cout << "How many elements you want to store? : ";
    cin >> s;
    if (s <= 0)
    {
        cout << "[OUT] : Invalid Size!\n";
        return;
    }
    HashTable ht(s * 2);

    while (true)
    {
        cout << endl;
        switch (menu())
        {
        case 1:
        {
            cout << "Enter value: ";
            cin >> t;
            ht.insert(t);
            break;
        }
        case 2:
        {
            cout << "Enter key: ";
            cin >> t;
            int idx = ht.search(t);
            cout << "[OUT] : ";
            idx == INT_MIN ? cout << t << " not found.\n" : cout << idx << "\n";
            break;
        }
        case 3:
        {
            ht.printTable();
            break;
        }
        case 0:
        {
            exit(0);
        }
        default:
        {
            cout << "[OUT] :: ";
            cout << "Invalid Choice, try again.\n";
            break;
        }
        }
    }
}

int main()
{
    wizard();
    return 0;
}
