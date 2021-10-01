#pragma once
#include<iostream>
#include<cstdlib>
#include<malloc.h>
#include<time.h>

#define True 1
#define Fales 0

typedef struct TreeNode {
	int numerator;
	int denominator;
	double value;
	char operater;
	TreeNode* lchild;
	TreeNode* rchild;
} EquationTreeNode;

void ExchangeChild(EquationTreeNode*& t);

void Free(EquationTreeNode* t);

EquationTreeNode* GenerateTree(int bound, EquationTreeNode*& NumArrayRoot);

bool Similarity(EquationTreeNode* tree, EquationTreeNode* tree1);

void TreeToEquation(EquationTreeNode* tree);

void IntToString(int num, char* str, int& index);
