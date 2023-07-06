#include<iostream>
#include<stdio.h>
#include<fstream>
#include<string.h>
#include <sstream>
#include<time.h>
using namespace std;
fstream fp;
 int get_1st_weekday(int year);
 void instructions(void);
int getValue(void);
void menu(int);
void available(void);
void list(void);
void assign(void);
void deelete(void);
int assigned[12]={0};
char seatID[12][3] = {"A1","A2","A3","A4","A5","A6","B1","B2","B3","B4","B5","B6"};
char lastName[12][15];
char firstName[12][15];
int i=0,ref,sum;
  char fname[20],seat, str[200], opt,meal,ad,in,ch,flight,inter[100],cla[100],dp[100],arri[100],currenttime;
    int seats,arrival,year,choice,inf,date;
    char c;
 
int get_1st_weekday(int year)
{
	
int d;
  d = (((year - 1) * 365) + ((year - 1) / 4) - ((year - 1) / 100) + ((year) / 400) + 1) % 7;
  return d;
}
void instructions(void)
{
	printf("\nPlease make a menu selection 1-6:\n\n");
}

int getValue(void)
{
	int value;
	
	do
	{
		scanf("%d", &value);
	}while(value > 12);
	
	return value;
}

void menu(int input)
{
	int temp = 0;

	switch(input)
	{
		case 1:
			for(int i = 0; i < 12; i++)
			{
				if(assigned[i] == 0)
					temp++;
			}
			printf("\nThere are %d available seats\n\n", temp);
			break;
			
		case 2:
			available();
			break;
			
		case 3:
			list();
			break;
			
		case 4:
			assign();
			break;
			
		case 5:
			deelete();
			break;
			
		case 6:
			
			break;

		default:
			printf("\nBe sure to enter a valid choice!\n");
	}
}

////////////////////////list available seats//////////////////

void available(void)
{
	printf("\nAvailable seats:\n");
	printf("________________\n");
	for(int i=0; i < 12; i++)
	{
		if( assigned[i] == 0 )
		{			
			printf("%s\n",seatID[i]);
		}
	}
}

////////////////////list NOT WORKING!!//////////////////////////

void list(void)
{
	char array[3][12][15];
	int c = 0;
	int max = 0;

	for(int i = 0; i < 12; i++)
	{
		if(assigned[i] > 0)
		{
			max++;
			strcpy(array[0][c], seatID[i]);
			strcpy(array[1][c], lastName[i]);
			strcpy(array[2][c], firstName[i]);
			c++;
		}
		printf("%d\n", max);
	}
			for(int x = 0; x < 3; x++)
				for(int y = 0; y < 2; y++)
					if(strcmp(array[1][y],array[1][y+1]) > 0)
					{
						char temp[15];

						strcpy(temp, array[1][y]);
						strcpy(array[1][y], array[1][y + 1]);
						strcpy(array[1][y + 1], temp);

						strcpy(temp, array[2][y]);
						strcpy(array[2][y], array[2][y + 1]);
						strcpy(array[2][y + 1], temp);

						strcpy(temp, array[0][y]);
						strcpy(array[0][y], array[0][y + 1]);
						strcpy(array[0][y + 1], temp);
					}
	for(int i = 0; i < max; i++)
	{
		printf("%s, %s,  %s\n",array[1][i], array[2][i], array[0][i]);
	}
}

////////////////////assign seat/////////////////

void assign(void)
{
	char column;
	int seat;

	for(int i = 0; i < (12 / 2); i++)
	{
		printf("A%d		B%d\n", i + 1, i + 1);
	}
	printf("\nSelect row A or B:  ");
	fflush(stdin);
	column=getchar();
	printf("\nSelect a seat number 1-6:  ");
	seat=getValue();
	if(toupper(column)=='A')
	{
		printf("\nEnter first and last name:  ");
		scanf("%s %s", firstName[seat - 1], lastName[seat - 1]);
		assigned[seat-1]++;
	}
	if(toupper(column)=='B')
	{
		printf("\nEnter first and last name:  ");
		scanf("%s %s", firstName[seat+(12 / 2) -1], lastName[seat+(12 / 2) -1]);
		assigned[seat + (12 / 2)-1]++;
	}
}



/////////////////////delete a seat/////////////////

void deelete(void)
{
	int x = 0;
	
	printf("\nEnter seat ID:  \n");

	for(int i = 0; i < 12; i++)
	{
		printf("%d	%s", x + 1, seatID[i]);

		if(assigned[i] < 1)
		{
			printf("%s, %s\n", lastName[i], firstName[i]);
		}else
		{
			printf("\n");
		}
		x++;
	}

	x = getValue();

	assigned[x - 1] = 0;
	printf("\n");
	
}




int main()

