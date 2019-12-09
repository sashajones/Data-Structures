#include "BSTY.hpp"
#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

BSTY::BSTY() {
	root = NULL;
}

// You write:  insert a new node with data x (a string) into the 
// binary search tree
// This method should return true if a new node is inserted and 
// false if the data x is already in the tree

// Remember to check whether the new node will be the root
// (meaning the root is currently NULL) and if so, set the root
// to be the new node.

// Note: Make sure you make the new node point to its parent!!! 
// Note2: after you've inserted a new node, you should call the 
// adjustHeights method that will update the heights of all the 
// ancestors of the node that was just inserted.
bool BSTY:: insertit(string x ) {
	cout << "Attempting to insert: " << x << endl;
	if (root == NULL) { // if this is the first node to be inserted
		NodeT *n = new NodeT(x);
		root = n;
		return true;
	}
	else {
		NodeT *n = root;
		while (n != NULL) {
			if (x < n->data) { // if x is less than the current node's data
				if (n->left == NULL) {
					NodeT *ins = new NodeT(x);
					n->left = ins;
					ins->parent = n;
					adjustHeights(n); // here n is the parent node of the node just inserted
					cout << endl<<"*** After inserting:	" << x << "	and balancing**"<< endl<<"PREORDER " << endl;
					//printTreePre();
					return true;
				} //end if statement
				else {
					n = n->left;
				} // end else statement
			} // end if statement

			else if (x > n->data) {
				if (n->right == NULL) {
					NodeT *ins = new NodeT(x);
					n->right = ins;
					ins->parent = n;
					adjustHeights(n); // n is the parent node of the newly inserted node
					cout << endl<<"*** After inserting:	" << x << "	and balancing**"<< endl<<"PREORDER " << endl;
					//printTreePre();
					return true;
				} // end if statement
				else {
					n = n->right;
				} // end else statement

			} // end else if
			else {
				return false; // Node already in tree
			} // end else
		} // end while loop
	} //end else statement


} // end insertit function

bool BSTY:: insertit(string x, string y ) {
	cout << "Attempting to insert: " << x << endl;
	if (root == NULL) { // if this is the first node to be inserted
		NodeT *n = new NodeT(x,y);
		root = n;
		return true;
	}
	else {
		NodeT *n = root;
		while (n != NULL) {
			if (x < n->data) { // if x is less than the current node's data
				if (n->left == NULL) {
					NodeT *ins = new NodeT(x,y);
					n->left = ins;
					ins->parent = n;
					adjustHeights(n); // here n is the parent node of the node just inserted
					cout << endl<<"*** After inserting:	" << x << "	and balancing**"<< endl<<"PREORDER " << endl;
					printTreePre();
					return true;
				} //end if statement
				else {
					n = n->left;
				} // end else statement
			} // end if statement

			else if (x > n->data) {
				if (n->right == NULL) {
					NodeT *ins = new NodeT(x,y);
					n->right = ins;
					ins->parent = n;
					adjustHeights(n); // n is the parent node of the newly inserted node
					cout << endl<<"*** After inserting:	" << x << "	and balancing**"<< endl<<"PREORDER " << endl;
					printTreePre();
					return true;
				} // end if statement
				else {
					n = n->right;
				} // end else statement

			} // end else if
			else {
				return false; // Node already in tree
			} // end else
		} // end while loop
	} //end else statement


} // end insertit overoad function

