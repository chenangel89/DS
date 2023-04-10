```c
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* deleteNode(struct TreeNode* root, int key) {
    if (root == NULL) {
        return NULL; // 如果根節點為空，則直接返回空
    }
    if (root->val > key) {
        root->left = deleteNode(root->left, key); // 如果要刪除的鍵比根節點小，則在左子樹中刪除
    }
    else if (root->val < key) {
        root->right = deleteNode(root->right, key); // 如果要刪除的鍵比根節點大，則在右子樹中刪除
    }
    else {
        if (root->left == NULL) { // 如果要刪除的節點只有右子樹
            struct TreeNode* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) { // 如果要刪除的節點只有左子樹
            struct TreeNode* temp = root->left;
            free(root);
            return temp;
        }
        else { // 如果要刪除的節點既有左子樹又有右子樹
            struct TreeNode* temp = root->right;
            while (temp->left != NULL) {
                temp = temp->left; // 找到右子樹中的最小節點
            }
            root->val = temp->val; // 將該最小節點的值賦值給要刪除的節點
            root->right = deleteNode(root->right, temp->val); // 在右子樹中刪除該最小節點
        }
    }
    return root;
}
```
