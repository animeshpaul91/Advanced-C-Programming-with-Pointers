#include<stdio.h>
#include<conio.h>
#include<string.h>
int main()
{
	FILE *fp1;
	char ch;
	char *pch;
	int n,i,count,count1,j=0;
	char arr1[10],arr2[10],arr3[10],arr4[10],temp[50],temp2[50];
	char used1[2][10],used2[2][10],used3[2][10];
	char call[4][10];
	char mnemonics[][7]={"STOP","ADD","SUB","MULT","MOVER","MOVEM","COMP","BC","DIV","READ","PRINT"};
	fp1=fopen("input.txt","r");
	while((ch=fgetc(fp1))!=EOF)
	{
		printf("%c",ch);
	}
	fclose(fp1);
	fp1=fopen("input.txt","r");
	printf("\n\n\nEnter the macro call:\n");
	gets(temp2);
	pch = strtok (temp2," ");
	while (pch != NULL)
	{
	strcpy(call[j++],pch);
	pch = strtok (NULL, " ");
	}
	printf("\n\nThe expanded form:\n");
	while((fgets(temp,50,fp1))!=NULL)
	{
		n=0;
		n=sscanf(temp,"%s%s%s%s",arr1,arr2,arr3,arr4);
		switch(n)
		{
		case 4:
			count=0;
			for(i=0;i<11;i++)
			{
				if(strcmp(arr1,mnemonics[i])==0)
				count++;
			}
			if(count==0)
			{
				strcpy(used1[0],arr2);
				strcpy(used2[0],arr3);
				strcpy(used3[0],arr4);
				strcpy(used1[1],call[1]);
				strcpy(used2[1],call[2]);
				strcpy(used3[1],call[3]);
		}
			break;
		case 3:
			if(((strcmp(arr2,used1[0]))==0)&&(strcmp(arr3,used2[0])==0))
			printf("\n + %s %s, %s",arr1,used1[1],used2[1]);
			 if(((strcmp(arr2,used1[0]))==0)&&(strcmp(arr3,used3[0])==0))
			printf("\n + %s %s, %s",arr1,used1[1],used3[1]);
		 	if(((strcmp(arr2,used2[0]))==0)&&(strcmp(arr3,used1[0])==0))
			printf("\n + %s %s, %s",arr1,used2[1],used1[1]);
		 	if(((strcmp(arr2,used2[0]))==0)&&(strcmp(arr3,used3[0])==0))
			printf("\n + %s %s, %s",arr1,used2[1],used3[1]);
			 if(((strcmp(arr2,used3[0]))==0)&&(strcmp(arr3,used1[0])==0))
			printf("\n + %s %s, %s",arr1,used3[1],used1[1]);
			 if(((strcmp(arr2,used3[0]))==0)&&(strcmp(arr3,used2[0])==0))
			printf("\n + %s %s, %s",arr1,used3[1],used2[1]);
			break;
			

	}
}
	getch();
	return 0;
}
