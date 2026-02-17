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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head){
            return head;
        }
        ListNode* temp=head;
        while (temp->next!=nullptr){
            int val=temp->val;
            if (temp->next->val!=val){
                temp=temp->next;
            }
            else if (temp->next->val==val){
                temp->next=temp->next->next;
            }
        }
        return head;
    }
};