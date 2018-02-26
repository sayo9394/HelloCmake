#include "BinarySearchTree.hpp"
#include <cassert>
#include <stdexcept>

using namespace std;

namespace { // Binary Search Tree Helper Functions

void InsertHelper(std::unique_ptr<Node>& node, double item) {
	auto tmp = unique_ptr<Node>(new Node(item));
  if (!node) {
    node = std::move(tmp);
  } else {
    if (item < node->item) {
      InsertHelper(node->left, item);
    } else {
      InsertHelper(node->right, item);
    }
  }
}

std::unique_ptr<Node> SearchTreeHelper(std::unique_ptr<Node>& node,
                                       double item) {
  std::unique_ptr<Node> tmp;
  return tmp;
}

} // namespace

BinarySearchTree::BinarySearchTree() : m_root{nullptr} {}

void BinarySearchTree::Insert(double item) { 
	InsertHelper(m_root, item); 
}

void BinarySearchTree::TraverseTree() {}

std::unique_ptr<Node> BinarySearchTree::SearchTree(double item) {
  return SearchTreeHelper(m_root, item);
}

double BinarySearchTree::FindMinimum() {
  if (!m_root) throw std::out_of_range("BST Empty");

  auto min = m_root.get();
  auto tmp = m_root.get();

  // auto val = min->item;
  // assert(val == 10);

  while (tmp)
  {
  	if (tmp->item < min->item)
  		min = tmp;
  	
  	tmp = tmp->left.get();
  }

  return min->item;
}