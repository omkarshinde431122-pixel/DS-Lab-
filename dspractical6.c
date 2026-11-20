/*
Title:- Binary Search Tree Operations and Traversals
Roll No :- CO2080
*/
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int roll;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int roll)
{
    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    newNode->roll = roll;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node *insert(struct Node *root, int roll)
{
    if (root == NULL)
        return createNode(roll);

    if (roll < root->roll)
        root->left = insert(root->left, roll);
    else if (roll > root->roll)
        root->right = insert(root->right, roll);
    else
        printf("Duplicate roll number not allowed!\n");

    return root;
}

struct Node *search(struct Node *root, int roll)
{
    if (root == NULL || root->roll == roll)
        return root;

    if (roll < root->roll)
        return search(root->left, roll);

    return search(root->right, roll);
}

struct Node *findMin(struct Node *root)
{
    while (root != NULL && root->left != NULL)
        root = root->left;

    return root;
}

struct Node *deleteNode(struct Node *root, int roll)
{
    struct Node *temp;

    if (root == NULL)
    {
        printf("Roll number not found!\n");
        return NULL;
    }

    if (roll < root->roll)
        root->left = deleteNode(root->left, roll);
    else if (roll > root->roll)
        root->right = deleteNode(root->right, roll);
    else
    {
        if (root->left == NULL)
        {
            temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            temp = root->left;
            free(root);
            return temp;
        }

        temp = findMin(root->right);
        root->roll = temp->roll;
        root->right = deleteNode(root->right, temp->roll);
    }

    return root;
}

void inorder(struct Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->roll);
        inorder(root->right);
    }
}

void preorder(struct Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->roll);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct Node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->roll);
    }
}

void freeTree(struct Node *root)
{
    if (root != NULL)
    {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main()
{
    struct Node *root = NULL;
    struct Node *result;
    int choice, roll;

    do
    {
        printf("\n--- Binary Search Tree Operations ---\n");
        printf("1. Insert a student roll number\n");
        printf("2. Delete a student roll number\n");
        printf("3. Search for a student roll number\n");
        printf("4. Display inorder traversal\n");
        printf("5. Display preorder traversal\n");
        printf("6. Display postorder traversal\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter roll number: ");
            scanf("%d", &roll);
            root = insert(root, roll);
            break;

        case 2:
            printf("Enter roll number to delete: ");
            scanf("%d", &roll);

            if (search(root, roll) == NULL)
                printf("Roll number not found!\n");
            else
            {
                root = deleteNode(root, roll);
                printf("Roll number deleted successfully.\n");
            }
            break;

        case 3:
            printf("Enter roll number to search: ");
            scanf("%d", &roll);

            result = search(root, roll);

            if (result != NULL)
                printf("Roll number %d found.\n", roll);
            else
                printf("Roll number %d not found.\n", roll);
            break;

        case 4:
            if (root == NULL)
                printf("Tree is empty.\n");
            else
            {
                printf("Inorder traversal: ");
                inorder(root);
                printf("\n");
            }
            break;

        case 5:
            if (root == NULL)
                printf("Tree is empty.\n");
            else
            {
                printf("Preorder traversal: ");
                preorder(root);
                printf("\n");
            }
            break;

        case 6:
            if (root == NULL)
                printf("Tree is empty.\n");
            else
            {
                printf("Postorder traversal: ");
                postorder(root);
                printf("\n");
            }
            break;

        case 7:
            freeTree(root);
            printf("Program terminated successfully.\n");
            break;

        default:
            printf("Invalid choice! Please try again.\n");
        }

    } while (choice != 7);

    return 0;
}
/*
Output:-

--- Binary Search Tree Operations ---
1. Insert a student roll number
2. Delete a student roll number
3. Search for a student roll number
4. Display inorder traversal
5. Display preorder traversal
6. Display postorder traversal
7. Exit
Enter your choice: 1
Enter roll number: 45

--- Binary Search Tree Operations ---
1. Insert a student roll number
2. Delete a student roll number
3. Search for a student roll number
4. Display inorder traversal
5. Display preorder traversal
6. Display postorder traversal
7. Exit
Enter your choice: 1
Enter roll number: 68

--- Binary Search Tree Operations ---
1. Insert a student roll number
2. Delete a student roll number
3. Search for a student roll number
4. Display inorder traversal
5. Display preorder traversal
6. Display postorder traversal
7. Exit
Enter your choice: 1
Enter roll number: 7

--- Binary Search Tree Operations ---
1. Insert a student roll number
2. Delete a student roll number
3. Search for a student roll number
4. Display inorder traversal
5. Display preorder traversal
6. Display postorder traversal
7. Exit
Enter your choice: 1
Enter roll number: 54

--- Binary Search Tree Operations ---
1. Insert a student roll number
2. Delete a student roll number
3. Search for a student roll number
4. Display inorder traversal
5. Display preorder traversal
6. Display postorder traversal
7. Exit
Enter your choice: 1
Enter roll number: 12

--- Binary Search Tree Operations ---
1. Insert a student roll number
2. Delete a student roll number
3. Search for a student roll number
4. Display inorder traversal
5. Display preorder traversal
6. Display postorder traversal
7. Exit
Enter your choice: 1
Enter roll number: 32

--- Binary Search Tree Operations ---
1. Insert a student roll number
2. Delete a student roll number
3. Search for a student roll number
4. Display inorder traversal
5. Display preorder traversal
6. Display postorder traversal
7. Exit
Enter your choice: 1
Enter roll number: 99

--- Binary Search Tree Operations ---
1. Insert a student roll number
2. Delete a student roll number
3. Search for a student roll number
4. Display inorder traversal
5. Display preorder traversal
6. Display postorder traversal
7. Exit
Enter your choice: 2
Enter roll number to delete: 99
Roll number deleted successfully.

--- Binary Search Tree Operations ---
1. Insert a student roll number
2. Delete a student roll number
3. Search for a student roll number
4. Display inorder traversal
5. Display preorder traversal
6. Display postorder traversal
7. Exit
Enter your choice: 3
Enter roll number to search: 7
Roll number 7 found.

--- Binary Search Tree Operations ---
1. Insert a student roll number
2. Delete a student roll number
3. Search for a student roll number
4. Display inorder traversal
5. Display preorder traversal
6. Display postorder traversal
7. Exit
Enter your choice: 4
Inorder traversal: 7 12 32 45 54 68

--- Binary Search Tree Operations ---
1. Insert a student roll number
2. Delete a student roll number
3. Search for a student roll number
4. Display inorder traversal
5. Display preorder traversal
6. Display postorder traversal
7. Exit
Enter your choice: 5
Preorder traversal: 45 7 12 32 68 54

--- Binary Search Tree Operations ---
1. Insert a student roll number
2. Delete a student roll number
3. Search for a student roll number
4. Display inorder traversal
5. Display preorder traversal
6. Display postorder traversal
7. Exit
Enter your choice: 6
Postorder traversal: 32 12 7 54 68 45

--- Binary Search Tree Operations ---
1. Insert a student roll number
2. Delete a student roll number
3. Search for a student roll number
4. Display inorder traversal
5. Display preorder traversal
6. Display postorder traversal
7. Exit
Enter your choice: 7
Program terminated successfully.
*/