// the adjustHeights method updates the heights of every ancestor of the node n.
// This method will be massively useful with our next lab, so make sure you have 
// this working now.  It should be called whenever you change the height of a 
// a particular node.  So, for instance, when a new node is inserted as a leaf, 
// its height is 1.  The adjustHeights method should then check the parent to see
// if the height of the parent changes (the height of each node is the maximum of 
// the height of the left child and the height of the right child, plus 1).  If 
// the parent's height changes, then the grandparent's height should be checked and,
// if necessary, adjusted.  If the grandparent's height is updated, then the great-
// grandparent's height should be adjusted, etc.  The checking stops when either 
// the loop has worked its way up to the root, or until the currently being checked
// ancestor is not changed.  
void BSTY::adjustHeights(NodeT *n) { // n here is the parent node of the node just inserted
	while (n != NULL) {

		if ((n->left != NULL) && (n->right == NULL)) { // if n only has one child on left
			n->height = (n->left->height) + 1;

		} // end if statement
		else if ((n->left == NULL) && (n->right != NULL)) { // if n only has one child on right
			n->height = (n->right->height) + 1;
			cout << n->data << "'s bal is: " << findBalance(n) << endl; //updates n's balance
			cout << n->data << "'s bal: " << n->balance << endl;

		}
		else if ((n->left == NULL) && (n->right == NULL)) { // if node has 0 children
			n->height = 1;

		}

		else { // if left & right  are both not null
			if (n->left->height >= n->right->height) { // if left > right
				if (n->height != ((n->left->height) + 1)) {
					n->height = n->left->height + 1;
				} // end if statement
				else {
					return; // node's heights no longer need to be adjusted
				}// end else
			} // end if statement
			else {
				if (n->height != ((n->right->height) + 1)) {
					n->height = n->right->height + 1;
				} // end if statement
				else {
					return; // node's heights no longer need to be adjusted
				}// end else
			}
		} // end else statement // if left > right


		// FOR PART 2 BALANCING

		findBalance(n); // adjusts balance of n

		/*
		if (n->balance > 1) {
			if(n->left->balance > 0) {
				// ***  Left-Left Case ***
				rotateRight(n);
				cout << "finished rotateRight" << endl;
			}
			else if (n->left->balance < 0) {  // left-right rotate
				cout << n->data << " must rotate right (" << n->balance << ")" << endl;
				cout << n->left->data << " must rotate left (child)" << endl;

				n->left = rotateLeft(n->left); // check if correct
				rotateRight(n);
			}
		}

		else if ( n->balance < -1) {
			if (n->right->balance < 0) {
				// *** Right-Right Case ***
				rotateLeft(n);
				cout << "finished rotateLeft" << endl;
			}
			else if (n->left->balance > 0) {
				cout << n->data << " must rotate left (" << n->balance << ")" << endl;
				cout << n->right->data << " child must rotate right" << endl;
				n->right = rotateRight(n->right);
				cout << "great" << endl;/// check if correct
				rotateLeft(n);
			}
		}
		*/


		if( (n->balance > 1) && ( n->left->balance > 0) ){
			// ***  Left-Left Case ***
			rotateRight(n);
			cout << "finished rotateRight" << endl;
		} // end if statement

		else if( (n->balance < -1) && (n->right->balance < 0) ) {
			// *** Right-Right Case ***
			rotateLeft(n);
			cout << "finished rotateLeft" << endl;
		} // end if statement

		else if ( (n->balance > 1 ) && (n->left->balance < 0) ) { // left-right rotate
			cout << n->data << " must rotate right (" << n->balance << ")" << endl;
			cout << n->left->data << " must rotate left (child)" << endl;

			n->left = rotateLeft(n->left); // check if correct
			rotateRight(n);
		} // end else if statement

		else if ( (n->balance < -1) && (n->right->balance > 0)) { // right-left rotate
			cout << n->data << " must rotate left (" << n->balance << ")" << endl;
			cout << n->right->data << " child must rotate right" << endl;
			n->right = rotateRight(n->right);
			cout << "great" << endl;/// check if correct
			rotateLeft(n);
		} // end else if statement

		else {
			cout << "	No need to rebalance: " << n->data << endl;
			cout << "		bal: " << n->balance << endl;
			cout << "		height: " << n->height << endl;
			if (n->parent != NULL) {
				cout << "		parent: " << n->parent->data << endl;
			}
		}

		n = n->parent;

	}
	cout << "out of while loop" << endl;

} // end adjustHeights method


void BSTY::printTreeIO() {
	if (root == NULL ) {
		cout << "Empty Tree" << endl;
	}
	else {
		printTreeIO(root);
	}
}

// Print the tree in order (left child, then parent, then right child).
// Use the slides, but make sure you can understand how the tree is 
// traversed in order
void BSTY::printTreeIO(NodeT *n) {
	if (n == NULL) {
		return;
	}
	else {
		printTreeIO(n->left);
		n->printNode();
		printTreeIO(n->right);
	}
}

void BSTY::printTreePre() {
	if (root == NULL ) {
		cout << "Empty Tree" << endl;
	}
	else {
		printTreePre(root);
	}
}

// Prints the tree using pre-order traversal (parent, then left child, then right
// child.  Use the slides, but make sure you understand how a tree is traversed in
// pre-order
void BSTY::printTreePre(NodeT *n) {
	if (n == NULL) {
		return;
	}
	else {
		n->printNode();
		printTreePre(n->left);
		printTreePre(n->right);
	}

}

void BSTY::printTreePost() {
	if (root == NULL ) {
		cout << "Empty Tree" << endl;
	}
	else {
		printTreePost(root);
		cout << endl;
	}
}

