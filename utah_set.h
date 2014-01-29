/* A 'utah set' is defined as a set of strings stored
 * in a hashtable that uses chaining to resolve collisions.
 */
#ifndef UTAH_SET_H
#define UTAH_SET_H

#include<string>

namespace cs3505
{
  class node;  
  
  class utah_set
  {
  public:
    utah_set(int capacity = 10);      
    utah_set(const utah_set & other); 
    ~utah_set();                      

    void add      (std::string element);  
    void remove   (std::string element);  
    bool contains (std::string element) const;  
    int  size     () const;               

    const utah_set & operator= (const utah_set & rhs);  

  void get_elements(std::string *array, int n) const;

     
  private:
    int hash (std::string s) const;  
    void clean ();                   
    
    int capacity;  
    int count;     
    node** table;  
                   
  public:
    static long long constructor_count ();  
    static long long destructor_count ();   

  private:
    static long long constructor_calls;  
    static long long destructor_calls;   
    
  };

 
}

#endif
