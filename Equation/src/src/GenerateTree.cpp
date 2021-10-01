#include "head.h"


int Greatest_Common_Devisor(int var, int var1) {
	int devisor = 1;
	int bigger_Num = (var > var1 ? var : var1);
	int smaller_Num = var + var1 - bigger_Num;

	if (bigger_Num % smaller_Num == 0) {
		return  smaller_Num;
	}

	for (int i = 1; i <= smaller_Num / 2; i++) {
		if (smaller_Num % i == 0)
			if (bigger_Num % i == 0) {
				devisor = i;
			}
	}

	return devisor;
}

void Creat_Operator(EquationTreeNode*& t)
{
	int i = rand() % 4;
	switch (i)
	{
	case 0: t->operater = '+';
		break;
	case 1: t->operater = '-';
		break;
	case 2: t->operater = '*';
		break;
	case 3: t->operater = '/';
		break;
	default:
		break;
	}
}

void ExchangeChild(EquationTreeNode*& t) {
	
	EquationTreeNode* p = t->lchild;
	t->lchild = t->rchild;
	t->rchild = p;
}

EquationTreeNode* GenerateNumArray(int mount, int bound) {
	EquationTreeNode* NumArray = (EquationTreeNode*)malloc(mount * sizeof(EquationTreeNode));
	int s;
	int devisor;
	for (int i = 0; i < mount; i++) {
		s = rand() % 4;
		if (s == 0) {
			NumArray[i].lchild = NULL;
			NumArray[i].rchild = NULL;
			NumArray[i].operater = '\0';

			NumArray[i].numerator = rand() % 10 + 1;
			NumArray[i].denominator = rand() % 10 + NumArray[i].numerator / bound + 1;
			devisor = Greatest_Common_Devisor(NumArray[i].numerator, NumArray[i].denominator);
			NumArray[i].numerator /= devisor;
			NumArray[i].denominator /= devisor;

			NumArray[i].value = (double)NumArray[i].numerator / (double)NumArray[i].denominator;
		}
		else {
			NumArray[i].lchild = NULL;
			NumArray[i].rchild = NULL;
			NumArray[i].operater = '\0';

			NumArray[i].numerator = rand() % bound + 1;
			NumArray[i].denominator = 1;

			NumArray[i].value = (double)NumArray[i].numerator;
		}

	}

	return NumArray;
}

EquationTreeNode* GenerateTree(int bound, EquationTreeNode* &NumArrayRoot) {
	int mount = rand()%3+2; 
	int devisor;
	EquationTreeNode* NumArray = GenerateNumArray(mount, bound);
	NumArrayRoot = NumArray;

	EquationTreeNode* s = NumArray;
	EquationTreeNode* root = NULL;

	for (int i = 1; i < mount ; i++) {

	    root = (EquationTreeNode*)malloc(sizeof(EquationTreeNode));
		Creat_Operator(root);
		root->lchild = s;
		root->rchild = NumArray + i;
		 
		if ((root->lchild->value < root->rchild->value) && root->operater == '-') {
			ExchangeChild(root);
		}

		if ((root->lchild->value > root->rchild->value) && root->operater == '/') {
			ExchangeChild(root);
		}

		switch (root->operater)
		{
		case'+':root->value = root->lchild->value + root->rchild->value;

				root->numerator = root->lchild->numerator * root->rchild->denominator
								+ root->rchild->numerator * root->lchild->denominator;
				root->denominator = root->lchild->denominator * root->rchild->denominator;

				//约分
				if (root->numerator != 0)
				{
					devisor = Greatest_Common_Devisor(root->numerator, root->denominator);
					root->numerator /= devisor;
					root->denominator /= devisor;
				}

			break;
		case'-':root->value = root->lchild->value - root->rchild->value;
				
				root->numerator = root->lchild->numerator * root->rchild->denominator 
					              - root->rchild->numerator * root->lchild->denominator;
				root->denominator = root->lchild->denominator * root->rchild->denominator;

				//约分
				if (root->numerator!=0)
				{
					devisor = Greatest_Common_Devisor(root->numerator, root->denominator);
					root->numerator /= devisor;
					root->denominator /= devisor;
				}

			break;
		case'*':root->value = root->lchild->value * root->rchild->value;

			    root->numerator = root->lchild->numerator * root->rchild->numerator;
			    root->denominator = root->lchild->denominator * root->rchild->denominator;

				//约分
				if (root->numerator != 0)
				{
					devisor = Greatest_Common_Devisor(root->numerator, root->denominator);
					root->numerator /= devisor;
					root->denominator /= devisor;
				}

			break;
		case'/':
			  if ( root->rchild->value != 0) {
				   root->value = root->lchild->value / root->rchild->value;
			  }
			  else
			  {
				  Free(root);
				  free(NumArrayRoot);
				  return GenerateTree(bound,NumArrayRoot);
			  }
			    
			    root->numerator = root->lchild->numerator * root->rchild->denominator;
				root->denominator = root->lchild->denominator * root->rchild->numerator;

				//约分
				if (root->numerator != 0)
				{
					devisor = Greatest_Common_Devisor(root->numerator, root->denominator);
					root->numerator /= devisor;
					root->denominator /= devisor;
				}

			break;
		default:
			break;
		}

		s = root;
	}

	return root;
}
//测试代码
/*
void PrintTree(EquationTreeNode* t, int deep) {
	if (t == NULL) return;

	PrintTree(t->rchild, ++deep);
	printf_s("\n");
	deep--;
	for (int i = 1; i <= deep; i++) {
		printf_s("        ");
	}
	printf_s("%c %d,%d", t->operater, t->numerator, t->denominator);
	PrintTree(t->lchild, ++deep);
}

int main() {
	EquationTreeNode* s = GenerateTree(10);
	PrintTree(s, 4);
}
*/