// Prints the tree using pre-order traversal (left child, then right, then parent)
// Use the slides, but make sure you understand how a tree is traversed in
// post-order
void BSTY::printTreePost(NodeT *n) {
	if (n == NULL) {
		return;
	}
	else {
		printTreePost(n->left);
		printTreePost(n->right);
		n->printNode();
	}

}
void BSTY::myPrint() {
	if (root == NULL ) {
		cout << "Empty Tree" << endl;
	}
	else {
		myPrint(root);
		cout << endl;
	}
}
void BSTY::myPrint(NodeT *n) {
	if (n == NULL) {
		return;
	}
	else {
		myPrint(n->left);
		cout << n->data.length()-1;
		if (mine) {
			cout <<".";
			mine = false;
		}
		myPrint(n->right);
	}
}

// the find method takes as input a string, and finds whether that string is already
// in the tree or not.  If it is in the tree, that node is returned from the tree.
// If it isn't, NULL is returned.  
// NOTE: If the node can't be found, this method prints out that x can't be found.
// if it is found, the printNode method is called for the node.  
NodeT *BSTY::find(string x) {
	NodeT *n = root;
	int compT = 1;
	while ( n != NULL) {

		if (x == root->data) {
			cout << compT << ": ";
			n->printNode();
			return n;
		}

		else if (x < n->data) {
			n = n->left;
			//compT++;
		}
		else if (x > n->data) {
			n = n->right;
			//compT++;
		}
		else {
			compT++;
			cout << compT << ": ";
			n->printNode();
			return n;
		}
		compT++;
	} // end while loop
	cout << x << " not found" << endl;
	return NULL;
} // end find method

/*************************************************************************************/
/* Extra Credit Methods                                                              */
/* Challenging: worth 35 EC pts to go towards labs                                   */
/* NOTE: IF YOU CHOOSE NOT TO IMPLEMENT THESE METHODS, YOU ARE STILL RESPONSIBLE FOR */
/* UNDERSTANDING HOW THEY WORK!!                                                     */
/*************************************************************************************/
/* When removing a node from a binary search tree, the resulting tree MUST BE a binary
/* search tree.  
/*
/* When removing a node, there are 3 conditions:
/* 1: when the node being removed has no children, in which case the node is deleted,
/* the node's parent is set to NULL, and the node's parent's height is adjusted (if
/* necessary) and heights on up are adjusted.
/* 2: when the node being removed has one child, in which case the node's parent points
/* to the node's child, and the node's child points to the node's parent, and the node
/* is deleted (and the height of the parent on up as necessary is adjusted)
/* 3: when the node has 2 children, in which case the left-most child of the node's 
/* right child replaces the node.  
/* A couple of notes about this one: you are replacing a node with a node that is lower
/* down in the tree.  That means that you are, in essence, removing the node from that
/* lower position and moving it up to the old node's location.  Thus the replacing node
/* must be removed using 1 or 2 above (why not 3?).  The heights must be adjusted after 
/* the replacing node is removed from its old location but before it is inserted into its 
/* new location.  Equally, the replacing node's height must be adjusted to be the larger of
/* its two children's heights before you adjust heights above that.  
/*****************************************************************************************/
/* remove(): takes as input a string, uses the find method to find the node in the tree that
/* holds that string, and then calls replace1, replace2, or replace3 depending on what type
/* of replacing should be done.  It adjusts the heights, deletes teh node, and returns 
/* true if the removal was successful.
 */
bool BSTY::remove(string s) {
	NodeT *rem = find(s);
	if (rem->left == NULL && rem->right == NULL) { // if node has no children
		remove1(rem);
	}
	else if (rem->left != NULL && rem->right != NULL) { // if node has 2 children
		remove3(rem);
	}
	else {
		remove2(rem);
	}
	return true;
}

/* remove1(): called when the node to be removed has no children. Takes as input the 
/* node to be removed, and sets the parent of the node to point to NULL.
/* helpful hint: if (n->parent->left == n) is true, then n is its parent's left child.
/* Make sure you check to whether n is the root or not.
 */
void BSTY::remove1(NodeT *n) {
	cout << "Node to be removed has no children" << endl;
	NodeT *npar = n->parent;
	n->parent->left = NULL;
	adjustHeights(n->parent);
	n->parent = NULL;
	delete n;

}

/* remove2(): called when the node to be removed has 1 child only.  Takes as input
/* the node to be removed and bypasses it by making the parent point to the node's
/* one child, and makes the node's one child point to the node's parent.  
/* This one needs a bunch of checking - you need to see if the node is the parent's
/* left or right child, and you need to see if the node's child is its left or its
/* right child.
/* Also, make sure you check that if the node to be removed is the root, then the 
/* one child becomes the root.
 */
