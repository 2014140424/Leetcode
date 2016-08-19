
 
class Solution {
public
    ListNode mergeKLists(vectorListNode& lists) {
        
    }
	
	void sift(vector<int>& vec, int i, int n) {
		int tmp = vec[i];
		int j = 2 * i + 1;
		while(j <= n) {
			if(j + 1 <= n && vec[j + 1] > vec[j]) {
				j++;
			}
			if(vec[j] > tmp) {
				vec[i] = vec[j];
				i = j;
				j = 2 * i + 1;
			}
			else {
				break;
			}
		}
		vec[i] = tmp;
	}
    
};