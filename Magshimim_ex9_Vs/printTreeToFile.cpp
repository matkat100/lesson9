#include "printTreeToFile.h"
#include <string>
#include <fstream>


void preOrder(const BSNode* root, std::string& str) {
    if (root == nullptr) {
        str += "# ";
        return;
    }
    str += (root->getData()) + " ";
    preOrder(root->getLeft(), str);
    preOrder(root->getRight(), str);
}

void printTreeToFile(const BSNode* bs, std::string output)
{
    std::string treePreOrder("");
    preOrder(bs, treePreOrder);

    std::ofstream outputFile(output);
    outputFile << treePreOrder;


}