#include <iostream>
#include <string>
using namespace std;
#define endl '\n'

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	while(t --) {
		string str;
		cin >> str;
		long long ans = 0LL;
		int size = (int)str.size() - 1;
		if(str[0] == '1') 
			ans = 1LL << size;
		int l = str[0] - '0';
		for(int i = 1 ; i < str.size() ; ++i) {
			size --;
			l ^= (str[i] - '0');
			if(l)
				ans += 1LL << size;
		}
		cout << ans << endl;
	}
	return 0;
}
