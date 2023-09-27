/*	MOVIE SCHEDULING IN A MULTIPLEX */

#include<stdio.h>         //slots 3 and 5 are time alloted for high priority movies, slots 2 and 4 are time alloted for average movies, slot 1 is for low priority movies
#include<string.h>		  // slots 4 and 5 are available only during weekends
struct movie			  //high priority movies=priority values [4,5), average priority movies=priority values [2,4), low priority movies=priority values [1,2)
{
	char movies[100];
	float cast_weightage;			//scale of 5 converted to 1.25
	float production_weightage;		//scale of 5 converted to 1.25
	float priority_score;			//scale of 5
	float success_rate;				//scale of 5(3:2 ratio) converted to 2.5 for old movies and 2.5(100 percent) for new movies
	int priority;				
}m1[100];

int count=0;			// total no. of movies running in multiplex
int counter1=0,counter2=0,counter3=0,i1,i2,i3,i4,i5;
char hp[50][20];		// high priority movies
char ap[50][20];		// average priority movies
char lp[50][20];		// low priority movies
int day=1;

struct screen
{
	char slot1[112][100];		// 16 screens * 7 days =112
	char slot2[112][100];
	char slot3[112][100];
	char slot4[112][100];
	char slot5[112][100];
}s;

char days[7][20]={"Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"};

void output()
{				// displaying the entire table using string formatting
	int ind=1;
	printf("%-15s%-15s%-30s%-30s%-30s%-30s%-30s\n","Day","Screen","Slot1","Slot2","Slot3","Slot4","Slot5");
	printf("\n");
	for (int i=1;i<17;i++){
		if (i==1)				// displaying the day at screen 1 alone
		{
			printf("%-15s%-15d%-30s%-30s%-30s%-30s%-30s\n",days[0],i,s.slot1[ind-1],s.slot2[ind-1],s.slot3[ind-1],s.slot4[ind-1],s.slot5[ind-1]);
			ind++;
		}
		else{
			printf("%-15s%-15d%-30s%-30s%-30s%-30s%-30s\n","",i,s.slot1[ind-1],s.slot2[ind-1],s.slot3[ind-1],s.slot4[ind-1],s.slot5[ind-1]);
			ind++;
		}
	}
	printf("\n");
	for (int i=1;i<17;i++){
		if (i==1)
		{
			printf("%-15s%-15d%-30s%-30s%-30s%-30s%-30s\n",days[1],i,s.slot1[ind-1],s.slot2[ind-1],s.slot3[ind-1],s.slot4[ind-1],s.slot5[ind-1]);
			ind++;
		}
		else{
			printf("%-15s%-15d%-30s%-30s%-30s%-30s%-30s\n","",i,s.slot1[ind-1],s.slot2[ind-1],s.slot3[ind-1],s.slot4[ind-1],s.slot5[ind-1]);
			ind++;
		}
	}
	printf("\n");
	for (int i=1;i<17;i++){
		if (i==1)
		{
			printf("%-15s%-15d%-30s%-30s%-30s%-30s%-30s\n",days[2],i,s.slot1[ind-1],s.slot2[ind-1],s.slot3[ind-1],s.slot4[ind-1],s.slot5[ind-1]);
			ind++;
		}
		else{
			printf("%-15s%-15d%-30s%-30s%-30s%-30s%-30s\n","",i,s.slot1[ind-1],s.slot2[ind-1],s.slot3[ind-1],s.slot4[ind-1],s.slot5[ind-1]);
			ind++;
		}
	}
	printf("\n");
	for (int i=1;i<17;i++){
		if (i==1)
		{
			printf("%-15s%-15d%-30s%-30s%-30s%-30s%-30s\n",days[3],i,s.slot1[ind-1],s.slot2[ind-1],s.slot3[ind-1],s.slot4[ind-1],s.slot5[ind-1]);
			ind++;
		}
		else{
			printf("%-15s%-15d%-30s%-30s%-30s%-30s%-30s\n","",i,s.slot1[ind-1],s.slot2[ind-1],s.slot3[ind-1],s.slot4[ind-1],s.slot5[ind-1]);
			ind++;
		}
	}
	printf("\n");
	for (int i=1;i<17;i++){
		if (i==1)
		{
			printf("%-15s%-15d%-30s%-30s%-30s%-30s%-30s\n",days[4],i,s.slot1[ind-1],s.slot2[ind-1],s.slot3[ind-1],s.slot4[ind-1],s.slot5[ind-1]);
			ind++;
		}
		else{
			printf("%-15s%-15d%-30s%-30s%-30s%-30s%-30s\n","",i,s.slot1[ind-1],s.slot2[ind-1],s.slot3[ind-1],s.slot4[ind-1],s.slot5[ind-1]);
			ind++;
		}
	}
	printf("\n");
	for (int i=1;i<17;i++){
		if (i==1)
		{
			printf("%-15s%-15d%-30s%-30s%-30s%-30s%-30s\n",days[5],i,s.slot1[ind-1],s.slot2[ind-1],s.slot3[ind-1],s.slot4[ind-1],s.slot5[ind-1]);
			ind++;
		}
		else{
			printf("%-15s%-15d%-30s%-30s%-30s%-30s%-30s\n","",i,s.slot1[ind-1],s.slot2[ind-1],s.slot3[ind-1],s.slot4[ind-1],s.slot5[ind-1]);
			ind++;
		}
	}
	printf("\n");
	for (int i=1;i<17;i++){
		if (i==1)
		{
			printf("%-15s%-15d%-30s%-30s%-30s%-30s%-30s\n",days[6],i,s.slot1[ind-1],s.slot2[ind-1],s.slot3[ind-1],s.slot4[ind-1],s.slot5[ind-1]);
			ind++;
		}
		else{
			printf("%-15s%-15d%-30s%-30s%-30s%-30s%-30s\n","",i,s.slot1[ind-1],s.slot2[ind-1],s.slot3[ind-1],s.slot4[ind-1],s.slot5[ind-1]);
			ind++;
		}
	}
	printf("\n");
}

