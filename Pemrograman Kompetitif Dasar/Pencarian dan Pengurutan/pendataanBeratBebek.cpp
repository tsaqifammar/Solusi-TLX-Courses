#include<bits/stdc++.h>
using namespace std;

int lowerIndex(int arr[], int n, int x) 
{ 
    int l = 0, h = n - 1; 
    while (l <= h) { 
        int mid = (l + h) / 2; 
        if (arr[mid] > x) 
            h = mid - 1; 
        else
            l = mid + 1; 
    } 
    return l; 
} 
int upperIndex(int arr[], int n, int y) 
{ 
    int l = 0, h = n - 1; 
    while (l <= h) { 
        int mid = (l + h) / 2; 
        if (arr[mid] <= y) 
            l = mid + 1; 
        else
            h = mid - 1; 
    } 
    return h; 
} 
  
// function to count elements within given range 
int countInRange(int arr[], int n, int x, int y) 
{
    int count = 0; 
    count = upperIndex(arr, n, y) - lowerIndex(arr, n, x) + 1; 
    return count; 
}

int main(){
	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++){
		cin >> arr[i];
	}
	int t;
	cin >> t;
	while(t--){
		int a, b;
		cin >> a >> b;
		int yo = countInRange(arr, n, a, b);
		cout << yo << "\n";
	}

}
