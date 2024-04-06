#include <iostream>
#include <utility>
#include "LinkNote.h"
using namespace std;
// 循环链表类定义
class CircularLinkedList {
private:
    LinkNote* head;

public:
    CircularLinkedList() : head(nullptr) {}
    CircularLinkedList(LinkNote * head) : head(head) {}

    // 析构函数，用于删除链表，防止内存泄漏
//    ~CircularLinkedList() {
//        if (head) {
//            LinkNote* temp = head;
//            while (temp->next != head) { // 遍历链表
//                LinkNote* next = temp->next;
//                delete temp;
//                temp = next;
//            }
//            delete head; // 删除最后一个节点
//        }
//    }

    // 插入节点到链表
    void insert(string data) {
        LinkNote* newNode = new LinkNote(data);
        if (!head) {
            head = newNode;
            newNode->next = head; // 形成循环
        } else {
            LinkNote* temp = head;
            while (temp->next != head) { // 找到最后一个节点
                temp = temp->next;
            }
            temp->next = newNode; // 插入新节点
            newNode->next = head; // 形成循环
        }
    }

    // 打印链表
    void print() {
        if (!head) return;

        LinkNote* temp = head;
        do {
            cout << temp->data << " --> ";
            temp = temp->next;
        } while (temp != head); // 由于是循环链表，使用 do-while 循环
        cout<<temp->data<<endl;
        cout << endl;
    }
    CircularLinkedList connect(CircularLinkedList L2){
        if (head == nullptr){
            head=L2.head;
            return CircularLinkedList(head);
        }
        if (L2.head == nullptr) {
            return CircularLinkedList(head);
        }
        //把当前链表和另外一个链表连接起来 L1的头节点
        LinkNote * l1_head=head;
        LinkNote * l2_head=L2.head;

        do {
            l1_head=l1_head->next;
        } while (l1_head->next!=head);

        LinkNote * temp=l2_head; //l2的尾节点
        do {
            temp=temp->next;
        } while (temp->next!=l2_head);

        l1_head->next=l2_head;
        temp->next=head;
        cout << head->data << endl;
        return CircularLinkedList(this->head);
    }

};



// 主函数，展示如何使用 CircularLinkedList 类
int main() {
    CircularLinkedList list1;

//    list1.insert("1");
//    list1.insert("2");
//    list1.insert("3");

    cout << "Circular Linked List1: ";
    list1.print();
    cout<<endl;

    CircularLinkedList list2;

    list2.insert("4");
    list2.insert("5");
    list2.insert("6");

    cout << "Circular Linked List2: ";
    list2.print();
    cout<<endl;

    cout << "Circular Linked List3: ";
    CircularLinkedList list3=list1.connect(list2);
    list3.print();



    return 0;
}


