#include<iostream>
#include<cstdlib>
using namespace std;

template<typename T> class Node{
//typename and class are equivalent.
    private:
        T key;
        Node<T> *next;
    public:
        Node(T key){
            this->key=key;
            next=NULL;
        }
        Node(T key,Node<T> *next){
            this->key=key;
            this->next=next;
        }
        T getKey(){
            return key;
        }
        Node<T> *getNext(){
            return next;
        }
        void setKey(T key){
            this->key=key;
        }
        void setNext(Node<T> *next){
            this->next=next;
        }
        void print(){
            cout<<"["<<key<<"]"<<endl;
        }
};

template<typename T> class List{
    private:
        int size;
        Node<T> *head;
        Node<T> *last;
    public:
        List(){
            size=0;
            head=NULL;
            last=NULL;
        } 
        int getSize(){
            return size;
        }
        List<T>* pushFront(T k){
            Node<T> *newNode=new Node<T>(k);
            if(head!=NULL){
                newNode->setNext(head);
            }
            else
            last=newNode;
            head=newNode;
            size++;
            return this;
        }
        List<T>* pushBack(T k){
            Node<T> *newNode=new Node<T>(k);
            if(head==NULL)
                head=newNode;
            else
                last->setNext(newNode);
            last=newNode;
            size++;
            return this;
        }
        void print(){
            Node<T> *aux=head;
            for(int i=0;i<size;i++){
                cout<<"Node "<<i<<": ";
                aux->print();
                aux=aux->getNext();
            }
            cout<<endl<<"Number of Nodes:"<<getSize()<<endl;
        }
        List<T>* deleteNodeWithIndex(int n){
            if(n >= getSize() || n < 0){
                cout<<"Node not Found "<<n<<endl;
                return this;
            }
            Node<T> *aux=head;
            Node<T> *aux2=head;
            if(n==0) head=aux->getNext();
            else{
                for(int i=0;i<n-1;i++)
                aux2=aux2->getNext();
                aux=aux2->getNext();
                aux2->setNext(aux->getNext());
            }
            delete aux;
            size--;
            return this;
        }
};

void printSeparator() {
    for(int i=0;i<100;i++) cout<<'_';
        cout<<endl;
}

int main(){
    List<int> *listInt=new List<int>;
    listInt->pushBack(4)->pushBack(6)->pushFront(8)->pushBack(2)->deleteNodeWithIndex(3)->pushFront(1)->print();

    printSeparator();
    
    List<string> *listString=new List<string>;
    listString->pushBack("dolor")->pushBack("sit")->pushFront("ipsum")->pushBack("amet")->deleteNodeWithIndex(3)->pushFront("lorem")->print();


    return EXIT_SUCCESS;
}