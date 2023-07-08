#include "HuffmanTree.hpp"
#include <fstream>

class Decoder
{
private:
    HuffmanTree tree;
    std::fstream inp, out;
    std::map<std::string, char> string_to_char;
    long long int num_characters_decoded;

public:
    void generateTree();
    std::string input_file_name, output_file_name;
    void setEncoding(HuffmanNode *root, std::string current);
    Decoder(std::string input, std::string output);
    void decodeContent();
    std::string decimal_to_binary(int decimal);
};