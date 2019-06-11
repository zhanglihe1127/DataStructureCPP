#ifndef LIST_HPP
#define LIST_HPP

#include<iostream>

class LinkList{

public:
    struct ListNode{
        int data;
        ListNode* next;
        ListNode(int val): 
            data(val), next(NULL) {}
    };
    
public: 
    LinkList();
    ~LinkList();

    void insertElementTail(int val); //尾部插入
    void insertElementFront(int val); //头部插入
    void insertElement(int k, int val); // 第k个节点后插入
    
    void deleteElementFront();  //尾部删除
    void deleteElementTail();   //头部删除
    void removeAll(int val);    //删除链表中所有val
    void clear();

    ListNode* find(int val);  //查找节点并返回这个节点
    int getLength();   //获取链表长度
    void reverse();    //链表反转

    void printLinkList();

private:
    ListNode* _head;

};

#endif //LIST_HPP