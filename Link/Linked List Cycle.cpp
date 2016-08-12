/*
* ����ָ���޻����������
* 1.����ָ��ͬʱ�ӵ�һ���ڵ������
* 1)�����������Ϊ�������ƶ�n���󣬿�ָ�뵽�����һ���ڵ㣨��2n+1��������ָ�뵽���n+1���ڵ㣬��ʱ��ָ��ָ������õ����м�Ľڵ㣨���糤��5��ָ��3������7ָ��4����
* 2)�����������Ϊż�����ƶ�n���󣬿�ָ�뵽�ﵹ���ڶ����ڵ㣨��2n+1��������ָ�뵽���n+1���ڵ㣬��ʱ��ָ������ָ��ǰ�벿�ֵ����һ���ڵ㣨���糤��10��ָ��5����
* 2.��ָ��ӵ�һ���ڵ��������ָ��ӵڶ����ڵ������
* 1)�����������Ϊ�������ƶ�n-1���󣬿�ָ�뵽�ﵹ���ڶ����ڵ㣨��2n��������ָ�뵽���n���ڵ㣬��ʱ��ָ��ָ������м�ڵ��ǰ����
* 2)�����������Ϊż�����ƶ�n-1���󣬿�ָ�뵽�����һ���ڵ㣨��2n��������ָ�뵽���n���ڵ㣬��ʱ��ָ������ָ��ǰ�벿�ֵ����һ���ڵ㣨���糤��10��ָ��5����
* ���ַ��������л��ģ���ָ���վ���׷����ָ�롣
* ���´���Ϊ�ڶ��ַ�����
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