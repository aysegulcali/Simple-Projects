#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Node identification
typedef struct node
{
    int number;
    struct node *left;
    struct node *right;
} node;

// Function prototypes
void free_tree(node *root);
void print_tree(node *root);
void print_tree_pretty(node *root, int level);
node* insert(node *root, int number);
node* create_node(int number);
bool search(node *root, int number);
int tree_depth(node *root);
node* find_min(node *root);
node* find_max(node *root);

int main(void)
{
    node *tree = NULL;
    int number;
    char buffer[100]; // Temporarily hold user input

    while (1)
    {
        printf("Enter the number to be added to the tree (enter 0 to end): ");
        if (fgets(buffer, sizeof(buffer), stdin) != NULL)
        {
            if (sscanf(buffer, "%d", &number) == 1)
            {
                if (number == 0)
                {
                    break;
                }
                tree = insert(tree, number);
            }
            else
            {
                printf("Invalid entry. Please enter a number.\n");
            }
        }
        else
        {
            fprintf(stderr, "Error: Input read failed.\n");
            return 1;
        }
    }

    printf("The numbers on the tree:\n");
    print_tree_pretty(tree, 0);

    printf("\nEnter the number to call: ");
    if (fgets(buffer, sizeof(buffer), stdin) != NULL)
    {
        if (sscanf(buffer, "%d", &number) == 1)
        {
            if (search(tree, number))
            {
                printf("%d in the tree.\n", number);
            }
            else
            {
                printf("%d not in the tree.\n", number);
            }
        }
        else
        {
            printf("Invalid entry. Please enter a number.\n");
        }
    }

    printf("Depth of the tree: %d\n", tree_depth(tree));

    node *min_node = find_min(tree);
    node *max_node = find_max(tree);
    if (min_node != NULL)
    {
        printf("The smallest number found at the root of the tree: %d\n", min_node->number);
    }
    if (max_node != NULL)
    {
        printf("The biggest number found at the root of the tree: %d\n", max_node->number);
    }

    free_tree(tree);
    return 0;
}

node* insert(node *root, int number)
{
    if (root == NULL)
    {
        return create_node(number);
    }
    if (number < root->number)
    {
        root->left = insert(root->left, number);
    }
    else if (number > root->number)
    {
        root->right = insert(root->right, number);
    }
    return root;
}

node* create_node(int number)
{
    node *n = malloc(sizeof(node));
    if (n == NULL)
    {
        fprintf(stderr, "Error: Memory allocation failed.\n");
        exit(1);
    }
    n->number = number;
    n->left = NULL;
    n->right = NULL;
    return n;
}

void free_tree(node *root)
{
    if (root == NULL)
    {
        return;
    }
    free_tree(root->left);
    free_tree(root->right);
    free(root);
}

void print_tree(node *root)
{
    if (root == NULL)
    {
        return;
    }
    print_tree(root->left);
    printf("%i\n", root->number);
    print_tree(root->right);
}

void print_tree_pretty(node *root, int level)
{
    if (root == NULL)
    {
        return;
    }
    print_tree_pretty(root->right, level + 1);
    for (int i = 0; i < level; i++)
    {
        printf("    ");
    }
    printf("%d\n", root->number);
    print_tree_pretty(root->left, level + 1);
}

bool search(node *root, int number)
{
    if (root == NULL)
    {
        return false;
    }
    if (root->number == number)
    {
        return true;
    }
    else if (number < root->number)
    {
        return search(root->left, number);
    }
    else
    {
        return search(root->right, number);
    }
}

int tree_depth(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int left_depth = tree_depth(root->left);
    int right_depth = tree_depth(root->right);
    return (left_depth > right_depth ? left_depth : right_depth) + 1;
}

node* find_min(node *root)
{
    while (root && root->left != NULL)
    {
        root = root->left;
    }
    return root;
}

node* find_max(node *root)
{
    while (root && root->right != NULL)
    {
        root = root->right;
    }
    return root;
}
