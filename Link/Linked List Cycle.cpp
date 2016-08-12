/*
* 快慢指针无环情况分析：
* 1.两个指针同时从第一个节点出发：
* 1)如果链表长度为奇数，移动n步后，快指针到达最后一个节点（第2n+1个），慢指针到达第n+1个节点，此时慢指针指向的正好的最中间的节点（比如长度5，指向3；长度7指向4）；
* 2)如果链表长度为偶数：移动n步后，快指针到达倒数第二个节点（第2n+1个），慢指针到达第n+1个节点，此时慢指针正好指向前半部分的最后一个节点（比如长度10，指向5）；
* 2.慢指针从第一个节点出发，快指针从第二个节点出发：
* 1)如果链表长度为奇数，移动n-1步后，快指针到达倒数第二个节点（第2n个），慢指针到达第n个节点，此时慢指针指向的最中间节点的前驱；
* 2)如果链表长度为偶数，移动n-1步后，快指针到达最后一个节点（第2n个），慢指针到达第n个节点，此时慢指针正好指向前半部分的最后一个节点（比如长度10，指向5）；
* 两种方法对于有环的，快指针终究会追上慢指针。
* 以下代码为第二种方法。
*/ 
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL || head->next == NULL || head->next->next == NULL) 
            return false;
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast->next != NULL && fast->next->next != NULL) {
            if(fast == slow)
                return true;
            slow = slow->next;
            fast = fast->next->next;
        }
        return false;
    }
};