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

const int N = 1e6;
int pai[N], tam[N];

void init(int n) {
	for(int i = 1; i <= n; i++) {
		pai[i] = i;
		tam[i] = 1;
	}
}

int find(int x) {
	if(pai[x] == x) return x;
	return pai[x] = find(pai[x]);
}

void join(int x, int y) {
	int a = find(x);
	int b = find(y);
	if(a == b) return;
	if(tam[a] > tam[b]) swap(a, b);
	pai[a] = b;
	tam[b] += tam[a];
}

int main(){
    ios_base::sync_with_stdio(false);
	
	int tc;
	cin >>tc;

	while(tc--) {
		int n, q;
		cin >> n >> q;
		map<int,int> come;
		map<int,int> comido;
		int ans = 0;
		init(n);
		while(q --) {
			int op, x, y;
			cin >>op >>x >>y;
			if(x > n or y > n) {
				ans++; continue;
			}
			if(op == 2) {
				int a = find(x);
				int b = find(y);
				if(a == b) {
					ans++; continue;
				}
				if(come[a] != 0 and come[a] != b) {
					ans++; continue;
				}
				if(come[b] != 0 and come[b] == a) {
					ans++; continue;
				}
				if(comido[b] != 0 and comido[b] != a) {
					
				}
				
				come[a] = b;
			}
			if(op == 1) {
				int a = find(x);
				int b = find(y);
				if(come[a] != 0) {
					if(come[a] == b){ 
						ans++; continue;
					}
					if(come[come[a]] == b) {
						ans++; continue;
					}
				}
				if(come[b] != 0) {
					if(come[b] == a){
						ans++; continue;
					}
					if(come[come[b]] == a)
						ans++; continue;
				}

				join(a, b);
			}
		}
		cout << ans <<endl;
	}
	
    return 0;
}

