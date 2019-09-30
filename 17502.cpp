#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	int n;
	string str;
	cin >> n;
	cin >> str;
	
	for(int i = 0 ; i < n ; ++i) {
		if(str[i] == '?') {
			if(str[n - 1 - i] == '?') {
				str[i] = 'a';
				str[n - 1 - i] = 'a';
			}
			else {
				str[i] = str[n - 1 - i];
			}
		}
	}
	
	cout << str << '\n';
	
	return 0;
}
