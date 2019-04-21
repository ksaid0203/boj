#include <iostream>
#include <vector>
using namespace std;
#define endl '\n'
void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}
vector<int> preorder;

void post(int begin, int end) {
	if(begin > end) return;
	int idx = begin + 1;
	for(; idx <= end && preorder[begin] > preorder[idx]; ++idx) {}
	if(idx == end + 1 || idx == begin + 1) {
		post(begin + 1, end);
	}
	else {
		post(begin + 1, idx - 1);
		post(idx, end);
	}
	cout << preorder[begin] << endl;
}

int main() {
	fastIO();
	int x;
	while(cin >> x) {
		preorder.emplace_back(x);
	}
	
	post(0, (int)preorder.size() - 1);
	return 0;
}

