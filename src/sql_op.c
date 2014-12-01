/*
 * sql_op.c

 *
 *  Created on: Nov 30, 2014
 *      Author: jeqi
 */
#include "sqlite3.h"
//#include "pthread.h"
#include <string.h>
#include "sql_op.h"
#include <stdio.h>
#include <stdlib.h>



int Available_Address[16];
int Available_Address_Count = 0;


int COM2_Read_Address(void * para, int n_column, char ** column_value, char ** column_name)
{
	int i;
	printf("n_colum:%d\r\n",n_column);

	for (i = 0; i < n_column; i++)
	{
		if (strcmp(column_name[i], "Address") == 0)
		{

			Available_Address[Available_Address_Count] = atoi(column_value[i]);
			Available_Address_Count++;
		}
	}

	return EXIT_SUCCESS;
}

int COM2_Table_Check( char *Table_Name )
{
	sqlite3 *db = 0;
	char temp_table_name[100];
	int result;
	char **errmsg = NULL;
	result = sqlite3_open(COM2_CONFIG,&db);
	if (result != SQLITE_OK)
		{
			printf("open db: %s failed error: %d \r\n", COM2_CONFIG, result);
			return -1;
		}
	sprintf(temp_table_name,"select * from %s where Status='enable'",Table_Name);
	printf("\r\n%s",temp_table_name);

	result = sqlite3_exec(db, temp_table_name, COM2_Read_Address, NULL, errmsg);
	printf("sqlite3_exec result is :%d \r\n",result);
	return EXIT_SUCCESS;
}

int COM2_Config_Check(void)
{
	COM2_Table_Check(DAIKIN);



	return EXIT_SUCCESS;
}

