#include <iostream>
#include <fstream>
#include <map>
#include <iomanip>
using namespace std;

typedef char String[25];
struct BookRec
{       
        unsigned int isbn;
        String name;
        String author;
        int onhand;
        float price;
        String type;
};

enum TransactionType {Add, Delete, ChangeOnhand, ChangePrice};

struct TransactionRec 
{
	TransactionType ToDo;
	BookRec B; 
};


int main(int argc, char *argv[])
{
	string fileName;
        if(argc == 2)
        {       
                fileName = argv[1];
        }
        else
        {       
                fileName = "";
        }

        ifstream file (fileName.c_str(), ios::in);
        ofstream output ("master", ios::out | ios::binary);

	map<unsigned int, int> books;
	int count = 0;
	
	while(master.read((char *) &buffer, sizeof(buffer)))
	{
		books[buffer.isbn] = count++ * sizeof(buffer);
	}

	while(transaction.read((char *) &trans, sizeof(trans)))
        	{
                	switch(trans.ToDo)
                	{
                        	case Add:
                                	if(books.find(trans.B.isbn) != books.end())
                                	{

					}

				case Delete:
					if(book.find(trans.B.isbn) != books.end())
					{

					}

				case ChangeOnHand:
					if(book.find(trans.B.isbn) != books.end())
					{

					}

				case ChangePrice:
					if(book.find(trans.B.isbn) != books.end())
					{

					}
			}
		}

	 map<unsigned int, int>::iterator j;

	for(j = books.begin(); j != books.end(); ++j)
	{
		master.clear();
		master.seekg(j->second);
		master.read((char *) &buffer, sizeof(buffer));
 		newMaster.write((char *) &buffer, sizeof(buffer));
	}
	newMaster.close();
	master.close();
	system("rm temp.out");
	fstream newMasterIn (newMasterName.c_str(), ios::in | ios::binary);
        
	while(newMasterIn.read((char *) &buffer, sizeof(buffer)))
	{
		printf("%010u%25s%25s%3d%7.2f%10s\n", buffer.isbn, buffer.name, buffer.author, buffer.onhand, buffer.price, buffer.type);
	}

				
}
