#ifndef TYPETREE_H
#define TYPETREE_H

typedef struct typeTreeRedAndBlack typeTreeRedAndBlack;

typeTreeRedAndBlack * newTreeRB();
void insertTreeRB(typeTreeRedAndBlack * tree, int info);
int searchTreeRB(typeTreeRedAndBlack * tree, int info);

#endif