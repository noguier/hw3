#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();


  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const; //done

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below
  std::vector<T> data;
  PComparator c_;
  int m_;
  void heapify(int idx); //aka trickledown
  void trickleUp(int idx);
};


  template <typename T, typename PComparator>
  Heap<T,PComparator>::Heap(int m, PComparator c) {
    m_ = m;
    c_ = c;
  }

  template <typename T, typename PComparator>
  Heap<T,PComparator>::~Heap() {  
  }

  template <typename T, typename PComparator>
  bool Heap<T, PComparator>::empty() const {
    return data.size() == 0;
  }

  template <typename T, typename PComparator>
  std::size_t Heap<T, PComparator>::size() const {
      return data.size();
  }

  // Add implementation of member functions here
  template <typename T, typename PComparator>
  T const& Heap<T, PComparator>::top() const {
      if (empty()) {
          throw std::underflow_error("Heap is empty");
      }
      return data[0];
  }

  // We will start pop() for you to handle the case of 
  // calling top on an empty heap
  template <typename T, typename PComparator>
  void Heap<T,PComparator>::pop()
  {
    if(empty()){
      // ================================
      // throw the appropriate exception
      // ================================
      throw std::underflow_error("Heap is empty");
    }
    data[0] = data.back(); //overwrite the top element with the data from the last element 
    data.pop_back(); //pop back the last element 
    heapify(0); //trickledown on the top element 
  }

  template <typename T, typename PComparator>
  void Heap<T, PComparator >::heapify(int idx) {
    int leftmostchild = m_*idx+1;
    int bestchild = 0;
  
  if (m_*idx+1 >= data.size()) { // if it is a leaf node
      return;
  }
  //compare to best bestchild
  //best child to be left most child (we know there is a left child bc not a leaf node)
  //go through all childen and compare to best node 
  // check if leftmost + i exists
  //if it is greater set best child to leftmost +i
  bestchild = leftmostchild;
  for (size_t i = 1; i < m_ ; i++) {
    if (leftmostchild+i < data.size()) {
        if (c_(data[leftmostchild+i], data[bestchild])) {
          bestchild = leftmostchild+i;
        }
    }
  }
  if (c_(data[bestchild], data[idx])) {
    std::swap(data[idx], data[bestchild]);
    heapify(bestchild);
  }
  }

  template <typename T, typename PComparator>
  void Heap<T, PComparator>::push(const T& item) {
    data.push_back(item);
    trickleUp(data.size()-1); //trickle up on the newly added element
    
  }
  template <typename T, typename PComparator>
  void Heap<T, PComparator >::trickleUp(int idx) {
    int parent = (idx-1)/m_; //setting the parent according m-ary of the tree
    while (parent >= 0 && c_(data[idx], data[parent])) {
      std::swap(data[parent], data[idx]);
      idx = parent;
      parent = (parent-1) / m_;
    }
  }


#endif

