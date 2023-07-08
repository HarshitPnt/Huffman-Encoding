#include "huffman-encoding/Decoder.hpp"

int main(int argc, char *argv[])
{
    std::string inputfile = argv[1];
    std::string outputfile = argv[2];
    Decoder dec(inputfile, outputfile);
    dec.generateTree();
    exit(0);
}