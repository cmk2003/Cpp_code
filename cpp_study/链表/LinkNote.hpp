#include <iostream>
#include <utility>
#include "LinkNote.h"
using namespace std;



class LinkedList{
public:
    LinkNote *head;

public:
    // Constructor
    LinkedList(){
        head = nullptr;
    }

    // Function to insert a new node at the end
    void insert(string data){
        auto *newNode = new LinkNote(std::move(data));
        if(head == nullptr){
            head = newNode;
        }else{
            LinkNote *temp = head;
            while(temp->next != nullptr){
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // Function to print the linked list
    void print(){
        if (head== nullptr){
            return;
        }
        LinkNote *temp = head;
        while(temp != nullptr){
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
    void deleteAll(){
        LinkNote * p= this->head;//这个是头节点
        LinkNote * q;//双指针
        while (p!= nullptr){
            q=p->next;
            cout<<p->data<<" will be deleted"<<endl;
            delete p;
            p=q;
        }
        head = nullptr;
    }
     bool empty() {
        if (head == nullptr){
            return true;
        }
        return false;
    }
     int getLength() {
        int length=0;
        LinkNote * temp=head;
        while (temp != nullptr){
            length++;
            temp=temp->next;
        }
        cout << length << endl;
        return length;
    }
    void getValue(int pos) {
        if (pos > this->getLength() || pos < 0) {
            return;
        }
        LinkNote * temp=head;
        for (int i = 0; i < pos-1; ++i) {
            temp=temp->next;
        }
        cout<<temp->data<<endl;
    }
    void findPos(const string& data) {
        int pos=1;
        LinkNote * temp=head;
        while (temp != nullptr) {

            if (temp->data==data) {
                cout<<pos<<endl;
                return;
            }
            pos++;
            temp=temp->next;

        }
    }
    void insertBeforePos(int pos,string data){
        if (pos > this->getLength() || pos < 0) {
            return;
        }
        auto * node = new LinkNote(std::move(data));
        LinkNote * beforeNode;
        LinkNote * nowNode=head;


        for (int i = 0; i < pos - 1; ++i) {
            beforeNode=nowNode;
            nowNode=nowNode->next;
        }
        if (beforeNode == nullptr) {
            node->next=nowNode;
            head=node;
            return;
        }
        beforeNode->next=node;
        node->next=nowNode;

    }
    void deletePos(int pos){
        if (pos > this->getLength() || pos < 0) {
            return;
        }
        LinkNote * beforeNode= nullptr;
        LinkNote * nowNode=head;
        for (int i = 0; i < pos - 1; ++i) {
            beforeNode=nowNode;
            nowNode= nowNode->next;
        }
        if (beforeNode== nullptr){
            LinkNote * node=nowNode->next;
            head=node;
            delete nowNode;
            return;
        }
        beforeNode->next=nowNode->next;
        delete nowNode;
    }

    void insertBefore(const string& data){ //const保证了原始数据不会被修改 传入地址增加性能
        auto node=new LinkNote(data);
        node->next=head;
        head=node;
    }
};

//int main(){
//    LinkedList list;
//
//    list.insert("First");
//    list.insert("Second");
//    list.insert("Third");
//    list.insert("Fourth");
//    list.insert("Fifth");
//
//    list.print(); // Expected Output: First -> Second -> Third -> NULL
////    list.deleteAll();
////    cout<<list.empty()<<endl;
////    if(list.empty()){
////        cout<<"清空！"<<endl;
////    }
//    list.getLength();
//    list.getValue(4);
//    list.findPos("Fourth");
//    list.insertBeforePos(5,"before5");
//    list.print();
//    list.deletePos(1);
//    list.print();
//    list.insertBefore("bbbbb");
//    list.print();
//
//    return 0;
//}
