#include <iostream>
using namespace std;

// Node structure
struct Node
{
    int data;
    Node *left;
    Node *right;
};

// Create Node
Node* CreateNode(int value)
{
    Node* newNode = new Node();
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Create Tree
Node* CreateTree()
{
    int value;
    cout << "Enter value (-1 for NULL): ";
    cin >> value;

    if (value == -1)
        return NULL;

    Node* newNode = CreateNode(value);

    cout << "Enter left child of " << value << endl;
    newNode->left = CreateTree();

    cout << "Enter right child of " << value << endl;
    newNode->right = CreateTree();

    return newNode;
}

// Inorder Traversal
void Inorder(Node* root)
{
    if (root == NULL)
        return;

    Inorder(root->left);
    cout << root->data << " ";
    Inorder(root->right);
}

// Preorder Traversal
void Preorder(Node* root)
{
    if (root == NULL)
        return;

    cout << root->data << " ";
    Preorder(root->left);
    Preorder(root->right);
}

// Postorder Traversal
void Postorder(Node* root)
{
    if (root == NULL)
        return;

    Postorder(root->left);
    Postorder(root->right);
    cout << root->data << " ";
}

// Main Function
int main()
{
    Node* root = NULL;

    cout << "Create Binary Tree\n";
    root = CreateTree();

    cout << "\nInorder Traversal: ";
    Inorder(root);

    cout << "\nPreorder Traversal: ";
    Preorder(root);

    cout << "\nPostorder Traversal: ";
    Postorder(root);

    return 0;
}
