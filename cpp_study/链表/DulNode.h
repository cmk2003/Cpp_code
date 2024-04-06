#include <iostream>
#include <utility>
using namespace std;

#ifndef C__CODE_LINKNOTE_H
#define C__CODE_LINKNOTE_H

#endif //C__CODE_LINKNOTE_H

class DulNode{
public:
    string data;

    DulNode* prior;
    DulNode* next;
    explicit DulNode(string data){
        this->data = std::move(data);
        this->next = nullptr;
        this->prior = nullptr;
    }
};
