/* This node class is used to build linked lists for the
 * utah_set class.
 */
#ifndef NODE_H
#define NODE_H
#include<string>

namespace cs3505
{
  
  class node
  {
    friend class utah_set;  // This allows functions in utah_set to access
			    //   private data within this class.
    
  private:
    node(const std::string & element);  // Constructor
    ~node();                            // Destructor

    std::string element;  // Variable to hold the element
    node* next;           // Variable to point to the next node in the list
   
  public:
    static long long constructor_count ();  // A debugging function 
    static long long destructor_count ();   // A debugging function 

  private:
    static long long constructor_calls;  // A debugging variable 
    static long long destructor_calls;   // A debugging variable  
  };
}

#endif
