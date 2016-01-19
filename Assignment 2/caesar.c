#include <stdio.h>
#include <string.h>

int main(void)
{

char s[100]; 
int l;
int a;
int r1;
int r2;
int i;


printf("Sentence:");
gets(s);
l = strlen(s);
//Check if th
while (l>=100){ 
printf("Your input is longer than 100 characters, type less than 100 characters\n");
printf("sentence:");
gets(s);
l=strlen(s);
}

printf("Number: ");
scanf("%d", &a);

 for (i=0; i<strlen(s);i++) 
{
//CAPITAL LETTERS
    if ('A'<=s[i] && s[i] <='Z') 
	{  r1= a%26;
	 if (r1>=0)
          { 
	   if (r1>('Z'-s[i]))
	   s[i] = 'A' + (r1-('Z'-s[i]));

	   else s[i] = s[i] + r1; 
	  }
        else if (s[i]-'A'<-r1)
		s[i]='Z'-((-r1)-(s[i]-'A'));
             else s[i]= s[i]+r1;	
         }
//LOWERCASE LETTERS
     if ('a' <=s[i] && s[i]<= 'z')
        {  r2 = a%26;
	  if (r2>=0)
           {
           if (r2>('z'-s[i]))
           s[i] = 'a' + (r2-('z'-s[i]));
           
           else s[i] = s[i] + r2;
            }
          else if (s[i]-'a'<-r2)
		s[i] = 'z'-((-r2)-(s[i]-'a'));
	       else s[i] = s[i] + r2;

         } 
}
printf("Cipher: %s\n" , s);
printf("Done\n");

return 0;

}
