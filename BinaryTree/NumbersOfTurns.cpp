#include<bits/stdc++.h>

using namespace std;

Node* findLCA(struct Node* root,
						int n1, int n2)
{
	// Base case
	if (root == NULL)
		return NULL;

	// If either n1 or n2 matches with
	// root's key, report the presence by
	// returning root (Note that if a key
	// is ancestor of other, then the
	// ancestor key becomes LCA
	if (root->data == n1 || root->data == n2)
		return root;

	// Look for keys in left and right subtrees
	Node* left_lca = findLCA(root->left, n1, n2);
	Node* right_lca = findLCA(root->right, n1, n2);

	// If both of the above calls return
	// Non-NULL, then one key is present
	// in once subtree and other is present
	// in other, So this node is the LCA
	if (left_lca && right_lca)
		return root;

	// Otherwise check if left subtree or right
	// subtree is LCA
	return (left_lca != NULL) ? left_lca :
								right_lca;
}

// function count number of turn need to reach
// given node from it's LCA we have two way to
bool CountTurn(Node* root, int key, bool turn,
								int* count)
{
	if (root == NULL)
		return false;

	// if found the key value in tree
	if (root->data== key)
		return true;

	// Case 1:
	if (turn == true) {
		if (CountTurn(root->left, key, turn, count))
			return true;
		if (CountTurn(root->right, key, !turn, count)) {
			*count += 1;
			return true;
		}
	}
	else // Case 2:
	{
		if (CountTurn(root->right, key, turn, count))
			return true;
		if (CountTurn(root->left, key, !turn, count)) {
			*count += 1;
			return true;
		}
	}
	return false;
}

// Function to find nodes common to given two nodes
int NumberOFTurns(Node* root, int first,
								int second)
{
	struct Node* LCA = findLCA(root, first, second);

	// there is no path between these two node
	if (LCA == NULL)
		return -1;
	int Count = 0;

	// case 1:
	if (LCA->data != first && LCA->data != second) {
		
		// count number of turns needs to reached
		// the second node from LCA
		if (CountTurn(LCA->right, second, false,
										&Count)
			|| CountTurn(LCA->left, second, true,
										&Count))
			;
		
		// count number of turns needs to reached
		// the first node from LCA
		if (CountTurn(LCA->left, first, true,
									&Count)
			|| CountTurn(LCA->right, first, false,
									&Count))
			;
		return Count + 1;
	}

	// case 2:
	if (LCA->data == first) {

		// count number of turns needs to reached
		// the second node from LCA
		CountTurn(LCA->right, second, false, &Count);
		CountTurn(LCA->left, second, true, &Count);
		return Count;
	} else {

		// count number of turns needs to reached
		// the first node from LCA1
		CountTurn(LCA->right, first, false, &Count);
		CountTurn(LCA->left, first, true, &Count);
		return Count;
	}
}

int main()
{

    return 0;
}