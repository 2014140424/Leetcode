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

//对n的每一位都要判断，共判断32次(0-31)；
//但是，res只能左移31次，所以先移后加，这样第一次左移无效，31次