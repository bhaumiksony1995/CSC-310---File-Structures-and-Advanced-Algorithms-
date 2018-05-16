#include <algorithm>
#include <iostream>
#include <string>
#include <fstream>
bool validname (string name);

int main (int argc, char* argv[])
{
	std::string name;
	name = argv[1];
	validname(name);
}

bool validname(std::string name)
{
  fstream file(name.c_str(),ios::in);
  if (!file.is_open())
      return false;
    
  return true;  
}

