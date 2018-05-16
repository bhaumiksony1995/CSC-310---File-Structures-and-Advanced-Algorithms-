#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main(int argc, char *argv[])
{
	int numLines = -(atoi(argv[1]));
	int count = 0;

	string filename = argv[2];
	ifstream in (filename.c_str(), ios::in);
	
	char ch;
	string output;

	// Set the pointer to the last character in the file.
	in.seekg(-2, ios::end);

	while(in.get(ch))
	{
		// If the character is a newline, increment the number of lines read.
		if(ch == '\n')
		{
			count++;
		}
		
		// If the target number of lines is not read, continue prepending to the output string.
		if(count < numLines)
		{
			output = ch + output;
			in.seekg( -2, ios::cur);
		}

		// Break out of the loop once the targeted number of lines are read.
		else
		{
			break;
		}
	}

	in.close();

	cout << output << endl;
	
	return 0;
}
