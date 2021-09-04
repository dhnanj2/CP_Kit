// Iterative C++ program to check
// if a string is subsequence
// of another string
#include <cstring>
#include <iostream>
using namespace std;
 
// Returns true if str1[] is a 
// subsequence of str2[]. m is
// length of str1 and n is length of str2
bool isSubSequence(string str1, string str2)
{
    int m=str1.size();
    int n=str2.size();

    int j = 0; // For index of str1 (or subsequence
    
    // Traverse str2 and str1, and 
    // compare current character
    // of str2 with first unmatched char 
    // of str1, if matched
    // then move ahead in str1
    for (int i = 0; i < n && j < m; i++)
        if (str1[j] == str2[i])
            j++;
 
    // If all characters of str1 were found in str2
    return (j == m);
}

// Time Complexity : O(N) where N->length of str2
// Driver program to test methods of graph class
int main()
{
    char str1[] = "gksrek";
    char str2[] = "geeksforgeeks";
    int m = strlen(str1);
    int n = strlen(str2);
    isSubSequence(str1, str2) ? cout << "Yes "
                                    : cout << "No";
    return 0;
}