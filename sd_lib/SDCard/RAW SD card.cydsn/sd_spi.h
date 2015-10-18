/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include <project.h>
#define len(x) (sizeof(x)/sizeof(x[0]))

typedef enum status{
	PASS = 0,
	FAILURE
}STATUS;

//Private functions.
static char sdSpiByte(char data);
static uint8 sdReadResp(char * buffer, int length);
static void sdReadResp_nBytes(char * buff, uint32 nBytes);
static char sdCrc7(char* chr,char cnt,char crc);
static void sdSendCommand(char cmd, uint32 param);
static void sdCommandAndResponse(char cmd, uint32 param);

//Global functions.
uint32 SD_Sector_Read(void * Read_buffer, uint32  sec_num);
uint32 SD_Sector_Write(void * Write_buffer ,uint32  sec_num);
int SD_init();
/* [] END OF FILE */
