/*
 * sql_op.h
 *
 *  Created on: Nov 30, 2014
 *      Author: jeqi
 */

#ifndef SQL_OP_H_
#define SQL_OP_H_

#define COM2_CONFIG "/home/jeqi/git/GD_DataBase/NEW/2/COM2_Config.db"
#define DAIKIN "DAIKIN_Register"
#define DARKIN_OFFSET 20

extern int Available_Address[16];
extern int Available_Address_Count;

int COM2_Config_Check(void);
#endif /* SQL_OP_H_ */
