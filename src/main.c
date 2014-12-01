/*
 * main.c
 *
 *  Created on: Nov 29, 2014
 *      Author: jeqi
 */

#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>
#include "sql_op.h"



int main(void)
{
	int i ;

	printf("HelloWorld!!");


	COM2_Config_Check();
	for(i=0;i<Available_Address_Count;i++)
	{
		printf("Address is : %d \r\n",Available_Address[i]);
	}
	return 0;
}
