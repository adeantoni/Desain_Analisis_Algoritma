#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Node
{
    public:
        int data;
        Node* left;
        Node* right;

        Node(int value)
        {
            data = value;
            left = NULL;
            right = NULL;
        }
};

class Tree
{
    private:
        Node* root;
        int mode;

        Node* insert(Node* root, int value)
        {
            if (root == NULL)
            {
                root = new Node(value);
            }

            else if (value <= root -> data)
            {
                root -> left = insert(root -> left, value);
            }
            else
            {
                root -> right = insert(root -> right, value);
            }

            return root;
        }

        void preOrder()
        {
            preOrder(root);
        }

        void inOrder()
        {
            inOrder(root);
        }

        void postOrder()
        {
            postOrder(root);
        }

        // -------------------------------------------------------------------------------------------
        // section logika untuk print berdasarkan algoritma traversal

        void preOrder(Node* root)
        {
            if(root == NULL)
            {
                return;
            }
            cout << root -> data << ' ';
            preOrder(root -> left);
            preOrder(root -> right);
        }

        void inOrder(Node* root)
        {
            if(root == NULL)
            {
                return;
            }

            inOrder(root -> left);
            cout << root -> data << ' ';
            inOrder(root -> right);
        }

        void postOrder(Node* root)
        {
            if(root == NULL)
            {
                return;
            }

            postOrder(root -> left);
            postOrder(root -> right);
            cout << root -> data << ' ';
        }
        // -------------------------------------------------------------------------------------------

    public:
        Tree()
        {
            root = NULL;
        }

        void insert(int value)
        {
            root = insert(root, value);
        }

        void printTree(int mode)
        {
            if (mode == 1)
            {
                preOrder(root);
                cout << endl;
            }

            else if (mode == 2)
            {
                inOrder(root);
                cout << endl;
            }
            
            else
            {
                postOrder();
                cout << endl;
            }
        }
};

int main()
{
    Tree tree;

    tree.insert(32);
    tree.insert(12);
    tree.insert(20);
    tree.insert(16);
    tree.insert(24);

    int mode;
    vector<int> availableModes = {1, 2, 3};

    userOption:
    cout << "Masukkan mode untuk input tree:\n"
            << "(1) Pre-order\n"
            << "(2) In-order\n"
            << "(3) Post-order\n";
    cin >> mode;
    
    if (find(availableModes.begin(), availableModes.end(), mode) == availableModes.end())
    {
        cout << "Mode invalid, silahkan masukkan angka yang tersedia.\n";
        goto userOption;
    }   

    tree.printTree(mode);
    cout << endl;
    
    goto userOption;
    return 0;
}