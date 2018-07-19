#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second
#define fori(i, a, b) for(int i = int(a); i < int(b); i++)

typedef long long ll;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
 
int n, total, m;

int main(){
    ios_base::sync_with_stdio(false);

	m = 0;
    cin >> n;

	while (n--) {
		int t, d; cin >> t >> d;
		total += t;
		if (d > m) m = d;
	}

	cout << max(0, total-m) << endl;

    return 0;
}

