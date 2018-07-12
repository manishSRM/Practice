#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <cmath>
#include <climits>
#include <set>

using namespace std;

typedef long long int ll;

struct node {
	int data;
	struct node *left;
	struct node *right;
}; 

struct node* createNode(int data) {
	struct node* node = (struct node*) malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
	return (node);
}

int height(struct node* node) {
    if (node == NULL) {
        return 0;
    } else {
        int leftHeight = height(node->left);
        int rightHeight = height(node->right);
        if (leftHeight > rightHeight) {
            return(leftHeight+1);
        } else {
        	return(rightHeight+1);
        }
    }
}

void printGivenLevel(struct node* root, int level, int order) {
    if (root == NULL) {
        return;
    }
    if (level == 1) {
        cout << root->data << " ";
    } else if (level > 1) {
    	if (order) {
	        printGivenLevel(root->left, level-1, order);
	        printGivenLevel(root->right, level-1, order);
	    } else {
	    	printGivenLevel(root->right, level-1, order);
	    	printGivenLevel(root->left, level-1, order);
	    }
    }
}

void printLevelOrder(struct node* root) {
    int h = height(root);
    bool order = false;
    for (int i = 1; i <= h; i++) {
        printGivenLevel(root, i, order);
        order = !order; 
    }
}

int main () {
	struct node *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    printLevelOrder(root);
    cout << endl;
	return 0;
}	