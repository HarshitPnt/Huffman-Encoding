#pragma once
#include <fstream>
#include <queue>
#include <map>
#include "huffman-encoding/HuffmanTree.hpp"
class FileWriter
{
public:
    std::string output_file_name;
    std::fstream out;
    int num_characters;
    long long int num_characters_encoded = 0;
    long long int written = 0;
    int last = 0;
    FileWriter(std::string output, long long int num_characters_encoded);
    void writeMetaData(HuffmanTree tree);
    void encodeFile(std::string input_file_name, HuffmanTree &tree);
    void insertEncoding(HuffmanTree tree);

private:
    std::map<std::string, char> string_to_char;
    std::queue<int> bit_queue;
    void enterQueue(std::string bit_stream);
    void flush_byte();
    unsigned char binary_to_char(std::string binary);
};