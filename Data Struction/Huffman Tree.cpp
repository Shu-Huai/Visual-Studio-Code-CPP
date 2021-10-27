#include "Huffman Tree.h"
int main()
{
    int count = 0;
    cin >> count;
    for (int i = 0; i < count; i++)
    {
        int number = 0;
        cin >> number;
        int *weight = new int[number]{0};
        for (int j = 0; j < number; j++)
        {
            cin >> weight[j];
        }
        HuffmanTree<int, int> tree(weight, weight, 6);
        cout << "Case " << i + 1 << endl;
        for (int j = 0; j < number; j++)
        {
            cout << weight[j] << " " << tree.Encode(weight[j]) << endl;
        }
        delete[] weight;
    }
    return 0;
}