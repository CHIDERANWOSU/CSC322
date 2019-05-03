#include <stdio.h> 
#include <stdlib.h> 


char * copyStr(char s[])
{
    int i;
    size_t len = strlen( s );

    char * p = (char*) malloc( len + 1 );

    for( i = 0; i < len; i++ )
        p[i] = s[i];

    p[i] = '\0';

    return p;
}

int main(int argc, char ** argv)
{
    
    char name[20];

    printf("Enter nation name\n");

    //scanf("%s", &name1); 
    fgets(name,20,stdin);

    printf("Enter best ally name for %s", name);
    
    //scanf("%s", &name);  
    fgets(name,20,stdin);
    
    printf("The best ally of %s is %s", name);
 	
    return 0;
}