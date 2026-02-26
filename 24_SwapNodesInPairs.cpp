// 24_SwapNodesInPairs.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/swap-nodes-in-pairs/
//

#include <iostream>
#include <vector>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
  static ListNode* swapPairs(ListNode* head)
  {
    if (!head)
    {
      return nullptr;
    }

    ListNode* l = head;
    ListNode* r = head->next;

    // Pick new head.
    ListNode* newHead = l;
    if (r) newHead = r;

    while (l && r)
    {
      // Flip pointers.
      ListNode* aux = r->next;
      r->next = l;
      l->next = (aux && aux->next ? aux->next : aux);

      // Move forward.
      l = aux;
      r = (aux ? aux->next : nullptr);
    }

    return newHead;
  }
};


int main()
{
  //std::vector<int> nums{ 1,12,-5,-6,50,3 };
  ListNode n4(4);
  ListNode n3(3, &n4);
  ListNode n2(2, &n3);
  ListNode n1(1, &n2);

  std::cout << Solution::swapPairs(&n1);

  return 0;
}
