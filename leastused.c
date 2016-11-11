//Author:Deepali Ghorpade, Ganesh Solanke

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<ctype.h>
#include<sys/stat.h>
#include<string.h>

int main(int argc,char *argv[])
{
  FILE *fptr,*fleastused;

  struct stat sb;
  double optionsec;

  char fdata[100], filename[50];
  int i = 0, j = 0,length;

   length= strlen(argv[1]);
   if(length < 4 || argv[1][0] != '-') {
	printf("invalid argument");
	exit(0);
   }

  char one = argv[1][1];
  char two = argv[1][2];
  char choice = argv[1][3];
  int count,onea,twoa;
  onea = one -'0';         //CONVERT CHARActer to integer
  twoa = two -'0';

  fptr = fopen("foutput.txt","w+");
  
  if(NULL == fptr)
    {
	printf("\n fopen() Error!!!");
	return 1;
    }
  printf("\n Data File opened successfully for writing");

  system("ls -ia >> foutput.txt");
  //system("ls -ia -R >> foutput.txt");			//use to list all files from directories.
  fclose(fptr);
 
  fptr = fopen("foutput.txt","r+");
  if(NULL == fptr)
    {
	printf("\n fopen() Error!!!");
	return 1;
    }
  printf("\n Data File opened successfully for reading");

  fleastused = fopen("filelist.txt","w+");
  if(NULL == fleastused)
    {
	printf("\n fopen() Error!!!\n");
	return 1;
    }
  printf("\n Output File opened successfully \n");

  time_t time_of_day;
  struct tm *sett,*yearsett,*currentt,*tyear,*setty;
  time_t t,difft,timer,ttyear;
  time(&t);

  timer = time(NULL);
  sett =localtime(&timer);    //convert to structure

  printf("\nToday's date and time: %s", ctime(&t));
  count = onea*10 + twoa;

 if(argv[1][0] == '-'){
  if(argv[1][3] == 'd'){
     if((count >= 1 && count <= 31)){
	  sett->tm_mday = sett->tm_mday - count;
	  printf("\n least used before %d Days \n",count);
     }else{
	printf("Invalid argument\n");
	exit(0);
     }
  }
  if(argv[1][3] == 'm'){
      if((count >= 1 && count <= 12)){
	sett->tm_mon = sett->tm_mon-count;
	printf(" least used before %d months\n",count);
      }
     else{
	printf("Invalid argument\n");
	exit(0);
     }
  }
  if(argv[1][3] == 'y'){
	setty->tm_year =1900 + sett->tm_year-count;
	printf("\n least used before %d Years\n",count);
	printf("option year = %d",  setty->tm_year);
  }
}
   time_t newt = mktime(sett);
   printf("\n");

  while(!feof(fptr)){
	i=0;
	fgets(fdata, 100, fptr);
	fdata[strlen(fdata) - 1] = '\0';

       // checking whether the input string is NULL
	if (fdata[0] == '\0') {
		printf("Input string is NULL\n");

	}

       j=0;
	// printing words in the given string
	while (fdata[i] != '\0') {

		/* ' '  is the separator to split words */
		if (fdata[i] == ' ') {
			filename[j] = '\0';
			j=0;

		} else {
			filename[j++] = fdata[i];
		}
		i++;
	}

	filename[j] = '\0';

	stat(filename,&sb);
	time_of_day = sb.st_mtime;
	ttyear = time_of_day;
	double msec = difftime(t,time_of_day);


	switch(choice){

	case 'd': optionsec = difftime(t,newt);
		  if(msec >= optionsec ){
			printf("%s", filename);
			printf("\tmtime: %s", ctime(&sb.st_mtime));
			fputs(filename,fleastused);
			fputs("\n",fleastused);

		   }

		   break;
	case 'm':  optionsec = difftime(t,newt);
		   if(msec >= optionsec){
			printf("%s", filename);
			printf("\tmtime: %s", ctime(&sb.st_mtime));
			fputs(filename,fleastused);
			fputs("\n",fleastused);
		   }

		   break;

	case 'y': tyear =localtime(&ttyear);
		  if(( setty->tm_year) == (1900 + tyear->tm_year)){
			printf("\n%s ", filename);
			printf("\tmtime: %s", ctime(&sb.st_atime));
			fputs(filename,fleastused);
			fputs("\n",fleastused);
		   }
		  break;

	default  :printf("WRONG OPTION");
		  break;

      }
}
    printf("\nclosing");
    fclose(fptr);
    fclose(fleastused);
    
}
