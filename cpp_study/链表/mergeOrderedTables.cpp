#include <iostream>
#include <vector>
using namespace std;

// 链表节点定义
template<typename T>
struct ListNode {
    T val;
    ListNode* next;
    ListNode(T x) : val(x), next(nullptr) {}
};

// 有序链表合并函数
template<typename T>
ListNode<T>* mergeSortedLists(ListNode<T>* l1, ListNode<T>* l2) {
    // 创建一个虚拟头节点，简化边界条件处理
    ListNode<T> dummy{T()};
    ListNode<T>* tail = &dummy;

    while (l1 != nullptr && l2 != nullptr) {
        if (l1->val <= l2->val) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }

    // 直接连接剩余部分
    tail->next = (l1 != nullptr) ? l1 : l2;

    return dummy.next;
}
// 删除有序链表中的重复元素
template<typename T>
void deleteDuplicates(ListNode<T> *&head) {
    ListNode<T> *current = head;
    while (current != nullptr && current->next != nullptr) {
        if (current->val == current->next->val) {
            ListNode<T> *temp = current->next;
            current->next = current->next->next;
            delete temp; // 释放被删除节点的内存
        } else {
            current = current->next;
        }
    }
}
// 辅助函数：打印链表
template<typename T>
void printList(ListNode<T>* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

// 辅助函数：创建链表
template<typename T>
ListNode<T>* createList(const vector<T>& vals) {
    ListNode<T>* dummy = new ListNode<T>(T());
    ListNode<T>* tail = dummy;
    for (const T& val : vals) {
        tail->next = new ListNode<T>(val);
        tail = tail->next;
    }
    ListNode<T>* head = dummy->next;
    delete dummy;
    return head;
}

// 主函数
int main() {
    // 示例：创建两个有序链表
    ListNode<int>* list1 = createList(vector<int>{1, 2, 4});
    ListNode<int>* list2 = createList(vector<int>{1, 3, 4});

    // 合并链表
    ListNode<int>* mergedList = mergeSortedLists(list1, list2);

    // 打印合并后的链表
    printList(mergedList);

    // 删除重复值
    deleteDuplicates(mergedList);
    printList(mergedList);

    // 清理内存
    while (mergedList != nullptr) {
        ListNode<int>* temp = mergedList;
        mergedList = mergedList->next;
        delete temp;
    }

    return 0;
}
