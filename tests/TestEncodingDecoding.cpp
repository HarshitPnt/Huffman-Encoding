#include "huffman-encoding/Decoder.hpp"
#include "huffman-encoding/Encoder.hpp"
#include <iostream>
#include <fstream>
#include <unistd.h>
#include <cstring>

int main(int argc, char *argv[])
{
    // encode a file and then decode it and then compare the two results
    for (int i = 1; i < argc; ++i)
    {
        std::string inputFile = std::string(argv[i]);
        std::string test_encoded = "../test_encoded.txt";
        std::string test_decoded = "../test_decoded.txt";
        Encoder enc(inputFile, test_encoded);
        enc.encode();
        Decoder dec(test_encoded, test_decoded);
        dec.generateTree();
        long long int differences = 0;
        std::fstream inp1(inputFile, std::ios::in);
        std::fstream inp2(test_decoded, std::ios::in);

        while (!inp1.eof() && !inp2.eof())
        {
            char ch1 = inp1.get();
            char ch2 = inp2.get();
            if (ch1 == -1 || ch2 == -1)
                continue;

            if (ch1 != ch2)
                ++differences;
        }

        if (differences == 0 && inp1.eof() && inp2.eof())
            std::cout << argv[i] << ": Perfectly correct!!" << std::endl;
        else
            std::cout << argv[i] << ": Incorrect with " << differences << " differences" << std::endl;
        unlink(test_encoded.c_str());
        unlink(test_decoded.c_str());
    }
}