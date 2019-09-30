#include <iostream>
#include <vector>
#define endl '\n'
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, q;
	cin >> n >> q;
	
	vector<long long> arr(n);
	for(int i = 0 ; i < n ; ++i) {
		cin >> arr[i];
	}
	
	int start = 0;
	for(int i = 0 ; i < q; ++i) {
		int query, x;
		cin >> query >> x;
		if(query == 1) {
			long long y;
			cin >> y;
			arr[(start + x - 1 + n) % n] += y;
		}
		else if(query == 3) {
			start += x;
			start %= n;
		}
		else {
			start -= x;
			start += n;
			start %= n;
		}
	}
	
	for(int i = 0 ;i < n ; ++i) {
		cout << arr[(i + start) % n] << ' ';
	}
	
	return 0;
}
