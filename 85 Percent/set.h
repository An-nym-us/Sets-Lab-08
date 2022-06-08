/***********************************************************************
 * Header:
 *    Set
 * Summary:
 *        ____     _______        __
 *      .' __ '.  |  _____|   _  / /
 *      | (__) |  | |____    (_)/ /
 *      .`____'.  '_.____''.   / / _
 *     | (____) | | \____) |  / / (_)
 *     `.______.'  \______.' /_/
 *
 *    This will contain the class definition of:
 *        set                 : A class that represents a Set
 * Author
 *    <your names here>
 ************************************************************************/

#pragma once

#include <cassert>
#include <iostream>
#include "bst.h"
#include <memory>     // for std::allocator
#include <functional> // for std::less


namespace custom
{


/************************************************
 * SET
 * A class that represents a Set
 ***********************************************/
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
   }
   set(set && rhs) 
   { 
   }
   set(const std::initializer_list <int> & il)
   {
   }
   template <class Iterator>
   set(Iterator first, Iterator last)
   {
   }
   ~set() 
   { 
   }

   //
   // Assign
   //
   set & operator = (const set & rhs)
   {
      return *this;
   }
   set & operator = (set && rhs)
   {
      return *this;
   }
   set & operator = (const std::initializer_list <int> & il)
   {
      return *this;
   }
   void swap(set& rhs) noexcept
   {
   }
   

   //
   // Access
   //

   bool find(const int& t);

   //
   // Insert
   //
   bool insert(const int& t);
   bool insert(int&& t);
   void insert(const std::initializer_list <int>& il)
   {
   }
   template <class Iterator>
   void insert(Iterator first, Iterator last)
   {
   }

   //
   // Remove
   //
   void   clear()  noexcept 
   { 
   }
   size_t erase(const int & t);
   
   //
   // Status
   //
   bool   empty() const noexcept 
   { 
      return true; 
   }
   size_t size()  const noexcept 
   { 
      return 99;
   }

   
private:
   
   custom::BST<int> bst;
};

/***********************************************
 * SET : FIND
 * Returns Iterator to searched for data.
 ***********************************************/
inline bool set::find(const int & t)
{
   return false;
}

inline size_t set::erase(const int & t)
{
   return 99;
}

/***********************************************
 * SET : INSERT
 * Inserts an element into the set.
 ***********************************************/
inline bool set::insert(const int & t)
{
   return false;
}

inline bool set::insert(int && t)
{
   return false;
}




}; // namespace custom



