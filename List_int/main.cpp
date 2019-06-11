#include<iostream>
#include "list.hpp"
// https://www.cnblogs.com/Lynn-Zhang/p/5396637.html
// https://blog.csdn.net/cangchen/article/details/45040259
// https://www.nowcoder.com/practice/75e878df47f24fdc9dc3e400ec6058ca?tpId=13&&tqId=11168&rp=2&ru=/activity/oj&qru=/ta/coding-interviews/question-ranking
// https://www.cnblogs.com/KGvito/p/8111047.html
using namespace std;

int main(){

    LinkList list;// = new LinkList();
    list.printLinkList();
    list.insertElementTail(1);
    list.printLinkList();
    list.insertElementTail(2);
    list.printLinkList();
    list.insertElementTail(3);
    list.printLinkList();
    list.insertElementFront(100);
    list.insertElementFront(101);
    list.insertElementFront(102);
    list.printLinkList();
    list.insertElement(3, 444);
    list.insertElement(4, 445);
    list.insertElement(5, 446);
    list.printLinkList();
    list.deleteElementFront(); 
    list.deleteElementFront(); 
    list.deleteElementFront(); 
    list.deleteElementFront(); 
    list.deleteElementFront(); 
    cout << "bb---" << endl;
    list.printLinkList();
    list.reverse();
    cout << "aa---" << endl;
    list.printLinkList();

    list.deleteElementTail();
    list.deleteElementTail();
    list.deleteElementTail();
    // list.deleteElementTail();
    
    list.removeAll(444);
    cout << "---" << endl;
    list.printLinkList();
    int l = list.getLength();  
    cout << l << endl;

    LinkList::ListNode* ss = list.find(3); 
    if(NULL != ss){
        cout << ss->data << endl;
    } 
    
    return 0;
}
