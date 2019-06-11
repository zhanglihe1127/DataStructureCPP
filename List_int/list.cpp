#include "list.hpp"

LinkList::LinkList():
    _head(NULL) {}

LinkList::~LinkList(){
    clear();
}

//尾部插入
void LinkList::insertElementTail(int val){
    if(NULL == _head) _head = new ListNode(val);
    else{
        ListNode* cur = _head;
        while(NULL != cur->next){
            cur = cur->next;
        }
        ListNode* p = new ListNode(val);
        cur->next = p;
        
        cur = cur->next;
        // cur = _head->next;
    }
}

//头部插入
void LinkList::insertElementFront(int val){
    if(NULL == _head) _head = new ListNode(val);
    else{
        ListNode* cur = new ListNode(val);
        cur->next = _head;
        _head = cur;
    }
}

// 第k个节点后插入(当k大于链表长度时,cout提示一下，同时插在尾部，小于0时插入头部)
void LinkList::insertElement(int k, int val){
    if(k<=0) insertElementFront(val);
    else if(k>getLength()){
        std::cout << "The insert number larger than the List length" << std::endl;
        insertElementTail(val);
    }
    else{
        ListNode* cur = _head;
        for(int i=1; i<k; i++){
            cur = cur->next;
        }
        ListNode* p = new ListNode(val);
        p->next = cur->next;
        cur->next = p;
    }
}

//头部删除
void LinkList::deleteElementFront(){
    if(NULL == _head) std::cout << "No element!" << std::endl;
    else{
        ListNode* cur = _head;
        cur = cur->next;
        _head = cur;
    }
}

//尾部删除
void LinkList::deleteElementTail(){
    if(NULL == _head) std::cout << "No element!" << std::endl;
    else{
        ListNode* cur = _head;
        while(NULL != cur->next){
            if(NULL == cur->next->next) break;
            cur = cur->next;
        }
        if(NULL == cur->next) _head=NULL;
        else cur->next = NULL;
    }
}

//删除链表中所有val
void LinkList::removeAll(int val){
    if(NULL == _head) return ;
    while(_head->data == val) deleteElementFront();
    if(NULL == _head) return ;

    ListNode* cur = _head->next;
    ListNode* p = _head;

    while(NULL != cur){
        if(cur->data == val) p = cur->next;
        else p = p->next;

        cur = cur->next;
    }
}

void LinkList::clear(){
    if(NULL == _head) return ;

    ListNode* cur = _head;
    while(NULL != cur){

        _head = _head->next;
        delete cur;
        cur = _head;
    }
    _head = NULL;
}

//查找节点并返回这个节点
LinkList::ListNode* LinkList::find(int val){
    ListNode* cur = _head;
    while(NULL != cur){
        if(cur->data == val) return cur;
        cur = cur->next;
    }
    return NULL;
}

//获取链表长度
int LinkList::getLength(){
    int listLen = 0;
    ListNode* cur = _head;
    while(NULL != cur){
        listLen++;
        cur = cur->next;
    }
    return listLen;
}

//链表反转, 不使用额外节点存储空间
void LinkList::reverse(){

    ListNode* cur = _head;
    ListNode* pNode = NULL;

    while(NULL != cur){
        ListNode* pNext = cur->next;

        if(NULL == pNext) _head = cur;

        cur->next = pNode;
        pNode = cur;

        cur = pNext;
    }
}   

void LinkList::printLinkList(){
    if(NULL == _head) return ;
    ListNode* cur = _head;
    while(NULL != cur){
        std::cout << cur->data << " ";
        cur = cur->next;
    }
    std::cout << std::endl;
}

