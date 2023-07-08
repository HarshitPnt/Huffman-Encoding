#include "huffman-encoding/HuffmanTree.hpp"
#include "huffman-encoding/FileWriter.hpp"

#include <fstream>
#include <queue>
#include <iostream>
FileWriter::FileWriter(std::string output, long long int num_char)
{
    output_file_name = output;
    out.open(output_file_name, std::ios::out);
    num_characters = 0;
    num_characters_encoded = num_char;
}

void FileWriter::writeMetaData(HuffmanTree tree)
{
    // needs to print the number of characters and byte to character encoding;
    out << (char)num_characters << "\n";
    out << tree.num_characters_encoded << "\n";
    // next insert the decode table

    //"go go gophers", the header information is "1g1o01s1 01e1h01p1r00000"
    // will have to traverse the tree in post order when any leaf node is visited it 1<character> is encoded and when a non-leaf is visited then 0 is inserted
    std::string output_string = tree.postOrderTraversal(tree.root);
    out << output_string << '\n';
    // metadata written
}

void FileWriter::insertEncoding(HuffmanTree tree)
{
    for (int i = 0; i < 128; ++i)
    {
        if (tree.tree_arr[i].frequency != -1)
        {
            string_to_char[tree.tree_arr[i].code] = tree.tree_arr[i].character;
            ++num_characters;
        }
    }
}

void FileWriter::enterQueue(std::string bit_stream)
{
    int size = bit_stream.length();
    for (int i = 0; i < size; ++i)
        bit_queue.push(bit_stream[i]);
}

unsigned char FileWriter::binary_to_char(std::string binary)
{
    int n = 0;
    int power_2 = 1;
    for (int i = 7; i >= 0; --i)
    {
        if (i == 7)
        {
            n += power_2 * (binary[i] - '0');
        }
        else
        {
            n += 2 * power_2 * (binary[i] - '0');
            power_2 *= 2;
        }
    }
    return (unsigned char)n;
}

void FileWriter::flush_byte()
{
    std::string str = "";

    for (int i = 0; i < 8; ++i)
    {
        str += std::string(1, bit_queue.front());
        bit_queue.pop();
    }
    unsigned char c = binary_to_char(str);
    out << c;
    ++written;
    if (((20 * written / num_characters_encoded)) > last)
    {
        ++last;
        std::cout << "-" << std::flush;
    }
}

void FileWriter::encodeFile(std::string input_file_name, HuffmanTree &tree)
{
    std::cout << "Encoding..." << std::endl;
    int charcater_count = 0;
    char curr;
    std::fstream inp(input_file_name, std::ios::in);
    while (!inp.eof())
    {
        curr = inp.get();
        if (curr == -1)
            continue;
        ++charcater_count;
        std::string encoding = tree.getEncoding(curr);
        enterQueue(encoding);
        while (bit_queue.size() >= 8)
        {
            flush_byte();
        }
    }
    if (!bit_queue.empty())
    {
        while (bit_queue.size() != 8)
            bit_queue.push('0');
        ++charcater_count;
        flush_byte();
    }
    out << (char)-1;
    std::cout << std::endl;
}