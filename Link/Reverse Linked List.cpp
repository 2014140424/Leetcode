/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
 //非递归，头插法倒置链表
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL) {
			return head;
		}
		
		ListNode* p = head;
		ListNode* newh = new ListNode(0);
		ListNode* q = NULL;
		while(p != NULL) {
			q = p->next;
			p->next = newh->next;
			newh->next = p;
			p = q;
		}
		return newh->next;
    }
};

//递归实现
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL)
			return head;
		ListNode* tail = NULL;
		reverses(head, tail);
		return head;
    }
	
	void reverses(ListNode* & h, ListNode* & t) {
		if(h->next == NULL) {
			t = h;
			return;
		}
		ListNode* tmp = h->next;
		reverses(tmp, t);
		t->next = h;
		h->next = NULL;
		t = h;
		h = tmp;
	}
};