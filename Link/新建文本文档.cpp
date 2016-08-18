/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        if(head == NULL || head->next == NULL)
			return head;
		ListNode* slow = head;
		ListNode* fast = head;
		while(fast->next != NULL && fast->next->next != NULL) {
			slow = slow->next;
			fast = fast->next->next;
		}
		ListNode* newhead = new ListNode(0);
		newhead->next = slow->next;
		slow->next = NULL;
		ListNode* p = newhead->next;
		ListNode* q = q->next;
		newhead->next = NULL;
		while(p != NULL) {
			q = p->next;
			p->next = newhead->next;
			newhead->next = p;
			p = q;
		}
		ListNode* r = head;
		p = newhead->next;
		q = p->next;
		while(p != NULL) {
			q = p->next;
			p->next = r->next;
			r->next = p;
			r = r->next->next;
			p = q;
		}
		return head;
    }
};