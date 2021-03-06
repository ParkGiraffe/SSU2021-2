#include <iostream>
#include "BinaryTree.h"

using namespace std;

BinaryTree::BinaryTree(void)
{
    root = NULL;
}
BinaryTree::~BinaryTree(void)
{
    deleteNode(root);
}

void BinaryTree::setRoot(NODE_TREE *node)
{
    root = node;
    cout << "root is " << node->data << " node." << endl;
}

NODE_TREE *BinaryTree::getRoot()
{
    return root;
}


NODE_TREE *BinaryTree::makeNode(
    element item,
    NODE_TREE *left,
    NODE_TREE *right)
{
    NODE_TREE *temp = new NODE_TREE;
    temp->data = item;
    temp->left = left;
    temp->right = right;

    cout << "create " << temp->data << " node" << endl;

    return temp;
}

bool BinaryTree::isEmpty()
{
    return root == NULL;
}

void BinaryTree::preorder(NODE_TREE *node)
{
    if (node != NULL)
    {
        cout << ' ' << node->data;
        preorder(node->left);
        preorder(node->right);
    }
}

void BinaryTree::inorder(NODE_TREE *node)
{
    if (node != NULL)
    {
        inorder(node->left);
        cout << ' ' << node->data;
        inorder(node->right);
    }   
}

void BinaryTree::postorder(NODE_TREE *node)
{
    if (node != NULL)
    {
        postorder(node->left);
        postorder(node->right);
        cout << ' ' << node->data;
    }   
}

// 트리의 총 노드 개수 반환
int BinaryTree::getCount(NODE_TREE *node)
{
    if (node == NULL)
    {
        return 0;
    }
    return 1 + getCount(node->left) + getCount(node->right);
}

// 트리의 높이(레벨) 반환
int BinaryTree::getHeight(NODE_TREE *node)
{
    if (node == NULL)
        return 0;

    int hLeft = getHeight(node->left);
    int hRight = getHeight(node->right);

    return (hLeft > hRight) ? hLeft + 1 : hRight + 1;
}

// 트리의 단말 노드 반환
int BinaryTree::getLeafCount(NODE_TREE *node)
{
    if (node == NULL)
    {
        return 0;
    }

    if (node->left == NULL && node->right == NULL)
        return 1;
    else 
        return getLeafCount(node->right) + getLeafCount(node->left);
}

void BinaryTree::deleteNode(NODE_TREE *node)
{
    if (node != NULL)
    {
        deleteNode(node->left);
        deleteNode(node->right);
        cout << "delete " << node->data << " node." << endl;
    }
}