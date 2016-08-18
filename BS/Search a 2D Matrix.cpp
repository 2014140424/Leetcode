#include<iostream>
#include<vector>
using namespace std;
int main() {
	int m;
	cin>>m;
	while(m--) {
		int n, t;
		cin>>n>>t;
		vector<int> tmp;
		int i = 0;
		while(i<2*n) {
			int x;
			cin>>x;
			tmp.push_back(x);
			++i;
		}
		for(int i=0; i<t; ++i) {
			vector<int> tmp2 = tmp;
			for(int j=0; j<2*n; ++j) {
				if(j<=n) {
					tmp[j+j] = tmp2[j];
				}
				else {
					tmp[j+j-n+1] = tmp2[j];
				}
			}
		}
		for(int i=0;i<2*n; ++i) {
			if(i==2*n-1) {
				cout << tmp[i];
			}
			else {
				cout << tmp[i] << " ";
			}
		}
		cout << endl;
	}
	return 0;
}
      