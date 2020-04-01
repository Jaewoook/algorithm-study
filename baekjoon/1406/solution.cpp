// unsolved - wrong answer
#include <iostream>
#include <string>
using namespace std;

struct node {
    char c;
    node* left;
    node* right;
};

struct cursor {
    node* left;
    node* right;
};

void insert(char c, cursor* cur) {
    node* newNode = new node;
    newNode->c = c;
    newNode->left = cur->left;
    newNode->right = cur->right;

    if (cur->left != NULL) {
        cur->left->right = newNode;
    }
    if (cur->right != NULL) {
        cur->right->left = newNode;
    }
    cur->left = newNode;
}

void del(cursor* cur) {
    if (cur->left == NULL || cur->left->c == 0) {
        return;
    }

    if (cur->left->left != NULL) {
        cur->left->left->right = cur->right;
    }
    if (cur->right) {
        cur->right->left = cur->left->left;
    }
    cur->left = cur->left->left;
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(0);

    string buffer;
    node start, *tmp = NULL;
    int commands = 0, data_size = 0;
    start.c = 0;
    start.left = NULL;
    start.right = NULL;
    cursor cur;
    cur.left = &start;
    cur.right = NULL;

    cin >> buffer;
    data_size = buffer.size();

    for (int i = 0; i < data_size; i++) {
        insert(buffer[i], &cur);
    }

    cin >> commands;
    cin.ignore();

    for (int i = 0; i < commands; i++) {
        getline(cin, buffer);
        switch (buffer[0]) {
            case 'L':
                if (cur.left != NULL && cur.left->c != 0) {
                    tmp = cur.left;
                    cur.left = cur.left->left;
                    cur.right = tmp;
                }
                break;
            case 'D':
                if (cur.right != NULL) {
                    tmp = cur.right;
                    cur.right = cur.right->right;
                    cur.left = tmp;
                }
                break;
            case 'B':
                del(&cur);
                break;
            case 'P':
                insert(buffer[2], &cur);
                break;
        }
    }

    cur.right = start.right;
    while (cur.right != NULL) {
        cout << cur.right->c;
        cur.right = cur.right->right;
    }
    cout << "\n";

    return 0;
}
