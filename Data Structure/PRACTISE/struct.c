#include<stdio.h>
struct st{
    char *p;
    int a;
    char name[100];
    struct st_n{
        int a;
        char c;
    }s1,s2;
};
void main()
{
    struct st s={"deep",5,"devraj",4,'d',6,'f'};
    printf("%s\n",s.p);
    printf("%d\n",s.s1.a);
    printf("%d\n",s.s2.a);
    struct st str={"sajan",5,"shrestha",5,'c',6,'g'};
    struct st *ptr;
    ptr=&str;
    printf("%d\n",str);
    printf("%d\n",&str);
    printf("%s\n",ptr->p);
    printf("%d\n",ptr->s1.a);
  // s.p=(char*)malloc(100);
      // scanf("%s",s.p);
   // strcpy(s.p,"sajan");
   // printf("%s\n",s.p);

  //  int *p=s;
   // printf("%d\n")
}