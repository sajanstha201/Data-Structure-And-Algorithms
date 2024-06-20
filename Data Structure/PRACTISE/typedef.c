#include<stdio.h>
#define saj "sajan shrestha"
#define var int
#define str struct st
struct st{
    int a;
    char name[100];
    char add[100];
};
void main()
{
    //typedef struct st str;
    str s;
   // struct st s;
    s.a=5;
    strcpy(s.name,"sajan");
    printf("%d\n",s.a);
    printf("%s\n",s.name);
    var a;
    a=5;
    printf("%d\n",a);
    typedef char name;
    name sajan;
    sajan='s';
    printf("%c\n",sajan);
    printf("%s\n",saj);
}