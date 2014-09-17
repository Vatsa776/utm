/************************************/
/* Srivathsan Jayaraman */
/* code to simulate a universal Turing machine */
/* Commands: > -> next tape 
			 < -> previous tape
			 + -> increment value at tape
			 - -> decrement value at tape
			 . -> output value at tape
			 , -> input value to tape
			 [ -> loop beginning
			 ] -> loop end
*/

#include<stdio.h>
#include<string.h>
typedef struct Tape Tape;

char tape[30000] = {0};
char code[500];	
char *ptr;
char *itr;

	
void initMachine() {
	
	int i;	
	
	printf("Welcome! Please note that this is an interpreter and so press newline to produce output.All values are in decimal.\n");

	strcpy(code,"");	
	ptr = tape;
} 

void runMachine() {
	
	int len;
	char symbol;
	int stack[100] ={0};	
	int top = 0;
	int depth = 0;
				
	
	scanf("%s", code);

	printf("Compiling!\n");

	len = strlen(code);

	itr = code;	

	while( *itr != '\0' ) {
				
		symbol = *itr;		
		
		switch(symbol)	{
	
			case '>' : ptr++;
					   break;
			
			case '<' : ptr--;
					   break;

			case '+' : (*ptr)++;
					   	break;

			case '-' : (*ptr)--;
					   break;
			
			case ',' : *ptr = getchar();
					   break;

			case '.' : printf("%c",*ptr);;		
					   break;

			case '[' : if(stack[top] != itr - code) 
                			stack[++top] = itr - code;

            		  	itr++;

            		  	if(*ptr != 0)
                			continue;
            
						else
            			{   				
                			depth = 1;
                			
							while((depth > 0) || *itr != ']')
                			{
                    			itr++;
                    			
								if(*itr == '[')
                    				depth++;
                    
								else if(*itr == ']')
                    				depth--;
                			}
                
							top--;
         				}   
        
						break;

			case ']':  itr = code + stack[top];
            			continue;
        	
			//case '\n': continue;
			}
							
			itr++;
	}		

}


int main(void)	{
	
	initMachine();
	runMachine();

	return 0;
}
