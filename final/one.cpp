#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char* argv[])
{
	fstream file ("file.dat", ios::in | ios::out);
	
	char ch1;
	char ch2;
	
	file.seekg(10);	
	file >> ch1;
	file.seekg(3);
	file >> ch2;
cout << ch1 << " " << ch2 << endl;
	file.seekg(0,ios::beg);
	if (ch1 < ch2)
	{
		file.seekg(11);
		file << ch1;
		file.seekg(1);
		file << ch2;
	}
	else
	{
		file.seekg(11);
		file << ch2;
		file.seekg(1);
		file << ch1;
	}
}
