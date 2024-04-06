#include <iostream>
#include <utility>
#include "DulNode.h"
using namespace std;
// 双向链表类定义
class dulLinkList{
private:
    DulNode * head;

public:
    dulLinkList(){
        this->head= nullptr;
    }

    void insert(string data) {
        auto * node=new DulNode(std::move(data));
        if (head== nullptr) {
            this->head=node;
            head->next=head;
            head->prior=head;
        } else {
            DulNode * temp=head;
            //找到最后一个节点
            do{
                temp=temp->next;
            }while (temp->next!=head);
            temp->next=node;
            node->prior=temp;
            node->next=head;
            head->prior=node;
        }

    }

    void print(){
        DulNode * temp=head;
        do{
            cout<<temp->data<<" <--> ";
            temp=temp->next;
        }while (temp!=head);
        cout<<head->data;
        cout<<endl;
    }
    int getLength() {
        int length=0;
        auto * temp=head;
        do{
            length++;
            temp=temp->next;
        }while (temp!=head);
        cout << length << endl;
        return length;
    }
    void insertBefore(DulNode * node){
        DulNode * lastNode=head->prior;
        node->next=head;
        head->prior=node;
        lastNode->next=node;
        node->prior=lastNode;
        head=node;
    }

    void insert(string data,int pos) {
        if (pos == this->getLength()) {
            //尾插
            insert(data);
        }
        if (pos > this->getLength() || pos < 0) {
            return;
        }
        auto * node=new DulNode(std::move(data));
        DulNode * before=nullptr;
        auto * after=head;

        for (int i = 0; i < pos-1; ++i) {
            before=after;
            after=after->next;
        }
        if (before== nullptr) {
            //说明是在第一个插入
            //找到最后一个节点
            insertBefore(node);
        } else {
            //中间插入
            before->next=node;
            node->prior=before;
            node->next=after;
            after->prior=node;
        }
    }

    void deleteByPos(int pos){
        if (pos > this->getLength() || pos < 0) {
            return;
        }

        //找到pos处的节点
        DulNode * temp=head;
        for (int i = 0; i < pos - 1; ++i) {
            temp=temp->next;
        }
        DulNode * before=temp->prior;
        DulNode * after=temp->next;
        before->next=after;
        after->prior=before;
        head=after;
        delete temp;
    }
};

int main(){

    dulLinkList list;

    list.insert("1");
    list.insert("2");
    list.insert("3");

    list.insert("2.5",2);

    list.print();

    list.deleteByPos(1);
    list.deleteByPos(1);
    list.deleteByPos(1);
    list.print();

    return 0;

}
