#include <stdio.h>
#include <string.h>
#include <stdlib.h>



//Enum for months using it for months because its a small set of same type
enum Months {
    January = 1,
    Febuary,
    March,
    April,
    May,
    June,
    July,
    August,
    September,
    October,
    November,
    December,
};

/*Struct to store a single task
 its variables name,start and dependecies
 the num dependecies describes the number of dependent tasks current task has 
 the array of dependencies is numbe
*/

typedef struct{
char name[80];
int start_month;
int end_month;
int num_dependencies;
int dependencies[10];
}Task;

/*
Struct to store all tasks from prev struct
tasklist holds an array of task structs and total number of tasks so we can store multiple tasks in one tasklist variable
 */
typedef struct {
    Task tasks[10];
    int num_tasks;
}Tasklist;

//function to display predefined chart
void predefined_gantt_chart();
//function to store users options 
void add_tasks(Task* Task);

int main(){

 // array to store tasks.
 Tasklist tasklist;
 //store users choice 
 char choice;
 int num_tasks,i,j;


 printf("Welcome to the Gantt Chart Generator\n");
 printf("Would you like to display predefined gantt  or create a new gantt chart?(y for yes or n for no)\n");
 scanf("%c", &choice);

if(choice == 'y') 
 { printf("\n");
    predefined_gantt_chart();
    
 } 
  else{
    printf("How many tasks do you want to enter (limit is 10)\n");
    scanf("%d", &num_tasks);

     tasklist.num_tasks = num_tasks;

     // Use a for loop to store information about each task
     for(i = 0; i < num_tasks; i++){
    

         printf("Enter name of task:\n");
         scanf("%s", tasklist.tasks[i].name);
         
         printf("Enter start of month(1-12):\n");
         scanf("%d",&tasklist.tasks[i].start_month);

         printf("Enter end of month(1-12):\n");
         scanf("%d",&tasklist.tasks[i].end_month); 

         printf("Enter number of dependencies for this task:\n");
         scanf("%d",&tasklist.tasks[i].num_dependencies);
       // tasks.tasks[i].dependencies = malloc(tasks.tasks[i].num_dependencies * sizeof(char*));

         //inner loop to store array of dependencies
         for(j = 0; j < tasklist.tasks[i].num_dependencies; j++)
         {
           printf("Enter dependent task:\n");
           scanf("%d",&tasklist.tasks[i].dependencies[j]);
           
         }
       }

  }
 

    return 0;
}


 void predefined_gantt_chart()
 {

    Tasklist tasklist;
    tasklist.num_tasks = 10;

     //Task 1
       strcpy(tasklist.tasks[0].name, "Water plants");
       tasklist.tasks[0].start_month = 1;
       tasklist.tasks[0].end_month = 2;
       tasklist.tasks[0].num_dependencies = 1;
       tasklist.tasks[0].dependencies[0] = 2;
     
      //Task 2
       strcpy(tasklist.tasks[1].name, "groceries");
       tasklist.tasks[1].start_month = 2;
       tasklist.tasks[1].end_month = 3;
       tasklist.tasks[1].num_dependencies = 2;
       tasklist.tasks[1].dependencies[0] = 4;
       tasklist.tasks[1].dependencies[1] = 5;
     
      //Task 3
       strcpy(tasklist.tasks[2].name, "sweeping");
       tasklist.tasks[2].start_month = 2;
       tasklist.tasks[2].end_month = 4;
       tasklist.tasks[2].num_dependencies = 0;
   
    
      //Task 4
      strcpy(tasklist.tasks[3].name, "dishes");
      tasklist.tasks[3].start_month = 3;
      tasklist.tasks[3].end_month = 5;
      tasklist.tasks[3].num_dependencies = 0;
      
     //Task 5
      strcpy(tasklist.tasks[4].name, "laundry");
      tasklist.tasks[4].start_month = 4;
      tasklist.tasks[4].end_month = 5;
      tasklist.tasks[4].num_dependencies = 0;
 
     //Task 6
      strcpy(tasklist.tasks[5].name, "Homework");
      tasklist.tasks[5].start_month = 5;
      tasklist.tasks[5].end_month = 6;
      tasklist.tasks[5].num_dependencies = 0;


     //Task 7
      strcpy(tasklist.tasks[6].name, "Bake");
      tasklist.tasks[6].start_month = 6;
      tasklist.tasks[6].end_month = 8;
      tasklist.tasks[6].num_dependencies = 0;
      

     //Task 8
      strcpy(tasklist.tasks[7].name, "Plan holiday");
      tasklist.tasks[7].start_month = 7;
      tasklist.tasks[7].end_month = 9;
      tasklist.tasks[7].num_dependencies = 0;
     

      //Task 9
      strcpy(tasklist.tasks[8].name, "Adopt a cat");
      tasklist.tasks[8].start_month =  8;
      tasklist.tasks[8].end_month = 10;
      tasklist.tasks[8].num_dependencies = 0;
     
     //Task 10
      strcpy(tasklist.tasks[9].name, "Study");
      tasklist.tasks[9].start_month = 9;
      tasklist.tasks[9].end_month = 12;
      tasklist.tasks[9].num_dependencies = 0;
 
     //display the gantt chart
     printf("Gantt Chart:\n");
     printf("Task | Start | End | Dependencies\n");
     for (int i = 0; i < tasklist.num_tasks; i++) {
     printf("%s | %d | %d | ", tasklist.tasks[i].name, 
     tasklist.tasks[i].start_month, tasklist.tasks[i].end_month);
        for (int j = 0; j < tasklist.tasks[i].num_dependencies; j++) {
            printf("%d ", tasklist.tasks[i].dependencies[j]);
        }
        printf("\n");
    }
}

