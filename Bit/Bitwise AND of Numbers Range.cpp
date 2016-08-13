/**
*	题目：求m到n之间所有数相与的结果
*	思路：其实是找m与n二进制后从高位开始的公共部分。
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