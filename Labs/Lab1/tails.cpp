#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cstdlib>
using namespace std;

bool Number(string input)
{
	for (int i = 0; i < input.size(); i++) 
	{
        	if ((int)input.at(i) < 48 || (int)input.at(i) > 57 ) 
		{
            		return false;
        	}
    	}
    
	return true;
}

int main (int argc, char *argv[])
{
	int numOfLines;
	numOfLines = -(atoi(argv[1]));

    	vector<string> myVector; //Read in arguments to vector

	for (int i = 1; i < argc; i++) 
	{
		myVector.push_back((argv[i]));
	}
    
	vector<string> myFilePath;	
	myFilePath = myVector;
    
	for (int i = 0; i < myFilePath.size(); i++) 
	{
        	ifstream readFile(myFilePath.at(i).c_str());
        	vector<string> File;
        
        	if (readFile.is_open()) 
		{
            		string line;
              		
			while (getline(readFile,line)) //read in lines from file
			{
				File.push_back(line);
            		}
            
		int myNum = 0;
		vector<string> output;

		cout << "\n";
	
		while ( myNum < numOfLines && !File.empty())
		{
                	output.insert(output.begin(),File.back()); //print lines of code from file
                	File.pop_back();
                	myNum++;
            	}
            
            	while (!output.empty())
		{
                	cout << output.front() << endl;
                	output.erase(output.begin()+0);
            	}
            
		}
	}
	cout << "\n";
	return 0;
}

20 38 56 75 94 115 116 142 144 185 188 251 255 283 294 301 306 320 322 323 357 359 376 408 409 469 470 503 506 539 542 547 576 600 605 651 654 708 738 747 781 785 812 829 889 894 920 936 949 966 991 992 1008 1010 1057 1061 1153 1187 1213 1228 1241 1278 1282 1331 1380 1395 1408 1412 1415 1430 1441 1443 1444 1752
