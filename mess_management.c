/* This program is a mess management system that allows users to check the timings of 
different meals and whether they are currently open or not. */
#include<stdio.h> // for input/output operations
#include<string.h> // for string comparison operations
#include<time.h> // for time operations
#include<stdlib.h> // for standard library functions

// Function prototypes
void list_meals(); // function to display the list of meals
int meal_time(); // function to check the timings of the selected meal
int check_time(float ,float ,char *); // function to check the current time and compare it with the meal timings
void mess_time(); // function to display the timings of all meals


int main()
{
    char id[100],reg_id[100];
    int f=0;
    printf("\n\n*************   WELCOME TO SRM MAIN MESS!   *************\n\n");
    printf("                ----------------------\n");               
    printf("\t\tENTER YOUR ID\n");
    printf("                ----------------------\n");
    printf("\t\t-> ");
    scanf("%s",id);   

    // File handling to check if the entered ID is registered in the mess                      
    FILE *file;                      
    file = fopen("srm_id.txt","r");          
    if (file == NULL)
    {
        printf("file doesnot exist\n");
        return 0;
    }
    while(fscanf(file,"%s",reg_id) != EOF)
    {
        if(strcmp(reg_id,id) == 0) // compare entered ID with the registered IDs in the file
        { 
            list_meals(); // call the function to display the list of meals                  
            meal_time();  // call the function to check the timings of the selected meal                  
            f=1;    
            break;
        }
    }   
    if(f==0) // if entered ID is not found in the file
        printf("\n\n\tSORRY, YOUR ID IS NOT REGISTERED FOR SRM MESS\n\n");
    fclose(file);  // close the file                         
    return 0;
}

// Function to display the list of meals
void list_meals()
{
    printf("\n\n                ------------------------------------------------\n");
    printf("\t\t|    SELECT NUMBER FOR MEALS AS SHOWN BELOW    |\n");
    printf("                ------------------------------------------------\n");
        printf("\t\t| 1. | BREAKFAST\t\t\t       |\n");
        printf("\t\t| 2. | LUNCH\t\t\t\t       |\n");
        printf("\t\t| 3. | SNACK\t\t\t\t       |\n");
        printf("\t\t| 4. | DINNER\t\t\t\t       |\n");
    printf("                ------------------------------------------------\n");
    printf("\t\t  ->");
}

// Function to check the timings of the selected meal
int meal_time() 
{
    float t1,t2;
    char *z;
    int choice;
    scanf(" %d",&choice);
    printf("                ------------------------------------------------\n");
    if(choice==1)
    {
    t1=7.5;
    t2=9;
    z="BREAKFAST";
    }
    else if(choice==2)
    {
        t1=12;
        t2=14;
        z="LUNCH";
    }
    else if(choice==3)
    {
        t1=16.5;
        t2=17.75;
        z="SNACK";
    }
    else if(choice==4)
    {
        t1=19.45;
        t2=20.75;
        z="DINNER";
    }
   check_time(t1,t2,z);            
   return 0;
}


void mess_time()
{
printf("                ------------------------------------------------\n");
printf("\t\t|\t\t MESS TIMINGS\t\t       |\n");
printf("                ------------------------------------------------\n");
printf("\t\t|\tBREAKFAST  7:30 AM TO 9:00 AM\t       |\n\n");
printf("\t\t|\tLUNCH     12:00 PM TO 2:00 PM\t       |\n\n");
printf("\t\t|\tSNACKS     4:30 PM TO 5:45 PM\t       |\n\n");
printf("\t\t|\tDINNER     7:15 PM TO 8:45 PM\t       |\n");
printf("                ------------------------------------------------\n");
}



int check_time(float t1, float t2,char *z)
{
    time_t current_time = time(NULL);
    struct tm *local_time = gmtime(&current_time);
    local_time->tm_hour +=5;
    local_time->tm_min +=30;
    mktime(local_time);
    float t= local_time->tm_hour + (local_time->tm_min/0.6);
    if( t>=t1 && t<=t2  )
    {
    printf("\n\n\t\t\tENJOY YOUR %s :)\n\n\n",z);
    }
    else
    {
    printf("\n\n   *************  SORRY,THIS IS NOT TIME FOR %s   *************\n\n\n",z);
    printf("\t\tFOR MESS TIMINGS SEE BELOW:\n");
    mess_time();
    }
    return 0;
}

/*//In this program, the user is prompted to enter their ID. The program then checks if the 
entered ID is registered in the mess by reading from a file called "srm_id.txt". If the ID is 
found in the file, the user is then shown a list of meals to choose from. The program then 
checks the current time and compares it to the timings of the selected meal. If the current
time falls within the meal timings, the user is given access to the meal. If not, the user is 
informed that the meal time is over and the timings for all meals are displayed.
*/






