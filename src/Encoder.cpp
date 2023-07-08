#include "huffman-encoding/Encoder.hpp"

Encoder::Encoder(std::string input, std::string output)
{
    inputFileName = input;
    outputFileName = output;
    tree = new HuffmanTree();
}

void Encoder::encode()
{
    tree->fill_tree_arr(inputFileName);
    tree->encodeFile(inputFileName, outputFileName);
}