#ifndef BINARY_SEARCH_TREE_HPP_
#define BINARY_SEARCH_TREE_HPP_

#include <memory>
#include <functional>
#include <cassert>
#include <stdexcept>

template <typename T>
struct Node
{
    Node() = default;

    explicit Node(T _item)
        : item(_item)
        , right{nullptr}
        , left{nullptr}{}

    T item;
    std::unique_ptr<Node> right{nullptr};
    std::unique_ptr<Node> left{nullptr};
};

template <typename T>
class BinarySearchTree
{
public:
    BinarySearchTree()
        : m_root{nullptr}
    {
    }

    ~BinarySearchTree() {}

    void Insert(T item) { InsertHelper(m_root, item); }

    void TraverseTree(const std::function<void(T _item)>& funk)
    {
        TraverseTreeHelper(m_root, funk);
    }

    std::unique_ptr<Node<T>> SearchTree(T item) { return SearchTreeHelper(m_root, item); }

    T FindMinimum()
    {
        if (!m_root) throw std::out_of_range("BST Empty");

        auto min = m_root.get();
        auto tmp = m_root.get();

        while (tmp)
        {
            if (tmp->item < min->item) min = tmp;

            tmp = tmp->left.get();
        }

        return min->item;
    }

private:
    void InsertHelper(std::unique_ptr<Node<T>>& node, T item)
    {
        auto tmp = std::unique_ptr<Node<T>>(new Node<T>(item));
        if (!node)
        {
            node = std::move(tmp);
        }
        else
        {
            if (item < node->item)
            {
                InsertHelper(node->left, item);
            }
            else
            {
                InsertHelper(node->right, item);
            }
        }
    }

    std::unique_ptr<Node<T>> SearchTreeHelper(std::unique_ptr<Node<T>>& node, T item)
    {
        std::unique_ptr<Node<T>> tmp;
        return tmp;
    }

    void TraverseTreeHelper(std::unique_ptr<Node<T>>& node,
                            std::function<void(T _item)> const& funk)
    {
        if (node)
        {
            TraverseTreeHelper(node->left, funk);
            funk(node->item);
            TraverseTreeHelper(node->right, funk);
        }
    }

private:
    BinarySearchTree(const BinarySearchTree&) = delete;
    BinarySearchTree& operator=(const BinarySearchTree&) = delete;

    std::unique_ptr<Node<T>> m_root;
};

#endif // BINARY_SEARCH_TREE_HPP_