#include<stdio.h>
#include<unistd.h>
#include<string.h>


#define BUFF_SIZE 1024

const char FILE_NAME[] ="MyQualities.txt";

void main()
{

   char QUALITIES[BUFF_SIZE] = "The qualities are ";
   char buff[BUFF_SIZE] = "";

   // Opening file for writting
   FILE *file = fopen(FILE_NAME , "w" );

   if ( file == NULL )  
   {
       printf("Error: Cannot create file [%s] to write.\n", FILE_NAME);
       return;
   }

   printf("Please enter sentences, . to end.\n");

   while( fgets( buff, BUFF_SIZE, stdin ) )
   {
       char temp[100] = "";

       if ( strstr(buff,"I am") )
       {
           // Getting the length of string atfer "I am" pattern
           int len = strlen(buff + 5);

           // length after removing new line char
           len = len - 1 ;

           // Coping string after "I am" to temp, till before new line char
           strncpy(temp, buff + 5 , len );

           // now we will write the qualities in file
           fputs(temp,file);
           fputc('\n',file);

           // appending comma after string
           strcat(temp, ",");

           // appending it to main QUALITIES string
           strcat(QUALITIES,temp);
           memset(buff, 0 , sizeof(buff));

           continue;
       }

      
       // removing new line char and checking remaining string contains only .
       int len = strlen(buff);   //   Getting the size of string
       buff[len-1] = '\0';   //   Overwritting new line char with '\0' char

       if ( strcmp(buff,"." ) == 0 )   // one is . and otheris new line char
                {
                        // break out of loop and print qualities
                        break;
                }


       memset(buff, 0 , sizeof(buff));
   }

   // removing the last extra comma character.
   int len = strlen(QUALITIES);
   QUALITIES[len - 1 ] = '\0';
  
   printf("%s.\n\n", QUALITIES);
   fclose(file);

   // Opening MyQualities.txt file for reading
   file = fopen(FILE_NAME , "r" );

   printf("Confirming the saved qualities ...\n");

   while( fgets( buff, BUFF_SIZE, file ) )
        {
       printf("%s", buff);
        }

   remove(FILE_NAME);
   fclose(file);
}
