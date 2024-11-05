from typing import List

class Solution:
    def hIndex(self, citations: List[int]) -> int:
        # Get the number of papers
        n = len(citations)

        # Initialize an array to count the number of papers with each possible citation count
        # This array will have size n + 1, where index i stores the count of papers with i citations
        # If a paper has more than n citations, it is counted in the last index (no_of_Papers_For_Citations[n])
        no_of_Papers_For_Citation = [0] * (n + 1)

        # Populate the citation counts array
        for citation in citations:
            # For citations greater than n, count them at index n
            no_of_Papers_For_Citation[min(n, citation)] += 1

        # Start with the highest possible h-index (n) and calculate the sum of papers with that many or more citations
        h_Index = n
        sum_of_All_Citations = no_of_Papers_For_Citation[h_Index]

        # Reduce h_Index while the sum of papers with citations >= h_Index is less than h_Index
        while h_Index > sum_of_All_Citations:
            h_Index -= 1
            sum_of_All_Citations += no_of_Papers_For_Citation[h_Index]

        # Return the computed h-index
        return h_Index