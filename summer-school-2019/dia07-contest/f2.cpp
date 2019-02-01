#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define sec second
#define fori(i, a, b) for(int i = int(a); i < int(b); i++)
#define cc(x)	cout << #x << " = " << x << endl
#define ok		cout << "ok" << endl

typedef pair<int,int> ii;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
int n,k;
const int T = 1e5 + 10;
int pai[T];
int peso[T];

void init() {
	for(int i = 0; i < T; i++) {
		pai[i] = i;
		peso[i] = 0;
	}
}

int find(int x) {
	return (pai[x] == x? x : pai[x] = find(x));
}

void join(int a, int b) {
	a = find(a); b = find(b);
	if(a == b) return;
	if(peso[a] < peso[b]) swap(a,b);
	pai[b] = a;
	if(peso[a] == peso[b]) peso[a]++;
}
 
int main(){
    ios_base::sync_with_stdio(false);
	int tc; cin >> tc;
	while(tc--) {
		init();
		cin >> n >> k;
		int oper,a,b;
		int ans = 0;
		for(int i = 0; i < k; i++) {
			cin >> oper >> a >> b;
			if(oper == 1) {
				if(podAmig(a,b)) fazAmig(a,b);
				else ans++;
			} else {
				if(podIni(a,b)) fazIni(a,b);
				else ans++;
			}
		}
	}
    return 0;
}

