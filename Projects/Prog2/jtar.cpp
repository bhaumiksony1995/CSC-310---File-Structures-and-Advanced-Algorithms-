#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <utime.h>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <vector>
#include <cstring>
#include "file.h"
#include <algorithm>

using namespace std;

void listAll(char* s);					// Function to list contents of a directory
bool fileORdir(const char * path,struct stat buf);	// Function to check if command line argument is file or directory
const char *getPermissions(struct stat buf);		// Fucntion to get permissions of a file
const char *getSize(struct stat buf);			// Fucntion to get size of a file
const char *getTimestamp(struct stat buf);		// Fucntion to get time stamp of a file
File getFile(const char *name, struct stat buf);	// Function to create a File

vector<File> myFiles;
vector<string> list;

int main(int argc, char *argv[])
{
	string option;
	int length;
	int filesize;
        char ch;
        filesize = myFiles.size();
        string line;
	string tempDir;
	string permission;
	string time;
	File holdingFile;
	File File1;
	File File2;
	int count;
	int SIZE;
	const char* temp;
	struct stat buf;
	struct stat tempBuf;
	char timeStamp[16];

	option = argv[1];
	
	if (option == "-cf" && argc < 4) // Check for right number of arguments for -cf option 
	{
		cout << "jtar: Invalid format \nTry 'jtar --help' for more information." << endl;
		exit(0);
	}

	if (option == "-tf" && argc < 3) // Check for right number of arguments for -tf option
	{
		cout << "jtar: Invalid format \nTry 'jtar --help' for more information." << endl;
		exit(0);
	}

	if (option == "-xf" && argc < 3) // Check for right number of arguments for -xf option
        {
                cout << "jtar: Invalid format \nTry 'jtar --help' for more information." << endl;
                exit(0);
        }

	if (argc == 2) //if argc == 2, option is --help
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

	if (option == "-cf")
	{
		File File1CF;
		File File2CF;
		cout << "-cf" << endl;
		for(int i = 3; i < argc; i++)
		{
			lstat (argv[i], &buf);
			if (S_ISREG(buf.st_mode)) // If current file is a file, add it to the vector of files
			{
                        	myFiles.push_back(getFile(argv[i], buf));
			}

			else if(S_ISDIR(buf.st_mode)) // If current file is a directory, add its contents recursively
			{
				File2CF = getFile(argv[i], buf);
				File2CF.flagAsDir();
				myFiles.push_back(File2CF);
				listAll(argv[i]);

				for (std::vector<string>::const_iterator it = list.begin(); it != list.end(); it++)
				{
					string tempfile = *it;
					File1CF = getFile(tempfile.c_str(), tempBuf);
					lstat (tempfile.c_str(), &tempBuf);
					strftime(timeStamp, 16, "%Y%m%d%H%M.%S", localtime(&tempBuf.st_ctime));	

					/*ostringstream tempTimeStamp;

					for(int j = 0 ; j < sizeof(timeStamp) ; j++)
					{
						tempTimeStamp << timeStamp[j];
					}
 
					string actualTimeStamp = tempTimeStamp.str();
					
					tempTimeStamp.clear();
					*/

					struct utimbuf timeBuf;

					utime(timeStamp, &timeBuf);


					//File1.setStamp(timeBuf);
					cout << File1.getSize() << endl;

					if (S_ISREG(tempBuf.st_mode))
					{
						ostringstream tempsize;
						tempsize << tempBuf.st_size;
						File1CF.setSize(tempsize.str());
						cout << File1CF.getSize() << endl;
						myFiles.push_back(File1CF);
						cout << File1CF.getName() <<  endl;
					}
                                
					else if (S_ISDIR(tempBuf.st_mode))
					{
						File1CF.flagAsDir();
						ostringstream tempsize;
						tempsize << tempBuf.st_size;
						File1CF.setSize(tempsize.str());
						cout << File1.getSize() << endl;
						myFiles.push_back(File1CF);
						cout << File1CF.getName() <<  endl;
					} 
				}
				list.clear();
			}
		}
           
		cout << myFiles.size() << endl;
		filesize = myFiles.size();
		count = filesize;
		ofstream outfile(argv[2], ios :: out | ios :: binary | ios :: app);
		outfile.write((char*) &filesize, sizeof(filesize));

/*		for(int i=0; i< myFiles.size() ; i++)
		{
			outfile.write((char*) &myFiles[i], sizeof(myFiles[i]));

			if(!myFiles[i].isADir())
			{
				fstream infile(myFiles[i].getName().c_str(),ios::in);
				infile.seekg(0,infile.end);
				length = infile.tellg();
				infile.seekg(0,infile.beg);

				while(infile.get(ch))
				{
					outfile.write((char*) &ch , sizeof(ch));      
				}
    			}
  		}*/
	}

	if (option == "-tf")
       	{
		File buffer;
               	cout << "-tf" << endl;
              	fstream tarfile(argv[2], ios::in | ios ::binary);
                tarfile.read((char*)&count, sizeof(count));
                
                for(int i = 0 ; i < count ; i++)
         	{       
                       	tarfile.read((char*)&buffer, sizeof(buffer));
	                //cout << buffer.getName() << endl;
               
	                if(buffer.isADir())
                        {       
               	                cout << buffer.getName() << endl;
             		}
                        
	                else if(!buffer.isADir())
                        {       
				cout << buffer.getName() << endl;
              	                int tfSIZE = atoi(buffer.getSize().c_str());
//                       	        tarfile.seekg(atoi(buffer.getSize().c_str()),std :: ios ::cur);
	                }

                }
	}


        if (option == "-xf")
        {
                cout << "-xf" << endl;
                fstream tarfile(argv[2], ios::in | ios ::binary);
                tarfile.read((char*)&count, sizeof(count));

                int x = 0;
                count = 0;
                tarfile.read((char*)&count, sizeof(count));

                for (int i = 0 ; i < count ; i++)
                {
                        tarfile.read((char*)&holdingFile, sizeof(holdingFile));
                        cout << holdingFile.getName() << endl;

                        if(!holdingFile.isADir())
                        {
                                SIZE = atoi(holdingFile.getSize().c_str());
                                fstream outfile (holdingFile.getName().c_str(),ios :: out | ios::app);
                                x = 0;

                                while( x != SIZE)
                                {
                                        tarfile.read((char *) &ch , sizeof(ch));
                                        outfile << ch;
                                        x++;
                                }

                                permission = "chmod " + holdingFile.getPmode()+ " " + holdingFile.getName() ;
                                cout << permission << endl;
                                system(permission.c_str());
                                time = "touch -t " + holdingFile.getStamp() + " " + holdingFile.getName();
                                cout << time << endl;
                                system(time.c_str());
			}

                        else
                        {
                                fstream directory(holdingFile.getName().c_str(), ios :: in);

                                if(!directory)
                                {
                                        string command = "mkdir " + holdingFile.getName();
                                        system(command.c_str());
                                }
                        }

                }
        }

		

	for (int i = 3 ; i < argc ; i++) // Check to see if the file given exists
	{
		fstream file (argv[i], ios::in);
		if (file);

		else
		{
			cout << "The file : " << argv[i] << " does not exist" << endl;
			return 0;
		}
	}
	return 0;
}     

