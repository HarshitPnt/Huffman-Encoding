#include <iostream>
#include <cstring>
// #ifndef HUFFMAN_STRING
// #define HUFFMAN_STRING
// #include <string>
// #endif
#include "huffman-encoding/HuffmanNodes.hpp"
#include "huffman-encoding/HuffmanTree.hpp"
#include "huffman-encoding/FileWriter.hpp"
#include "huffman-encoding/Decoder.hpp"

int main(int argc, char *argv[])
{
    std::string inputfile = "../inputFiles/input.txt";
    std::string outputfile = "../outputFiles/encoded.txt";
    HuffmanTree tree;
    tree.fill_tree_arr(inputfile);
    tree.encodeFile(inputfile, outputfile);
    exit(0);
}