#include <bits/stdc++.h>

#define besmellah ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
const ll INF = 1e9 + 7;
const ll MOD = 1e9 + 7;
const ll N = 8e3;
#define M_PI 3.14159265358979323846
#define endl '\n'
int dx[] = {+0, +0, +1, -1, +1, -1, +1, -1};
int dy[] = {+1, -1, +0, +0, +1, -1, -1, +1};


/*
 * This problem will give us preorder and inorder and post order for a tree and we need to know
 * if these three inputs for same tree or not
 */

/*
 * we will use inorder and preorder to construct a tree and then we will compare a tree with the postorder
 *
 * if you don't know the algorithm please google it to understand the code
 */

//We will initialize a nodes as struct
struct node {
    int data;
    node *left;
    node *right;
};

int n;
vector<int> pre, post, in;


//adding new nodes
node *newNode(int data) {
    node *Node = new node();
    Node->data = data;
    Node->left = nullptr;
    Node->right = nullptr;

    return Node;
}


//searching for the node in inorder array
int search(int strt, int end, int value) {
    int i;
    for (i = strt; i <= end; i++) {
        if (in[i] == value)
            return i;
    }
}


//recursive function to build the tree
node *buildTheTree(int instrt, int inend) {
    static int preIdx = 1;
    if (instrt > inend) {
        return nullptr;
    }
    node *tnode = newNode(pre[preIdx++]);
    if (instrt == inend) {
        return tnode;
    }
    int inIndex = search(instrt, inend, tnode->data);
    tnode->left = buildTheTree(instrt, inIndex - 1);
    tnode->right = buildTheTree(inIndex + 1, inend);
    return tnode;
}

queue<int> NewPostOrder;

//traverse the constructed tree and get the new postorder
void dfs(node *i) {
    if (i == nullptr) {
        return;
    }
    dfs(i->left);
    dfs(i->right);
    NewPostOrder.push(i->data);
}

int main() {
    besmellah
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //    freopen("closing.out", "w", stdout);
#endif
    cin >> n;
    pre.resize(n + 1);
    post.resize(n + 1);
    in.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> pre[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> post[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> in[i];
    }
    node *root = buildTheTree(1, n);
    dfs(root);
    int i = 1;
    while (!NewPostOrder.empty() and NewPostOrder.front() == post[i++]) {
        NewPostOrder.pop();
    }
    if (NewPostOrder.size() == 0)cout << "yes";
    else cout << "no";
}
