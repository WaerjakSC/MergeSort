#ifndef TREENODE_H
#define TREENODE_H
#include <cstdlib>
#include <iostream>
#include <utility>
#include <vector>

namespace ADS101
{
template <typename Comparable>
class TreeNode
{
    struct node;

public:
    TreeNode() { root = nullptr; }
    void addNode(Comparable data) { addNodePrivate(data, root); }
    void remove(Comparable data) { removePrivate(data, root); }
    void printInOrder() { printInOrderPrivate(root); }
    void printPreOrder() { preOrderPrintPrivate(root); }
    void printPostOrder() { postOrderPrintPrivate(root); }
    TreeNode::node *findMin(TreeNode::node *Ptr)
    {
        if (Ptr == nullptr)
            return nullptr;
        if (Ptr->left == nullptr)
            return Ptr;
        return findMin(Ptr->left);
    }

private:
    struct node
    {
        Comparable data;
        node *left;
        node *right;
    };
    node *root;

    TreeNode::node *CreateLeaf(Comparable data)
    {
        node *n = new node;
        n->data = data;
        n->left = nullptr;
        n->right = nullptr;

        return n;
    }
    /**
   * @brief addNodePrivate
   * @param data
   * @param Ptr
   * Simple all-purpose function to add a new node
   */
    void addNodePrivate(Comparable data, TreeNode::node *Ptr)
    {
        if (root == nullptr) // If tree is empty, make it not empty
        {
            root = CreateLeaf(data);
        }
        else if (data < Ptr->data) // If data value is less than current node data value
        {
            if (Ptr->left != nullptr)
            {
                addNodePrivate(data, Ptr->left);
            }
            else
            {
                Ptr->left = CreateLeaf(data);
            }
        }
        else if (data > Ptr->data) // If data value is greater than current node data value
        {
            if (Ptr->right != nullptr)
            {
                addNodePrivate(data, Ptr->right);
            }
            else
            {
                Ptr->right = CreateLeaf(data);
            }
        }
    }
    /**
  Note to self: Forgot to pass by reference at first so changing Ptr wasn't having
  an effect on the actual tree and changing the Ptr left a dangling pointer
  */
    void removePrivate(Comparable data, node *&Ptr)
    {
        if (Ptr == nullptr)
        {
            return;
        }
        if (data < Ptr->data)
        {
            removePrivate(data, Ptr->left);
        }
        else if (data > Ptr->data)
        {
            removePrivate(data, Ptr->right);
        }
        else if (Ptr->left != nullptr && Ptr->right != nullptr) // two children
        {
            Ptr->data = findMin(Ptr->right)->data;
            removePrivate(Ptr->data, Ptr->right);
        }
        else
        {
            node *oldNode = Ptr;
            Ptr = (Ptr->left != nullptr) ? Ptr->left : Ptr->right; // if Ptr->left is nullptr, set Ptr to Ptr->right
            delete oldNode;                                        // get rid of pointer
        }
    }
    /**
   * @brief printInOrderPrivate
   * @param Ptr
   * Below - the three print functions
   */
    void printInOrderPrivate(node *Ptr)
    {
        if (root != nullptr)
        {
            if (Ptr->left != nullptr)
            {
                printInOrderPrivate(Ptr->left);
            }
            std::cout << Ptr->data << " ";
            if (Ptr->right != nullptr)
            {
                printInOrderPrivate(Ptr->right);
            }
        }
        else
        {
            std::cout << "Tree is empty.\n";
        }
    }
    void preOrderPrintPrivate(node *Ptr)
    {
        if (root != nullptr)
        {
            std::cout << Ptr->data << " ";
            if (Ptr->left != nullptr)
            {
                printInOrderPrivate(Ptr->left);
            }
            if (Ptr->right != nullptr)
            {
                printInOrderPrivate(Ptr->right);
            }
        }
        else
        {
            std::cout << "Tree is empty.\n";
        }
    }
    void postOrderPrintPrivate(node *Ptr)
    {
        if (root != nullptr)
        {
            if (Ptr->left != nullptr)
            {
                printInOrderPrivate(Ptr->left);
            }
            if (Ptr->right != nullptr)
            {
                printInOrderPrivate(Ptr->right);
            }
            std::cout << Ptr->data << " ";
        }
        else
        {
            std::cout << "Tree is empty.\n";
        }
    }
};
} // namespace ADS101
#endif // TREENODE_H
