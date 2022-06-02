#include<iostream>
#include<cstdlib>
using namespace std;

template<typename C>
class Iterable{
    public: 
        virtual bool hasNext()=0;
        virtual C getNext()=0;
        virtual void reset()=0;
};

template<typename T>
class Node:public Iterable<Node<T>*>{
    private:
        T key;
        Node<T> *next;
    public:
        Node(T key){
            this->key=key;
            next=NULL;
        }
        bool hasNext(){
            if(next!=NULL)
            return 1;
            return 0;
        }
        Node<T>* getNext(){
            return next;
        }
        void reset(){
            key=0;
            next=NULL;
        }
        T getKey(){
            return key;
        } 
        void setNext(Node <T>* Nod){
            next=Nod;
        }
        void setKey(T key){
            this->key=key;
        }
};

template<typename T>
class Queue{
    private:
        Node<T>* head;
        Node<T>* last;
        int size;
    public:
        Queue(){
            head=NULL;
            last=NULL;
            size=0;
        }
        Queue<T>* enqueue(T k){ 
            Node<T> *newNode=new Node<T>(k);
            if(!head) head=last=newNode;
            else{
                last->setNext(newNode);
                last=newNode;
            }
            size++;
            return this;
        }
        Queue<T>* dequeue(){
            if(size==0)
            return this;
            T k;
            Node<T> *aux=head;
            head=aux->getNext();
            k=aux->getKey();
            delete aux;
            size--;
            return this;
        }
       void print(){
            Node<T> *aux=head;
            for(int i=0;i<size;i++){
                cout<<i<<": ["<<aux->getKey()<<"]"<<endl;
                aux=aux->getNext();
            }
        }
};


int main()
{
    Queue<int> *q=new Queue<int>;
    q->enqueue(10)->enqueue(12)->dequeue()->enqueue(15)->enqueue(2)->enqueue(3)->dequeue()->print();
    return EXIT_SUCCESS;
}