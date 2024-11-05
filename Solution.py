from typing import List

class Solution:
    def hIndex(self, citations: List[int]) -> int:
        # Initialize h-index counter
        h_Index = 0
        
        # Sort the citations in ascending order
        citations.sort()

        # Iterate to find the maximum h-index
        # h-index is the maximum number where 'h' papers have at least 'h' citations
        while (h_Index < len(citations) and 
               citations[len(citations) - 1 - h_Index] > h_Index): 
            h_Index += 1  # Increment h-index if the condition holds

        return h_Index  # Return the computed h-index