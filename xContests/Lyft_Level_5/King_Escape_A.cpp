#include<bits/stdc++.h>

using namespace std;

bool KingEscape(int n, int qx, int qy, int kx, int ky, int dx, int dy) 
{
	int **board = new int*[n];

	for(int i=0;i<n;i++)
		board[i] = new int[n];

	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			board[i][j] = 0;
	
	for(int i=0;i<n;i++)
		board[qx][i] = 1;	

	for(int i=0;i<n;i++)
		board[i][qy] = 1;	

	for(int i=-1*(n-1);i<n;i++)
		if((qx+i)>=0 && (qx+i)<n && (qy+i)>=0 && (qy+i)<n)
			board[qx+i][qy+i] = 1;	

	for(int i=0;i<n;i++)
		if((qx-i)>=0 && (qx-i)<n && (qy+i)>=0 && (qy+i)<n)
			board[qx-i][qy+i] = 1;

	for(int i=0;i<n;i++)
		if((qx+i)>=0 && (qx+i)<n && (qy-i)>=0 && (qy-i)<n)
			board[qx+i][qy-i] = 1;

	if(board[kx][ky] == 1 || board[dx][dy] == 1)
		return false;
	
	int a1 = qx - kx;
	int a2 = qy - ky;

	int b1 = qx - dx;
	int b2 = qy - dy;

	if( (a1*b1) > 0 && (a2*b2) > 0)
		return true;
	
	return false;

}



int main()
{

	int n;
	cin >> n;

	int qx,qy; //queens Coordinates
	int kx,ky; //Kings Coordinates
	int dx,dy; //Destination of King!

	cin >> qx >> qy;
	cin >> kx >> ky;
	cin >> dx >> dy;

	if( KingEscape(n, qx-1, qy-1, kx-1, ky-1, dx-1, dy-1) == false)
		cout << "NO" << endl;
	else
		cout << "YES" << endl;


	return 0 ; 

}

