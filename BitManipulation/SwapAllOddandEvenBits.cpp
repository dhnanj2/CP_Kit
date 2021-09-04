/*
Given an unsigned integer N. The task is to swap all odd bits with even bits. For example, if the given number is 23 (00010111), it should be converted to 43(00101011). 
Here, every even position bit is swapped with adjacent bit on the right side(even position bits are highlighted in the binary representation of 23),
and every odd position bit is swapped with an adjacent on the left side.
*/
/*
If we take a closer look at the example, we can observe that we basically need to right shift (>>) all even bits (In the above example, even bits of 23 are highlighted) by 1 so that they become odd bits (highlighted in 43), and left shift (<<) all odd bits by 1 so that they become even bits. The following solution is based on this observation. The solution assumes that input number is stored using 32 bits.
Let the input number be x 
1) Get all even bits of x by doing bitwise and of x with 0xAAAAAAAA. The number 0xAAAAAAAA is a 32 bit number with all even bits set as 1 and all odd bits as 0. 
2) Get all odd bits of x by doing bitwise and of x with 0x55555555. The number 0x55555555 is a 32 bit number with all odd bits set as 1 and all even bits as 0. 
3) Right shift all even bits. 
4) Left shift all odd bits. 
5) Combine new even and odd bits and return.
*/
#include<bits/stdc++.h>

using namespace std;

// time : O(1) , space:O(1)
unsigned int swapBits(unsigned int n)
{
	bitset<32> b(n);
    auto s=b.to_string();
    for(int i=0;i+1<s.size();i+=2) {
        swap(s[i],s[i+1]);
    }
    bitset<32> ans(s);
    return ans.to_ulong();
}

// Function to swap even
// and odd bits
unsigned int swapBits(unsigned int x)
{
    // Get all odd bits of x
    // 5-> 0101 therfore 0x55555555 = 01010101010101010101010101010101
    unsigned int odd_bits = x & 0x55555555;

    // Get all odd bits of x
    // 5<<1-> 1010 therfore 0x55555555 = 10101010101010101010101010101010
    unsigned int even_bits = x & (0x55555555<<1);
 
    even_bits >>= 1; // Right shift even bits
    odd_bits <<= 1; // Left shift odd bits
 
    return (even_bits | odd_bits); // Combine even and odd bits
}

int main()
{

    return 0;
}