#include <iostream>
#include <utility>
using namespace std;

#ifndef C__CODE_LINKNOTE_H
#define C__CODE_LINKNOTE_H

#endif //C__CODE_LINKNOTE_H
class LinkNote{
public:
    string data;
    LinkNote *next;

    // Constructor
    explicit LinkNote(string data){
        this->data = std::move(data);
        this->next = nullptr;
    }
};