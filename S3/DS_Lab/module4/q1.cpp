#include<iostream>
using namespace std;

struct node
{
	int data;
	node *left;
	node *right;
};
class btree
{
	public:
	node *ROOT;
	btree()
	{
		ROOT = nullptr;
	}
	void insert(int data)
	{
		node *newnode = new node;
		newnode->data = data;
		newnode->left = nullptr;
		newnode->right = nullptr;		
		if(ROOT == nullptr)
		{
			ROOT = newnode;
			return;
		}
		
		queue<node*> q;
    	q.push(ROOT);
    	while (!q.empty()) {
      
          // Fron a front element in queue
        	node *currentnode = q.front();
        	q.pop();
        
          	// First check left if left is null 
          	// insert node in left otherwise chaeck for right
        	if (currentnode->left != nullptr)
        		q.push(currentnode->left);
        	else {
            	currentnode->left = newnode;
            	return root;
        	}
    
        	if (currentnode->right != nullptr)
            	q.push(currentnode->right);
        	else {
            	currentnode->right = newnode;
            	return root;
        	}
    	}
	}
};
