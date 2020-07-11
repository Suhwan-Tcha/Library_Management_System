#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

struct book {
	int bi;
	char bn[20];
	char pd[10];
	char pn[20];
	char ppn[20];
	char an[20];
	char aea[50];
};
int main(void)
{
	int num, i, temp, flag, idx = 0, delid;
	struct book bid[100];
	char name[20];
	do {
		printf("<<<Library Management Program>>>\n\n");
		printf("1.Add book information \n");
		printf("2.Update book information \n");
		printf("3.Delete book information \n");
		printf("4.Search book information \n");
		printf("5.Display a list of book(s) published by an author \n");
		printf("6.Display a list of book(s) published by a publisher \n");
		printf("7.Display a list of all book \n");
		printf("8.Exit \n");
		scanf("%d", &num);
		
		switch (num)
		{
		case 1:
			flag = 0;
			printf("Enter book ID: ");
			scanf("%d", &temp);
			if (temp < 0)
			{
				printf("You entered it incorrectly");
				break;
			}
			for (i = 0; i < idx; i++)
			{
				if (temp == bid[i].bi)
					flag = 1;
			}
			if (flag == 1)
			{
				printf("This ID already exists");
				break;
			}
			bid[idx].bi = temp;
			printf("Enter the book name: ");
			scanf("%s", &bid[idx].bn, 20);
			printf("Enter the publication date: ");
			scanf("%s", &bid[idx].pd, 10);
			printf("Enter the publisher name: ");
			scanf("%s", &bid[idx].pn, 20);
			printf("Enter the publisher phone number: ");
			scanf("%s", &bid[idx].ppn, 20);
			printf("Enter the author name: ");
			scanf("%s", &bid[idx].an, 20);
			printf("Enter the author email address: ");
			scanf("%s", &bid[idx].aea, 50);
			idx++;
			break;
		case 2:
			flag = 0;
			printf("Enter the ID of book you want to update: ");
			scanf("%d", &temp);
			if (temp < 0)
			{
				printf("You entered it incorrectly");
				break;
			}
			for (i = 0; i < idx; i++)
			{
				if (temp == bid[i].bi)
				{
					bid[i].bi = temp;
					printf("Enter the book name: ");
					scanf("%s", &bid[idx].bn, 20);
					printf("Enter the publication date: ");
					scanf("%s", &bid[idx].pd, 10);
					printf("Enter the publisher name: ");
					scanf("%s", &bid[idx].pn, 20);
					printf("Enter the publisher phone number: ");
					scanf("%s", &bid[idx].ppn, 20);
					printf("Enter the author name: ");
					scanf("%s", &bid[idx].an, 20);
					printf("Enter the author email address: ");
					scanf("%s", &bid[idx].aea, 50);
					flag = 1;

				}

			}
			if (flag == 0)
				printf("This ID does not exist");
			break;
		case 3:
			flag = 0;
			printf("Enter the ID of book you want to delete:");
			scanf("%d", &temp);
			for (i = 0; i < idx; i++)
			{
				if (bid[i].bi == temp)
				{
					flag = 1;
					delid = i;
				}
			}
			if (flag == 0)
			{
				printf("You entered it incorrectly\n");
				break;
			}
			for (i = delid; i < idx; i++)
			{
				bid[i] = bid[i + 1];
			}
			idx--;
			break;
		case 4:
			flag = 0;
			printf("Enter the ID of book you want to search: \n");
			scanf("d", &temp);
			for (i = 0; i < idx; i++)
			{
				if (bid[i].bi == temp)
				{
					flag = 1;
					printf("The name of book is : %s\n", bid[i].bn);
					printf("The publication date is : %s\n", bid[i].pd);
					printf("The publisher name is : %s\n", bid[i].pn);
					printf("The publisher phone number is : %s\n", bid[i].ppn);
					printf("The author name is : %s\n", bid[i].an);
					printf("The author email address is : %s\n", bid[i].aea);
					break;
				}
			}
			if (flag == 0)
				printf("You entered it incorrectly\n");
			break;
		case 5:
			flag = 0;
			printf("Enter the author name you want to search: \n");
			scanf("%s", &name, 20);
			for (i = 0; i < idx; i++)
			{
				if (strcmp(name, bid[i].an) == 0)
				{
					flag = 1;
					printf("Book name : %s\n", bid[i].bn);
					printf("Publication date : %s\n", bid[i].pd);
					printf("Ppublisher name : %s\n", bid[i].pn);
					printf("Ppublisher phone number : %s\n", bid[i].ppn);
					printf("Author name : %s\n", bid[i].an);
					printf("Author email address : %s\n", bid[i].aea);
				}
			}
			if (flag == 0)
				printf("You entered it incorrectly\n");
			break;
		case 6:
			flag = 0;
			printf("Enter the publisher name you want to search: \n");
			scanf("%s\n", &name, 20);
			for (i = 0; i < idx; i++)
			{
				if (strcmp(name, bid[i].pn) == 0)
				{
					flag = 1;
					printf("Book name : %s\n", bid[i].bn);
					printf("Publication date : %s\n", bid[i].pd);
					printf("Ppublisher name : %s\n", bid[i].pn);
					printf("Ppublisher phone number : %s\n", bid[i].ppn);
					printf("Author name : %s\n", bid[i].an);
					printf("Author email address : %s\n", bid[i].aea);
				}
			}
			if (flag == 0)
				printf("You entered it incorrectly\n");
			break;

		case 7:
			printf("-----List of all book-----");
			for (i = 0; i < idx; i++)
			{
				printf("%s\n", bid[i].bn);
			}
			break;
		case 8:
			printf("Exit");
			break;
		default:
			printf("You entered wrong number\n");
			break;
		
		}

	} 
	while (num != 8);
	return 0;
}

