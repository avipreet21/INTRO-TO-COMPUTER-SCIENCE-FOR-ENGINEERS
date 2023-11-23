/*
   Author:  Tamara Dakic
   Date: Nov 5, 2009
   File: Lab7Driver.c
   Compiler Version: DevC++ 4.9.2

   ------------------------------------------------------
   Comp120 -- Lab 7
   Test driver program for functions developed in lab 7

   -------------------------------------------------------
*/


#include <stdio.h>
#include <stdlib.h>

#define QUIT  0
#define READ_CODE 1
#define CODE_VALID 2
#define ENCODE_CHAR  3
#define DECODE_CHAR 4
#define ENCODE_FILE 5
#define DECODE_FILE 6

#define PRINTABLE_CHARS 95
#define FIRST_CHAR 32
#define LAST_CHAR 126
#define TRUE 1
#define FALSE 0


int GetTestChoice();
void clean ();
void readCode(char[]);
char encodeChar(char ,char []);
void encodeFile(char []);
char decodeChar(char ,char []);
int BinarySearch(char [], int, char);
void decodeFile(char []);
void slectionsort(char [], int );

int main()
{
    int choice;			/* store choice for which function to test */
    char codeArray[PRINTABLE_CHARS];
    char ch;


	printf( "*** Test driver for lab 7. *** \n\n");

	do
	{
		choice = GetTestChoice();

		switch (choice)
		{
            case READ_CODE:
                 printf( "Reading the code from code.txt...\n");
                 readCode(codeArray);
                 printf( "Reading complete.\n");

                 break;

            case ENCODE_CHAR:
                 printf( "Enter the character you want to encode: ");
				 scanf("%c",&ch);
				 clean();
				 printf("\nThe encoded character is %c.\n", encodeChar(ch,codeArray));

				 break;

		    case ENCODE_FILE:
				 encodeFile(codeArray);
				 printf("File data.txt encoded successfully. Output in encoded.txt.\n");

				 break;

            case DECODE_CHAR:
				 printf( "Enter the character you want to decode: ");
			     scanf("%c",&ch);
				 clean();
		         printf("\nThe decoded character is %c.\n", decodeChar(ch,codeArray));

				 break;

	        case DECODE_FILE:
	 	         decodeFile(codeArray);
				 printf("File encoded.txt decoded successfully. Output in decoded.txt\n");

				 break;

			case CODE_VALID:
				 printf( "Testing the code for validity...\n");
				 if (codeValid(codeArray))
                     printf("\nCode is valid \n");
                 else
                    printf("\nCode is not valid \n");

				 break;



			default:
				if (choice != QUIT)
					printf("\n That is NOT a valid test case.  Try again...\n");
				break;

		}  /* end switch  */

	} while (choice != QUIT);
    printf("Finishing the program.\n");
    system("PAUSE");
    return 0;


}




/*********************************************************************
 * clean()
 *        Reads all characters from the input buffer until NEWLINE reached
 *        Returns: none
 * PRE: input stream is not empty
 * POST: input stream is empty
 *********************************************************************/
void clean (void)
{
     char dummy;
     do
     {
         scanf("%c",&dummy); /* read a single char */
     } while(dummy != '\n'); /* if it was the NEWLINE we are done */
}


/*********************************************************************
 * GetTestChoice()
 *		Displays a menu of all the functions tested in this test driver.
 *		Returns a number indicating user's choice for function to test.
 * PRE : none
 * POST: the user has been prompted to select a function AND
 *		 an integer representing the user's choice is returned.
 * NOTE: no data validation performed
 *********************************************************************/
int GetTestChoice()
{
	int choice;

	printf("\n\nEnter the number of the function you want to test:\n");

	printf("%d: Quit the test driver program.\n", QUIT);
	printf("%d: Read code from file.\n",READ_CODE);
	printf("%d: Test code. \n",CODE_VALID);
	printf("%d: Encode a character.\n", ENCODE_CHAR);
	printf("%d: Decode a character.\n",DECODE_CHAR);
	printf("%d: Encode file. \n",ENCODE_FILE);
	printf("%d: Decode file. \n",DECODE_FILE);


	scanf("%i", &choice);
	clean(); /* empty the input buffer */
	printf("\n\n");

	return choice;
}

void readCode(char codearray[]){
    FILE*inputFile = NULL;
   // Try to open file
   printf("Opening file myfile.txt.\n");
   inputFile = fopen("code.txt", "r");
   if (inputFile == NULL) {
      printf("Could not open file myfile.txt.\n");
      return -1; // -1 indicates error
   }
   for(int i=0; i < PRINTABLE_CHARS; i++){
    char single;
    fscanf(inputFile, "%c",&single);
    codearray[i] = single;
   }
           // Done with file, so close it
    printf("Closing file myfile.txt.\n");
    fclose(inputFile);

}

char encodeChar(char c, char codeArray[]) {
    int index = (int)c - FIRST_CHAR;
    return codeArray[index];
}

void encodeFile(char codeArray[]){
    char ch;
    int numread;
    FILE*infile = NULL;
    infile = fopen("data.txt", "r");
    if (infile == NULL){
        printf("file infile didnt open.");
        return -1;
    }
    FILE*outfile = NULL;
    outfile = fopen("encoded.txt", "w");
    if (outfile == NULL){
        printf("file didnt open.");
        return -1;
    }
    while(TRUE){
        numread = fscanf(infile, "%c", &ch);
        if(numread != 1 || ch == '\n'){
            break;
            }
        ch = encodeChar(ch, codeArray);
        fprintf(outfile, "%c", ch);
    }
        // Close both files after processing
    fclose(infile);
    fclose(outfile);
}



int BinarySearch(char codearray[], int size, char key){
    int low;
    int mid;
    int high;

    low = 0;
    high = size - 1;

    while(high >= low){
        mid = (high + low)/2;
        if(codearray[mid]< key){
            low = mid +1;
        }else if (codearray[mid] > key){
            high = mid - 1;
        }else{
            return mid;
        }
    }
    return -1;
}


char decodeChar(char c, char codeArray[]) {
    int index = BinarySearch(codeArray, PRINTABLE_CHARS, c);
    int orignalindex = index + FIRST_CHAR;
    return (char)orignalindex;
}

void decodeFile(char codearray[]){
    char ch;
    int numread;
    FILE*infile = NULL;
    infile = fopen("encoded.txt", "r");
    if(infile == NULL){
        printf("coudnt open infile");
        return -1;
    }
    FILE*outfile = NULL;
    outfile = fopen("decoded.txt", "w");
    if(outfile == NULL){
        printf("coundnt open outfile");
        return -1;
    }
    while(TRUE){
        numread = fscanf(infile, "%c", &ch);
        if (numread != 1 || ch == '\n'){
            break;
        }
     ch = decodeChar(ch,codearray);
     fprintf(outfile, "%c", ch);
    }
    fclose(infile);
    fclose(outfile);
}

void slectionsort(char codearray[], int size){
    int i;
    int j;
    int indexsmallest;
    int temp;
    for(i = 0; i < size -1; ++i){
        indexsmallest = i;
        for(j = i +1; j < size; ++j){
            if (codearray[j] < codearray[indexsmallest]){
                indexsmallest = j;

            }
        }
        temp = codearray[i];
        codearray[i] = codearray[indexsmallest];
        codearray[indexsmallest] = temp;
    }

}


