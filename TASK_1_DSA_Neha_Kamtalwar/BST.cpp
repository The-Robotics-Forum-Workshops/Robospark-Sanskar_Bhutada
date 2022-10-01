#include <iostream>

using namespace std;


struct Node {  
    int data;  
    Node *left;  
    Node *right;  
};  
Node* create(int item)  
{  
    Node* node = new Node;  
    node->data = item;  
    node->left = node->right = NULL;  
    return node;  
}  
  
void inorder(Node *root)  
{  
    if (root == NULL)  
        return;  
    inorder(root->left);  
    cout<< root->data << "   ";  
    inorder(root->right);   
}  
Node* findMinimum(Node* cur)   
{  
    while(cur->left != NULL) {  
        cur = cur->left;  
    }  
    return cur;  
}  

Node* insertion(Node* root, int item)  
{  
    if (root == NULL)  
        return create(item);   
    if (item < root->data)  
        root->left = insertion(root->left, item);  
    else  
        root->right = insertion(root->right, item);  
    return root;  
}  
void search(Node* &cur, int item, Node* &parent)  
{  
    while (cur != NULL && cur->data != item)  
    {  
        parent = cur;  
        if (item < cur->data)  
            cur = cur->left;  
        else  
            cur = cur->right;  
    }  
} 

int main()
{

  Node* root = NULL;  
  root = insertion(root, 55);  
  root = insertion(root, 34);  
  root = insertion(root, 50);  
  root = insertion(root, 25);  
  root = insertion(root, 48);  
  root = insertion(root, 45);  
  root = insertion(root, 6);  
  root = insertion(root, 4);  
  printf("The inorder traversal of the given binary tree is - \n");  
  inorder(root);

    return 0;
}
