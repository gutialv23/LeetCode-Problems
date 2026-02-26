// 141_LinkedListCycle.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/linked-list-cycle/
//

#include <iostream>
#include <vector>
#include <unordered_map>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* ptr1 = head;
        ListNode* ptr2 = head->next;

        while (ptr1 != ptr2 && ptr2 != NULL) {
          ptr1 = ptr1->next;
          ptr2 = ptr2->next;
          if (ptr2) ptr2 = ptr2->next;
        }

        return ptr1 == ptr2 && ptr1 != NULL;
    }
};

int main()
{
  // TODO: fill.
  return 0;
}
