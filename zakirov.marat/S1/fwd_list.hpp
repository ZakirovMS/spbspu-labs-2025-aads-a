#ifndef MY_LIST_HPP
#define MY_LIST_HPP
#include "fwd_list_node.hpp"
#include "fwd_iterator.hpp"

namespace zakirov
{
  template< typename T >
  class FwdList
  {
  public:
    FwdList();
    ~FwdList();
    FwdListNode< T > * front();
    FwdIterator< T > begin();
    FwdIterator< T > end();
    void pop_front();
    void push_front(const T & data);
    void push_front(const T && data);
    bool empty();
    size_t size();
    void swap(FwdList & other);
    void clear();
  private:
    FwdListNode< T > * fake_node_;
  };

  template< typename T >
  FwdList< T >::FwdList():
    fake_node_(reinterpret_cast< FwdListNode< T >* >(new char[sizeof(FwdListNode< T >)])),
    node_quantity_(0)
  {
    fake->next = fake;
  }

  template< typename T >
  FwdList< T >::~FwdList()
  {
    clear();
  }

  template< typename T >
  FwdListNode< T > * FwdList< T >::front()
  {
    return fake_node_->next_;
  }

  template< typename T >
  FwdIterator< T > FwdList< T >::begin()
  {
    return FwdIterator< T >(fake_node_->next_);
  }

  template< typename T >
  FwdIterator< T > FwdList< T >::end()
  {
    return FwdIterator< T >(fake_node_);
  }

  template< typename T >
  void FwdList< T >::pop_front()
  {
    FwdListNode< T > * new_begin = (fake_node_->next_)->next_;
    delete fake_node_->next_;
    fake_node_->next_ = new_begin;
  }

  template< typename T >
  void FwdList< T >::push_front(const T & data)
  {
    FwdListNode< T > * new_element = new FwdListNode< T >(data);
    new_element->next_ = fake_node_->next_;
    fake_node_->next_ = new_element;
  }

  template< typename T >
  void FwdList< T >::push_front(const T && data)
  {
    FwdListNode< T > * new_element = new FwdListNode< T >(std::move(data));
    new_element->next_ = fake_node_->next_;
    fake_node_->next_ = new_element;
  }

  template< typename T >
  bool FwdList< T >::empty()
  {
    if (fake_node_->next_ == fake_node_)
    {
      return 1;
    }

    return 0;
  }

  template< typename T >
  size_t FwdList< T >::size()
  {
    size_t counter = 0;
    FwdListNode< T > * nailed_ptr = fake_node_;
    FwdListNode< T > * fillable_ptr = fake_node_->next_;
    while (nailed_ptr != fillable_ptr)
    {
      ++counter;
      fillable_ptr->next_;
    }

    return counter;
  }

  template< typename T >
  void FwdList< T >::swap(FwdList & other)
  {
    FwdListNode< T > * temporary_node = other.fake_node_;
    other.fake_node_ = fake_node_;
    fake_node_ = temporary_node;
  }

  template< typename T >
  void FwdList< T >::clear()
  {
    while (!empty())
    {
      pop_front();
    }
  }
}

#endif
