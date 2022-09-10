/* Write your test code for the ULListStr in this file */

#include <iostream>
#include "ulliststr.h"
using namespace std;


int main(int argc, char* argv[])
{
	ULListStr dat;
dat.pop_front(); //POPFRONT WHEN nothing
cout << dat.size() << endl;
dat.pop_back(); //POP Back when nothing
cout << dat.size() << endl;


//dat.push_back("2");
dat.push_front("2");
cout << dat.size() << endl;
dat.pop_back(); //tests pop back when removes only item and checks if it deletes
cout << dat.size() << endl;
//dat.get(0); //[nothing here]


cout << "popfront" << endl;
//dat.push_back("2");
dat.push_front("2");
cout << dat.size() << endl;
dat.pop_front(); //tests pop front when removes only item  and checks if it deletes
cout << dat.size() << endl;
//dat.get(0); //[nothing here]


//dat.push_front("1");
dat.push_front("7");  //push front when empty
dat.push_back("8"); //creates new item
dat.push_front("9");
// dat.push_back("7"); //[push back when empty]
// dat.push_front("8"); //creates new item
// dat.push_back("9");


cout << dat.front() <<endl;
cout << dat.back() << endl;
cout << dat.get(0) << " " << dat.get(1) << " " << dat.get(2) << endl;
// prints: 8 7 9


cout << dat.size() << endl;  // prints 3 since there are 3 strings stored
dat.pop_front(); //test pop front not edge case
cout << dat.size() << endl; 
dat.pop_back(); //test pop back not edge case
cout << dat.size() << endl; 
cout << dat.get(0) << endl;
cout << dat.front() << endl;
cout << dat.back() << endl;
// cout << dat.get(1) << endl;   [doesnt exist]
	
}
