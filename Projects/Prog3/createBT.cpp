#include <iostream>
#include <fstream>
#include "btree.h"
using namespace std;

int main(int argc, char *argv[])
{
	BTree tree;
	string input;
	string output;
	string temp;
	int numberofLines;
	input = argv[1];
	
	fstream inputFile (input.c_str(), ios::in);
	int numberOfRecord = numberOflines; //I should divide this by 3 since there are 3 lines per record
	
	while (getline(inputFile))
	{
		numberofLines++;
	}

	while (int i != numberOfRecord/3)
	{
		Album album;
		getline(inputFile, temp);
		album.UPC = temp;
		getline(inputFile, temp);
		album.artist = temp;
		getline(inputFile, tmep)
		album.Title = temp;
	
		tree.insert(album);
		i++;
	}

	tree.traverse(numberofRecords);
}