void assign()
{
	int r1=0,r2=0,r3=0,b,day=1,ind=1;
	for(int i=0;i<count;i++)
	{
		if (m1[i].priority==2 && m1[i].priority!=3)
		{
			strcpy(hp[counter1],m1[i].movies);
			counter1++;
		}
	}
	for(int i=0;i<count;i++)
	{
		if (m1[i].priority==1 && m1[i].priority!=3)
		{
			strcpy(ap[counter2],m1[i].movies);
			counter2++;
		}
	}
	for(int i=0;i<count;i++)
	{
		if(m1[i].priority==0 && m1[i].priority!=3)
		{
			strcpy(lp[counter3],m1[i].movies);
			counter3++;
		}
	}
	printf("High priority movies are :\n");
	for(int i=0;i<counter1;i++)
		printf("%s ",hp[i]);
	printf("\nAverage priority movies are : \n");
	for(int i=0;i<counter2;i++)
		printf("%s ",ap[i]);
	printf("\nLow priority movies are : \n");
	for(int i=0;i<counter3;i++)
		printf("%s ",lp[i]);
	printf("\n");
	if (counter1>0)							// filling slots 3 and 5 (prime time slots)
	{
		while(i3<112)						//112 = 16 screens * 7 days
		{
			for(int i=0;i<counter1;i++)
			{
				strcpy(s.slot3[i3],hp[i]);
				if (i3==15 || i3==31 || i3==47 || i3==63 || i3==79 ||i3==95 || i3==111)   // end of day
					day++;
				i3++;
			}
		}
		day=1;
		while(i5<112)
		{
			for(int i=0;i<counter1;i++)
			{
				if (day==6 || day==7)					// slot 5 is active only on days 6 and 7
				{
					strcpy(s.slot5[i5], hp[i]);
					if (i5==15 || i5==31 || i5==47 || i5==63 || i5==79 ||i5==95 || i5==111)
						day++;
					i5++;
				}
				else{
					strcpy(s.slot5[i5],"NA");
					if (i5==15 || i5==31 || i5==47 || i5==63 || i5==79 ||i5==95 || i5==111)
						day++;
					i5++;
				}
			}
		}
		day=1;
	}
	else										// if high priority mivies are 0
	{
		if (counter2 == 0)						// if average priority movies are 0, printing low priority movies
		{
			while (i3 < 112)
			{
				for (int i = 0; i < counter3; i++)
				{
					strcpy(s.slot3[i3], lp[i]);
					if (i3==15 || i3==31 || i3==47 || i3==63 || i3==79 ||i3==95 || i3==111)
						day++;
					i3++;
				}
			}
			day=1;
			while (i5 < 112)
			{
				for (int i = 0; i < counter3; i++)
				{
					if (day==6 || day==7)
					{
						strcpy(s.slot5[i5], lp[i]);
						if (i5==15 || i5==31 || i5==47 || i5==63 || i5==79 ||i5==95 || i5==111)
							day++;
						i5++;
					}
					else
					{
						strcpy(s.slot5[i5], "NA");
						if (i5==15 || i5==31 || i5==47 || i5==63 || i5==79 ||i5==95 || i5==111)
							day++;
						i5++;
					}
				}
			}
			day=1;
		}
		else										// if average priority movies are not 0, printing average priority movies
		{
			while (i3 < 112)
			{
				for (int i = 0; i < counter2; i++)
				{
					strcpy(s.slot3[i3], ap[i]);
					if (i3==15 || i3==31 || i3==47 || i3==63 || i3==79 ||i3==95 || i3==111)
						day++;
					i3++;
				}
			}
			day=1;
			while (i5 < 112)
			{
				for (int i = 0; i < counter2; i++)
				{
					if (day==6 || day==7)
					{
						strcpy(s.slot5[i5], ap[i]);
						if (i5==15 || i5==31 || i5==47 || i5==63 || i5==79 ||i5==95 || i5==111)
							day++;
						i5++;
					}
					else
					{
						strcpy(s.slot5[i5], "NA");

						if (i5==15 || i5==31 || i5==47 || i5==63 || i5==79 ||i5==95 || i5==111)
							day++;
						i5++;
					}
				}
			}
			day=1;
		}
	}
	if (counter2>0)						//filling average priority slots 2 and 4
	{
		while(i4<112)
		{
			for(int i=0;i<counter2;i++)
			{
				if (day==6 || day==7)
				{
					strcpy(s.slot4[i4], ap[i]);
					if (i4==15 || i4==31 || i4==47 || i4==63 || i4==79 ||i4==95 || i4==111)
						day++;
					i4++;
				}
				else
				{
					strcpy(s.slot4[i4],"NA");
					if (i4==15 || i4==31 || i4==47 || i4==63 || i4==79 ||i4==95 || i4==111)
						day++;
					i4++;
				}
			}
		}
		day=1;
		while(i2<112)
		{
			for(int i=0;i<counter2;i++)
			{
				strcpy(s.slot2[i2],ap[i]);
				if (i2==15 || i2==31 || i2==47 || i2==63 || i2==79 ||i2==95 || i2==111)
					day++;
				i2++;
			}
		}
		day=1;
	}
	else									// if average movies are 0, printing high priority or low priority movies
	{
		if (counter1==0)					// if high priority movies are 0, printing low priority movies
		{
			while(i4<112)
			{
				for(int i=0;i<counter3;i++)
				{
					if (day==6 || day==7)
					{
						strcpy(s.slot4[i4], lp[i]);
						if (i4==15 || i4==31 || i4==47 || i4==63 || i4==79 ||i4==95 || i4==111)
							day++;
						i4++;
					}
					else
					{
						strcpy(s.slot4[i4],"NA");

						if (i4==15 || i4==31 || i4==47 || i4==63 || i4==79 ||i4==95 || i4==111)
							day++;
						i4++;
					}
				}
			}
			day=1;
			while(i2<112)
			{
				for(int i=0;i<counter3;i++)
				{
					strcpy(s.slot2[i2],lp[i]);
					if (i2==15 || i2==31 || i2==47 || i2==63 || i2==79 ||i2==95 || i2==111)
						day++;
					i2++;
				}
			}
			day=1;
		}
		else				// if high priority movies are available, filing the average priority slots with high priority movies
		{
			while(i4<112)
			{
				for(int i=0;i<counter1;i++)
				{
					if (day==6 || day==7)
					{
						strcpy(s.slot4[i4], hp[i]);
						if (i4==15 || i4==31 || i4==47 || i4==63 || i4==79 ||i4==95 || i4==111)
							day++;
						i4++;
					}
					else
					{
						strcpy(s.slot4[i4],"NA");

						if (i4==15 || i4==31 || i4==47 || i4==63 || i4==79 ||i4==95 || i4==111)
							day++;
						i4++;
					}
				}
			}
			day=1;
			while(i2<112)
			{
				for(int i=0;i<counter1;i++)
				{
					strcpy(s.slot2[i2],hp[i]);
					if (i2==15 || i2==31 || i2==47 || i2==63 || i2==79 ||i2==95 || i2==111)
						day++;
					i2++;
				}
			}
			day=1;
		}
	}
	if (counter3>0)					// filling low priority slots 
	{
		while(i1<112)
		{
			for(int i=0;i<counter3;i++)
			{
				strcpy(s.slot1[i1],lp[i]);
				if (i1==15 || i1==31 || i1==47 || i1==63 || i1==79 ||i1==95 || i1==111)
					day++;
				i1++;
			}
		}
		day=1;
	}
	else						// if low priority movies are 0, then filling its slot with high priority movies or average priority movies
	{
		if(counter1==0)			// if high priority movies are 0, then filling low priority slots with average priority movies
		{
			while(i1<112)
			{
				for(int i=0;i<counter2;i++)
				{
					strcpy(s.slot1[i1],ap[i]);
					if (i1==15 || i1==31 || i1==47 || i1==63 || i1==79 ||i1==95 || i1==111)
						day++;
					i1++;
				}
			}
			day=1;
		}
		else				// if high priority movies are available, then filling the slot 1 with high priority movies
		{
			while(i1<112)
			{
				for(int i=0;i<counter1;i++)
				{
					strcpy(s.slot1[i1],hp[i]);
					if (i1==15 || i1==31 || i1==47 || i1==63 || i1==79 ||i1==95 || i1==111)
						day++;
					i1++;
				}
			}
			day=1;
		}
	}
}

