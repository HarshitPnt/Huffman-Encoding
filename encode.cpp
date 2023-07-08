
#include "huffman-encoding/Encoder.hpp"

int main(int argc, char *argv[])
{
    std::string inputFile = std::string(argv[1]);
    std::string outputFile = std::string(argv[2]);
    Encoder enc(inputFile, outputFile);
    enc.encode();
    exit(0);
}