void listAll(char* s) //Function to list contents of a directory
{
	DIR *dir;
	int x = 0;
 	struct dirent *entry;
 	struct stat info;
	dir = opendir(s);

	if(!dir)
  	{
    		cout << "Directory not Found" <<endl;
  	}

	else 
	{
		while ((entry = readdir(dir)) != NULL)
		{
			if (entry -> d_name[0] != '.')
			{
				string path = string(s)+ "/" + string(entry->d_name);            
        			File f2;
				f2 = getFile(path.c_str(),info);
				myFiles.push_back(f2);
				lstat(path.c_str(),&info);
          
          			if(S_ISDIR(info.st_mode))
			        {
					myFiles.pop_back();
					File f1;
					f1 = getFile(path.c_str(),info);
					f1.flagAsDir();
					myFiles.push_back(f1);
					cout << f1.getName() << endl;
					listAll((char*)path.c_str());              
          			}
          		}
      		}       
		closedir(dir);
	}
}

bool fileORdir(const char * path,struct stat buf) //Function to check whether to see if command line argument is a file or directory
{
	if (stat(path,&buf) == 0)
	{
		if (buf.st_mode & S_IFDIR)
		{
			return true;
		}

		else  
		{
        		return false;
		}   
	}
}

File getFile (const char *name, struct stat buf) // Function to create a file
{
	string perms = string(getPermissions(buf));
        string size = string(getSize(buf));
        string stamp = string(getTimestamp(buf));
        File retFile(name, perms.c_str(), size.c_str(), stamp.c_str());
        return retFile;
}

const char *getPermissions (struct stat buf) // Function to get permissions of a file
{
	ostringstream permissions;
        permissions << ((buf.st_mode & S_IRWXU) >> 6) << ((buf.st_mode & S_IRWXG) >> 3) << (buf.st_mode & S_IRWXO);
        return permissions.str().c_str();
}

const char *getSize (struct stat buf) // Funciton to get size of a file
{
	ostringstream size;
        size << buf.st_size;
        return size.str().c_str();
}

const char *getTimestamp (struct stat buf) // Fucntion to get timestamp of a file
{
	ostringstream retStamp;
        char stamp[16];
        strftime(stamp, 16, "%Y%m%d%H%M.%S", localtime(&buf.st_ctime));
        retStamp << stamp;
        return retStamp.str().c_str();
}
