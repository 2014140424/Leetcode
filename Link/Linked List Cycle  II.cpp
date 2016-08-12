/*
* 快慢指针无环情况分析：
* 1.两个指针同时从第一个节点出发：
* 1)如果链表长度为奇数，移动n步后，快指针到达最后一个节点（第2n+1个），慢指针到达第n+1个节点，此时慢指针指向的正好的最中间的节点（比如长度5，指向3；长度7指向4）；
* 2)如果链表长度为偶数：移动n步后，快指针到达倒数第二个节点（第2n+1个），慢指针到达第n+1个节点，此时慢指针正好指向前半部分的最后一个节点（比如长度10，指向5）；
* 2.慢指针从第一个节点出发，快指针从第二个节点出发：
* 1)如果链表长度为奇数，移动n-1步后，快指针到达倒数第二个节点（第2n个），慢指针到达第n个节点，此时慢指针指向的最中间节点的前驱；
* 2)如果链表长度为偶数，移动n-1步后，快指针到达最后一个节点（第2n个），慢指针到达第n个节点，此时慢指针正好指向前半部分的最后一个节点（比如长度10，指向5）；
* 
* 该题思想：基于以上第二种分析，当最后fast追上slow时，slow指向第n个，fast指向2n个，而fast比slow快了一圈（也可能n圈），故一圈有2n-n=n个节点，让fast后移一步，slow指向head，它们形成一个长度为n+1的链表，此链表正好可以经过移动，首尾重合在环的入口。
*/ 
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
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL || head->next == NULL || head->next->next == NULL) {
            return NULL;
        }
        ListNode* slow = head;
        ListNode* fast = head->next;
        bool isCycle = false;
        while(fast->next != NULL && fast->next->next != NULL) {
            if(fast == slow) {
                isCycle = true;
                break;
            }
            slow = slow->next;
            fast = fast->next->next;
        }
        while(!isCycle) {
            return NULL;
        }
        slow = head;
        fast = fast->next;
        while(true) {
            if(fast == slow) {
                return fast;
            }
            fast = fast->next;
            slow = slow->next;
        }
        return NULL;
    }
};