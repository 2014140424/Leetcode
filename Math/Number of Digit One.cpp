class Solution {
public:
    int countDigitOne(int n) {
		if(n <= 0)
			return 0;
        int res = 0;
		int low = 0;
		int high = n / 10;
		int gz = 1;
		int dq = n % 10;
		while(dq != 0 || high != 0) {
			if(dq > 1) {
				res += (high + 1) * gz;
			}
			else if(dq == 1) {
				res += high * gz;
				res += (low + 1);
			}
			else if(dq == 0) {
				res += high * gz;
			}
			low = low + dq * gz;
			dq = high % 10;
			high = high / 10;
			gz *= 10;			
		}
		return res;
    }
};