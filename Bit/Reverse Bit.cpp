class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
		for(int i=0; i<32; ++i) {
			if((n & 1) == 0) {
				res <<= 1;
			}
			else {
				res <<= 1;
				res++;
			}
			n >>= 1;
		}
		return res;
    }
};

//��n��ÿһλ��Ҫ�жϣ����ж�32��(0-31)��
//���ǣ�resֻ������31�Σ��������ƺ�ӣ�������һ��������Ч��31��