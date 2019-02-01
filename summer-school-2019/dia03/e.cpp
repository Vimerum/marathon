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

char board[10][10];
ii bKing;
ii wKing;

void printar () {
	fori(i,1,9) {
		fori(j,1,9) {
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
}

bool valid () {
	fori(i,1,9) {
		fori(j,1,9) {
			if (board[i][j] != '.')  {
				return true;
			}
		}
	}
	return false;
}

void read () {
	fori(i,1,9) {
		fori(j,1,9) {
			cin >> board[i][j];
			if (board[i][j] == 'k') bKing = mk(i,j);
			if (board[i][j] == 'K') wKing = mk(i,j);
		}
	}
}

bool isLower (char c) {
	return (c >= 97 and c <= 122);
}

bool pawn (ii c, char king) {
	vector<char> v;
	if (isLower(king)) {
		v.pb(board[c.fi+1][c.sec+1]);
		v.pb(board[c.fi+1][c.sec-1]);

		for (char c : v) {
			if (c == 'P') return true;
		}
	}
	else {
		v.pb(board[c.fi-1][c.sec+1]);
		v.pb(board[c.fi-1][c.sec-1]);

		for (char c : v) {
			if (c == 'p') return true;
		}
	}
	return false;
}

bool rook (ii c, char toFind) {
	for (int i = c.fi-1; i > 0; i--) {
		char current = board[i][c.sec];
		if (current != '.') {
			if (current == toFind) return true;
			break;
		}
	}
	fori(i,c.fi+1,9) {
		char current = board[i][c.sec];
		if (current != '.') {
			if (current == toFind) return true;
			break;
		}
	}
	for (int i = c.sec-1; i > 0; i--) {
		char current = board[c.fi][i];
		if (current != '.') {
			if (current == toFind) return true;
			break;
		}
	}
	fori(i,c.sec+1,9) {
		char current = board[c.fi][i];
		if (current != '.') {
			if (current == toFind) return true;
			break;
		}
	}
	return false;
}

bool bishop (ii c, char toFind) {
	bool f = false;
	for (int i = c.fi - 1; i > 0;) {
		for (int j = c.sec + 1; j < 9; j++, i--) {
			char current = board[i][j];
			if (current != '.') {
				if (current == toFind) return true;
				f = true;
				break;
			}
		}
		if (f) break;
	}
	f = false;
	for (int i = c.fi - 1; i > 0;) {
		for (int j = c.sec - 1; j > 0; j--, i--) {
			char current = board[i][j];
			if (current != '.') {
				if (current == toFind) return true;
				f = true;
				break;
			}
		}
		if (f) break;
	}
	f = false;
	for (int i = c.fi + 1; i < 9;) {
		for (int j = c.sec + 1; j < 9; j++, i++) {
			char current = board[i][j];
			if (current != '.') {
				if (current == toFind) return true;
				f = true;
				break;
			}
		}
		if (f) break;
	}
	f = false;
	for (int i = c.fi + 1; i < 9;) {
		for (int j = c.sec - 1; j > 0; j--, i++) {
			char current = board[i][j];
			if (current != '.') {
				if (current == toFind) return true;
				f = true;
				break;
			}
		}
		if (f) break;
	}
	return false;
}

bool king (ii c, char toFind) {
	fori(i,c.fi-1,c.fi+2) {
		fori(j,c.sec-1,c.sec+2) {
			if (i == c.fi and j == c.sec) continue;
			if (board[i][j] != '.') {
				if (board[i][j] == toFind) return true;
			}
		}
	}
	return false;
}

bool knight (ii c, char toFind) {
	if (board[c.fi-1][c.sec-2] == toFind) return true;
	if (board[c.fi-1][c.sec+2] == toFind) return true;
	if (board[c.fi+1][c.sec-2] == toFind) return true;
	if (board[c.fi+1][c.sec+2] == toFind) return true;
	if (board[c.fi-2][c.sec-1] == toFind) return true;
	if (board[c.fi+2][c.sec-1] == toFind) return true;
	if (board[c.fi-2][c.sec+1] == toFind) return true;
	if (board[c.fi+2][c.sec+1] == toFind) return true;
	return false;
}

bool checkBlack () {
	return pawn(bKing, 'k') or rook(bKing, 'R') or bishop(bKing, 'B') or rook(bKing, 'Q') or bishop(bKing, 'Q') or king(bKing, 'K') or knight(bKing, 'N');
}

bool checkWhite () {
	return pawn(wKing, 'K') or rook(wKing, 'r') or bishop(wKing, 'b') or rook(wKing, 'q') or bishop(wKing, 'q') or king(wKing, 'k') or knight(wKing, 'n');
}
 
int main(){
    ios_base::sync_with_stdio(false);
	
	fori(i,0,10)
		fori(j,0,10)
			board[i][j] = '.';
	
	int test = 1;
	while (true) {
		read();
		if (!valid()) break;
		
		//printar();

		if (checkWhite()) {
			cout << "Game #" << test++ << ": white king is in check." << endl;
			continue;
		}
		if (checkBlack()) {
			cout << "Game #" << test++ << ": black king is in check." << endl;
			continue;
		}
		cout << "Game #" << test++ << ": no king is in check." << endl;

		fori(i,0,8)
			fori(j,0,8)
				board[i][j] = '.';
	}
	
    return 0;
}

