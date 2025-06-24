#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H

typedef struct DoublyListNodeType{
    int data;
    struct DoublyListNodeType* pLLink;
    struct DoublyListNodeType* pRLink;
}DoublyListNode;

typedef struct DoublyListType{
    int currentCount;
    DoublyListNode headerNode;
}DoublyList;

// function declaration
// ADT act - create, get , add, remove, length, display(print-all), delete
DoublyList* createDoublyList();
int getDoublyListData(DoublyList* pList, int position);
int addDoublyListData(DoublyList* pList, int position, int data);
int removeDoublyListData(DoublyList* pList, int position);
int getDoublyListLength(DoublyList* pList);
void displayDoublyList(DoublyList* pList);
void deleteDoublyList(DoublyList* pList);

#endif