{

    char fname[20],seat, str[200], opt,meal,ad,in,ch,flight,inter[100],cla[100],dp[100],arri[100],currenttime;
    int seats,arrival,year,choice,inf,date;
    char c;
    //fstream fp; 
   
    fp.open("zainab.txt", std::fstream::in | std::fstream::out | std::fstream::app);
    if(!fp)
    {
    printf("\nError Occurred!");
        return 0;
    }
 /*   printf("Enter the name: ");
	gets(str);
fp<<"/t"<<str;    */
    
   // while(strlen(str)>0)
    {
    	 printf("*******WELCOME TO ONLINE RESERVATION SYSTEM*******");
  	   
  /*  printf("please select the following:");
        printf("\n\n\t\t 1. one way/two way");
		printf("\n\n\t\t 2. date");
		printf("\n\n\t\t  3 No of passengers");
        printf("\n\n\t\t 3.Domestic/International\n");
        printf("\n\n\t\t 4. arrival");
        printf("\n\n\t\t 5. departure");
        printf("\n\n\t\t 6. class");
        printf("\n\n\t\t 7. meal/no meal");
        printf("\n\n\t\t 8. seats");
        */
        printf("\nSelect arrival place:");
        fflush(stdin);
		gets(arri);
		fp<<"\t"<<arri;
		printf("Enter the departure place");
        fflush(stdin);
		gets(dp);
		fp<<"\t"<<dp;
	    printf("Select One way/two way,: ");
        fflush(stdin);
		gets(str);
		fp<<"\t"<<str;    
        printf("Enter meal or no meal ");
       fflush(stdin);
	   gets(str);
         fp<<"\t"<<str;
         
         
         
    /*     printf("\nSelect arrival place:");
        fflush(stdin);
		gets(arri);
		fp<<"\t"<<arri;*/
	/*printf("Enter the departure place");
                fflush(stdin);
				gets(dp);
				fp<<"\t"<<dp;
		  printf("Enter the number of adults");
              fflush(stdin);
			    scanf("%d",&ad);
			    fp<<"\t"<<ad;
                printf("\nEnter the number of children");
                fflush(stdin);
				scanf("%d",&ch);
				fp<<"\t"<<ch;
                printf("Enter the number of infants");
                fflush(stdin);
				scanf("%d",&inf);
				fp<<"\t"<<inf;
                 printf("\nSelect international/Domestic flight: ");
                 fflush(stdin);
				 gets(inter);
				 fp<<"\t"<<inter;
                printf("Select your class Economy or Bussiness: ");
               fflush(stdin);
			   gets(cla);
			fp<<"\t"<<cla;*/
   int year,month,day,daysInMonth,weekDay=0,startingDay;
   printf("\nEnter your desired year:");
fflush(stdin);
   scanf("%d",&year);
   fp<<"\t"<<year;

   char *months[]={"January","February","March","April","May","June","July","August","September","October","November","December"};
   int monthDay[]={31,28,31,30,31,30,31,31,30,31,30,31};

   if((year%4==0&&year%100!=0)||year%400==0)
       monthDay[1]=29;

   startingDay= get_1st_weekday(year);

   for(month=0;month<12;month++)
   {
      daysInMonth=monthDay[month];
      printf("\n\n---------------%s-------------------\n",months[month]);
      printf("\n  Sun  Mon  Tue  Wed  Thurs  Fri  Sat\n");

      for(weekDay=0;weekDay<startingDay;weekDay++)
        printf("     ");

      for(day=1;day<=daysInMonth;day++){
        printf("%5d",day);

        if(++weekDay>6){
            printf("\n");
            weekDay=0;
        }
        startingDay=weekDay;
      }

   }
    time_t t;   
            time(&t);		
         printf("\n\ncurrent date and time is %s",ctime(&t));
         printf("\n\nSelect date after current date:");
     scanf("%d",&date);
     fp<<"\t"<<date;
                printf("\nSelect international/Domestic flight: ");
                 fflush(stdin);
				 gets(inter);
				 fp<<"\t"<<inter;
				 int totalpeople;
				 totalpeople=ch+inf+ad;

                printf("\nSelect your class Economy or Bussiness: ");
               fflush(stdin);
			   gets(cla);
			   fp<<"\n"<<cla;
	printf("\nThe total amount is 20000");
			

			   int payment,balence,children,infant,adults,amount;			
    		 
	int choice;

	instructions();  
	do
	{
		printf("1. Number Avaliable 2. List Available\n");
		
		printf("3. List Names       4. Assign Seat\n");
		
		printf("5. Delete seat      6. QUIT\n\n");
		
		choice = getValue();
		menu(choice);
	}while(choice != 6);
	
	              	
}
   fp.open("zainab.txt", std::fstream::in | std::fstream::out | std::fstream::app);
    printf("----------------------------------------");
    
    FILE *fp1, *fp2;
 
    // opening files
    fp1 = fopen("zainab.txt", "a+");
    fp2 = fopen("projecr.txt", "a+");
 
    // If file is not found then return.
    if (!fp1 && !fp2) {
        printf("Unable to open/"
               "detect file(s)\n");
        
    }
 
    char buf[100];
 
    // explicitly writing "\n"
    // to the destination file
    // so to enhance readability.
    fprintf(fp2, "\n");
 
    // writing the contents of
    // source file to destination file.
    while (!feof(fp1)) {
        fgets(buf, sizeof(buf), fp1);
        fprintf(fp2, "%s", buf);
    }
 
    rewind(fp2);
 
    // printing contents of
    // destination file to stdout.
    while (!feof(fp2)) {
        fgets(buf, sizeof(buf), fp2);
        printf("%s", buf);
    }
   
    
   fstream my_file;
	my_file.open("final.txt", ios::in);
	
	
	string myText;
	// Use a while loop together with the getline() function to read the file line by line
		while (getline (my_file, myText)) {
  		// Output the text from the file
  		//cout << "/n/n";
		//cout<<myText;
		
		istringstream ss(myText);
	
		printf("%s\t %s\t",fname,seat);

		
		
			
		 
		
		
  		
	}
// Close the file
my_file.close(); 

    
     return 0;
}
    
