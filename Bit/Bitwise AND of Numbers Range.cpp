/**
*	��Ŀ����m��n֮������������Ľ��
*	˼·����ʵ����m��n�����ƺ�Ӹ�λ��ʼ�Ĺ������֡�
*/

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int flag = 0;
        while(n != m) {
            m >>= 1;
            n >>= 1;
            flag++;
        }
        return m<<flag;
    }
};