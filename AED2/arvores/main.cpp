#include "iostream"
#include "cstring"
#include "tree.h"

using namespace std;


int main(){

    typeTree nTree;
    typeData dt;

    newTree(&nTree);

    dt.age = 10;
    insertTree(&nTree, &dt);

    dt.age = 5;
    insertTree(&nTree, &dt);

    dt.age = 13;
    insertTree(&nTree, &dt);

    dt.age = 2;
    insertTree(&nTree, &dt);

    dt.age = 7;
    insertTree(&nTree, &dt);

    dt.age = 12;
    insertTree(&nTree, &dt);

    dt.age = 17;
    insertTree(&nTree, &dt);


    //showTree(&nTree);

    dt.age = 10;
    
    cout << "Antecessor: " << (predecessor(&nTree,&dt))->age << " Sucessor: " << (successor(&nTree,&dt))->age << "\n";
}
