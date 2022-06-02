#include<iostream>
#include<cstdlib>
using namespace std;

template<class T>class Node
//typename and class are equivalent.
{
    private:
        T key;
        Node<T> *next;
    public:
        Node(T key)
        {
            this->key=key;
            next=NULL;
        }
        void setKey(T key)
        {
            this->key=key;
        }
        void setNext(Node<T>* next)
        {
            this->next=next;
        }
        T getKey()
        {
            return key;
        }
        Node<T>* getNext()
        {
            return next;
        }
};

template<class T>class Stack
{
    private:
        Node<T>* head;
        Node<T>* tail;
        int size;
    public:
        Stack()
        {
            head=NULL;
            size=0;
        }
        Stack<T>* push(T elem)
        {
            Node<T> *newNode = new Node<T> (elem);
            if(head)
            newNode->setNext(head);
            head = newNode;
            size++;
            return this;
        }
        T pop()
        {
            if(!head)
            return 0;
            T k;
            Node<T>* aux=head;
            k=head->getKey();
            head=head->getNext();
            delete aux;
            size--;
            return k;
        }
        void print()
        {
            Node<T>* aux=head;
            for(int i=size-1;i>=0;i--)
            {
                cout<<i<<" : ["<<aux->getKey()<<"]"<<endl;
                aux=aux->getNext();
            }
        }
};


int main()
{
    Stack<int> *stackInt=new Stack<int>;
    stackInt->push(7)->push(3)->push(2)->push(5);
    cout<<"Pop: "<<stackInt->pop()<<endl;
    stackInt->print();
    return EXIT_SUCCESS;
}