void BSTY::remove2(NodeT *n) {
	cout << " Node to be removed has 1 child" << endl;
	if (n->parent == NULL) { // if node to be removed is the root
		if (n->left != NULL) {
			n->left->parent = NULL;
			root = n->left;
			delete n;
		}
		else {
			n->right->parent = NULL;
			root = n->right;
			delete n;
		}
	} // end if statement

	else {
		if (n->parent->left == n) { // if n is a left child
			if (n->left != NULL) { // if n's children are on the left
				n->parent->left = n->left;
				n->left->parent = n->parent;
				adjustHeights(n->left);
				delete n;
			}
			else { // if n's children are on the right
				n->parent->left = n->right;
				n->right->parent = n->parent;
				adjustHeights(n->right);
				delete n;
			}
		}
		else { // if n is a right child
			if (n->right != NULL) { // if n's children are on the left
				n->parent->right = n->left;
				n->left->parent = n->parent;
				adjustHeights(n->left);
				delete n;
			}

			else { // if n's children are on the right
				n->parent->right = n->right;
				n->right->parent = n->parent;
				adjustHeights(n->right);
				delete n;
			}

		} // end else statement

	}

} // end remove2 method

/* remove3(): called when the node to be removed has 2 children.  Takes as input the
/* node to be removed.  The node to replace the node to be removed should be the 
/* left-most descendent of the node's right child.  That way the binary search tree
/* properties are guaranteed to be maintained.
/* When replacing the node to be removed with the replacing node, the replacing node
/* is, in essence, being removed from its place in the tree, and thus replace1 or 
/* replace2 methods should be used.
/* The new node's parent must be set to the removed node's parent, the removed node's
/* parent must point to the new node, the new node's left child must point to the 
/* removed node's left child (and the child must point to the new node as a parent), 
/* and the same for teh right child.
/* Remember to take into account that the node being removed might be the root.
 */
void BSTY::remove3(NodeT *n) {
	cout << " Node to be removed has 2 children" << endl;
	NodeT *tmp=findMin(n);
	n->data=tmp->data;
	tmp->parent->left=NULL;
	adjustHeights(tmp->parent);
	delete tmp;

	/*
	NodeT *tmp = findMin(n); // node to replace removed node
	NodeT *tmp2= tmp->parent;
	cout << " tmp is: " << tmp->data << endl;
	//remove(n->data);

	if (n->parent->left == n) { // if n is a left child
		n->parent->left = tmp; // set n's parent's child to new node
		tmp->parent = n->parent;  // set new node's parent to n's parent
	}
	else if(n->parent->right == n) { // if n is a right child
		n->parent->right = tmp;
		tmp->parent = n->parent;
	}

		tmp->left = n->left;
		tmp->left->parent = tmp;

		tmp->right = n->right;
		tmp->right->parent = tmp;

		adjustHeights(findMin(tmp));
		adjustHeights(tmp);


	//tmp->parent = n->parent;

	 */
}

/* findMin(): takes as input a node, and finds the left-most descendant of its 
/* right child.  The left-most descendent is returned.
 */
NodeT *BSTY::findMin(NodeT *n) {
	n = n->right;
	while(n->left != NULL) {
		n = n->left;
	}
	return n;
}

void BSTY::myPrintEC() {
	if (root == NULL ) {
		cout << "Empty Tree" << endl;
	}
	else {
		myPrintEC(root);
		cout << endl;
	}
}
void BSTY::myPrintEC(NodeT *n) {
	if (n == NULL) {
		return;
	}
	else {
		myPrintEC(n->left);
		cout << alpha[n->data.length()-2];
		myPrintEC(n->right);
	}
}


/************************************************************************/

// PART 5b Part 2

