// Given an array of unsorted elements, find the minimum difference between any 2 elements in the array.
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> A(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        sort(A.begin(), A.end());
        int ans = INT_MAX;
        for (int i = 1; i < N; i++) {
            ans = min(ans, (A[i]-A[i-1]));
        }
        cout << ans << endl;
    }
    return 0;
}
