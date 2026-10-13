#include <stdio.h>
#include <conio.h>

struct abc {
    int data;
    char val;
    struct abc *link;
};

int main() {
    struct abc obj1,obj2;
    obj1.data=10;
    obj1.val='A';
    obj1.link=NULL;
    obj2.data=11;
    obj2.val='B';
    obj2.link=NULL;

    obj1.link=&obj2;
    printf("%d\n",obj1.data); 
    printf("%c\n",obj1.val);
    printf("%d\n",obj1.link->data); 
    printf("%c\n",obj1.link->val);

    return 0;
}

