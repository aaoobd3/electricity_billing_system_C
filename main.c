#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
  char Name[50];
   int EM;
  double CMR;
  double PMR;
  char pcode[5];
  char address[100];
  double price;
  
} customer;
customer *c=NULL;
int count_lines = 0;
 char** split (char* string, const char* delim) {
char* p;
int i = 0;
char** array;

array = malloc(strlen(string) * sizeof (char*));
p = strtok (string, delim);
while (p != NULL) {
    array[i] = malloc(sizeof(char) );
    array[i++] = p;
    p = strtok(NULL, delim);
    
}
return array;
} 
void open_file() {
if(c!= NULL)
  free(c);
  
 char s2[]="b.txt";
char s1[]="a.txt";
char s3[]="c.txt";
FILE *fp,*fp1,*fp2;
    fp=fopen(s2,"r");
    fp1=fopen(s1,"r");
    fp2=fopen(s3,"r");
  char chr;  
      count_lines = 0;
      chr = getc(fp);
      
      
    while (chr != EOF)
    {
    	  
        //Count whenever new line is encountered
        if (chr == '\n')
        {
            count_lines = count_lines + 1;
        }
        //take next character from file.
        chr = getc(fp);
    }
    
  
    fclose(fp);
    
    
    
     c= (customer *)calloc(count_lines,sizeof(customer));
     
     
    fp=fopen(s2,"r");
    if (fp==NULL) {
      printf("error1 %s\n\n",s2);
      exit(1);
    }
    if (fp1==NULL) {
      printf("error2 %s\n\n",s1);
      exit(1);
    }
    if (fp2==NULL) {
      printf("error3 %s\n\n",s3);
      exit(1);
    }
    else{

    
char str1[200];
char str2[200];
char str3[200];
  int i = 0;
  
  while ((fgets(str1,200,fp))!=NULL && (fgets(str2,200,fp1))!=NULL && (fgets(str3,200,fp2))!=NULL) {
  	
  	if(str1[strlen(str1)-1]=='\n' )
  		str1[strlen(str1)-1]='\0';
  		if(str2[strlen(str2)-1]=='\n' )
  		str2[strlen(str2)-1]='\0';
  		if(str3[strlen(str3)-1]=='\n' )
  		str3[strlen(str3)-1]='\0';
  	
char *token  = strtok(str1, ",");
strcpy((c+i)->Name,token);
token  = strtok(NULL, ",");
(c+i)->EM = atoi(token);
token  = strtok(NULL, ",");
strcpy((c+i)->pcode,token);
token  = strtok(NULL, ",");
strcpy((c+i)->address,token);

    (c+i)->price = 0.00;
    char*token2  = strtok(str2, ",");
    token2  = strtok(NULL, ",");
    
    (c+i)->CMR = atof(token2);
    char *token3  = strtok(str3, ",");
    token3  = strtok(NULL, ",");
    (c+i)->PMR = atof(token3);
    
    i++;
    
    
          }
          
          
              fclose(fp);
              fclose(fp1);
              fclose(fp2);

}
  
}
void add(){
char s2[]="b.txt";
char s1[]="a.txt";
char s3[]="c.txt";
FILE *fp,*fp1,*fp2;
    fp=fopen(s2,"a");
    fp1=fopen(s1,"a");
    fp2=fopen(s3,"a");
    
    char Name[50];
  char EM[7];
  float CMR;
  float PMR;
  char pcode[5];
  char address[100];
  fflush(stdin);
  printf("\nENTER NAME:");
  gets(Name);
    fflush(stdin);

    printf("\nENTER ELECTRICITY METER NUMBER(7 DIGITS):");
  gets(EM);
    fflush(stdin);

    printf("\nENTER ENTER POSTAL CODE (5 DIGITS):");

  gets(pcode);
    fflush(stdin);

    printf("\nENTER ADDRESS(100 char MAX) dont use comma: ");

  gets (address);
    fflush(stdin);
    printf ("\nPLEASE PROCEED WITH UPDATING THE Current ");
    fprintf(fp,"%s,%s,%s,%s\n",Name,EM,pcode,address);
    fprintf(fp1,"%s,%s\n",EM,"0");
    fprintf(fp2,"%s,%s\n",EM,"0");
    fclose(fp);
    fclose(fp1);
    fclose(fp2);
    open_file();
}
void printreceipt(){
	open_file();
	int i ;

	for(i=0;i<count_lines;i++){
		double unit =(c+i)->CMR;
		double amount = 0;	
		if(unit<=200&&unit>=0)
    {
        amount=unit*0.218;
    }
    else if(unit<=300&&unit>=201)
    {
        amount=((200*0.218)+(unit-200)*0.334);
    }
    else if((unit<=600)&&unit>=301){
        amount=(200*0.218)+((100)*0.334)+(unit-300)*0.516;
    }
    else if((unit<=900)&&unit>=601){
        amount=(200*0.218)+((100)*0.334)+(300)*0.516+(unit-600)*0.546;
    }
    else{
        amount=(200*0.218)+((100)*0.334)+(300)*0.516+(600)*0.546+(unit-900)*0.571;
    }
    
    (c+i)->price = amount;
    printf("\n**********************************************************************\n");
    printf("                      ABC Electric Company SDN. BHD.                    \n");
    printf("                Electric Bill for the month of August 2020              \n");
    printf("  Customer Name: %s\n",(c+i)->Name);
    printf("  Address: %s                                           Meter Number:%d \n",(c+i)->pcode,(c+i)->EM);
    printf("                Number of units consumed:%.2f\n",(c+i)->CMR);
    printf("                   Amount to be paid:%.2f\n",(c+i)->price);
    printf("\n**********************************************************************\n\n\n\n");
	}
}
void indreceipt(){
	open_file();
	int i,input ;
printf("\nENTER YOUR METER NUMBER 7 DIGITS:");
scanf("%d",&input);
	for(i=0;i<count_lines;i++){
	if ((c+i)->EM == input){
	
		double unit =(c+i)->CMR;
		double amount = 0;	
		if(unit<=200&&unit>=0)
    {
        amount=unit*0.218;
    }
    else if(unit<=300&&unit>=201)
    {
        amount=((200*0.218)+(unit-200)*0.334);
    }
    else if((unit<=600)&&unit>=301){
        amount=(200*0.218)+((100)*0.334)+(unit-300)*0.516;
    }
    else if((unit<=900)&&unit>=601){
        amount=(200*0.218)+((100)*0.334)+(300)*0.516+(unit-600)*0.546;
    }
    else{
        amount=(200*0.218)+((100)*0.334)+(300)*0.516+(600)*0.546+(unit-900)*0.571;
    }
    
    (c+i)->price = amount;
    printf("\n**********************************************************************\n");
    printf("                      ABC Electric Company SDN. BHD.                    \n");
    printf("                Electric Bill for the month of August 2020              \n");
    printf("  Customer Name: %s\n",(c+i)->Name);
    printf("  Address: %s                                           Meter Number:%d \n",(c+i)->address,(c+i)->pcode,(c+i)->EM);
    printf("                Number of units consumed:%.2f\n",(c+i)->CMR);
    printf("                   Amount to be paid:%.2f\n",(c+i)->price);
    printf("\n**********************************************************************\n\n\n\n");
	}
}}
void edit_curr(){
	FILE *fp1,*fptemp;
	char s1[]="a.txt";
	char temp[]="temp.txt";
	
	fp1=fopen(s1,"r");
	fptemp = fopen(temp,"w");
	char str1[200];
	int input,CMR;
	int flag = 0;
	printf("\nenter the electrical meter number :");
	scanf("%d",&input);
	printf("\nenter the  current meter reading:");
	scanf("%d",&CMR);
	while ((fgets(str1,200,fp1))!=NULL) {
  	
  	if(str1[strlen(str1)-1]=='\n' )
  		str1[strlen(str1)-1]='\0';  
		  char *line;		
    line = strtok(str1,",");
    char EM[10],PRE[10];
    strcpy(EM,line);
    line = strtok(NULL,",");
    strcpy(PRE,line);
    
    if (atoi(EM)==input){
	fprintf(fptemp,"%s,%d\n",EM,CMR);
	flag = 1;

	} else{
	fprintf(fptemp,"%s,%s\n",EM,PRE);
	}
	}
	if (flag){
	printf("\nchanging done");}
	else{
	printf("\nnot found");
	}
	
	
	fclose(fp1);

	fclose(fptemp);
	
	
	remove ("a.txt");
	getch();
	rename ("temp.txt","a.txt");
    open_file();

	}
	
