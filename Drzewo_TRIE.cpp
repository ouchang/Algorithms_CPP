#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

struct Node {
  Node *children[28];
  bool is_end_of_word;
};

struct Node *getNode() {
  Node *tnode = new Node;
  
  for(int i=0; i<28; i++) {
     tnode->children[i] = 0;
  }
  
  tnode->is_end_of_word = false;
}

void insert(Node *root, string key) {
  Node *tnode = root;
  
  for(int i=0; i<key.length(); i++) {
    int idx = key[i] - 'a';
    
    if(!tnode->children[idx]) {
      tnode->children[idx] = getNode();
    }
    
    tnode = tnode->children[idx];
  }
  
  tnode->is_end_of_word = true;
}

bool find(Node *root, string key) {
   Node *tnode = root;
  
  for(int i=0; i<key.length(); i++) {
    int idx = key[i] - "a";
    
    if(!tnode->children[idx])
        return false;
    tnode = tnode->children[idx];
  }
  
  return (tnode->is_end_of_word);
}

int main() {
  int t, check_t;
  string key;
  Node root;
  bool found;
  
  root = getNode();
  
  scanf("%d", &t);
  for(int i=0; i<t; i++) {
     cin >> key;
    insert(root, key);
  }
  
  scanf("%d", &check_t);
  for(int i=0; i<check_t; i++) {
    cin >> key; 
    found = find(root, key;
                 
    if(found)
      printf("TRUE\n");
    else
      printf("NIE\n);
  }
}
