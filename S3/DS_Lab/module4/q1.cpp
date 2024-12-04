#include <iostream>
#include <queue>
using namespace std;

struct node {
  int data;
  node *left;
  node *right;
};
class btree {
public:
  node *ROOT;
  btree() {
    ROOT = nullptr;
  }
  void insert(int data) {
    node *newnode = new node;
    newnode->data = data;
    newnode->left = nullptr;
    newnode->right = nullptr;
    if (ROOT == nullptr) {
      ROOT = newnode;
      return;
    }

    queue<node *> q;
    q.push(ROOT);
    while (!q.empty()) {

      // front element in queue
      node *currentnode = q.front();
      q.pop();

      // First check left if left is null
      // insert node in left otherwise check for right
      if (currentnode->left != nullptr)
        q.push(currentnode->left);
      else {
        currentnode->left = newnode;
        return;
      }

      if (currentnode->right != nullptr)
        q.push(currentnode->right);
      else {
        currentnode->right = newnode;
        return;
      }
    }
  }
  void traverse()
  {
    inorder(ROOT);
  }
  void inorder(node *curr) {
    if (curr == nullptr)
      return;
    inorder(curr->left);
    cout << curr->data << ' ';
    inorder(curr->right);
  }
};


int main()
{
    btree bt;
    int operationchoice;
    while(true) {
        cout<<"Enter operation:\n1) Insert\n2) Traverse\n3) Exit\n";
        cin>>operationchoice;
        if(operationchoice == 1)
        {
            int data;
            cout<<"Enter data to insert:\n";
            cin>>data;
            bt.insert(data);
        }
        else if(operationchoice == 2)
        {
            bt.traverse();
        }
        else {
            break;
        }
    }
}
