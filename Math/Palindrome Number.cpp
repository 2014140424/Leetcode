class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
			return false;
		if(x == 0)
			return true;
		if(x % 10 == 0)
			return false;
		int rev = 0;
		while(x > rev) {
			int tmp = x % 10;
			x /= 10;
			rev *= 10;
			rev += tmp;
		}
		return rev == x || rev / 10 == x;
    }
};