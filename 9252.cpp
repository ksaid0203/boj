#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;
string str1, str2;
int dp[1001][1001];
/* I see commentary */
/* reference: http://dailyddubby.blogspot.com/2018/03/75-lcs-2longest-common-subsequence.html */
void print(unsigned int i, unsigned int j) {
	if(i == 0 || j == 0)
		return;
		
	if(str1[i] == str2[j]) {
		print(i - 1, j - 1);
		cout << str1[i];
	}
	
	else {
		if(dp[i - 1][j] > dp[i][j - 1]) {
			print(i - 1, j);
		}
		else {
			print(i, j - 1);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> str1 >> str2;
	for(int i = 0; i < str1.size(); ++i) {
		int bestnext = -1;
		for(int j = 0; j < str2.size(); ++j) {
			if(str1[i] == str2[j]) {
				dp[i + 1][j + 1] = 1 + dp[i][j];
			}
			else
				dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
		}
	}

	cout << dp[str1.size()][str2.size()] << endl;
	
	print(str1.size() - 1, str2.size() - 1);
	return 0;
}
