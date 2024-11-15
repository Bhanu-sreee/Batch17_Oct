#include<stdio.h>
#include<string.h>
struct employee
{
int eid;
float esal;
char eaddress[20];
char ename[20];
char egender;
};
typedef struct employee emp;
int main()
{
emp e1;
 
e1.eid =101;
e1.esal=1000000.1;
strcpy(e1.ename,"havila");
strcpy(e1.eaddress,"nyc");
e1.egender='f';
 
 
printf("\n employee details are:" );
printf("\n id:%d",e1.eid);
printf("\n name:%s",e1.ename);
printf("\n gender:%c",e1.egender);
return 0;
}
