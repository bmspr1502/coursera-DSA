#include <iostream>
using namespace std;

class Node{
    int value;
    class Node* prev;
    class Node* next;

    public:
    Node(){
        value = 0;
        prev= NULL;
        next = NULL;
    }

    int getValue(){return value;}
    Node* getPrev(){return prev;}
    Node* getNext(){return next;}
    void setValue(int x){value = x;}
    void setPrev(Node* x){prev = x;}
    void setNext(Node* x){next =x;}
}*head = NULL, *tail = NULL;

void insert(Node* pos, Node* ins){
    if(pos->getNext() == NULL){
        ins->setPrev(pos);
        pos->setNext(ins);
        ins->setNext(NULL);
        tail = ins;
    }
    else{
    ins->setPrev(pos);
    ins->setNext(pos->getNext());
    pos->setNext(ins);
    ins->getNext()->setPrev(ins);
    }
}

void viewFwd(){
    Node* ptr = head;
    while(ptr!=NULL){
        cout<<ptr->getValue()<<"->";
        ptr = ptr->getNext();
    }

    cout<<'\n';
}

void viewBwd(){
    Node* ptr = tail;
    while(ptr!=NULL){
        cout<<ptr->getValue()<<"<-";
        ptr = ptr->getPrev();
    }

    cout<<'\n';
}

void insBeg(){
    Node* ptr = new Node;
    int temp;
    cin>>temp;
    ptr->setValue(temp);

    if(head==NULL && tail==NULL){
        head = ptr;
        tail = ptr;
    } else {
        ptr->setNext(head);
        head->setPrev(ptr);
        head = ptr;
    }
}

void insEnd(){
    Node* ptr = new Node;
    int temp;
    cin>>temp;
    ptr->setValue(temp);

    if(head==NULL && tail==NULL){
        head = ptr;
        tail = ptr;
    } else {
        tail->setNext(ptr);
        ptr->setPrev(tail);
        tail = ptr;
    }
}

int findEle(int x){
    Node* ptr = head;
    int count = 0, found = 0;
    while(ptr!=NULL){
        count++;
        if(ptr->getValue() == x){
            found = 1;
            break;
        }
        ptr = ptr->getNext();
    }
    if(found==0)
        return -1;
    else
        return count;
}


Node* findpos(int x){
    Node* ptr = head;
    while(ptr!=NULL){
        if(ptr->getValue() == x)
            break;
        ptr = ptr->getNext();
    }
    return ptr;
}

void insBtw(){
    int ele;
    cout<<"\nEnter the value after which you want to insert the element: ";
    cin>>ele;
    if(findEle(ele)==-1)
        cout<<"Element Not Found";
    else
    {
        Node *temp = findpos(ele);
        Node *ins = new Node;
        int x;
        cout<<"Enter new Value: ";
        cin>>x;
        ins->setValue(x);

        insert(temp, ins);
    }
}

void delVal(int x){
    Node *pos = findpos(x);
    if(pos==NULL){
        cout<<"Element NOt Found;";
    } else {
        pos->getPrev() ->setNext(pos->getNext());
        pos->getNext() ->setPrev(pos->getPrev());
        delete(pos);  
    }
}

int main(){
    int choice=0;
    int temp;
    do{
        start:
        cout<<"\nMenu\n1.Insert at Head\n2.Insert at tail\n3.View Forward\n4.View Backward\n5.Insert after an Element";
        cout<<"\n6.Find an Element\n7.Delete an Element\n8.Exit\nEnter choice(1-8)";
        cin>>choice;

        switch (choice)
        {
        case 1:
            cout<<"\nEnter Value:";
            insBeg();
            break;
        case 2:
            cout<<"\nEnter Value:";
            insEnd();
            break;
        
        case 3:
            viewFwd();
            break;

        case 4:
            viewBwd();
            break;

        case 5:
            insBtw();
            break;
        case 6:
            cout<<"Enter the element to find:";
            cin>>temp;
            temp=findEle(temp);
            if(temp==-1)
                cout<<"Element Not Found";
            else
                cout<<"Element Found at "<<temp;
            break;
        
        case 7:
            cout<<"Enter the element to Delete: ";
            cin>>temp;
            delVal(temp);
            break;
        
        case 8:
            break;
        default:
            goto start;
            break;
        }
    }while(choice>=1 && choice<=7);
    return 0;
}
