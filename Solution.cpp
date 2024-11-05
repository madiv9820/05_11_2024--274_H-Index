#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        int hIndex(vector<int> citations) {
            // Get the number of papers
            int n = citations.size();
            
            // Initialize an array to count the number of papers with each possible citation count
            // The array has size n + 1, where index i stores the count of papers with i citations
            // If a paper has more than n citations, it is counted in the last index (no_of_Papers_For_Each_Citation[n])
            vector<int> no_of_Papers_For_Each_Citation(n + 1, 0);

            // Populate the citation counts array
            for (const int& citation : citations)
                ++no_of_Papers_For_Each_Citation[min(citation, n)];

            // Start with the highest possible h-index (n) and calculate the sum of papers with that many or more citations
            int h_Index = n;
            int sum_of_All_Citations = no_of_Papers_For_Each_Citation[h_Index];

            // Reduce h_Index while the sum of papers with citations >= h_Index is less than h_Index
            for (; h_Index > sum_of_All_Citations; 
                 sum_of_All_Citations += no_of_Papers_For_Each_Citation[h_Index])
                --h_Index;

            // Return the computed h-index
            return h_Index;
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