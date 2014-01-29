/* A 'utah set' is defined as a set of strings stored
 * in a hashtable that uses chaining to resolve collisions.
 */
#include <fstream>
#include <iostream>
#include <string>
#include "utah_set.h"
#include "node.h"

namespace cs3505
{
  
  /** Constructor:  The parameter indicates the
    *   size of the hashtable that should be used
    *   to keep this set.
    */
  utah_set::utah_set(int capacity)
  {
    utah_set::constructor_calls++;
    this->capacity = capacity;
    this->count = 0;
    this->table = new node*[capacity];  // Create table
    
    for (int i = 0; i < capacity; i++)
      table[i] = NULL;
  }

  
  /** Copy constructor:  Initialize this set
    *   to contain exactly the same elements as
    *   another set.
    */
  utah_set::utah_set(const utah_set & other)
  {

    utah_set::constructor_calls++;  
    this->capacity = 0;
    this->count = 0;
    this->table = NULL;
    *this = other;
  }

  
  /** Destructor:  release any memory allocated
    *   for this object.
    */
  utah_set::~utah_set()
  {
    utah_set::destructor_calls++;    
    clean();  
  }

  
  /** Adds the specified element to this set.  If the element
    *   is already in this set, no action is taken.
    */
  void utah_set::add (std::string element)
  {
    
    int index = hash(element);
    node *current = table[index], *last = NULL;
    
    while (current != NULL)
    {
      if (current->element == element)  
	return;  
      last = current;           
      current = current->next;  
    }
    
    current = new node(element);

    if (last == NULL)  
      table[index] = current;  
    else
      last->next = current;  

    count++;
  }

  
  /** Removes the specified element from this set.  If the
    *   element is not in the set, no action is taken.
    */
  void utah_set::remove (std::string element)
  {

   if(!contains(element)) return;
	int index = hash(element);
	node *current = table[index], *prev = NULL;
	while(current != NULL)
	{
		if(current->element == element){
			if(prev != NULL){
				prev->next = current->next;
			}else table[index] = NULL;

			delete current;
			count--;
			return;
		}
		prev = current;
		current = current->next;
	}
  }

  
  /** Returns true if the specified element in in this set,
    *   false otherwise.
    */
  bool utah_set::contains (std::string element) const
  {

    int index = hash(element);
    node *current = table[index];  
    while (current != NULL)
    {
      if (current->element == element) 
	return true;  
      
      current = current->next;  
    }
    
    return false;  
  }

  
  /** Returns a count of the number of elements
    *   in this set.
    */
  int utah_set::size () const
  {
    return count;
  }

  
  /** This function overloads the assignment operator.  It
    *   clears out this set, builds an empty table, and copies
    *   the entries from the right hand side (rhs) set into
    *   this set.
    */
  const utah_set & utah_set::operator= (const utah_set & rhs)
  {

    if (this == &rhs)  
      return *this;  

    clean();

	this->capacity = rhs.capacity;
	this->count = 0;
	this->table = new node*[rhs.capacity];  
	for (int i = 0; i < capacity; i++)
      table[i] = NULL;
	for (int i = 0; i < rhs.capacity; i++){		
		node *current = rhs.table[i];
		while(current != NULL){
			this->add(current->element);
		current = current->next;	
		}
	}
    return *this;
  }


  /** Computes a table index for a given string.
    *   If two strings have the same contents, their
    *   hash code (table index) will be identical.
    * The hash code is guaranteed to be in the
    *   range [0..capacity).
    */  
  int utah_set::hash (std::string s) const
  {
    
    long long hash = 0;
    for (int i = 0; i < s.length(); i++)
      hash = ((hash * 1117) + s[i]) % capacity;

    return static_cast<int>(hash);
  }


  /** Releases any memory that was allocated by
    *   this object.  This effectively destroys the
    *   set, so it should only be called if this object
    *   is destructing, or is being assigned.
    */
  void utah_set::clean ()
  {

    if (table == NULL)  
      return;

    for (int i = 0; i < capacity; i++)
    {
      node *current = table[i];
      while (current != NULL)
      {

	node *temp_next = current->next;
	delete current;
	current = temp_next;
	
      }      
    }

    delete [] table;  
    table = NULL;
  }


   /** This function populates an array of strings with elements from the set.
    * It is assumed that the array reference is valid and that n is non-negative.
    */
  void utah_set::get_elements(std::string *array, int n) const{
 
 	  int size = n < this->count ? n: this->count;
	  int j = 0;
	  for(int i = 0; j < size; i++)
	  {
		   node *current = table[i];		   
		   while(current != NULL && j < size){
			   array[j] = current->element;
			   current = current->next;
			   j++;
		   }
	  }
  }
  
  /*These are for debugging purposes only.   
   */
  long long utah_set::constructor_calls = 0;
  long long utah_set::destructor_calls = 0;


  /** Returns the number of times any utah_set
    *   constructor has been called.
    */
  long long utah_set::constructor_count ()
  {
    return utah_set::constructor_calls;
  }

  
  /** Returns the number of times the utah_set
    *   destructor has been called.
    */
  long long utah_set::destructor_count ()
  {
    return utah_set::destructor_calls;
  }

}
