#include "Huffman Tree.h"
int main()
{
    int count = 0;
    cin >> count;
    for (int i = 0; i < count; i++)
    {
        int number = 0;
        cin >> number;
        int *weights = new int[number]{0};
        for (int j = 0; j < number; j++)
        {
            cin >> weights[j];
        }
        int *chars = new int[number]{0};
        for (int j = 0; j < number; j++)
        {
            chars[j] = j;
        }
        HuffmanTree<int, int> tree(chars, weights, number);
        cout << "Case " << i + 1 << endl;
        for (int j = 0; j < number; j++)
        {
            cout << weights[j] << " " << tree.Encode(chars[j]) << endl;
        }
        delete[] weights;
        delete[] chars;
    }
    return 0;
}