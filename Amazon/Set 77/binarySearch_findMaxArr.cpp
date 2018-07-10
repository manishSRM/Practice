/*Given an array in which elements are first increasing and then decreasing. find the maximum element in the array.*/

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <cmath>
#include <climits>
#include <set>
 
using namespace std;
 
int binarySearch(vector<int> arr, int start, int end) {
	int mid = start + (end - start) / 2;
	if (arr[mid] > arr[mid + 1] && arr[mid] > arr[mid - 1]) {
		return mid;
	} else if (arr[mid] > arr[mid + 1] && arr[mid] < arr[mid - 1] ) {
		return binarySearch(arr, start, mid - 1);
	} else {
		return binarySearch(arr, mid + 1, end);
	}
}
 
int main () {
	int arrSize;
	cin >> arrSize;
	vector<int> arr(arrSize);
	for (int i = 0; i < arrSize; i++) {
		cin >> arr[i];
	}
	if (arrSize == 1) {
		cout << arr[0];
	} else if (arrSize == 2 ) {
		cout << max(arr[0], arr[1]);
	} else {
		cout << arr[binarySearch(arr, 0, arrSize)] << endl;
	}
	return 0;
}