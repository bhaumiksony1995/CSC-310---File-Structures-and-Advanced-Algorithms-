#include <fstream>      // std::ofstream

int main () {

  std::ofstream outfile;
  outfile.open ("test.txt");

  outfile.write ("This is an apple",16);
  long pos = outfile.tellp();
  outfile.seekp (pos-7);
  outfile.write (" sam",4);

  outfile.close();

  return 0;
}

// read a file into memory
#include <iostream>     // std::cout
#include <fstream>      // std::ifstream

int main () {
	std::ifstream is ("test.txt", std::ifstream::binary);
	if (is) {
	// get length of file:
	is.seekg (0, is.end);
	int length = is.tellg();
	is.seekg (0, is.beg);

	// allocate memory:
	char * buffer = new char [length];

	// read data as a block:
	is.read (buffer,length);

	is.close();

	// print content:
	std::cout.write (buffer,length);

	delete[] buffer;
}
return 0
}
