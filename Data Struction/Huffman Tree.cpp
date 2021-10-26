#include "Huffman Tree.h"
int main()
{
    char ch[6] = {'A', 'B', 'C', 'D', 'E', 'F'};
    int w[6] = {9, 8, 3, 4, 1, 2};
    HuffmanTree<char, int> tree(ch, w, 6);
    return 0;
}