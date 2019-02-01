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
const int T = 1e5 + 10;
bool vis[T];
set<int> precisa;
int tmp[T];
bool ficaigual[T];

const double PI = acos(-1.0);
 
int main(){
    ios_base::sync_with_stdio(false);
	int n; cin >> n;
	int aux;
	for(int i = 1; i <= n; i++) precisa.insert(i);
	for(int i = 1; i <= n; i++) {
		cin >> aux;
		tmp[i] = aux;
		if(!vis[aux] and aux <= n) {
			vis[aux] = true;
			ficaigual[i] = true;
			precisa.erase(aux);
		}
	}
	for(int i = 1; i <= n; i++) {
		if(ficaigual[i]) cout << tmp[i] << " "; 
		else {
			cout << *precisa.rbegin() << " ";
			precisa.erase(*precisa.rbegin());
		}
	}
	cout << endl;
	

	
	
	
    return 0;
}

