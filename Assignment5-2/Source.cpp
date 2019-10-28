#include <iostream>

using namespace std;

struct Binary_Tree
{
	int value;
	struct Binary_Tree *left;
	struct Binary_Tree *right;
};

int SearchTree(struct Binary_Tree* node)
{
	if (node == NULL)
	{
		return true;
	}

	if (node->left != NULL && maxValue(node->left) > node->value)
	{
		return false;
	}

	if (node->right != NULL && minValue(node->right) < node->value)
	{
		return false;
	}

	if (!SearchTree(node->left) || !SearchTree(node->right))
	{
		return false;
	}

	return true;
}

int main()
{
	return 0;
}

int minValue(struct Binary_Tree* node)
{

	if (node->value < node->left->value)
	{
		node->value = node->left->value;
	}
	if (node->value < node->right->value)
	{
		node->value = node->right->value;
	}
	else
	{
		minValue(node->left);
		minValue(node->right);
	}
	return node->value;

}

int maxValue(struct Binary_Tree* node)
{

	if (node->value > node->left->value)
	{
		node->value = node->left ->value;
	}
	if (node->value > node->right->value)
	{
		node->value = node->right->value;
	}
	else
	{
		maxValue(node->left);
		maxValue(node->right);
	}
	return node->value;

}