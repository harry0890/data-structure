#include <iostream>
#include <stack>
using namespace std;

/* A binary tree Node has data, pointer to left child 
   and a pointer to right child */
struct Node 
{ 
    int data; 
    struct Node* left; 
    struct Node* right; 
    Node (int data) 
    { 
        this->data = data; 
        left = right = NULL; 
    } 
}; 
  
void inOrder(struct Node *root) 
{ 
    stack<Node *> s; 
    Node *curr = root; 
  
    while (curr != NULL || s.empty() == false) 
    { 
        while (curr !=  NULL){ 
            s.push(curr); 
            curr = curr->left; 
        } 
  
        curr = s.top(); 
        s.pop(); 
  
        cout << curr->data << " "; 
        curr = curr->right; 
  
    }
} 
  
int main() 
{ 
  
    /* Constructed binary tree is 
              1 
            /   \ 
          2      3 
        /  \ 
      4     5 
    */
    struct Node *root = new Node(1); 
    root->left        = new Node(2); 
    root->right       = new Node(3); 
    root->left->left  = new Node(4); 
    root->left->right = new Node(5); 
  
    inOrder(root);
    system("pause");
    return 0; 
} 
