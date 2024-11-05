#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    public:
        int hIndex(vector<int> citations) {
            // Initialize h-index counter
            int h_Index = 0, n = citations.size();

            // Sort citations in ascending order
            sort(citations.begin(), citations.end());

            // Loop to find the maximum h-index
            // The h-index is the maximum value where h papers have at least h citations
            for (; h_Index < n && citations[n - 1 - h_Index] > h_Index; ++h_Index);

            return h_Index;  // Return the computed h-index
        }
};

int main() {
    vector<int> citations; int input; Solution sol;
    cin >> input;

    while(input != -1) {
        citations.emplace_back(input);
        cin >> input;
    }

    cout << sol.hIndex(citations = citations) << endl;
}