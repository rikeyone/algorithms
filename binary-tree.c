/*
 * 二叉树，每个根节点有1个左节点和1个右节点
 *
 * 遍历方式有3种：
 *
 * 前序遍历（先根遍历）
 *  a. 访问根节点
 *  b. 访问左子树
 *  c. 访问右子树
 *
 * 中序遍历（中根遍历）
 *  a. 访问左子树
 *  b. 访问根节点
 *  c. 访问右子树
 *
 * 后序遍历（后根遍历）
 *  a. 访问左子树
 *  b. 访问右子树
 *  c. 访问根节点
 *
 *
 *                 A
 *                /  \
 *               B    E
 *              / \  / \
 *             C  D  F  G
 *
 * 前序遍历（A、B、C、D、E、F、G）
 * 中序遍历（C、B、D、A、F、E、G）
 * 后序遍历（C、D、B、F、G、E、A）
 *
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct bnode {
	char *data;
	struct bnode *left, *right;
};

char *argv[] = {"a", "b", "c", ",", ",", "d", ",", ",", "e", "f", ",", ",", "g", ",", "," };

/*
 * 按照前序排序法创建tree
 *
 */
struct bnode *create_tree(void)
{
	static int i = 0;
	struct bnode *node = NULL;

	/* when match "," means end node of subtree */
	if (!strcmp(argv[i], ",")) {
		i++;
		return NULL;
	}

	node = (struct bnode *)malloc(sizeof(struct bnode));
	node->data = argv[i++];
	node->left = create_tree();
	node->right = create_tree();

	return node;
}

void print_node(struct bnode *node)
{
	printf("%s ", node->data);
}

/*
 * 前序遍历查找打印
 *
 */
void preorder_iter(struct bnode *node)
{
	if (node) {
		print_node(node);
		preorder_iter(node->left);
		preorder_iter(node->right);
	}
}

/*
 * 中序遍历查找打印
 *
 */
void inorder_iter(struct bnode *node)
{
	if (node) {
		inorder_iter(node->left);
		print_node(node);
		inorder_iter(node->right);
	}
}

/*
 * 后序遍历查找打印
 *
 */
void postorder_iter(struct bnode *node)
{
	if (node) {
		postorder_iter(node->left);
		postorder_iter(node->right);
		print_node(node);
	}
}


int main(int argc, char *argv[])
{
	struct bnode *tree;

	tree = create_tree();
	if (!tree) {
		printf("create tree failed!\n");
		return 1;
	}

	printf("pre-order:");
	preorder_iter(tree);
	printf("\n");
	printf("in-order:");
	inorder_iter(tree);
	printf("\n");
	printf("post-order:");
	postorder_iter(tree);
	printf("\n");

	/* TODO: free node*/

	return 0;
}
