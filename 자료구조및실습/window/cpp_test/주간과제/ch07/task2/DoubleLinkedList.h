#pragma once

typedef struct nodeData
{
    char name[20];
    char phone[14];
} NODE_DATA;

typedef struct nodeRecord
{
    struct nodeRecord *Prev; //DLinkedList에서 추가
    //int Data;
    NODE_DATA Data;
    struct nodeRecord *Next;
} NODE;


class DLinkedList
{
private:
    NODE *Head, *Tail;

public:
    DLinkedList(void);
    ~DLinkedList(void);

    // 노드 추가
    void Add(char name[], char phone[]);

    // 노드 삭제
    void Remove(char phone[]);
    void RemoveLastNode();
    void RemoveAll();

    // 전체 노드 개수
    int Count();

    // 모든 노드 출력
    void PrintAllList();

    // 모든 노드 반대로 출력
    void PrintAllListReverse(); //DLinkedList에서 추가

    // bool Exist(int Item);

    // void InsertAfter (int TargetItem, int Item);

    // void InsertBefore (int TargetItem, int Item);
};