#include <stdio.h>
#include <windows.h> 

int talking(int talkNum, char change, int tNum[600], char tNames[600][40], char text[600][80]);

int extraText(int textNum);

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
   fp = fopen("Text2.txt", "r");
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
      if(*buff == ' '){
      }
      else if(prev == empty && *buff != empty){
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

   int textNum = 0;
   for (int i = 0; i < 150; ++i)
   {
   		if(31 < i && i < 37){
   			extraText(textNum);

   			if (textNum==0)
   			{
   				textNum = 4;
   			}

   			textNum++;
   		}

   		nameChar = tNames[i][0];

   		switch(nameChar) {
    		case '[' :
         		change = '\xF';
        	break;
      		case 'F' :
         		change = '\x2';
        	break;
        	case 'P' :
         		change = '\xD';
        	break;
        	case 'S' :
         		change = '\xE';
        	break;
           	case 'B' :
         		change = '\x09';
        	break;
      		default :
         		change = '\x7';
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


int extraText(int textNum){

	char text[30][5000] = {
		"\tTommy glances at the message on his phone and lets out\n"
		"\ta huff before returning his eyes to the road.\n\n",

		"\t\"I know you saw it.\" Forzen calls to him. Tommy\n"
		"\trefuses to react in any way shape or form. Instead,\n"
		"\this eyes remain glued to the road ahead of them. \n"
		"\t\"Stop ignoring me, I know you can hear me.\"\n\n",

		"\t\"Not right now, Forzen.\" Tommy mumbles, then\n"
		"\timmediately bites his tongue. He shouldn't have responded.\n"
		"\tThat's only going to encourage Forzen and Tommy already\n"
		"\thas enough to deal with.\n\n"

		"\tTommy glances at all the cars nearby him,\n"
		"\tspecifically checking their drivers. None of the cars have\n"
		"\ttinted windows- a good sign. Most of the drivers around him\n"
		"\tright now don't immediately set off any alarms- another good sign.\n\n",

		"\tHis shoulders roll and try to relax. He glances in the rear view mirror,\n"
		"\tlooking over Forzen again before checking himself. \n"
		"\tEverything looks normal- Tommy looks perfectly normal- \n"
		"\tbut he can't be too careful. Tommy can never be too careful these days.\n"
		"\tNot with everything on the line, not with everything \n"
		"\the needs to keep track of- not after everything everything everything-\n\n",

		"\tTommy's phone lights up again. He glances at it,\n"
		"\tcatching a hint of the message.\n\n",



		"\tIt takes everything in him not to make another sarcastic response.\n"
		"\tOf course I'm tense, I gave you one specific instruction and you went\n"
		"\tagainst it anyways. On my day off too- you know how many of these I get a year,\n"
		"\tForzen, and you took one of the few ones I have away from me.\n\n"

		"\tAnother text pops up.\n\n",



		"\tTommy sucks in a breath, doing so with an irritated look on his face.\n"
		"\tHe hates that Forzen can read him right now. Usually Tommy is good\n"
		"\tabout it but his emotions are raw and unfiltered right now.\n"
		"\tThere's no concealing it.\n\n",



		"\tWith one hand, Tommy reaches over and quickly types in a response,\n"
		"\tall while keeping a steady eye on the road. Forzen is lucky Tommy's\n"
		"\tgotten good at multitasking. He wouldn't have lasted this long without it.\n\n",



		"\tTo Tommy's surprise, no new messages seem to come after that.\n"
		"\tHis eyes do another quick sweep of everything- eyes on the road,\n"
		"\tcheck the cars and their drivers, check Forzen and his wounds,\n"
		"\tcheck yourself and your posture, deep breaths, stay calm, stay collected,\n"
		"\tand above all act natural. Though for a moment, he notes that Forzen seems\n"
		"\tto still be texting, even if Tommy gets no new texts.\n\n",

		"\tMinutes pass by. Tommy's starting to think he's in the clear\n"
		"\twhen his phone lights up again. He's almost frustrated until\n"
		"\the stares at the new number in confusion. Then he's thrown in\n"
		"\tfor a loop when he reads the message and mentally suppresses his\n"
		"\turge to slam his foot down on the break.\n\n",

		"\t\"Did you tattle on me?\" Tommy finally turns his head to look \n"
		"\tat Forzen for a brief moment, sending a look as he does. \n"
		"\tHe can hardly believe it. \"You- you tattled on me to the soda parlor worker?\"\n\n",
		
		"\t\"You weren't talking to me.\" Forzen says, like that explains everything.\n\n",
		
		"\tTommy honestly wants to bang his head against the horn of the car and let it \n"
		"\tring out in frustration. Unfortunately, he can't do that because he's on the \n"
		"\thighway and would really rather avoid a crash. That's the last thing they need right now.\n\n",
		
		"\t\"Okay- fine! We're- we're talking!\"\n\n",
		
		"\t\"You're stressed.\"\n\n",
		
		"\t\"Great observation.\"\n\n",
		
		"\t\"Tommy.\"\n\n",
		
		"\tThat makes him stop. Because Forzen is looking at the rear view mirror\n"
		"\tand he sounds genuine and softer than before. \"I'm sorry.\"\n\n",
		
		"\tHe knows, at least. That he owes Tommy an apology. \n"
		"\tHearing it outloud feels nice. A pound taken away from the load on his chest.\n"
		"\tTommy can breath just a little easier and finds his words leave him easier too.\n\n",
		
		"\t\"I told you not to go there. I gave you one thing to do and- and it was just \n"
		"\tto not do something. One thing! I- I didn't think it would be that hard to follow!\"\n\n",
		
		"\t\"I'm sorry.\" Forzen repeats. \"I wasn't thinking and I didn't mean for this to happen.\"\n"
		"\tHe's making it hard to get mad at him with that look on his face.\n\n",
		
		"\t\"I- I need you to understand that it's not because you went against \n"
		"\tmy wishes or- or because you're making me work on my day off. You got hurt, \n"
		"\tForzen. I'm- I'm mad because you got hurt and you scared me.\n"
		"\tI don't like it when you get hurt!\"\n\n",

		"\t\"I know.\" Forzen's voice is quieter now, guilty. \"I'm sorry.\"\n\n",
		
		"\tIt's so easy to let it go. Tommy breathes out and one of the knots in his chest is gone.\n"
		"\t\"I forgive you.\" Tommy always tries make that as clear as possible after a fight with Forzen.\n"
		"\tOtherwise he usually doesn't get the message and assumes Tommy is still mad,\n"
		"\teven weeks after the fight. \"Just... Please don't do that again?\"\n\n",
		
		"\tForzen nods. Tommy does another sweep- road, cars and drivers, Forzen, yourself,\n"
		"\tstay calm- before his eyes linger to the phone sitting on his stand.\n"
		"\tHe pauses before reaching over to it.\n\n"
	};

	printf("%s", text[textNum]);
	if(textNum == 0){
		textNum++;
		for (int i = textNum; i < 5; ++i)
		{
			getchar();
			printf("%s", text[i]);
		}
	}

	if (textNum == 8)
	{
		for (int i = textNum; i < textNum + 17; ++i)
		{
			getchar();
			printf("%s", text[i]);
		}
	}
	
	getchar();
}
