// 206_ReverseLinkedList.cpp.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/reverse-linked-list/
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

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
      if (!head) return nullptr;

      ListNode* ptr0 = nullptr;
      ListNode* ptr1 = head;

      while (ptr1) {
        ListNode* aux = ptr1->next;
        ptr1->next = ptr0;

        ptr0 = ptr1;
        ptr1 = aux;
      }

      return ptr1 ? ptr1 : ptr0;
    }
};


int main()
{
  //std::vector<int> nums{ 1,12,-5,-6,50,3 };
  ListNode n5(5);
  ListNode n4(4, &n5);
  ListNode n3(3, &n4);
  ListNode n2(2, &n3);
  ListNode n1(1, &n2);

  std::cout << Solution::swapPairs(&n1);

  return 0;
}
