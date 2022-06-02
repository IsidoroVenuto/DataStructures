#include<iostream>
#include<cstdlib>
using namespace std;

template<class T>
class Node {
	private:
		T key;
		bool leaf;
		Node<T>* left;
		Node<T>* right;
		Node<T>* parent;
	public:
		Node(T key,Node<T>*parent) {
			this->key=key;
			this->parent=parent;
			left=NULL;
			right=NULL;
			leaf=1;
		}
		void setKey(T key){this->key=key;}
		void setParent(Node<T>* parent){this->parent=parent;}
		void setLeft(Node<T>* left){this->left=left;}
		void setRight(Node<T>* right){this->right=right;}
		void setLeaf(bool leaf){this->leaf=leaf;}
		T getKey(){return key;}
		Node<T>* getParent(){return parent;}
		Node<T>* getSx(){return left;}
		Node<T>* getDx(){return right;}
		bool isLeaf(){return leaf;}	
};



template<class T>
class Tree {
	private:
		Node<T>*root;
		int n;
	public:
		Tree() {
			root=NULL;
			n=0;
		}
		Tree<T>* add(T key) {
			Node<T>* y=NULL;
			Node<T>* x=root;
			while(x!=NULL) {
				y=x;
				if(x->getKey()>key)
				x=x->getSx();
				else
				x=x->getDx();
			}
			x=new Node<T>(key,y);
			if(y==NULL)
			root=x;
			else {
				if(y->getKey()>key)
				y->setLeft(x);
				else
				y->setRight(x);
				y->setLeaf(0);
			}
			n++;
			return this;
		}


		Node<T>* search(T key) {
			Node<T>* aux=root;
			while(aux!=NULL && aux->getKey()!=key)
			{
				if(aux->getKey()>key)
				aux=aux->getSx();
				else
				aux=aux->getDx();
			}
			return aux;
		}
		
		void inorder(Node<T>* x) {
			if(x!=NULL) {
				inorder(x->getSx());
				if(x->isLeaf())
				cout<<"[ "<<x->getKey()<<" ]l\t";
				else
				cout<<"[ "<<x->getKey()<<" ]\t";
				inorder(x->getDx());
			}
		}
		
		void preorder(Node<T>*x) {
			if(x!=NULL) {
				if(x->isLeaf())
				cout<<"[ "<<x->getKey()<<" ]l\t";
				else
				cout<<"[ "<<x->getKey()<<" ]\t";
				preorder(x->getSx());
				preorder(x->getDx());
			}
		}
		
		void postorder(Node<T>* x) {
			if(x!=NULL) {
				postorder(x->getSx());
				postorder(x->getDx());
				if(x->isLeaf())
				cout<<"[ "<<x->getKey()<<" ]l\t";
				else
				cout<<"[ "<<x->getKey()<<" ]\t";
			}
		}
		void printInorder() {
			cout<<"Number Of Nodes "<<n<<endl;
			cout<<"Inorder:"<<endl;
			inorder(root);
			cout<<endl<<endl;
		}
		
		void printPostorder() {
			cout<<"Number Of Nodes "<<n<<endl;
			cout<<"Postorder:"<<endl;
			postorder(root);
			cout<<endl<<endl;
		}		
		
		void printPreorder() {
			cout<<"Number Of Nodes "<<n<<endl;
			cout<<"Preorder:"<<endl;
			preorder(root);
			cout<<endl<<endl;
		}	
		Tree<T>* del(T key) {
			Node<T>* aux=search(key);
			auxdel(aux);
			return this;
		}
		
		void auxdel(Node<T>* x)  {
			if(x==NULL) return;
			n--;
			Node<T> *y=x->getParent();
			if(x->isLeaf()) {
				if(y==NULL) root = NULL;
				else {
					if( x->getKey() > y->getKey() ) 
					y->setRight(NULL);
					else y->setLeft(NULL);
					if(y->getDx()==NULL) y->setLeaf(1);
				}
				return;
			}
			if( x->getSx()==NULL || x->getDx()==NULL) {
				Node<T> *z = x->getSx();
				if(z==NULL) z= x->getDx();
				if(y==NULL) root = z;
				else {
					if( z->getKey() > y->getKey() ) y->setRight(z);
					else y->setLeft(z); 
				}
				z->setParent(y);
				return;
			}
			Node<T> *w = predecessor(x);
			x->setKey(w->getKey());
			n++;
			return auxdel(w);
		}
		
		Node<T>* predecessor(Node<T> *x) {
			if(x==NULL) return x;
			if(x->getSx()!=NULL) return max(x->getSx());
			Node<T>* y=x->getParent();
			while(y!=NULL && y->getKey()>x->getKey()) y=y->getParent();
			return y;
		}	
		
		Node<T>* max(Node<T>* y) {
			Node<T>* x=y;
			if(x==NULL) return x;
			while(x->getDx()!=NULL)
			x=x->getDx();
			return x;
		}
};

void printSeparator() {
    for(int i=0;i<100;i++) cout<<'_';
        cout<<endl;
}


int main()
{
	Tree<int>* treeString=new Tree<int>;
    //Example with int type
	treeString->add(5)->add(6)->add(6)->add(8)->add(4);
	treeString->printInorder();
	treeString->printPostorder();
	treeString->printPreorder();
	treeString->del(6);
	treeString->printPreorder();
	
	printSeparator();

	Tree<string>* treeInt=new Tree<string>;
    //Example with string type
	treeInt->add("lorem")->add("ipsum")->add("dolor")->add("sit")->add("amet");
	treeInt->printInorder();
	treeInt->printPostorder();
	treeInt->printPreorder();
	treeInt->del("dolor");
	treeInt->printInorder();


	return EXIT_SUCCESS;
}
