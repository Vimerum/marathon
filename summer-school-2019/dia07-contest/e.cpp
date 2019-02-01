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
const int T = 1e5 + 10;
map<string, int> id;
int opposite[T];
int n, m, q;
int pai[T];
int peso[T];

void init() {
	for(int i = 0; i < T; i++) pai[i] = i; 
}

int find(int x) {
	return (pai[x] == x? x : pai[x] = find(pai[x]));
}

void join(int a, int b) {
	a = find(a); b = find(b);
	if(a == b) return;
	if(peso[a] < peso[b]) swap(a,b);
	pai[b] = a;
	if(peso[a] == peso[b]) peso[a]++;
}

bool saoIni(int a, int b) {
	//se sou seu inimigo
	if (find(a) == find(opposite[find(b)]) and find(a) != 0) return true;
	if (find(b) == find(opposite[find(a)]) and find(b) != 0) return true;
	return false;
}

bool saoAmi(int a, int b) {
	//se somos amigos
	//se sou amigo de seu inimigo
	return (find(a) == find(b) and find(a) != 0);
}

bool podIni(int a, int b) {
	if (saoAmi(find(a),find(b))) return false;
	if (saoIni(find(a),find(opposite[find(b)]))) return false;
	if (saoIni(find(b),find(opposite[find(a)]))) return false;
	return true;
}

bool podAmi(int a, int b) {
	if (saoAmi(find(a),find(opposite[find(b)]))) return false;
	if (saoAmi(find(b),find(opposite[find(a)]))) return false;
	if (saoIni(find(a),find(b))) return false;
	return true;
}

void fazIni(int a, int b) {
	//vou virar amigo de seu inimigo
	int inia = find(opposite[find(a)]);
	int inib = find(opposite[find(b)]);
	if(inia != 0) join(b,inia);
	if(inib != 0) join(a,inib);
	opposite[find(a)] = find(b);
	opposite[find(b)] = find(a);
}

void fazAmi(int a, int b) {
	if (find(opposite[find(b)]) != 0 and find(opposite[find(a)]))
		join(find(opposite[find(a)]),find(opposite[find(b)]));
	int tmp = max(find(opposite[find(a)]),find(opposite[find(b)]));
	join(find(a),find(b));
	opposite[find(a)] = tmp;
}

 
int main(){
    ios_base::sync_with_stdio(false);
	cin >> n >> m >> q;
	init();
	string s1,s2;
	int oper;
	for(int i = 1; i <= n; i++) {
		cin >> s1;
		id[s1] = i;
	}
	for(int i = 0; i < m; i++) {
		cin >> oper >> s1 >> s2;
		int a = id[s1];
		int b = id[s2];

		// tenta amigo
		if(oper == 1) {
			if(podAmi(a,b)) {
				fazAmi(a,b);
				cout << "YES" << endl;
			} else {
				cout << "NO" << endl;
			}
		} else {
			//tenta ini
			if(podIni(a,b)) {
				fazIni(a,b);
				cout << "YES" << endl;
			} else {
				cout << "NO" << endl;
			}
		}
	}

	for(int i = 0; i < q; i++) {
		cin >> s1 >> s2;
		int a = id[s1];
		int b = id[s2];
		if(find(a) == find(b)) cout << 1 << endl;
		else if(find(opposite[find(a)]) == find(b) or find(opposite[find(b)]) == find(a)) 
			cout << 2 << endl;
		else cout << 3 << endl;
	}
	
    return 0;
}

