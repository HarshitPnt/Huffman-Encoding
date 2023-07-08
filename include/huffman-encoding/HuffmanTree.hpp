#include "HuffmanNodes.hpp"
#include <queue>
#include <vector>
#include <string>
#include <map>
#ifndef HUFFMAN_TREE
class Compare
{
public:
    bool operator()(HuffmanNode *below, HuffmanNode *above)
    {
        if (below->frequency >= above->frequency)
            return true;
        else
            return false;
    }
};
class HuffmanTree
{
public:
    HuffmanNode tree_arr[128];
    HuffmanNode *root;
    std::priority_queue<HuffmanNode *, std::vector<HuffmanNode *>, Compare> pq;

    // member functions

    HuffmanTree();
    void fill_tree_arr(std::string inputfile);
    void encodeFile(std::string input_file_name, std::string output_file_name);
    long long num_characters_encoded = 0;
    std::string postOrderTraversal(HuffmanNode *root);
    std::string getEncoding(char c);

private:
    std::map<char, std::string> character_to_code;
    void fill_pq();
    void display_tree_arr();
    void display_pq();
    void generateTree();
    void assignCode(HuffmanNode *root, std::string code);
    void displayCode();
};
#endif