#include "btree.h"

BTNode::* initialize()
{
    int i;
    np = new BTreeNode;
    np->data = new int[5]; //array of contents
    np->child = new BTreeNode *[5]; //order of 5
    np->isLeaf = true;
    np->n = 0;
    for (i = 0; i < 5; i++)
    {
        np->child_ptr[i] = NULL;
    }
    return np;
}

bool album_sort(Album const& left, Album const& right, int num) //Function to organize array based on UPC values
{
	int a = atoi(left.UPC.c_str()); //grab UPC codes
	int b = atoi(right.UPC.c_str()); //grab UPC codes
	int n = num;

	if (b < a)
	{
		return (b < a);
	}
}

int BTNode::doSplit(int i, BTNode *node, Album key) //BTNode function to split tree when it hits node capacity
{
	int j;
	int middle;

	BTNode *ptr1;
	BTNode *ptr2;
	BTNode *r;

	ptr2 = initialize();

	if(i == -1)
	{
		middle = x->data[2];
		x->data[2] = 0;
		x->currSize--;
		ptr1->isLeaf = false;
		x->isLeafe = true;

		for (j = 0; j < 4; j++)
		{
			ptr2->data[j-1] = x->data[j];
			ptr2->child[j-1] = x->child[1];
			ptr2->currSize++;
			x->data[j] = 0;
			x->currSize--;
		}

		for (j = 0; j < 5; j++)
		{
			x->child[j] = NULL;
		}

		ptr1->data[0] = middle;
		ptr1->child[ptr1->currSize] = x;
		ptr1->child[ptr1->currSize + 1] = ptr2;
		ptr1->currSize--;
		root = ptr1;
	}

	else
	{
		r = x->child[i];
		middle = r->data[2];
		r->data[2] = 0;
		r->currSize--;

		for (j = 0; j < 4; j++)
		{
			ptr3->data[j-1] = r->data[j];
			ptr3->currSize++;
			r->data[j] = 0;
			r->currSize--;
		}

		x->child[i + 1] = r;
		x->child[i + 1] = r;
	}
	return middle;
}	

void BTNode::insert(Album key) //BTNode function to insert nodes into tree
{
	int i;
	int temp;
	x = root;

	if (x == NULL) //If root is empty init it
	{
		root = initialize();
		x = root;
	}

	else
	{
		if (x->isLeaf == true && x->currSize == 5)
		{
			temp = doSplit(x, -1, key)
			x = root;

			for (i = 0; i < (x->currSize); i++)
			{
				if((key > x->data[i]) && (key < x->data[i + 1]))
				{
					i++;
					break;
				}

				else if (key < x->data[0])
				{
					break;
				}

				else
				{
					continue;
				}
			}

			x = x->child[i];
		}

		else
		{
			while (x->isLeaf == false)
			{
				for (i = 0; i < (x->currSize); i++)
				{
					if ((key > x->data[i]) && (key < x->data[i + 1]))
					{
						i++;
						break;
					}

					else if (key < x->data[0])
					{
						break;
					}

					else
					{
						continue;
					}
				}

				if ((x->child[i]->currSize == 5)
				{
					temp = doSplit(x, i, key);
					x->data[x->currSize] == temp;
					x->currSize++;
					continue;
				}

				else
				{
					x = x->child[i];
				}
			}
		}
	}

	x->data[x->currSize] = key;
	album_sort(x->data, x->currsize, i);
	x->currSize++;
}

void BTNode::traverse(BTNode *node)
{
	for (int i = 0; i < node->currSize; i++)
	{
		if (node-isLeaf == false)
		{
			traverse(node->child[i]);
		}
	}

	if (node->isLeaf == false)
	{
		traverse(node->child[i];
	}
}

