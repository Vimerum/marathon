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

bool verifica(string s, int k) {
	
	int cont = 0;
	char last = '-';
	for(int i = 0; i < s.size(); i++) {
		if(s[i] != last) {
			cont = 1;
		} else {
			cont++;
		}

		if(cont > k) {
			return false;
		}
		last = s[i];
	}
	return true;
}

int main(){
    ios_base::sync_with_stdio(false);
	
	int n, k, a, b;
	cin >>n >>k >>a >>b;
	
	map<char, char> ma;
	ma['a'] = 'G';
	ma['b'] = 'B';

	if(a > b) {
		swap(a, b);
		ma['a'] = 'B';
		ma['b'] = 'G';
	}
	
	int cont = 0;
	string ans = "";
	while(a != b and a > 0 and b > 0) {
		if(cont == k) {
			a--;
			cont = 0;
			ans += ma['a'];
		} else {
			b--;
			cont++;
			ans += ma['b'];
		}
	}
	
	if(a == 0 and b == 0) {
		//imprime resposta
		cout <<ans <<endl;
	} 
	
	else if((a == 0 and b > 0) or (b == 0 and a > 0)) {
		//insiro resposta e verifico
		while(b > 0) {
			ans += ma['b'];
			b--;
		}
		while(a > 0){
			ans += ma['a'];
			a--;
		}
		
		if(!verifica(ans, k)) {
			cout <<"NO" <<endl;
			return 0;
		}
		cout <<ans <<endl;
	} 
	
	else if(a > 0 and b > 0) {
		//alterno sem repetir  ultimo
		char last = 'B';
		if(ans.size() > 0)
			last = ans[ans.size()-1];
		while(last == ma['a'] and a > 0 and b > 0) {
			ans += ma['b'];
			ans += ma['a'];
			a--;
			b--;
		}
		while(last == ma['b'] and a > 0 and b > 0) {
			ans += ma['a'];
			ans += ma['b'];
			a--;
			b--;
		}
		cout <<ans <<endl;
	}

    return 0;
}

