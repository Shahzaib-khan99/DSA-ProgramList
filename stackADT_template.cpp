#include<iostream>
#include"stackADT.h"
int main()
{
	stack <int> s;
	s.push(22);
	s.push(13);
	s.push(87);
	s.push(99);
	s.display();
   
	s.pop();
	s.pop();
	s.size()
		s.empty();
	s.top();
	s.display();
	return 0;
}
