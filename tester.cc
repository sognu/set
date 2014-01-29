//Written by Chad Miller January 2013.
//Manual test cases on utah_set.cc.  Each test case presents a problem to utah_set.cc and tests its response.
#include <iostream>
#include <fstream>
#include <set>
#include <iterator>
#include "utah_set.h"
#include "node.h"
#include <string>
using namespace std;

int main ()
{
  
  {
    
    set<string>      stlset;  // The built-in set class - no constructor parameters.
    cs3505::utah_set ourset1(1000);  // Our set class, with a hashtable of 1000 slots.
    cs3505::utah_set ourset2(1);     // with one slot.
	cs3505::utah_set ourset3;        // an empty set.
	cs3505::utah_set ourset4;        // an empty set.
	ifstream in("YankeeCut.txt");  //Smaller text file. Few collisions.
	bool testPassed = true;
    while (true)
    {      
      string word;
      in >> word;
    
      if (in.fail())
	break;

      // Word successfully read.  Add it to both sets.    
      stlset.insert(word);
      ourset1.add(word);
    }

    // Close the file.
    in.close();

	//Test 1 
       ourset2 = ourset1;
       if(ourset2.size() != ourset1.size()){
	 cout << "test 1 failed =" << endl;
	 testPassed = false;
       }
	//Test 2
	string *e = new string[10];
        ourset2.get_elements(e, 10);
	if(!ourset2.contains(e[0])){ 
	  cout << "test 2 failed get_elements" << endl;
	  testPassed = false;
	}
	
	//Test 3
	ourset2.remove(e[3]);
	if(ourset2.contains(e[3])){
	  cout << "test 3 failed remove";
	  testPassed = false;
	}
	
	//Test 4
	if(ourset1.size() == ourset2.size()){
	  cout << "test 4 failed remove" << endl;
	  testPassed = false;
	}

	//Test 5
	ourset2 = ourset1;
	ourset2.remove("asdfsdfsdfdsf");   //remove an element not in set.
	if(ourset2.size() != ourset1.size()){
	  cout << "test 5 failed remove" << endl;
	  testPassed = false;
	}
	
	//Test 6
	ourset2 = ourset1;
	if(ourset2.size() != ourset1.size()){
	  cout << "test 6 failed =" << endl;
	  testPassed = false;
	}
	
	//Test 7
	string *f = new string[10];
        ourset1.get_elements(f, 10);
	ourset1.remove(f[0]);
	int j = 10 < ourset1.size() ? 10 : ourset1.size();
	bool contains = false;
	for(int i = 0; i < j; i++)
	  if(f[i] == f[0]) contains = true;
	if(!contains) {
	  cout << "test 7 failed get_elements" << endl;
	  testPassed = false;
	}

	//Test 8
	j = 10 < ourset1.size() ? 10 : ourset1.size();
	for(int i = 0; i < j; i++)
	  f[i] = "";
	if(ourset2.contains(f[0])){
	  cout << "test 8 failed get_elements" << endl;
	  testPassed = false;
	}
	
	//Test 9
	string a = f[2];
	ourset2.add(a);
	ourset2.remove(a);
	if(ourset2.size() == ourset1.size()){
	  cout << "test 9 failed remove" << endl;
	  testPassed = false;
	}
	
	//Test 10
	cs3505::utah_set ourset5;
	ourset5.remove("");
	if(ourset5.size() != 0){
	  cout << "test 10 failed remove" << endl;
	  testPassed = false;
	}

	//Test 11
	ourset5.add("a");
	if(!ourset5.contains("a")){
	  cout<< "test 11 failed add" << endl;
	  testPassed = false;
	}

	//Test 12
	if(ourset5.contains("b")){
	  cout << "test 12 failed contains" << endl;
	  testPassed = false;
	}

	//Test 13
	ourset5.remove("c");
	if(ourset5.size() != 1){
	  cout << "test 13 failed remove" << endl;
	  testPassed = false;
	}

	//Test 14
	ourset4 = ourset1;
	string *g = new string[10];
        ourset4.get_elements(g, 10);
	int k = 10 < ourset4.size() ? 10 : ourset4.size();
	bool passed = true;
	for(int i = 0; i < k; i++){
	  if(!ourset1.contains(g[i])){
	  passed = false;
	   }
	}
	if(!passed){
	  cout << "test 14 failed =" << endl;
	  testPassed = false;
	}

	//Test 15
	string *h = new string[15];
        ourset1.get_elements(h, 15);
	bool p = true;
	int l = 15 < ourset1.size() ? 15 : ourset1.size();
	for(int i = 0; i < l; i++){
	  if(!ourset4.contains(h[i])){
	  p = false;
	   }
	}

	if(!p){
	  cout << "test 15 failed ="<< endl;
	  testPassed = false;
	}

	if(testPassed) cout << "Tests passed" << endl;
	else cout << "Tests failed" << endl;

  }

  return 0;
}
