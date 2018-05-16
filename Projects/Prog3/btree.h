
#include <vector>
#include <set>
#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>
#include "album.h"
using namespace std;

#ifndef BTREE_H
#define BTREE_H

struct myAlbum
{
	string UPC;
	string Artist;
	string Title;
}

const int ORDER = 5;
typedef Album keyType;
typedef int IndexArray[ORDER];
typedef keyType ValueArray[ORDER-1];

struct BTNode
{
        int currSize;
        //ValueArray contents;
        IndexArray child;
	int *data;
	BTNode **child;
	bool isLeaf;
}; 

struct Pair
{
        Album element;
        int loffset;
        int roffset;
        friend bool operator < (const Pair& p1, const Pair& p2)
           { return (p1.element < p2.element);  }
};

class BTree
{
 public:
	BTree();
	void writeHeader (char * fileName);
	void insert (keyType key);
	void reset (char * filename);
	void close ();
	void printTree();
	void inorder();
	void reverse();
	void insert(Album, string key);
	int getHeight();
	bool search (string key);
	BTNode *root;
	BTNode *temp;
	BTNode *nPtr;
	BTNode *x;
	keyType retrieve (string key);
	void totalio() const;
	int countLeaves();
	// bool search (keyType key);
	// void print (ostream &);
	// void print (ostream &, int nodeAddr, int level);

	// int open (char * name);
	// int create (char * name);
        void traverse(BTNode *node)
        {
		if (root != NULL) 
		{
			root->traverse();
		}		
        }
	BTree()
	{
		root = NULL;
		nPtr = NULL;
		x = NULL;
	}
 private:
	//BTNode root;
        int rootAddr;
	char treeFileName[80];
	fstream treeFile;
	int height;
	void printTree (int rootAddr);
	void inorder (int rootAddr);
	void reverse (int rootAddr);
	int read;
	int write;

	int findAddr (keyType key, BTNode t, int tAddr);
	int findpAddr(keyType key, BTNode t, int tAddr);
	void insert (keyType key, int recAddr, int oneAddr, int twoAddr);
        BTNode getNode (int recAddr);
	void printNode(int recAddr);
        void placeNode (keyType k,int recAddr,int oneAddr,int twoAddr);
	bool isLeaf (int recAddr);
	bool isLeaf(BTNode t);
	int countLeaves(int recAddr);
        void adjRoot (keyType rootElem, int oneAddr, int twoAddr);
        void splitNode (keyType& key,int recAddr,int& oneAddr,int& twoAddr);
	bool search (string key, BTNode t, int tAddr);
	
	// int search (keyType key, int recAddr = -1);

	// BTNode * FindLeaf (keyType key);
	// load a branch into memory down to the leaf with key
	// int Height 
};

class myBTNode
{
        int currSize; //current number of keys
        Album keys[4]; //array of keys
        BTNode **child; //array of child points
        bool isItALeaf;
public:
        BTNode(bool isLeaf);
        void insert(Album key);
        void doSplit(int i, BTNode *node, Album key);
        void walkThruTree();
        friend class Btree;
	void traverse(BTNode *node)
        {
                if (root != NULL)
                {
                        root->traverse();
                }
        }
};

#endif
