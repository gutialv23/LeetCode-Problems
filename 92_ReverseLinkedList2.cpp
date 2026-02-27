// 206_ReverseLinkedList.cpp.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/reverse-linked-list-ii/description/
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* prevLeft = nullptr;
        ListNode* prev = nullptr;
        ListNode* curr = head;

        for (int i = 1; i < right + 1; ++i)
        {
          if (i + 1 == left) {
            prevLeft = curr;
          }

          if (i >= left && i < right)
          {
            ListNode* aux = curr->next;
            curr->next = prev;
            
            prev = curr;
            curr = aux;
          }
          else if (i == right) {
            ListNode newRight = (prevLeft ? prevLeft->next : head);
            if (prevLeft) {
              prevLeft->next = curr;
            }
            
            ListNode* aux = curr->next;
            curr->next = prev;
            
            newRight->next = aux;
          }
          else
          {
            curr = curr->next;
          }
        }

        return (prevLeft ? head : curr);
    }
};


1 -> 2 -> 3 -> 4 -> 5
1 -> 3 -> 2 -> 4 -> 5
1 -> 


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
