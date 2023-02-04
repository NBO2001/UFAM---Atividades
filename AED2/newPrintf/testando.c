#include<stdarg.h>
#include<stdio.h>

//I'll do it without the typedef this time.
#define Foreach_string(iterator, ...)\
for (char **iterator = (char*[]){__VA_ARGS__, NULL}; *iterator; iterator++)

int main(){
    char *str = "thread";
    Foreach_string(i, "yarn", str, "rope"){
    printf("%s\n", *i);
}
}

// typedef char* string;

// int main(){
//     string str = "thread";
//     
//     for (list; *list; list++)
//     printf("%s\n", *list);
// }