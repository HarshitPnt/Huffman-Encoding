#include "huffman-encoding/HuffmanTree.hpp"
#include "huffman-encoding/HuffmanNodes.hpp"
#define HUFFMAN_TREE
#include "huffman-encoding/FileWriter.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <queue>
#include <vector>

HuffmanTree::HuffmanTree()
{
    root = new HuffmanNode();
}

void HuffmanTree::display_tree_arr()
{
    for (int i = 0; i < 128; ++i)
    {
        if (tree_arr[i].frequency != -1)
            std::cout << tree_arr[i].character << " " << tree_arr[i].frequency << std::endl;
    }
}

void HuffmanTree::fill_tree_arr(std::string inputfile)
{
    std::fstream inp(inputfile, std::ios::in);
    // tree_arr[0].character = (char)(0);
    // tree_arr[0].frequency = 1;
    while (!inp.eof())
    {
        char read;
        read = inp.get();
        if (read == -1)
            continue;
        ++num_characters_encoded;
        tree_arr[read].character = read;
        if (tree_arr[read].frequency != -1)
            tree_arr[read].frequency++;
        else
            tree_arr[read].frequency = 1;
    }
    // display_tree_arr();
    fill_pq();
}

void HuffmanTree::display_pq()
{
    std::priority_queue<HuffmanNode *, std::vector<HuffmanNode *>, Compare> temp(pq);
    std::cout << "Displaying priority queue\n";
    while (!temp.empty())
    {
        HuffmanNode *curr = temp.top();
        temp.pop();
        std::cout << curr->character << " " << curr->frequency << std::endl;
    }
}

void HuffmanTree::fill_pq()
{
    for (int i = 0; i < 128; ++i)
    {
        if (tree_arr[i].frequency != -1)
            pq.push(&tree_arr[i]);
    }
    // display_pq();
    generateTree();
}

void HuffmanTree::generateTree()
{
    if (pq.size() == 0)
        return;
    while (pq.size() != 1)
    {
        HuffmanNode *first = pq.top();
        pq.pop();
        HuffmanNode *second = pq.top();
        pq.pop();
        HuffmanNode *cumulative = new HuffmanNode(first->frequency + second->frequency);
        cumulative->left = first;
        cumulative->right = second;
        pq.push(cumulative);
    }
    root = pq.top();
    pq.pop();
    assignCode(root, "");
    // displayCode();
}
void HuffmanTree::displayCode()
{
    for (int i = 0; i < 128; ++i)
    {
        if (tree_arr[i].frequency != -1)
            std::cout << tree_arr[i].character << " " << tree_arr[i].frequency << " " << tree_arr[i].code << std::endl;
    }
}

void HuffmanTree::assignCode(HuffmanNode *root, std::string code)
{
    if (!root)
        return;
    if (!root->left && !root->right)
    {
        root->code = code;
        character_to_code[root->character] = code;
    }
    assignCode(root->left, code + "0");
    assignCode(root->right, code + "1");
}

void HuffmanTree::encodeFile(std::string input_file_name, std::string output_file_name)
{
    // std::fstream inp(input_file_name, std::ios::in);
    FileWriter fw(output_file_name);
    fw.insertEncoding(*this);
    fw.writeMetaData(*this);
    fw.encodeFile(input_file_name, *this);
}

std::string HuffmanTree::getEncoding(char c)
{
    return character_to_code[c];
}

std::string HuffmanTree::postOrderTraversal(HuffmanNode *root)
{
    if (!root->left && !root->right)
        return "1" + std::string(1, root->character);
    std::string left = "", right = "";
    if (root->left)
        left = postOrderTraversal(root->left);
    if (root->right)
        right = postOrderTraversal(root->right);

    return left + right + "0";
}
