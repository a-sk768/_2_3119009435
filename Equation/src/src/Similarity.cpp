#include"head.h"


bool Similarity(EquationTreeNode* tree, EquationTreeNode* tree1) {

	bool isSimilar;

	if (tree == NULL && tree1 == NULL) {
		return True;
	}

	if (tree->value != tree1->value || tree->operater != tree1->operater) {
		 return Fales;
	}


	if (tree->operater == '\0' && tree1->operater == '\0') {
		if (tree->value == tree1->value) {
			return True;
		}
		return Fales;
	}

	 if((tree->operater == '+' && tree1->operater == '+' || tree->operater == '*' && tree1->operater == '*'))
	{
		
		if ((tree->lchild->operater == tree1->lchild->operater && tree->rchild->operater == tree1->rchild->operater) 
			&& (tree->lchild->value == tree1->lchild->value && tree->rchild->value == tree1->rchild->value)) 
		{
		
			isSimilar = True;
			isSimilar = Similarity(tree->lchild, tree1->lchild);
			isSimilar = Similarity(tree->rchild, tree1->rchild);
			
			return isSimilar;

		}
		if ((tree->lchild->operater == tree1->rchild->operater && tree->rchild->operater == tree1->lchild->operater)
			&& (tree->lchild->value == tree1->rchild->value && tree->rchild->value == tree1->lchild->value))
		{
			
			ExchangeChild(tree1);
			isSimilar = True;
			isSimilar = Similarity(tree->lchild, tree1->lchild);
			isSimilar = Similarity(tree->rchild, tree1->rchild);
			
			return isSimilar;
		}
		
		return Fales;
	}

	 if (tree->operater == '-' && tree1->operater == '-' || tree->operater == '/' && tree1->operater == '/') {
	
		 if ((tree->lchild->value != tree1->lchild->value || tree->rchild->value != tree1->rchild->value)
			 || (tree->lchild->operater != tree1->lchild->operater || tree->rchild->operater != tree1->rchild->operater))
		 {
	
			 return Fales;
		 }
		 else
		 {
	
			 isSimilar = True;
			 isSimilar = Similarity(tree->lchild, tree1->lchild);
			 isSimilar = Similarity(tree->rchild, tree1->rchild);
		
			 return isSimilar;
		 }

	 }

	 return Fales;

}

void Free(EquationTreeNode* t) {
	if (t == NULL) return;

	if (t->operater!='\0') {
		if (t->lchild->operater!='\0') {
			Free(t->lchild);
		}
		if (t->rchild->operater != '\0') {
			Free(t->rchild);
		}
		free(t);
		
	}
	return;
}


//²âÊÔ´úÂë
/*
	int main() {
	EquationTreeNode* a = GenerateTree(2);
	srand(time(0));
	EquationTreeNode* b = GenerateTree(2);
	PrintTree(a, 4);
	printf_s("\n");
	printf_s("---------------------------------------------------------------------------------------");
	printf_s("\n");
	PrintTree(b, 4);
	printf_s("\n");
	printf_s("---------------------------------------------------------------------------------------");
	printf_s("\n");
	printf_s("%d", Similarity(a, b));
	return 0;
}
*/
/*
	EquationTreeNode* a = (EquationTreeNode*)malloc(sizeof(EquationTreeNode));
	EquationTreeNode* b = (EquationTreeNode*)malloc(sizeof(EquationTreeNode));
	EquationTreeNode* c = (EquationTreeNode*)malloc(sizeof(EquationTreeNode));
	b->denominator = a->numerator = 0;
	b->lchild = NULL;
	b->rchild = NULL;
	b->operater = 'h';
	b->value = 0;
	c->denominator = a->numerator = 0;
	c->lchild = NULL;
	c->rchild = NULL;
	c->operater = 'h';
	c->value = 0;
	a->denominator = a->numerator = 0;
	a->lchild = b;
	a->rchild = c;
	a->operater = 'h';
	a->value = 0;

	ExchangeChild(a);
	ExchangeChild(a);
	free(a->lchild);
	-----------------------------------------------
	int main() {
	EquationTreeNode* a = GenerateTree(2);
	srand(time(0));
	//EquationTreeNode* b = GenerateTree(2);
	//PrintEquation(a);
	PrintTree(a,3);
	//PrintEquation(b);
	printf_s("\n");
	printf_s("---------------------------------------------------------------------------------------");
	printf_s("\n");
	//printf_s("%d", Similarity(a, b));
	//free(a->rchild);
	free(a->rchild);
	PrintTree(a, 2);
	free(a);

	return 0;
} 
------------------------------------------------------------------------------------------------------
void PrintTree(EquationTreeNode* t, int deep) {
	if (t == NULL) {  return; }

		PrintTree(t->rchild, ++deep);


	printf_s("\n");
	deep--;
	for (int i = 1; i <= deep; i++) {
		printf_s("        ");
	}

	printf_s("%c %f", t->operater, t->value);

	  PrintTree(t->lchild, ++deep);

}
*/