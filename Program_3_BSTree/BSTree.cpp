#include "BSTree.h" //Collborated with Casey Le and help from outside resources
#include "Node.h"

BSTree::BSTree() {
    root = nullptr;
}

BSTree::~BSTree() {
    delete root;
}

void BSTree::insert(const string& newstring) {
    Node* curr = root;
    Node* newNode = new Node(newstring);
    bool found;
    found = search(newstring);

    if (!found) {
        if (root == nullptr) {
            root = newNode;
        }
        else {
            while (curr != nullptr) {
                if (newstring < curr->getString()) {
                    if (curr->left == nullptr) {
                        curr->left = newNode;
                        newNode->parent = curr;
                        curr = nullptr;
                    }
                    else {
                        curr = curr->left;
                    }
                }
                else {
                    if (curr->right == nullptr) {
                        curr->right = newNode;
                        newNode->parent = curr;
                        curr = nullptr;
                    }
                    else {
                        curr = curr->right;
                    }
                }
            }
        }
    }
    else {
        curr = search(root, newstring);
        curr->count = curr->count + 1;
    }
}

bool BSTree::search(const string& key) const {
    if (search(root, key) != nullptr) {
        return true;
    }
    else {
        return false;
    }
}

Node* BSTree::search(Node* n, const string& key) const {
    if (n) {
        if (n->data == key) {
            return n;
        }
        else if (n->data < key) {
            return search(n->right, key); //would be n->left if it was else if (key < n->data)
        }

        else if (n->data > key) {
            return search(n->left, key);
        }
        else {
            return nullptr;
        }
    }
    else {
        return nullptr;
    }
}

string BSTree::largest() const {
    Node* curr = root;
    string output = "";
    if (curr == nullptr) {
        output = "";
    }
    
    else {
        while (curr->right != nullptr) {
            curr = curr->right;
        }
        output = curr->data;
    }

    return output;
}

string BSTree::smallest() const {
    Node* curr = root;
    string output = "";
    if (curr == nullptr) {
        output = "";
    }

    else {
        while (curr->left != nullptr) {
            curr = curr->left;
        }
        output = curr->data;
    }

    return output;
}

int BSTree::height(const string& key) const {
    Node* curr = search(root, key);
    return heighthelper(curr);
}

int BSTree::heighthelper(Node* curr) const {
    if (curr == nullptr) {
        return -1;
    }
    else if ((curr->left == nullptr) && (curr->right == nullptr)) {
        return 0;
    }

    if (heighthelper(curr->left) > heighthelper(curr->right)) {
        return heighthelper(curr->left) + 1;
    }
    else {
        return heighthelper(curr->right) + 1;
    }

    return 0;
}

void BSTree::preOrder() const {
    preOrder(root);
    cout << endl;
}

void BSTree::preOrder(Node* n) const {
    if (n) {
        cout << n->data << "(" << n->count << "), ";
        preOrder(n->left);
        preOrder(n->right);
    }
}

void BSTree::postOrder() const {
    postOrder(root);
    cout << endl;
}
void BSTree::postOrder(Node* n) const {
    if (n) {
        postOrder(n->left);
        postOrder(n->right);
        cout << n->data << "(" << n->count << "), ";
    }
}

void BSTree::inOrder() const {
    inOrder(root);
    cout << endl;
}

void BSTree::inOrder(Node* n) const {
    if (n) {
        inOrder(n->left);
        cout << n->data << "(" << n->count << "), ";
        inOrder(n->right);
    }
}



void BSTree::remove(const string& key) {
    bool found = search(key);
    Node* curr = search(root, key);

    if (found) {
        if (curr->count > 1) {
            curr->count = curr->count - 1;
        }
        else {
            remove(curr, key);
        }
    }
}

void BSTree::remove(Node* n, string key) {
    if ((n->left == nullptr) && n->right == nullptr) {
        if (n->parent == nullptr) {
            root = nullptr;
        }
        else if (n->parent->left == n) {
            n->parent->left = nullptr;
        }
        else {
            n->parent->right = nullptr;
        }
        return;
    }
    else if (n->left == nullptr) {
        Node* succ = n->right;
        if (n->right != nullptr) {
            while (succ->left != nullptr) {
                succ = succ->left;
            }
        }
        else {
            succ = nullptr;
        }
        n->data = succ->data;
        n->count = succ->count;
        if (succ->count > 1) {
            succ->count = succ->count - 1;
        }
        remove(succ, succ->data);
        return;
    }
    else {
        Node* prev = n->left;
        if (n->left != nullptr) {
            while (prev->right != nullptr) {
                prev = prev->right;
            }
        }
        else {
            prev = nullptr;
        }
        n->data = prev->data;
        n->count = prev->count;
        if (prev->count > 1) {
            prev->count = prev->count - 1;
        }
        remove(prev, prev->data);
        return;
    }
}

