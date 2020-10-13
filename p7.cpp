#include<bits/stdc++.h>
using namespace std;

bool rowYes (vector <vector <int> > &board, int row, int num) {
    for (int i = 0; i < 9; i++) {
        if (board[row][i] == num) return false;
    }
    return true;
}

bool colYes (vector <vector <int> > &board, int col, int num) {
    for (int i = 0; i < 9; i++) {
        if (board[i][col] == num) return false;
    }
    return true;
}

bool boxYes (vector <vector <int> > &board, int row, int col, int num) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) if (board[i+row][j+col] == num) return false;
    }
    return true;
}

bool isSafe(vector <vector <int> > &board, int i, int j, int num) {
    return (rowYes(board, i, num) && colYes(board, j, num) && boxYes(board, i-(i%3), j-(j%3), num)); 
}


pair<int, int> findLocation(vector <vector <int> > &board) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] == 0) return {i, j};
        }
    }
    return {9, 9};
}

void solve(vector <vector <int> > &board) {
    int i, j;
    pair <int, int> p;
    p = findLocation(board);
    if (p.first == 9 && p.second == 9) return;
    i = p.first;
    j = p.second;
    for (int num = 1; num <= 9; num++) {
        if (isSafe(board, i, j, num)) board[i][j] = num;
        solve(board);
        board[i][j] = 0;
    } 
    return;
}

int main()
 {
	int t;
	cin >> t;
	while (t--) {
	   
	   //use double pointerto define 2d array! That's way easy!
	   
	    vector<vector<int>> board(9, vector<int>(9, 0));
	   // cout << "p0\n";
	   
	    for (int i = 0; i < 9; i++) {
	        for (int j = 0; j < 9; j++) cin >> board[i][j];
	    }
	   // cout << "p1\n";
	    solve(board);
	   // cout << "p2\n";
	    for (int i = 0; i < 9; i++) {
	        for (int j = 0; j < 9; j++) cout << board[i][j] << ' ';
	    }
	    cout << '\n';
	}
	return 0;
}