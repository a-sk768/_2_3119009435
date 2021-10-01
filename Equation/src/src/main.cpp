/*
   三个最基础的功能：
	  1.生成二叉树，并计算结果
	  2.对生成的二叉树查相似
	  3.输出
*/
#include"head.h"

void IntToString(int num, char* str, int& index) {
	
	int i = 0;
	int num1 = num;
	while (num > 0) {
		num /= 10;
		i++;
	}
	index += i;
	i--;
	for (; i>=0;i--) {
		*(str + i) = num1 % 10 + 48;
		num1 /= 10;
	}

	return;
}


void TreeToEquation(EquationTreeNode* tree) {
	

	if (tree == NULL) return;
	
	if (tree->operater == '\0') 
	{
		if(tree->denominator==1){
			printf_s("%d", tree->numerator);
		}
		else{
			printf_s(" ");
			printf_s("%d", tree->numerator);
			printf_s("\\");
			printf_s("%d", tree->denominator);
			printf_s(" ");
		}
		return;
	}
	else 
	{
		if ((tree->operater == '*' || tree->operater == '/' || tree->operater == '-')
			&& (tree->lchild->operater == '+' || tree->lchild->operater == '-')) {
			printf_s("(");
			TreeToEquation(tree->lchild);
			printf_s(")");
		}
		else {
			TreeToEquation(tree->lchild);
		}


		printf_s("%c", tree->operater);

		if ((tree->operater == '*' || tree->operater == '/' || tree->operater == '-')
			&& (tree->rchild->operater == '+' || tree->rchild->operater == '-')) {
			printf_s("(");
			TreeToEquation(tree->rchild);
			printf_s(")");
		
		}
		else {
	
			TreeToEquation(tree->rchild);

		}

		return;
	}
	return;
}


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
	   // srand(time(0));
		int mount = 10000, bound = 5;
		int length = 0;
		int i = 0;
		int index = 0;
		char* str = (char*)malloc(100 * sizeof(char));
	
		EquationTreeNode* p = NULL;
		EquationTreeNode* NumArrayRoot = NULL;
		EquationTreeNode** TreeArray = (EquationTreeNode * *)malloc(mount * sizeof(EquationTreeNode));

		while (length < mount) {
			p = GenerateTree(bound, NumArrayRoot);

			for (int i = 0; i < length; i++) {
				if (Similarity(p, TreeArray[i])) {
					Free(p);
					p = NULL;
					free(NumArrayRoot);
					break;
				}
			}

			if (p != NULL) {
				TreeArray[length] = p;
				length++;
			}
		}
		for (int i = 0; i < mount; i++) {
			TreeToEquation(TreeArray[i]);
			printf_s("\n");
		}
	return 0;
}

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

*/
/*

if (tree == NULL) return;

	if (tree->operater == '\0')
	{
		if(tree->denominator==1){
			IntToString(tree->numerator,str,index);
		}
		else{
			IntToString(tree->numerator, str, index);
			*(str + index) = '\\';
			index += 1;
			IntToString(tree->denominator, str+index, index);
		}
		return;
	}
	else
	{
		if ((tree->operater == '*' || tree->operater == '/' || tree->operater == '-')
			&& (tree->lchild->operater == '+' || tree->lchild->operater == '-')) {
			*(str + index) = '(';
			index += 1;
			TreeToEquation(tree->lchild, str , index);
			*(str + index) = ')';
			index += 1;
		}
		else {
			TreeToEquation(tree->lchild, str , index);
		}


		*(str + index) = tree->operater;
		index +=1;

		if ((tree->operater == '*' || tree->operater == '/' || tree->operater == '-')
			&& (tree->rchild->operater == '+' || tree->rchild->operater == '-')) {
			*(str + index) = '(';
			index += 1;
			TreeToEquation(tree->rchild, str , index);
			*(str + index) = ')';
			index += 1;
		}
		else {

			TreeToEquation(tree->rchild, str+index , index);

		}

		return;
	}
	return;
*/
/*
int main() {
	nt mount = 0, bound = 0;
	int length = 0;

	EquationTreeNode* p = NULL;
	EquationTreeNode* NumArrayRoot = NULL;
	EquationTreeNode** TreeArray = (EquationTreeNode * *)malloc(mount * sizeof(EquationTreeNode));

	while (length < mount) {
			p = GenerateTree(bound, NumArrayRoot);

			for (int i = 0; i < length; i++) {
				if (Similarity(p, TreeArray[i])) {
					Free(p);
					p = NULL;
					free(NumArrayRoot);
					break;
				}
			}

			if (p != NULL) {
				TreeArray[length] = p;
				length++;
			}
		}
		for (int i = 0; i < mount; i++) {
			TreeToEquation(TreeArray[i],str,index);
			str[index] = '\0';
			printf_s("%s",str);
			printf_s("\n");
		}
}
*/
/*

	while (length < mount) {
			p = GenerateTree(bound, NumArrayRoot);

			for (int i = 0; i < length; i++) {
				if (Similarity(p, TreeArray[i])) {
					Free(p);
					p = NULL;
					free(NumArrayRoot);
					break;
				}
			}

			if (p != NULL) {
				TreeArray[length] = p;
				length++;
			}
		}
		for (int i = 0; i < mount; i++) {
			TreeToEquation(TreeArray[i], str, index);
			str[index] = '\0';
			printf_s("%s", str);
			printf_s("\n");
		}

*/