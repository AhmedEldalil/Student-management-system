/*
 * studentmangmentsystem.c
 *
 *  Created on: Aug 14, 2024
 *      Author: Ahmed M.Eldalil
 */
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>
/* functions prototype*/

/*student struct to make all data in one place*/
struct student
{
	int id;
	char name[50];
	int age;
	float gpa;
};
/*node of the linked list*/
struct node
{
	struct student data;
	struct node *next;
};
struct node *head=NULL; /*to make sure that the pointer head of the first node in the linked list is not a dangling pointer*/

void addStudent(const struct student *const ptr);
void displayStudents(void);
void searchStudentByID(int id);
void updateStudent(int id);
float calculateAverageGPA(void);
void searchHighestGPA(void);
void deleteStudent(int id);


int main()
{
	/*those two lines to solve the problem of printf and scanf in eclipse*/
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	int choosennum,id;
	while(1)
	{
		printf("\n welcome in student management system\n please choose a number from below\n 1-add student \n 2-display students \n 3-search student by id \n 4-update student by id \n 5- calculate avg gpa\n 6-search for highest gpa\n 7-delete student by id\n  8-EXIT/n ");
		scanf("%d",&choosennum);
		switch(choosennum)
		{
		case 1:
			struct node s1;

			printf("Enter name , id ,age ,gpa of student : \n");
			scanf("%s%d%d%f",s1.data.name,&s1.data.id,&s1.data.age,&s1.data.gpa);

			addStudent(&s1.data);
			break;
		case 2:

			displayStudents();

			break;
		case 3:

			printf("please enter id\n");
			scanf("%d",&id);
			searchStudentByID(id);
			break;
		case 4:

			printf("please enter id\n ");
			scanf("%d",&id);
			updateStudent(id);
			break;
		case 5:
			float avg;
			avg=calculateAverageGPA();
			printf("the average of gpas for all students is %f\n",avg);
			break;
		case 6:
			searchHighestGPA();
			break;
		case 7:

			printf("please enter id of student you want to delete\n");
			scanf("%d",&id);
			deleteStudent(id);
			break;
		case 8:
			return 0;
			break;
		default:
			return 1;
		}


	}

return 0;
}





void addStudent(const struct student *const ptr)
{

	struct node *current = NULL;
	// Allocate memory for new node
		struct node *link = (struct node*) malloc(sizeof(struct node));
		 assert(link != NULL);

		 current = head;
		 while(current != NULL)
		 		{
		 			if(current->data.id==ptr->id )
		 			{
		 				printf(" error student is already exit \n");
		 				return;
		 			}
		 			current = current->next;

		 		}
		 link->data.age = ptr->age;
		 link->data.gpa=ptr->gpa;
		 for(int i=0;i<strlen(ptr->name);i++)
		 {
		 link->data.name[i]=ptr->name[i];
		 }
		 link->data.id=ptr->id;
		 link->next = NULL;
		 if(head==NULL)
		 	{
		 		head = link;
		 		return;
		 	}


		 current = head;
		 	// loop until reach the last node in the old list
		 	while(current->next != NULL)
		 	{
		 		current = current->next;
		 	}

		 	// Make the last node in the old list point to new node
		 	current->next = link;
}




void displayStudents(void)
{
	struct node *ptr = head;
	if(ptr==NULL)
	{
		printf("no students Available\n");
		return;
	}
	while(ptr != NULL)
		{
			printf("Name = %s ",ptr->data.name);
			printf("age = %d \n ",ptr->data.age);
			printf("id = %d \n",ptr->data.id);
			printf("gpa = %f ",ptr->data.gpa);
			printf("\n-----------------------------------------------------------------------------\n");
			ptr = ptr->next;
		}

}





void searchStudentByID(int id)
{
	struct node *current = NULL;
	if(head==NULL)
		{
			printf("student is not found while no students available\n");
			return;
		}

		// start checking from the first node
		current = head;
		while(current != NULL)
		{
			if(current->data.id == id)
			{
				printf(" id= %d\n name=%s \n age = %d \n gpa= %f \n",current->data.id,current->data.name,current->data.age,current->data.gpa );

				return;
			}
			current = current->next;

		}
		// item not found in the list
		printf("student do not exist in the list\n");


}





void updateStudent(int id)
{
	char name[50];
	int age;
	float gpa;
	struct node *current = NULL;
	//no students in the linked list
	if(head==NULL)
		{
			printf("student not found please insert students first\n");
			return;
		}
	//start from first node
	current = head;
		while(current != NULL)
		{
			if(current->data.id == id)
			{
				printf("please enter the new name,age,gpa you want to modify \n ");
				gets(name);
				scanf("%d %f",&age,&gpa);
				for(int i =0;i<strlen(name);i++)
				{
				current->data.name[i] =name[i];
				}
				current->data.age =age;
				current->data.gpa =gpa;

				return;
			}
			current = current->next;

		}
		// item not found in the list
		printf("could not found student by this id\n");



}
float calculateAverageGPA(void)
{
	float avg;
	float count=0;
	int numberofstudents=0;
	struct node *ptr = head;
		if(ptr==NULL)
		{
			avg=0.0;
			return avg;
		}
		while(ptr != NULL)
			{
			count=count+ptr->data.gpa;
				numberofstudents++;

				ptr = ptr->next;
			}
		if(numberofstudents>0)
		avg=count/numberofstudents;

	return avg;

}




void searchHighestGPA(void)
{
	float heightsgpa=0;
	struct node *ptr = head;
			if(ptr==NULL)
			{
				printf("no heights Gpa as there are no students\n");

			}
			while(ptr != NULL)
				{
					if(heightsgpa<ptr->data.gpa)
					{
						heightsgpa=ptr->data.gpa;
					}

					ptr = ptr->next;
				}
			printf("the heights gpa is %f \n",heightsgpa);


}





void deleteStudent(int id)
{
	struct node *current = NULL;
	struct node *prev = NULL;
	struct node * delete_node = NULL;
	if(head==NULL)
		{
			printf("No students to delete\n");
			return;
		}
	//check the first node in the linked list
		if(head->data.id == id)
		{
			delete_node = head;
			// move head to next node
			head = head->next;
			printf("student has deleted \n");
			free(delete_node);
			return;
		}

		//check the rest of nodes in the linked list
		current = head->next;
		prev = head;
		while(current != NULL)
			{
				if(current->data.id == id)
				{
					//element found
					delete_node = current;
					prev->next = current->next;
					free(delete_node);
					return;
				}
				prev = current;
				current = current->next;

			}
		if(delete_node == NULL)
			{
				printf("%d not found to delete \n",id);
			}





}















