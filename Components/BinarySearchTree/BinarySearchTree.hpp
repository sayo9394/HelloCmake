#ifndef BINARY_SEARCH_TREE_HPP_
#define BINARY_SEARCH_TREE_HPP_

#include <memory>
#include <functional>

struct Node
{
	Node() : item(0.0), right{nullptr}, left{nullptr} {}
	Node(double _item) : item(_item), right{nullptr}, left{nullptr} {}

	double item;
	std::unique_ptr<Node> right;
	std::unique_ptr<Node> left;	
};

class BinarySearchTree
{
public:
	BinarySearchTree();
	~BinarySearchTree(){}

	void Insert(double item);
	void TraverseTree(std::function<void(double _item)>const& funk);
	
	std::unique_ptr<Node> SearchTree(double item);
	double FindMinimum();

private:
	BinarySearchTree(const BinarySearchTree&) = delete;
	BinarySearchTree& operator=(const BinarySearchTree&) = delete;

	std::unique_ptr<Node> m_root;
};

#endif //BINARY_SEARCH_TREE_HPP_