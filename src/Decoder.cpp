#include "huffman-encoding/Decoder.hpp"
#include <stack>
#include <iostream>

Decoder::Decoder(std::string input, std::string output)
{
    input_file_name = input;
    output_file_name = output;
    inp.open(input, std::ios::in);
    out.open(output, std::ios::out);
}

void Decoder::generateTree()
{
    if (inp.eof())
    {
        std::cout << "The file is not supported\n";
        return;
    }
    int num_characters = inp.get();
    inp.get();
    inp >> num_characters_decoded;
    char next = inp.get();
    if (next != '\n')
    {
        std::cout << "The file is not supported\n";
        return;
    }

    std::stack<HuffmanNode *> st;
    next = inp.get();
    if (next != '1')
    {
        std::cout << "The file is not supported\n";
        return;
    }
    HuffmanNode node[num_characters];
    node[0].character = inp.get();
    st.push(&node[0]);
    next = inp.get();
    if (next != '1')
    {
        std::cout << "The file is not supported\n";
        return;
    }
    node[1].character = inp.get();
    st.push(&node[1]);
    int charcters_done = 2;
    while (!st.empty())
    {
        next = inp.get();
        if (next == '1')
        {
            // HuffmanNode temp;
            node[charcters_done++].character = inp.get();
            st.push(&node[charcters_done - 1]);
        }
        else if (next == '0')
        {
            // pop the above two elements
            HuffmanNode *a1, *a2;
            a1 = st.top();
            st.pop();
            if (st.empty())
            {
                std::cout << "The file type is not supported\n";
                return;
            }
            a2 = st.top();
            st.pop();
            HuffmanNode *a3 = new HuffmanNode();
            a3->left = a2;
            a3->right = a1;
            st.push(a3);
        }
        else if (next == '\n')
        {
            // the tree has been generated
            tree.root = st.top();
            st.pop();
            if (!st.empty())
            {
                std::cout << "The file type is not supported\n";
                return;
            }
        }
        else
        {
            std::cout << "The file type is not supported\n";
            return;
        }
    }
    HuffmanNode *current = tree.root;
    while (current->left)
        current = current->left;

    ;

    setEncoding(tree.root, "");
    decodeContent();
}

void Decoder::setEncoding(HuffmanNode *root, std::string current)
{
    if (!root->left && !root->right)
    {
        string_to_char[current] = root->character;
        return;
    }
    if (root->left)
        setEncoding(root->left, current + "0");
    if (root->right)
        setEncoding(root->right, current + "1");
}

std::string Decoder::decimal_to_binary(int decimal)
{
    std::string str = "";
    for (int i = 0; i < 8; ++i)
    {
        int c = decimal % 2;
        char ch = (c == 1 ? '1' : '0');
        decimal = decimal / 2;
        str = std::string(1, ch) + str;
    }
    return str;
}

void Decoder::decodeContent()
{
    std::string str = "";
    std::cout << "Decoding..." << std::endl;

    while (!inp.eof())
    {
        unsigned char current = inp.get();
        std::string decodedString = decimal_to_binary(current);
        long long int total_to_be_decoded = num_characters_decoded;
        int last = 0;
        for (int i = 0; i < 8; ++i)
        {
            str += std::string(1, decodedString[i]);
            if (string_to_char.find(str) != string_to_char.end())
            {
                out << string_to_char[str];
                str = "";
                --num_characters_decoded;
                if (((20 * (total_to_be_decoded - num_characters_decoded)) / total_to_be_decoded) > last)
                {
                    ++last;
                    std::cout << "-" << std::flush;
                }
                if (num_characters_decoded == 0)
                {
                    std::cout << std::endl;
                    out.close();
                    return;
                }
            }
        }
    }
    std::cout << std::endl;

    out.close();
}