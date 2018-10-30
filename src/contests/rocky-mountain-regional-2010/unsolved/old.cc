#include <bits/stdc++.h>
using namespace std;

struct node;
// typedef map<int, node*> mmap;

struct tree {
   tree() {
      root = nullptr;
   }

   tree(int s, int d) {
      root = new node(s);
   }
   
   ~tree() {
      destroy();
   }

   void destroy(node *n) {
      if (n == nullptr) return;
      destroy(n->w);
      destroy(n->d);
      destroy(n->l);
      delete n;
   }
   
   void insertLevel(int score, node *n) {
      
      
      
      
      // assert(n != nullptr);
      // n->w = new node(score + 3);
      // n->d = new node(score + 1);
      // n->l = new node(score);
   }
   
   void postorder(node *n) {
      if (n == nullptr) return;
      postorder(n->w);
      postorder(n->d);
      postorder(n->l);
      cout << "score: " << n->score << endl;
   }
   
   node *root;
};

struct node {
   int score;
   node *w, *d, *l;
   node(int s) : score(s) {
      w == nullptr;
      d == nullptr;
      l == nullptr;
   }

   void newLevel(int score) {
      w = new node(score + 3);
      d = new node(score + 1);
      l = new node(score);
   }
};

node* newNode(int score) {
   node* n = new node(score);
   n->w = nullptr;
   n->d = nullptr;
   n->l = nullptr;
   return n;
}

// void add(node& rt) {
//    rt.m.insert(make_pair(0, new node(rt.score+3)));
//    rt.m.insert(make_pair(1, new node(rt.score+1)));
//    rt.m.insert(make_pair(2, new node(rt.score)));
//    // rt.m['d'] = rt.score + 1;
//    // rt.m['l'] = rt.score;
// }

// void clear(node* n) {

// }

void preorder(node* n, int d) {
   // if node has no elements in map, print score   
   if (n == nullptr)
      return;

   cout << "depth " << d << ", score " << n->score << endl;

   preorder(n->m[0], d+1);
   
}

int main() {

   int v = 0;
   node root(v);

   add(root);
   preorder(&root, 0);

   return 0;
}
