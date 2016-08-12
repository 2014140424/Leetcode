/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 /**
 * 化为可循环的子问题：1.首先判断是否后边有两个节点；2.如果有，把1号节点拿下来；3.把拿下来的1号节点插入到2号节点之后；4.追踪指针后移动两位；5.循环。
 * 注意点：链表问题很多使用头节点可以相当大地简化问题。
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* newh = new ListNode(0);
        newh->next = head;
        ListNode* p = newh;
        while(p->next != NULL && p->next->next != NULL) {
            ListNode* r = p->next;
            p->next = p->next->next;
            r->next = p->next->next;
            p->next->next = r;
            p = p->next->next;
        }
        return newh->next;
    }
};