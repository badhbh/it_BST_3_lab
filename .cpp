#include <iostream>

using namespace std;

template <class T, class compare = std::less<T>>
class BST
{
private:

	T key;
	//BST *parent;
	BST *left;
	BST *right;

	BST *top = NULL;
public:
	BST()
	{}
	BST(const BST& *jojo) {
		key = jojo->key;
		left = new BST(jojo->left);
		right = new BST(jojo->right);
	}

	BST* insert(T val) {
		if (*this == NULL) {
			key = val;
			left = right = NULL;
		}
		else if (val < key) {
			left = new BST(*this);
			left = left->insert(val);
		}
		else if (val > key) {
			right = new BST(jojo);
			right = right->insert(val);
		}
		return *this;
	}

	BST *min() {
		if (*this == NULL)
			return NULL;
		else if (left == NULL)
			return *this;
		else
			return min(left);
	}

	BST *max() {
		if (*this == NULL)
			return NULL;
		else if (right == NULL)
			return *this;
		else
			return max(right);
	}

	BST* remove(T val) {
		if (*this == NULL)
			return *this;
		else if (val < key)
			left = left->remove(val);
		else if (val > key)
			right = right->remove(val);
		else if (left != NULL && right != NULL)
		{
			key = min(right).key;
			right = right->remove(val);
		}
		else if (left != NULL)
			*this = left;
		else
			*this = right;
		return *this;
	}
	BST* search(T val) {
		if (*this = NULL || val == this->key) {
			return *this;
		}
		else if(val < this->key) {
			return left->search(val);
		}
		else {
			return right->search(val);
		}
	}
	

		class iterator {
		private:

		BST * top;
		BST *n2;

		public:
		iterator() {}
		iterator(BST *node, BST *n2){
			this->node = node;
			this->n2 = n2;
		}

		T operator *() {
		return n2->key;
		}
		bool operator != (const iterator& jojo) {
		return this->n2 != jojo.n2;
		}
		bool operator == (const iterator& jojo) {
		return this->n2 == jojo.n2;
		}
		iterator& operator ++ () {
		compare k = compare();
		BST *current = top;
		BST *successor = NULL;
		if (comp(n2->key, current->key)) {
			successor = current;
			current = current->left;
		}
		else {
			current = current->right;
		}
		this->n2 = successor;
		return *this;
		}
		iterator& operator --() {
		compare k = compare();
		BST *current = top;
		BST *successor = NULL;
		if (comp(n2->key, current->key)) {
			successor = current;
			current = current->right;
		}
		else {
			current = current->left;
		}

		this->n2 = successor;
		return *this;
		}
		};
		
		class citerator {
		private:
			BST *top;
			const BST *n1;
		public:
			citerator() {}
			citerator(BST *top, BST *n1){
				this->top = top;
				this->n1 = n1;
			}

			T operator *() {
				return n1->key;
			}
			bool operator != (const citerator& jojo) {
				return n1 != jojo.n1;
			}
			bool operator == (const citerator& jojo) {
				return this->n1 == jojo.n1;
			}
			citerator& operator ++ () {
				compare k = compare();
				BST *current = top;
				BST *successor = NULL;
				if (comp(n1->key, current->key)) {
					successor = current;
					current = current->left;
				}
				else {
					current = current->right;
				}

				this->n1 = successor;
				return *this;
			}
			citerator& operator --() {
				compare k = compare();
				BST *current = top;
				BST *successor = NULL;
				if (comp(n1->key, current->key)) {
					successor = current;
					current = current->right;
				}
				else {
					current = current->left;
				}

				this->n1 = successor;
				return *this;
			}
		};
		
		iterator begin() {
			iterator iter(min(top), top);
			return iter;
		}
		citerator cbegin() {
			citerator citer(min(top), top);
			return citer;
		}
		iterator end() {
			iterator iter(max(top), top);
			return citer;
		}
		citerator end() {
			citerator citer(max(top), top);
			return citer;
		}
		iterator insert(const T & value) {
			if (top->search(value) == NULL) {
				top = top->insert(value;)
			}
			else { break; }
			return
		}
		iterator remove(const T &value) {

		}
		iterator find(const T &value) {
			iterator iter(top->search(value), top);
			return iter;
		}
		citerator cfind(const T &value) const {

		}

};
		

int main(){
return 0;
}
	