NodeT *BSTY::rotateRight(NodeT *n) {

	cout << " Rotate " << n->data << " Right" << endl;
	NodeT *x = n->left;
	NodeT *tmp = x->right; // may be NULL

	x->right = n;

	// assigning n's previous parents as x's parents
	// If n's parent != NULL ( if n is NOT the root)
	if (n->parent != NULL) {
		if (n->parent->left == n) { // if n is its' parents' left child
			n->parent->left = x;
			x->parent = n->parent;
		}
		else if(n->parent->right == n) { // if n is its' parents right child
			n->parent->right = x;
			x->parent = n->parent;
			//cout << x->data << "'s new parent is: " << x->parent->data << endl;
		}
		else { // this means that n was the root of the tree
			cout << n->data <<" was root of tree.. fall through of nested conditions." << endl;
		} // end else statement

	} // end if statement

	else if (n->parent == NULL) {
		//cout << n->data <<" was root of tree" << endl;
		x->parent = NULL;
		root = x; // make x the new root
		//cout << "new root is: " << root->data << endl;
	}
	else { // safety case
		cout << "Something fell through. Check rotateRight function. BSTY.cpp" << endl;
	}

	// TRY THIS
	n->parent = x;
	//cout << n->data << "'s new parent is: " << n->parent->data << endl;

	// making x's right child n's left child
	n->left = tmp;
	if (tmp != NULL) { // establishes parent node connection
		n->left->parent = n;
		cout << n->left->parent->data << " yep" << endl;
	}

	// adjusting heights of rotated nodes
	if (n->right == NULL && n->left == NULL) { //if n's children are NULL
		n->height = 1;
	}

	else if (n->left == NULL && n->right != NULL) {
		n->height = n->right->height + 1;
	}

	else if (n->left->height > n->right->height) {
		n->height = ( (n->left->height) + 1);
	}
	else {
		if ( n->right != NULL) {
			n->height = n->right->height + 1;
		}
		else {
			n->height = 1;
		}
	}

// FINISH ADJUSTING HEIGHTS OF ROTATED NODES


	if (x->left == NULL && x->right == NULL) {
		x->height = 1;
		cout << "SHOULDN'T HAPPEN" << endl;
	}
	else if (x->left == NULL && x->right != NULL) {
		x->height = x->right->height + 1;
	}

	else if (x->left->height > x->right->height) {
		x->height = x->left->height + 1;
	}

	else if (x->left != NULL && x->right == NULL) {
		x->height = x->left->height + 1;
		cout << "WHAT TF" << endl;
	}

	else {
		x->height = x->right->height + 1;
	}

// return new root
	return x;
}

NodeT *BSTY::rotateLeft(NodeT *n) {

	cout << " Rotate " << n->data << " Left" << endl;
	NodeT *x = n->right;
	NodeT *tmp = x->left; // may be NULL

	x->left = n;

	// assigning n's previous parents as x's parents
	// If n's parent != NULL ( if n is NOT the root)
	if (n->parent != NULL) {
		if (n->parent->left == n) { // if n is its' parents' left child
			n->parent->left = x;
			x->parent = n->parent;
			//cout << x->data << "'s parent is: " << x->parent->data << endl;
		}
		else if(n->parent->right == n) { // if n is its' parents right child
			n->parent->right = x;
			x->parent = n->parent;
		}
		else { // this means that n was the root of the tree
			cout << n->data <<" was root of tree.. fall through of nested conditions." << endl;
			//root = x; // make x the new root
		} // end else statement

	} // end if statement

	else if (n->parent == NULL) {
		//cout << n->data <<" was root of tree" << endl;
		x->parent = NULL;
		root = x; // make x the new root
		//cout << "new root is: " << root->data << endl;
	}
	else { // safety case
		cout << "Something fell through. Check rotateLeft function. BSTY.cpp" << endl;
	}

	n->parent = x;
	//cout << n->data << "'s new parent is: " << n->parent->data << endl;


	// making x's left child n's right child
	n->right = tmp;
	if (tmp != NULL) { // establishes parent node connection
		n->right->parent = n;
		cout << n->right->parent->data << " yep" << endl;
	}

	// adjusting heights of rotated nodes
	if (n->right == NULL && n->left == NULL) { //if n's children are NULL
		n->height = 1;
	}
	else if (n->right == NULL && n->left != NULL) { //if n's children are NULL
		n->height = n->left->height + 1;
	}
	else if (n->right->height > n->left->height) {
		n->height = ( (n->right->height) + 1);
	}
	else {
		if ( n->left != NULL) {
			n->height = n->left->height + 1;
		}
		else {
			n->height = 1;
		}
	}

	//*/


	if (x->right == NULL && x->left == NULL) {
		x->height = 1;
	}

	else if (x->left != NULL && x->right == NULL) {
		x->height = x->left->height + 1;
		//cout << "mammmmi" << endl;
	}

	else if (x->right->height > x->left->height) {
		x->height = x->right->height + 1;
	}
	else {
		x->height = x->left->height + 1;
	}
	// return new root
	return x;
} // end rotateLeft function

int BSTY::findBalance(NodeT *n) {
	if (n == NULL) {
		n->balance = 0;
		return n->balance;
	}
	if (n->left == NULL) {
		n->balance = (0 - n->right->height);
		return n->balance;
	}
	if (n->right == NULL) {
		n->balance = n->left->height;
		return n->balance;
	}
	else {
		n->balance = (n->left->height) - (n->right->height);
		return n->balance;
	}
}
