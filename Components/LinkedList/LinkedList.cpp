#include "LinkedList.hpp"

LinkedList::LinkedList() : m_size{0}, m_head{nullptr} {}

// LinkedList::LinkedList(std::initializer_list<double> il) {}

void LinkedList::InsertAfter(double val) {}

double LinkedList::PopFront() {
	auto retVal = m_head->value;
  // set new head
  m_head = std::move(m_head->next);
  m_size--;
  
  return retVal;
}

void LinkedList::PushFront(double val) {
	// create new node
	auto newHead = new Node(val);
	// set the old head to be new head's next
	// move destructs m_head
	newHead->next = std::move(m_head);
	// create new ptr with newHead
	m_head = std::unique_ptr<Node>(newHead);
	m_size++;
}

double LinkedList::At(int index) { return 0.0; }

// void LinkedList::PushFront(double val) {
// 	// backup the current head
// 	// don't need to check for nullptr in case of inserting first element,
// 	// since next of first element == nullptr anyways.
//   auto oldHead = std::move(m_head);

//   // at this point, move has destructed m_head
//   // does reset work here? or should i create a new pointer? 
//   m_head.reset(new Node(val));
//   //m_head = std::unique_ptr<Node>(new Node(val));

//   // Moving old Head to new head's next!
//   m_head->next= std::move(oldHead);

//   // increment size
//   ++m_size;
// }
