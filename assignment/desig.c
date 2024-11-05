 /*
  Desc: to read a designation code and display his designation as a string. Use the following mapping.
 
  2 – Software Developer
 
  3 – Senior Software Developer
 
  4 – Team Lead
 9
 5 – Senior Team Lead
11
12 anyother value – incorrect designation code
13 */
 
 #include<stdio.h>
 int main()
 {
     int DesCode;
     printf("Enter Designation Code:");
     scanf("%d",&DesCode);
     if(DesCode==2)
         printf("Designation is Software Developer\n");
     else if(DesCode==3)
         printf("Designation is Senior Software Developer\n");
     else if(DesCode==4)
         printf("Designation is Team Lead\n");
     else if(DesCode==5)
         printf("Designation is Senior Team Lead\n");
     else
         printf("Incorrect designation code\n");
     return 0;
}

