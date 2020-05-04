//Dynamic program approach...
/*
            1
          /  \    
        2      3
      /  \       \
    4      6       5
          /  \
         8    7


Required answer= 5 (1,4,8,7,5)

*/

#include <bits/stdc++.h> 
using namespace std;  
int max(int x, int y) 
{ 
	return (x > y) ? x : y; 
} 

class node 
{ 
	public: 
	int data; 
	node *left, *right; 
}; 
int MAXS(node *root) 
{ 
	if (root == NULL) 
	return 0; 

	// Calculate size excluding the current node 
	int size_excl = MAXS(root->left) + 
					MAXS(root->right); 

	int size_incl = 1; 
	if (root->left) 
		size_incl += MAXS(root->left->left) + 
					MAXS(root->left->right); 
	if (root->right) 
		size_incl += MAXS(root->right->left) + 
					MAXS(root->right->right);  
	return max(size_incl, size_excl); 
} 

node* newNode( int data ) 
{ 
	node* temp = new node(); 
	temp->data = data; 
	temp->left = temp->right = NULL; 
	return temp; 
} 

// Driver Code 
int main() 
{ 
	//construct the tree
	node *root = newNode(1); 
	root->left = newNode(2); 
	root->left->left = newNode(4); 
	root->left->right = newNode(6); 
  	root->left->right->right = newNode(7);
    root->left->right->left = newNode(8);
	root->right = newNode(3); 
	root->right->right = newNode(5); 

	cout << "Size of the Largest  Independent Set is "<< MAXS(root); 

	return 0; 
} 
