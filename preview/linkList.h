#ifndef __LINKLIST_H_
#define __LINKLIST_H_

class LinkList
{
private:
    int data;
    int len;
    char *next;
    char *head;
    char *tail;
    
public:
    void init();//初始化
    void headInsert();
    void taildelete();

};



#endif// __LINKLIST_H_