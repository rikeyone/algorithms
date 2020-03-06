#include <stdio.h>


struct node {
    struct node *left;
    struct node *right;
    char c;
};


static char buf[15] = { 'A', 'B', 'C', ':', ':', 'D', ':', ':', 'E', 'F', ':', ':', 'G', ':', ':'};

struct node *create_tree(void)
{
    int len;
    static int i = 0;
    struct node *node;

    len = sizeof(buf);
    if (i == len)
        return NULL;

    if (buf[i] == ':') {
        i++;
        return NULL;
    } else {
        node = (struct node *)malloc(sizeof(struct node));
        node->c = buf[i++];
        node->left = create_tree();
        node->right = create_tree();
    }
    return node;
}

int preorder_print_tree(struct node *root)
{
    if (root) {
    printf("%c\n", root->c);
    preorder_print_tree(root->left);
    preorder_print_tree(root->right);
    }
    return 0;
}

int inorder_print_tree(struct node *root)
{
    if (root) {
    inorder_print_tree(root->left);
    printf("%c\n", root->c);
    inorder_print_tree(root->right);
    }
    return 0;
}


int postorder_print_tree(struct node *root)
{
    if (root) {
    postorder_print_tree(root->left);
    postorder_print_tree(root->right);
    printf("%c\n", root->c);
    }
    return 0;
}

int maxdepth(struct node *root)
{
    int left, right;
    if (root == NULL) {
        return 0;
    } else {
        left = maxdepth(root->left) + 1;
        right = maxdepth(root->right) + 1;
    }

    return left > right ? left : right;
}


int mindepth(struct node *node)
{
	int left, right;
	if (node == NULL)
		return 0;
	if (node->left == NULL)
		return mindepth(node->right) + 1;
	if (node->right == NULL)
		return mindepth(node->left) + 1;

	left = mindepth(node->left) + 1;
	right = mindepth(node->right) + 1;
	return left < right ? left : right;
}

int main(void)
{
    struct node *root;

    root = create_tree();
    printf("preorder:\n");
    preorder_print_tree(root);
    printf("inorder:\n");
    inorder_print_tree(root);
    printf("postorder:\n");
    postorder_print_tree(root);
    printf("maxdepth:%d, mindepth:%d\n", maxdepth(root), mindepth(root));
    return 0;
}