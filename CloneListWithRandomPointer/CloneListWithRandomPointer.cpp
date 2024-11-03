// CloneListWithRandomPointer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

class ListNode
{
public:
    int data;
    ListNode* next;
    ListNode* random;
    ListNode(int d)
        : data(d)
        , next(nullptr)
        , random(nullptr)
    {}
};

ListNode* GetListFromInput(ListNode** ppHead, int count)
{
    if (count == 0)
        return nullptr;

    std::cout << "Enter " << count << " numbers of the list: ";
    ListNode* pTail = *ppHead;
    for (int i = 0; i < count; ++i)
    {
        int data = 0;
        std::cin >> data;
        if (*ppHead == nullptr)
        {
            *ppHead = new ListNode(data);
            pTail = *ppHead;
        }
        else
        {
            pTail->next = new ListNode(data);
            pTail = pTail->next;
        }
    }

    return pTail;
}

int GetIndexOfRandomNode(ListNode* pHead, ListNode* pNode)
{
    if (pHead == nullptr)
        return -1;

    int index = 0;
    while (pHead != pNode)
    {
        pHead = pHead->next;
        ++index;
    }

    if (pHead == nullptr)
        return -1;

    return index;
}

ListNode* GetNodeByIndex(ListNode* pHead, int index)
{
    if (index == -1)
        return nullptr;

    for (int i = 0; i < index; ++i)
    {
        pHead = pHead->next;
    }

    return pHead;
}

ListNode* CloneTheLinkedList(ListNode* originalHead)
{
    if (originalHead == nullptr)
        return nullptr;

    ListNode* pClonedNode = new ListNode(originalHead->data);
    ListNode* pCurrentNewNode = pClonedNode;
    ListNode* pCurOriginal = originalHead->next;
    while (pCurOriginal)
    {
        pCurrentNewNode->next = new ListNode(pCurOriginal->data);
        pCurrentNewNode = pCurrentNewNode->next;
        pCurOriginal = pCurOriginal->next;
    }

    pCurrentNewNode = pClonedNode;
    pCurOriginal = originalHead;
    while (pCurOriginal != nullptr)
    {
        if (pCurOriginal->random == nullptr)
            pCurrentNewNode->random = nullptr;
        else
        {
            int index = GetIndexOfRandomNode(originalHead, pCurOriginal->random);
            pCurrentNewNode->random = GetNodeByIndex(pClonedNode, index);
            pCurrentNewNode = pCurrentNewNode->next;
        }
        pCurOriginal = pCurOriginal->next;
    }

    return pClonedNode;
}

void PrintList(ListNode* pHead)
{
    std::cout << "{" << pHead->data << ", " << (pHead->random ? pHead->random->data : -1) << "}";
    pHead = pHead->next;

    while (pHead != nullptr)
    {
        std::cout << ", {" << pHead->data << ", " << (pHead->random ? pHead->random->data : -1) << "}";
        pHead = pHead->next;
    }

    std::cout << std::endl;
}

void FreeList(ListNode* pNode)
{
    if (pNode == nullptr)
        return;

    FreeList(pNode->next);
    delete pNode;

}

int main()
{
    while (true)
    {
        int count = 0;
        std::cout << "Number of nodes in list: ";
        std::cin >> count;
        if (count == 0)
            break;

        ListNode* pOrignalHead = nullptr;
        ListNode* pOriginalTail = GetListFromInput(&pOrignalHead, count);
        
        ListNode* pCurrentOriginal = pOrignalHead;
        std::cout << "Enter indexes of the random pointer of all nodes: ";
        for (int i = 0; i < count; ++i)
        {
            int index = 0;
            std::cin >> index;
            pCurrentOriginal->random = GetNodeByIndex(pOrignalHead, index);
            pCurrentOriginal = pCurrentOriginal->next;
        }

        ListNode* pCloned = CloneTheLinkedList(pOrignalHead);
        
        std::cout << "Original: ";
        PrintList(pOrignalHead);
        FreeList(pOrignalHead);
        std::cout << "Cloned: ";
        PrintList(pCloned);
        FreeList(pCloned);
    }
}
