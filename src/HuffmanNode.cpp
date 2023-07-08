#include "huffman-encoding/HuffmanNodes.hpp"
#ifndef HUFFMAN_STRING
#define HUFFMAN_STRING
#include <string>
#endif
HuffmanNode::HuffmanNode(long long int freq, std::string encoding)
{
    frequency = freq;
    code = encoding;
    left = NULL;
    right = NULL;
}

HuffmanNode::HuffmanNode(long long int freq)
{
    frequency = freq;
    code = "";
    left = NULL, right = NULL;
}

HuffmanNode::HuffmanNode()
{
    frequency = -1;
    code = "";
    left = NULL, right = NULL;
}