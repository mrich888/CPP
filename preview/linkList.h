#ifndef __LINKLIST_H_
#define __LINKLIST_H_

class Node
{
public:
    int data;
    Node *next;
};

class LinkList
{
private:
    char *head;
    char *tail;
    
public:
    void init();
    void headInsert();
    void taildelete();

};



#endif// __LINKLIST_H_