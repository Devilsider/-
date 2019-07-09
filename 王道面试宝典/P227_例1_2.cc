#include <stdlib.h>

#include <iostream>
using namespace std;

struct TreeNode
{
    int data;
    TreeNode* left;
    TreeNode* right;
};
int height(TreeNode* root)
{
    if(root==NULL)
    {
        return 0;
    }
    return 1+max(height(root->left),height(root->right));
}
bool isBalanced(TreeNode* root)
{
    return (height(root->left)-height(root->right)<=1);
}

int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

