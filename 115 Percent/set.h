/***********************************************************************
* Header:
*    Set
* Summary:
 *      __      __     _______        __
 *     /  |    /  |   |  _____|   _  / /
 *     `| |    `| |   | |____    (_)/ /
 *      | |     | |   '_.____''.   / / _
 *     _| |_   _| |_  | \____) |  / / (_)
 *    |_____| |_____|  \______.' /_/
 *
 *    This will contain the class definition of:
*        set                 : A class that represents a Set
*        set::iterator       : An iterator through Set
* Author
*    <your names here>
************************************************************************/

#pragma once

#include <cassert>
#include <iostream>
#include "bst.h"
#include <memory>     // for std::allocator
#include <functional> // for std::less

class TestSet;        // forward declaration for unit tests

namespace custom
{

//   class TestSet;

/************************************************
 * SET
 * A class that represents a Set
 ***********************************************/
template <typename T>
class set
{
   friend class ::TestSet; // give unit tests access to the privates
public:
   
   // 
   // Construct
   //
   set() 
   { 
   }
   set(const set &  rhs)
   {
       this->bst = rhs.bst;
   }
   set(set && rhs) 
   {
       this ->bst = std::move(rhs.bst);
   }
   set(const std::initializer_list <T> & il) 
   {
       this->bst= il;
   }
   template <class Iterator>
   set(Iterator first, Iterator last) 
   {
       for(auto p = first; p!= last; ++p)
          insert(*p);
   }
    ~set() { clear(); }

   //
   // Assign
   //

   set & operator = (const set & rhs)
   {
       clear();
       this->bst = rhs.bst;
       
       return *this;

   }
   set & operator = (set && rhs)
   {
       clear();
       swap(rhs);
       return *this;
   }
    set & operator = (const std::initializer_list <T> & il)
    {
       clear();
       for(auto it = il.begin(); it != il.end(); ++it)
          insert(*it);
       return *this;
    }
    void swap(set& rhs) noexcept
    {
        this->bst.swap(rhs.bst);
    }

   //
   // Iterator
   //

   class iterator;
   iterator begin() const noexcept 
   { 
      return iterator(bst.begin());
   }
   iterator end() const noexcept 
   { 
      return iterator(bst.end());
   }

   //
   // Access
   //
   iterator find(const T& t) 
   { 
      return iterator(bst.find(t));
   }

   //
   // Status
   //
   bool empty() const noexcept 
   { 
      return size() == 0;
   }
   size_t size() const noexcept 
   { 
      return bst.size();
   }

   //
   // Insert
   //
   std::pair<iterator, bool> insert(const T& t)
   {
      std::pair<iterator, bool> p(iterator(), true);
      p = bst.insert(t,true);
       
      return std::pair<iterator, bool>(iterator(p.first), p.second);
   }
   std::pair<iterator, bool> insert(T&& t)
   {
      std::pair<iterator, bool> p(iterator(), true);
      p = bst.insert(std::move(t), true);
      
      return std::pair<iterator, bool>(iterator(p.first), p.second);
   }
   void insert(const std::initializer_list <T>& il)
   {
      for(auto p = il.begin(); p!= il.end(); ++p)
         insert(*p);
   }
   template <class Iterator>
   void insert(Iterator first, Iterator last)
   {
      for(auto p = first; p!= last; ++p)
         insert(*p);
   }


   //
   // Remove
   //
   void clear() noexcept 
   {
      bst.clear();
   }
   iterator erase(iterator &it)
   { 
      return iterator(bst.erase(it.it));
   }
   size_t erase(const T & t) 
   {
      iterator it  = find(t);
      if(it == end())
         return 0;
      erase(it);
      return 1;

   }
   iterator erase(iterator &itBegin, iterator &itEnd)
   {
      while(itBegin != itEnd)
         itBegin = erase(itBegin);
      
      return itEnd;

   }

private:
   
   custom::BST <T> bst;
};


/**************************************************
 * SET ITERATOR
 * An iterator through Set
 *************************************************/
template <typename T>
class set <T> :: iterator
{
   friend class ::TestSet; // give unit tests access to the privates
   friend class custom::set<T>;
public:
   // constructors, destructors, and assignment operator
   iterator() 
   {
      it = nullptr;
   }
   iterator(const typename custom::BST<T>::iterator& itRHS) 
   {
      this->it = itRHS;
   }
   iterator(const iterator & rhs) 
   {
      this->it = rhs.it;
   }
   iterator & operator = (const iterator & rhs)
   {
      this->it = rhs.it;
      return *this;
   }

   // equals, not equals operator
   bool operator != (const iterator & rhs) const 
   { 
      return this->it != rhs.it;
   }
   bool operator == (const iterator & rhs) const 
   { 
      return this->it == rhs.it;

   }

   // dereference operator: by-reference so we can modify the Set
   const T & operator * () const 
   { 
      return *it;
   }

   // prefix increment
   iterator & operator ++ ()
   {
      it++;
      return *this;
   }

   // postfix increment
   iterator operator++ (int postfix)
   {
      iterator temp(*this);
      ++it;
      return temp;
   }
   
   // prefix decrement
   iterator & operator -- ()
   {
      it--;
      return *this;
   }
   
   // postfix decrement
   iterator operator-- (int postfix)
   {
      iterator temp(*this);
      --it;
      return temp;
   }
private:

   typename custom::BST<T>::iterator it;
};

/***********************************************
 * SET : EQUIVALENCE
 * See if two sets are the same size
 ***********************************************/
template <typename T>
bool operator == (const set <T> & lhs, const set <T> & rhs)
{
   return true;
}

template <typename T>
inline bool operator != (const set <T> & lhs, const set <T> & rhs)
{
   return true;
}

/***********************************************
 * SET : RELATIVE COMPARISON
 * See if one set is lexicographically before the second
 ***********************************************/
template <typename T>
bool operator < (const set <T> & lhs, const set <T> & rhs)
{
   return true;
}

template <typename T>
inline bool operator > (const set <T> & lhs, const set <T> & rhs)
{
   return true;
}

}; // namespace custom



