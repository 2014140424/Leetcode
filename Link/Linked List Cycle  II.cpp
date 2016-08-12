/*
* ����ָ���޻����������
* 1.����ָ��ͬʱ�ӵ�һ���ڵ������
* 1)���������Ϊ�������ƶ�n���󣬿�ָ�뵽�����һ���ڵ㣨��2n+1��������ָ�뵽���n+1���ڵ㣬��ʱ��ָ��ָ������õ����м�Ľڵ㣨���糤��5��ָ��3������7ָ��4����
* 2)���������Ϊż�����ƶ�n���󣬿�ָ�뵽�ﵹ���ڶ����ڵ㣨��2n+1��������ָ�뵽���n+1���ڵ㣬��ʱ��ָ������ָ��ǰ�벿�ֵ����һ���ڵ㣨���糤��10��ָ��5����
* 2.��ָ��ӵ�һ���ڵ��������ָ��ӵڶ����ڵ������
* 1)���������Ϊ�������ƶ�n-1���󣬿�ָ�뵽�ﵹ���ڶ����ڵ㣨��2n��������ָ�뵽���n���ڵ㣬��ʱ��ָ��ָ������м�ڵ��ǰ����
* 2)���������Ϊż�����ƶ�n-1���󣬿�ָ�뵽�����һ���ڵ㣨��2n��������ָ�뵽���n���ڵ㣬��ʱ��ָ������ָ��ǰ�벿�ֵ����һ���ڵ㣨���糤��10��ָ��5����
* 
* ����˼�룺�������ϵڶ��ַ����������fast׷��slowʱ��slowָ���n����fastָ��2n������fast��slow����һȦ��Ҳ����nȦ������һȦ��2n-n=n���ڵ㣬��fast����һ����slowָ��head�������γ�һ������Ϊn+1���������������ÿ��Ծ����ƶ�����β�غ��ڻ�����ڡ�
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