#include <stdio.h>

int day_of_year(int year, int month, int day);
int month_day(int year, int yearday, int *pmonth, int *pday);

static int daytable[2][13] = {
	{0,31,28,31,30,31,30,31,31,30,31,30,31},
	{0,31,29,31,30,31,30,31,31,30,31,30,31}
};

int main(){
	printf("%d\n",day_of_year(2013,3,1));
	int month, day;
	month_day(2013,32,&month, &day);
	printf("%d, %d", month, day);
	return 0;
}


int day_of_year(int year, int month, int day){
	int leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
	int i, yearday;
	yearday = 0;
	int *p = &daytable[leap][0];
	for(i = 0; i < month; i++){
		yearday += *(p+i);
	}
	yearday += day;
	return yearday;
}

int month_day(int year, int yearday, int *pmonth, int *pday){

	int leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
	*pmonth = *pday = 0;
	int *p = &daytable[leap][0];
	while(yearday > *(p+*pmonth)){
		yearday -= *(p+*pmonth);
		(*pmonth)++;
	}
	*pday = yearday;
}