void run(){
	int c,z=0;						// c = 1 for new movie and 0 for old movie, z = total no. of movies 
	float sr1=0,sr2=0;				// success rate 1 and success rate 2
	char ch='y',q[100];
	while(ch=='y'||ch=='Y')
	{
		i1=0,i2=0,i3=0,i4=0,i5=0;					// variables initialized to be used in assign() module
		counter1=0,counter2=0,counter3=0;			// variables initialized to be used in assign() module
		printf("Enter the number of upcoming new movies: ");
		int n;										//n= no. of upcoming movies
		float priority_score=0;
		scanf("%d",&n);
		z+=n;
		for(int i=0;i<z;i++)
		{
			printf("Enter  1  for new movies , 0  old  for old movies :");
			scanf("%d",&c);
			if (c==1)
			{
				printf("Enter the name of the movie :");
				scanf("%s",m1[count].movies);
				printf("Enter the cast weightage within the range of [0-5] :");
				scanf("%f",&m1[count].cast_weightage);
				printf("Enter the prodcution weightage within the range of [0-5] :");
				scanf("%f",&m1[count].production_weightage);
				m1[count].success_rate=2.5;
				priority_score=(1.25/5*m1[count].cast_weightage+1.25/5*m1[count].production_weightage+m1[count].success_rate);
				m1[count].priority_score=priority_score;
				count+=1;
			}
			else
			{
				printf("Enter the name of the movie :");
				scanf("%s",q);
				for(int i=0;i<z;i++)
				{
					if (strcmp(q,m1[i].movies)==0)
					{
						printf("Enter the success rate out of 3 for weekends :");
						scanf("%f",&sr1);
						printf("Enter the success rate out of 2 on weekdays :");
						scanf("%f",&sr2);
						m1[i].success_rate=sr1+sr2;
						m1[i].priority_score=m1[i].success_rate;
					}
				}
			}
		}
		for(int i=0;i<z;i++)			// printing the entered values for both new and old movies
		{
			printf("The name of the movie is : %s \n",m1[i].movies);
			printf("The cast weightage for %s is : %f \n",m1[i].movies,m1[i].cast_weightage);
			printf("The production weightage for %s is : %f \n",m1[i].movies,m1[i].production_weightage);
			printf("The success rate for %s is : %f \n",m1[i].movies,m1[i].success_rate);
			printf("The priority score for the %s is : %f \n",m1[i].movies,m1[i].priority_score);
			printf("\n");
		}
		for(int i=0;i<z;i++)
		{
			if(m1[i].priority_score>=4 && m1[i].priority_score<=5)
				m1[i].priority=2;				// assigning priority value=2 for high priority movies
		}
		for(int i=0;i<z;i++)
		{
			if(m1[i].priority_score>=2 && m1[i].priority_score<4)
				m1[i].priority=1;				//assigning priority value=1 for average priority movies
		}
		for(int i=0;i<z;i++)
		{
			if(m1[i].priority_score>=1 && m1[i].priority_score<2)
				m1[i].priority=0;				//assigning priority value=0 for low priority movies
		}
		for(int i=0;i<z;i++)
		{
			if(m1[i].priority_score>=0 && m1[i].priority_score<1)
				m1[i].priority=3;				//assigning priority value=3 for movies to be removed
		}
		assign();
		output();
		printf("Press y to conitnue to next week: ");
		getchar();
		scanf("%c",&ch);
	}
}

void main()
{
	run();
}