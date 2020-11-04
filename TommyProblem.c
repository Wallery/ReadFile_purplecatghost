#include <stdio.h>
#include <windows.h> 

int talking(int talkNum, char change, int tNum[600], char tNames[600][40], char text[600][80]);

int main() {

   FILE *fp;
   char buff[600];

   char tNames[600][40]= {""}; // Contains Names
   char text[600][80]= {""};  // Contains text

   char empty;       // Where there is no char
   char prev;        // What past char was
   
   int tNum[600];     // Position of asklines
   int k1 = 0;       // Num of ask lines 
   int k2;           // Used with names[][]
   int k3 = 0;       // Position for num[]

   // open and set up file
   fp = fopen("Text.txt", "r");
   fgets(buff, 600, (FILE*)fp);
   fgets(buff, 600, (FILE*)fp);
   empty = *buff;

   // get info from file
   for (int i = 0; i < 620; ++i)
   {
      prev = *buff;
      fgets(buff, 600, (FILE*)fp);

   /*
      Saving the name in names
      Saving the number of ask lines
      Saving text[]
   */
      if(prev == empty && *buff != empty){
         /*
         Save content of buff in names when prev is empty
         k3 denotes a placement for name, first name is 0
         k2 gives a position for the char 
         */
         k2 = 0;
         while(buff[k2] != empty){
            tNames[k3][k2] = buff[k2];
            k2++;
         }
         tNum[k3] = (k1);
         k3++;
      }
      else if(*buff != empty){
         /*
         Save the ask text in text[][],
         char by char
         */
         k2 = 0;
         while(buff[k2] != empty){
            text[k1][k2] = buff[k2];
            k2++;
            
         }
         /* Adds one to k1, how many lines*/
         k1++;
      } 
      //end of else if
   } 
   // end of loop

   fclose(fp);

   char change;
   char nameChar;

   for (int i = 0; i < 201; ++i)
   {
   		nameChar = tNames[i][0];

   		switch(nameChar) {
    		case '[' :
         		change = '\017';
        	break;
      		case 'F' :
         		change = '\002';
        	break;
        	case 'P' :
         		change = '\015';
        	break;
        	case 'S' :
         		change = '\016';
        	break;
      		default :
         		change = '\007';
   }

   	talking(i, change ,tNum, tNames, text);
   	getchar();
   }

	printf("   Credit: purplecatghostposts.tumblr.com\n");
	getchar();
}

int talking(int talkNum, char change, int tNum[600], char tNames[600][40], char text[600][80]){

   HANDLE  hConsole;
   hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

   int n = tNum[talkNum];

   printf("\n\t\332   ");
   SetConsoleTextAttribute(hConsole, change);   // Change color
   printf("%s",tNames[talkNum]);
   SetConsoleTextAttribute(hConsole, 7);        // Back to org
   // ---- Formated Text -----------------
   printf("\n\t\263");   
   while(n != tNum[talkNum+1]){
      printf("\n\t\263\t%s", text[n]);
      n++; }
   printf("\n\t\263 \n\t\300\n");

}
