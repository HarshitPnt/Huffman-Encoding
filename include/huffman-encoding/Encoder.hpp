#pragma once
#include "HuffmanTree.hpp"
#include "FileWriter.hpp"

class Encoder
{
    std::string inputFileName;
    std::string outputFileName;
    HuffmanTree *tree;

public:
    Encoder(std::string input, std::string output);
    void encode();
};