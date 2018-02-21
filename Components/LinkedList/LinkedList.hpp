#ifndef LINKED_LIST_HPP_
#define LINKED_LIST_HPP_

#include <cstdlib>
#include <memory>

struct Node {
  Node() : value{0}, next{nullptr} {}
  Node(double _value) : value{_value}, next{nullptr} {}
  Node(double _value, Node *node)
      : value{_value}
      , next{std::unique_ptr<Node>(node)} {}

  double value;
  std::unique_ptr<Node> next{};
};

class LinkedList {
public:
  LinkedList();
  // LinkedList(std::initializer_list<double> il);

  void InsertAfter(double val);
  void PushFront(double val);
  double PopFront();
  double At(int index);

  size_t Size() { return m_size; }

  ~LinkedList() {}

private:
  LinkedList(const LinkedList &) = delete;
  LinkedList &operator=(const LinkedList &) = delete;

  size_t m_size;
  std::unique_ptr<Node> m_head;
};
#endif // LINKED_LIST_HPP_