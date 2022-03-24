// https://leetcode.com/problems/odd-even-linked-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!(head && head->next && head->next->next)) return head;
        
        ListNode* element = head;
        ListNode* seam = head->next;
        ListNode* temp;
        bool evenStep = false;
        
        while (element->next->next) { // cycle stops 2 steps away from nullptr
            temp = element->next;
            element->next = element->next->next;
            element = temp;
            evenStep = !evenStep;
        };
        
        if (evenStep) {              // if we made even steps towards it, make another odd one
            temp = element->next;
            element->next = element->next->next;
            element = temp;
        }
        
        element->next = seam;   // seam is made two elements short of nullptr if step was not Even 
        
        return head;
    }
};