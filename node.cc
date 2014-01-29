/* This node class is used to build linked lists for the
 * utah_set class.
 */

#include <string>
#include "node.h"

namespace cs3505
{

  /** Constructor:  Creates a node containing
    *   an element.  It is initialized to
    *   not point to any other node.
    */
  node::node(const std::string & e)
    : element(e)  
  {
    node::constructor_calls++;

    this->next = NULL;  
  }

  
  /** Destructor:  release any memory allocated
    *   for this object.
    */
  node::~node()
  {
    node::destructor_calls++;
  }

  
 
   /*These are for debugging purposes only.*/ 
  long long node::constructor_calls = 0;
  long long node::destructor_calls = 0;


  /** Returns the number of times any node
    *   constructor has been called.
    */
  long long node::constructor_count ()
  {
    return node::constructor_calls;
  }

  
  /** Returns the number of times the node
    *   destructor has been called.
    */
  long long node::destructor_count ()
  {
    return node::destructor_calls;
  }
}
