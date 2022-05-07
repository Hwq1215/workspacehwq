#ifndef AFFC60E6_63B3_4327_8C9D_EFB58FF488E5
#define AFFC60E6_63B3_4327_8C9D_EFB58FF488E5
#include<bits/stdc++.h>
using namespace std;
class HuffmanTree{
    public:
    int weight = 0;
    int lchild = 0;
    int rchild = 0;
    int parent = 0;
};
vector<HuffmanTree> createHuffmanTree(vector<int> in);
bool select(int pos,int & miner,int & minest,vector<HuffmanTree> & t);
vector<string> HuffmanCoding(vector<HuffmanTree>);
void testHuffman(vector<int> in);
#endif /* AFFC60E6_63B3_4327_8C9D_EFB58FF488E5 */
