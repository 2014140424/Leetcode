class Solution {
public:
    string convertToTitle(int n) {
		string res = "";
		while(n > 0) {
			int tmp = n % 26;
			if(tmp == 0) {
				res += 'Z';
				n = n / 26 - 1;
			}
			else {
				res += 'A' + tmp - 1;
				n = n / 26;
			}
		}
		reverse(res.begin(), res.end());
		return res;
    }
};