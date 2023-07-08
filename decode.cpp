#include <iostream>
#include <cstring>
// #ifndef HUFFMAN_STRING
// #define HUFFMAN_STRING
// #include <string>
// #endif
#include "../include/huffman-encoding/HuffmanNodes.hpp"
#include "../include/huffman-encoding/HuffmanTree.hpp"
#include "../include/huffman-encoding/FileWriter.hpp"
#include "../include/huffman-encoding/Decoder.hpp"

int main(int argc, char *argv[])
{
    std::string inputfile = "../inputFiles/input2.txt";
    std::string outputfile = "../outputFiles/encoded.txt";
    // HuffmanTree tree;
    // tree.fill_tree_arr(inputfile);

    // HuffmanTree tree;
    // HuffmanNode n1(13), n2(6), n3(3), n4(3), n5(7), n6(3), n7(1), n8(2), n9(4), n10(2), n11(1), n12(1), n13(2), n14(1), n15(1);
    // tree.root = &n1;
    // n1.left = &n2;
    // n2.left = &n3;
    // n3.character = 'g';
    // n2.right = &n4;
    // n4.character = 'o';
    // n1.right = &n5;
    // n5.left = &n6;
    // n6.left = &n7;
    // n7.character = 's';
    // n6.right = &n8;
    // n8.character = ' ';
    // n5.right = &n9;
    // n9.left = &n10;
    // n10.left = &n11;
    // n11.character = 'e';
    // n10.right = &n12;
    // n12.character = 'h';
    // n9.right = &n13;
    // n13.left = &n14;
    // n13.right = &n15;
    // n15.character = 'r';
    // n14.character = 'p';
    // tree.encodeFile(inputfile, outputfile);
    Decoder dec(outputfile, inputfile);
    dec.generateTree();
    exit(0);
}