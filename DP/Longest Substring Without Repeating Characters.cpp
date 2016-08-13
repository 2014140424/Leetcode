/**
* 建立一个数组hash记录各个字母最近一次出现的位置，数组的索引表示字母，数组的值表示该字母最近一次出现的位置。
* hash数组初始全部置-1，表示所有字母都未出现过。
* border表示最后一个无效位置，初始时border为-1，表示所有位置有效；以后每次出现重复元素border都会被置为该重复元素上次的位置
* 循环各个字母进行处理：如果s[i]以前没出现过，则hash[s[i]]==0；如果s[i]出现在border以及以前，则hash[s[i]] <= border;这两种情况不会影响border的值，直接更新hash数组和当前长度thisLength（判断条件冗余，但更易于理解）。如果s[i]出现过且出现在border以后，也就是hash[s[i]] > border, 此时因为重复元素出现在thisLength长度所覆盖的元素中，此时需要更新border，重新计算thisLength。
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
		if(n == 0)
			return 0;
		int hash[150];
		memset(hash, -1, sizeof(hash));
		int border = -1;
		int thisLength = 0;
		int maxLength = 0;
		for(int i=0; i<n; ++i) {
			if(hash[s[i]] == -1 || hash[s[i]] <= border) {
				hash[s[i]] = i;
				thisLength++;				
			}
			else {				
				border = hash[s[i]];
				thisLength = i - border;	
				hash[s[i]] = i;
			}
			maxLength = max(maxLength, thisLength);
		}
		return maxLength;
    }
};