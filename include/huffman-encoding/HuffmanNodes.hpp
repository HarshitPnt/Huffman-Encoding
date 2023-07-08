#pragma once
#include <string>
#define HUFFMAN_STRING
class HuffmanNode
{
public:
    long long int frequency;
    char character;
    std::string code;
    HuffmanNode *left, *right;

    HuffmanNode(long long int freq, std::string code);
    HuffmanNode(long long int freq);
    HuffmanNode();
};
