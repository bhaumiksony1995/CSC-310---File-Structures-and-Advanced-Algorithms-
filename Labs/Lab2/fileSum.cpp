#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main (int argc, char *argv[])
{
	ifstream myFile;
	myFile.open("textFile.txt");

	int current;
	int compare;
	int sum;

	while(!myFile.eof())
	{
    		myFile >> current;

		if(myFile.fail())
		{
			myFile.clear();
			myFile >> compare;

			if(compare != ',')
			{
				return -1;
			}
		}

		else
		{
			sum += current;
		}
	}

	cout << "The sum is " << sum << endl;

return 0;
}

