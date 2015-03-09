1.������

typedef struct TreeNode *PtrToNode;
typedef struct PtrToNode Tree;

struct TreeNode
{
	ElementType Element;
	Tree Left;
	Tree Right;
};

2.���������
#ifndef 
struct TreeNode;
typedef struct TreeNode *Position;
typedef struct TreeNode *SearchTree;

SearchTree MakeEmpty(SearchTree T);
Position Find(ElementType X, SearchTree T);
Position FindMin(SearchTree T);
Position FindMax(SearchTree T);
SearchTree Insert(ElementType X, SearchTree T);
SearchTree Delete(ElementType X, SearchTree T);
ElementType Retrieve(Position);
#endif

/* Place in the implementation file */
struct TreeNode
{
	ElementType Element;
	SearchTree Left;
	SearchTree Right;
};

//����һ�ÿ���
SearchTree MakeEmpty(SearchTree T)
{
	if (T != NULL)		
	{
		MakeEmpty(T->Left);
		MakeEmpty(T->Right);
		free(T);
	}
	return NULL;
}

Position Find(ElementType X, SearchTree T);
{
	if (T == NULL)
		return NULL;
	if (X < T->Element)
		return Find(X, T -> Left);
	else if (X > T->Element)
		return Find(X, T->Right);
	else
		return T;
}

Position FindMin(SearchTree T)
{
	if (T == NULL)
		return NULL;
	else if (T->Left == NULL)
	{
		return T;
	}
	else
		return FindMin(T->Left);
}

Position FindMax(SearchTree T)
{
	if (T == NULL)
		return NULL;
	else if (T->Right == NULL)
	{
		return T;
	}
	else
		return FindMax(T->Right);
}
//�ǵݹ��FindMax
Position FindMax(SearchTree T)
{
	if (T != NULL)
		while (T->Right != NULL)
			T = T->Right;
	return T;
}

SearchTree Insert()