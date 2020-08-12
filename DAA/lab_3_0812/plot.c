#include <stdio.h>
#include <stdlib.h>

int main()
{       
        int j;   
        int i;  

printf("Enter how many coordinates you want to input:\n");
scanf("%d", &j);

int x[j];
int y[j];

 for(i=0; i<j; i++)
   {      
       printf("Enter your x and y coordinate:\n");        
       scanf("%d %d", &x[i], &y[i]);

   }

   freopen("myfile.txt", "w", stdout);

   for(i=0; i<j; i++)        
   {    
       printf("%d %d\n", x[i], y[i]);

   }
system("gnuplot -p -e \"plot '/home/sahil/sem5_lab/DAA/lab_3_0812/myfile.txt'\"");


return 0;
}