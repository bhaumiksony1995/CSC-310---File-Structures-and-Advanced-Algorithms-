#include <fstream>
#include <iostream>
#include <sys/stat.h>
#include <sys/types.h>
#include <utime.h>
#include <stdlib.h>

using namespace std;

int main(int argc, char *argv[])
{
	string option;
	string file;
	string dir;
	string tarfile;
	
	if (argc == 2)
	{
		option = argv[1];

		if (option == "--help")
		{
			cout << "NAME"  << endl;
                        cout << "\tjtar - Linux system utility tar\n" << endl;
                        cout << "Description" << endl;
                        cout << "\tThe jtar lets the user create a tar file, unpack a tar file, and list the files packed into a tar file\n" << endl;
                        cout << "\tOptions are: \n" << endl;
                        cout << "\t-cf [tarfile name] [file1] [dir1]\tMake a tar file based on the files and directories following the name of the tar file." << endl;
                        cout << "\t-tf [tarfile name]\t\t\tList the names of all files that are packed into a tar file." << endl;
                        cout << "\t-xf [tarfile name]\t\t\tRead a tar file, recreate all the files saved in the specified tar file" << endl;
		}
	}

	else if (argc == 3)
	{
		option = argv[1];
		tarfile = argv[2];
		
		if (option == "-tf")
		{
			//list names of all files that have packed into a tar file
			cout << "tf" << endl;
		}

		else if (option == "-xf")
		{
			//read a tar file, recreate all the files saved in that tarfile
			cout << "xf" << endl;
		}
	}		

	else if (argc == 5)
	{
		option = argv[1];
		tarfile = argv[2];
		file = argv[3];
		dir = argv[4];
		cout << option << tarfile << file << dir << endl;
	}

return 0;		
}
