#include <fstream>
#include <queue>
#include <map>
#ifndef HUFFMAN_TREE
#define HUFFMAN_TREE
#include "HuffmanTree.hpp"
#endif
class FileWriter
{
public:
    std::string output_file_name;
    std::fstream out;
    int num_characters;
    FileWriter(std::string output);
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