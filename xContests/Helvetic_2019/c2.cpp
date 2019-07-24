#include <bits/stdc++.h> 
using namespace std; 

const int MAX_POINTS = 500; 
typedef complex<int> Point; 

Point arr[MAX_POINTS]; 
int dis[MAX_POINTS][MAX_POINTS]; 

int getPointsInside(int i, int r, int n) 
{ 
	// This vector stores alpha and beta and flag 
	// is marked true for alpha and false for beta 
	vector<pair<double, bool> > angles; 

	for (int j=0; j<n; j++) 
	{ 
		if (i != j && dis[i][j] <= 2*r) 
		{ 
			// acos returns the arc cosine of the complex 
			// used for cosine inverse 
			double B = acos(dis[i][j]/(2*r)); 

			// arg returns the phase angle of the complex 
			double A = arg(arr[j]-arr[i]); 
			double alpha = A-B; 
			double beta = A+B; 
			angles.push_back(make_pair(alpha, true)); 
			angles.push_back(make_pair(beta, false)); 
		} 
	} 

	sort(angles.begin(), angles.end()); 

	int count = 1, res = 1; 
	vector<pair<double, bool> >::iterator it; 
	for (it=angles.begin(); it!=angles.end(); ++it) 
	{ 
		if ((*it).second) 
			count++; 

		else
			count--; 

		if (count > res) 
			res = count; 
	} 

	return res; 
} 

int maxPoints(Point arr[], int n, int r) 
{ 
	for (int i=0; i<n-1; i++) 
		for (int j=i+1; j<n; j++) 
			dis[i][j] = dis[j][i] = abs(arr[i]-arr[j]); 

	int ans = 0; 
	for (int i=0; i<n; i++) 
		ans = max(ans, getPointsInside(i, r, n)); 

	return ans; 
} 

// Driver code 
int main() 
{ 
	/*Point arr[] = {Point(6.47634, 7.69628), 
					Point(5.16828, 4.79915), 
					Point(6.69533, 6.20378)}; */
	int n,r;
	cin >> n >> r;

	Point *arr = new Point[n];
	for(int i=0;i<n;i++)
	{
		int a,b;
		cin >> a >> b;
		Point p(a,b);
		arr[i] = p;	
	}					
	cout << maxPoints(arr, n, r) << endl;; 

	return 0; 
} 
