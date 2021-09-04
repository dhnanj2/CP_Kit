/*
Given a encoded binary string and a Huffman MinHeap tree, your task is to complete the function decodeHuffmanData(), which decodes the binary encoded string and return the original string. 
Note: Each node of the min heap contains 2 data members, a character and an integer to denote its frequency. The character '$' is the special character used for internal nodes whose min heap node only need a integer field.

Example 1:

Input :
binaryString = 
0000000000001100101010101011111111010101010
Min Heap Tree =  
                $(20)
              /      \
            /          \
         $(8)            \
       /     \             \
    $(3)      \            $(12)
    /  \       \           /    \
B(1)    D(2)    E(5)    C(6)    A(6)

Output: AAAAAABCCCCCCDDEEEEE

Explanation:
The following chart can be made from the 
given min heap tree.
character    frequency    code
    A             6        00                 
    B             1        110
    C             6        01
    D             2        111    
    E             5        10

Example 2:

Input :
binaryString =
01110100011111000101101011101000111
Min Heap Tree =  
                         $(13)
                      /        \
                    /            \
                  /                \
               $(5)                  \
             /      \                  \
            /        \                   \
         $(3)         \                  $(8)
        /    \         \                /    \
     $(2)     \         \            $(4)     \
    /   \      \         \          /   \      \
f(1)    o(1)    r(1)    g(2)    k(2)    s(2)    e(4)

Output: geeksforgeeks

Explanation:
The following chart can be made from the 
given min heap tree.
character    frequency    code
    f             1        0000                 
    o             1        0001
    r             1        001
    g             2        01    
    k             2        100
    s             2        101
    e             4        11

Your Task:  
You dont need to read input or print anything. Complete the function decodeHuffmanData() which takes the root of the Huffman min heap tree and the encoded Binary String as input parameters and returns the decoded string.

Expected Time Complexity: O(N log N)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ N ≤ 10^3
*/
#include<bits/stdc++.h>

using namespace std;

char solve(struct MinHeapNode* root,string &s,int &i) {
    char c;
    // if(i>s.size()) return c;
    if(s[i]=='0' && root->left) i++,c=solve(root->left,s,i);
    else if(s[i]=='1' && root->right) i++,c=solve(root->right,s,i);
    else c=root->data;
    return c;
}

string decodeHuffmanData(struct MinHeapNode* root, string s)
{
    string ans;
    int i=0;
    while(i<s.size()) {
        ans.push_back(solve(root,s,i));
    }
    return ans;
}

int main()
{   

    return 0;
}