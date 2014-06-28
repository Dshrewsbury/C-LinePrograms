#include <iostream>
using namespace std;

template<class DataType>
struct Node
{
  DataType data;
  Node<DataType>* next;
};

template<class DataType>
class LinkedList
{
  public:
   LinkedList();
   LinkedList(const LinkedList<DataType> & aplist);
   ~LinkedList();
  LinkedList<DataType>& operator=(const LinkedList<DataType>& rlist);
  void insert(const DataType& element);
  bool first(DataType& listEl);
  bool getNext(DataType& listEl);
  bool find(const DataType& element);
  bool retrieve(DataType& element);
  bool replace(const DataType& newElement);
  bool remove(DataType& element);
  bool isEmpty() const;
  void makeEmpty();
  DataType&  operator[](int index);
  int length() const;

  private:
  int size;
  int currentIndex;
  Node<DataType>* start;
  Node<DataType>* current;
  DataType dummy;
  void deepCopy(const LinkedList<DataType>& original);  
};

template <class DataType>
int LinkedList<DataType>::length() const
{
  return size;
}

template <class DataType>
DataType& LinkedList<DataType>::operator[](int index)
{
  if(!start) return dummy;

  if(index == 0)
  {
    current = start;
    currentIndex = 0;
    return current->data;
  }  
  else if(index == currentIndex + 1)
  {
    current = current->next;
    currentIndex++;

    if(!current)
    {
      currentIndex = -1;
      return dummy;
    }
    
    return current->data;
  }
  else
 {
  while(currentIndex != index)
  {
    current = current->next;
    currentIndex++;
  }

   return current->data;
 }
  currentIndex++;
  return start->data;

}

template <class DataType>
LinkedList<DataType>::LinkedList()
: start(0), current(0) {size = 0;}

template <class DataType>
LinkedList<DataType>::~LinkedList()
{
  Node<DataType>* p;
  while (start) 
  { 
    p = start->next; 
    delete start; 
    start = p;
} }

template <class DataType>
LinkedList<DataType>::LinkedList(const LinkedList<DataType>& a)
: start(0), current(0), size(0)
{
  Node<DataType>* p;
  Node<DataType>* end = 0;
  
  for (p = a.start; p; p = p->next)
  {
    Node<DataType>* node = new Node<DataType>;
    node->data = p->data;
    node->next = 0;
    if (end) end->next = node;
    else start = node;
    end = node;
    if (p == a.current) current = node; 
    size++;
} }

template <class DataType>
LinkedList<DataType>& LinkedList<DataType>::operator=(const LinkedList<DataType>& a)
{
  if (this != &a)
  {
    current = 0;
    Node<DataType>* p;
    Node<DataType>* end = 0;
    while (start) 
    { 
      p = start->next; 
      delete start; 
      start = p;
    }
    for (p = a.start; p; p = p->next)
    {
      Node<DataType>* node = new Node<DataType>;
      node->data = p->data;
      node->next = 0;
      if (end) end->next = node;
      else start = node;
      end = node;
      if (p == a.current) current = node; 
      size++;
  } }
  return *this;
}

template<class DataType>
void LinkedList<DataType>::insert(const DataType& parameter) // O(1)
{
  current = 0;
  Node<DataType>* node = new Node<DataType>;
  node->data = parameter;
  node->next = start;
  start = node;
  size++;

}

template<class DataType>
bool LinkedList<DataType>::first(DataType& parameter) // O(1)
{
  if (!start) return false;
  parameter = start->data;
  current = start;
  return true;
}

template<class DataType>
bool LinkedList<DataType>::getNext(DataType& parameter) // O(1)
{
  if (!current) return false;
  current = current->next;
  if (!current) return false;
  parameter = current->data;
  return true;
}

template<class DataType>
bool LinkedList<DataType>::find(const DataType& parameter) // O(n)
{
  DataType temp;
  if (first(temp)) do
  {
    if (parameter == temp) return true; // found it
  } while (getNext(temp));
  return false; // no match
}

template<class DataType>
bool LinkedList<DataType>::retrieve(DataType& parameter) // O(n)
{
  if (!find(parameter)) return false;
  parameter = current->data; // set in find
  return true;
}

template<class DataType>
bool LinkedList<DataType>::replace(const DataType& parameter) // O(1)
{
  if (!current) return false;
  current->data = parameter;
  return true;
}

template<class DataType>
bool LinkedList<DataType>::remove(DataType& parameter) // O(n)
{
  // find node to remove
  Node<DataType>* p;
  Node<DataType>* prev;
  for (prev = 0, p = start; p; prev = p, p = p->next)
    if (p->data == parameter)
      break;

  // deallocate node here
  if (!p) return false; // no match
  if (prev) prev->next = p->next; else start = p->next;
  if (p == current) current = current->next;
  parameter = p->data;
  delete p;
  size--;
  return true;
}

template<class DataType>
bool LinkedList<DataType>::isEmpty() const // O(1)
{
  return start == 0;
}

template<class DataType>
void LinkedList<DataType>::makeEmpty() // O(n)
{
  while (start) 
  { 
    current = start->next; 
    delete start; 
    start = current;
} }