#include <iostream>

using namespace std;

struct node {
	int data;
	node* parent;
	node* left;
	node* right;
	bool color;//0=black 1=red
};

typedef node* RBT_node;

class RBTree {
private:
	RBT_node root;
	RBT_node RBT;

	void RBNew(RBT_node node, RBT_node parent) {
		node->data = 0;
		node->parent = parent;
		node->left = nullptr;
		node->right = nullptr;
		node->color = 0;
	}

	void RBInsert(RBT_node k) {
		RBT_node u;
		while (k->parent->color == 1) {
			if (k->parent == k->parent->parent->right) {
				u = k->parent->parent->left;
				if (u->color == 1) {
					u->color = 0;
					k->parent->color = 0;
					k->parent->parent->color = 1;
					k = k->parent->parent;
				}
				else {
					if (k == k->parent->left) {
						k = k->parent;
						rightRotate(k);
					}
					k->parent->color = 0;
					k->parent->parent->color = 1;
					leftRotate(k->parent->parent);
				}
			}
			else {
				u = k->parent->parent->right;

				if (u->color == 1) {
					u->color = 0;
					k->parent->color = 0;
					k->parent->parent->color = 1;
					k = k->parent->parent;
				}
				else {
					if (k == k->parent->right) {
						k = k->parent;
						leftRotate(k);
					}
					k->parent->color = 0;
					k->parent->parent->color = 1;
					rightRotate(k->parent->parent);
				}
			}
			if (k == root) {
				break;
			}
		}
		root->color = 0;
	}

	void inOrder(RBT_node node) {
		if (node != RBT) {
			inOrder(node->left);
			cout << node->data << " " << node->color << "\n";
			inOrder(node->right);
		}
	}

	void preOrder(RBT_node node) {
		if (node != RBT) {
			cout << node->data << " ";
			preOrder(node->left);
			preOrder(node->right);
		}
	}

	void postOrder(RBT_node node) {
		if (node != RBT) {
			postOrder(node->left);
			postOrder(node->right);
			cout << node->data << " ";
		}
	}

	void RBDelete(RBT_node x) {
		RBT_node s;
		while (x != root && x->color == 0) {
			if (x == x->parent->left) {
				s = x->parent->right;
				if (s->color == 1) {
					s->color = 0;
					x->parent->color = 1;
					leftRotate(x->parent);
					s = x->parent->right;
				}

				if (s->left->color == 0 && s->right->color == 0) {
					s->color = 1;
					x = x->parent;
				}
				else {
					if (s->right->color == 0) {
						s->left->color = 0;
						s->color = 1;
						rightRotate(s);
						s = x->parent->right;
					}

					s->color = x->parent->color;
					x->parent->color = 0;
					s->right->color = 0;
					leftRotate(x->parent);
					x = root;
				}
			}
			else {
				s = x->parent->left;
				if (s->color == 1) {
					s->color = 0;
					x->parent->color = 1;
					rightRotate(x->parent);
					s = x->parent->left;
				}

				if (s->right->color == 0 && s->right->color == 0) {
					s->color = 1;
					x = x->parent;
				}
				else {
					if (s->left->color == 0) {
						s->right->color = 0;
						s->color = 1;
						leftRotate(s);
						s = x->parent->left;
					}

					s->color = x->parent->color;
					x->parent->color = 0;
					s->left->color = 0;
					rightRotate(x->parent);
					x = root;
				}
			}
		}
		x->color = 0;
	}


	void RbTrans(RBT_node m, RBT_node n) {
		if (m->parent == nullptr)
			root = n;
		else if (m == m->parent->left)
			m->parent->left = n;
		else
			m->parent->right = n;

		n->parent = m->parent;
	}

	void deleteNode(RBT_node node, int val) {
		RBT_node z = RBT;
		RBT_node x, y;
		while (node != RBT) {
			if (node->data == val) {
				z = node;
			}

			if (node->data <= val) {
				node = node->right;
			}
			else {
				node = node->left;
			}
		}

		if (z == RBT) {
			cout << "Value is not present in the tree.." << endl;
			return;
		}

		y = z;
		int y_color = y->color;
		if (z->left == RBT) {
			x = z->right;
			RbTrans(z, z->right);
		}
		else if (z->right == RBT) {
			x = z->left;
			RbTrans(z, z->left);
		}
		else {
			y = minimum(z->right);
			y_color = y->color;
			x = y->right;
			if (y->parent == z) {
				x->parent = y;
			}
			else {
				RbTrans(y, y->right);
				y->right = z->right;
				y->right->parent = y;
			}

			RbTrans(z, y);
			y->left = z->left;
			y->left->parent = y;
			y->color = z->color;
		}
		delete z;
		if (y_color == 0)
			RBDelete(x);

	}


public:
	RBTree() {
		RBT = new node;
		RBT->color = 0;
		RBT->left = nullptr;
		RBT->right = nullptr;
		root = RBT;
	}

	void inorder() {
		inOrder(this->root);
	}

	void preorder() {
		preOrder(this->root);
	}

	void postorder() {
		postOrder(this->root);
	}

	RBT_node searchNode(int val) {
		return SearchTree(this->root, val);
	}

	RBT_node minimum(RBT_node node) {
		while (node->left != RBT) {
			node = node->left;
		}
		return node;
	}

	void leftRotate(RBT_node x) {
		RBT_node y = x->right;
		x->right = y->left;

		if (y->left != RBT)
			y->left->parent = x;

		y->parent = x->parent;

		if (x->parent == nullptr)
			this->root = y;
		else if (x == x->parent->left)
			x->parent->left = y;
		else
			x->parent->right = y;

		y->left = x;
		x->parent = y;
	}

	void rightRotate(RBT_node x) {
		RBT_node y = x->left;
		x->left = y->right;

		if (y->right != RBT)
			y->right->parent = x;

		y->parent = x->parent;

		if (x->parent == nullptr)
			this->root = y;
		else if (x == x->parent->right)
			x->parent->right = y;
		else
			x->parent->left = y;

		y->right = x;
		x->parent = y;
	}

	void insert(int val) {
		RBT_node newnode = new node;
		newnode->parent = nullptr;
		newnode->data = val;
		newnode->left = RBT;
		newnode->right = RBT;
		newnode->color = 1;

		RBT_node y = nullptr;
		RBT_node x = this->root;

		while (x != RBT) {
			y = x;
			if (newnode->data < x->data)
				x = x->left;
			else
				x = x->right;
		}

		newnode->parent = y;
		if (y == nullptr)
			root = newnode;
		else if (newnode->data < y->data)
			y->left = newnode;
		else
			y->right = newnode;

		if (newnode->parent == nullptr) {
			newnode->color = 0;
			return;
		}

		if (newnode->parent->parent == nullptr)
			return;

		RBInsert(newnode);
	}

	RBT_node getRoot() {
		return this->root;
	}

	void deleteNode(int data) {
		deleteNode(this->root, data);
	}

	RBT_node SearchTree(RBT_node node, int val) {
		int found = 0;
		while (node != NULL && found == 0)
		{
			if (val == node->data) {
				found = 1;
				return node;
			}
			if (found == 0)
			{
				if (val < node->data)
					node = node->left;
				else
					node = node->right;
			}

		}
		return NULL;
	}

};

void main() {
	RBTree tree;

	tree.insert(1);
	tree.insert(2);
	tree.insert(3);
	tree.insert(4);
	tree.insert(5);
	tree.insert(6);
	tree.insert(7);
	tree.inorder();
	cout << "\n";
	tree.deleteNode(2);
	cout << "\n";
	tree.inorder();

}