void close_month(){
	open_file();
	
char s1[]="a.txt";
char s2[]="c.txt";
FILE *fp1;


if (fp1==NULL) {
      printf("\n\nCan't open the files ");
      exit(1);
    }
  else{
 
  remove("c.txt");
 
  rename("a.txt","c.txt");

  fp1=fopen(s1,"a");
  int i;
  for (i=0;i<count_lines;i++)
  fprintf(fp1,"%d,%d\n",(c+i)->EM,0);
  }
  fclose(fp1);
      open_file();
printf("month closed and moved to previous meter reading ");
   
}

   void	printreport(){
   	open_file();
   		double total =0;
	int i;

 printf("\n***********************************************************************************\n");
    printf("                            ABC Electric Company SDN. BHD.                        \n");
    printf("                      Electric Bill for the month of August 2020                  \n");
    printf("\n\nMeter Number         Customer Name        Units        consumed Bill amount (RM)\n\n");
	for(i=0;i<count_lines;i++){
	
	
		double unit =(c+i)->CMR;
		double amount = 0;
		
		if(unit<=200&&unit>=0)
    {
        amount=unit*0.218;
    }
    else if(unit<=300&&unit>=201)
    {
        amount=((200*0.218)+(unit-200)*0.334);
    }
    else if((unit<=600)&&unit>=301){
        amount=(200*0.218)+((100)*0.334)+(unit-300)*0.516;
    }
    else if((unit<=900)&&unit>=601){
        amount=(200*0.218)+((100)*0.334)+(300)*0.516+(unit-600)*0.546;
    }
    else{
        amount=(200*0.218)+((100)*0.334)+(300)*0.516+(600)*0.546+(unit-900)*0.571;
    }
    
    (c+i)->price = amount;
    
   printf ("\n%d\t\t%s\t%.3f\t\t%.3f\n",(c+i)->EM,(c+i)->Name,(c+i)->CMR,(c+i)->price);
	
	total  = total+amount;
}
printf ("\n\t\t\t%.3f\n",total);
   	
   }


void main(){
int ch = 0;	
printf("\n\t1.add customer\n\t2.edit current meter reading\n\t3.print all receipt\n\t4.print indivisual receipt");
printf("\n\t5.print report\n\t6.close month\n\t0.exit\n\t Enter your choice:");
fflush (stdin);
scanf("%d",&ch);
switch(ch)
    {
    	case 0:
    exit(1);
        break;
    case 1:
    add();
    getch();
        system("cls");
        break;
    case 2:
    edit_curr();	
    	getch();
        system("cls");
        break;
    case 3:
    printreceipt();	
    	getch();
        system("cls");
        break;
    case 4:
  indreceipt();
    	getch();
        system("cls");
        break;
    case 5:
    	printreport();
    	getch();
        system("cls");
	    break;
	case 6:
		close_month();
		getch();
        system("cls");
		break;    
    default:
        printf("\n\t\n\t-----------input invalid try again------------------\n\t");
        getch();
        system("cls");
        break;
    }
system("cls");
main();
}
