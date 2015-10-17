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
#include "sd_spi.h"
#include "assert.h"

extern char resp[0x210];

#if 0
void SD_command(unsigned char cmd, unsigned long arg, unsigned char crc, unsigned char read) {
	unsigned char i, buffer[8];
		
	//CS_ENABLE();
	SPIM_WriteTxData(cmd);
	SPIM_WriteTxData(arg>>24);
	SPIM_WriteTxData(arg>>16);
	SPIM_WriteTxData(arg>>8);
	SPIM_WriteTxData(arg);
	SPIM_WriteTxData(crc);
		
	for(i=0; i<read; i++)
		SPIM_WriteTxData(0xFF);
		buffer[i] = SPIM_ReadRxData();
		
	//CS_DISABLE();
	return 
}

char SD_command(unsigned char cmd, unsigned long arg, unsigned char crc) {	
	unsigned char retry, res;
	int i;
	uint64 com_res;
	
	 
	SPIM_SpiUartWriteTxData(cmd | 0x40);	//SD Spec: 1st bit always zero, 2nd always 1
	SPIM_SpiUartWriteTxData(arg>>24);	//first of the 4 bytes address
	SPIM_SpiUartWriteTxData(arg>>16);	//second
	SPIM_SpiUartWriteTxData(arg>>8);	//third
	SPIM_SpiUartWriteTxData(arg);	//fourth
	SPIM_SpiUartWriteTxData(crc);	//CRC and last bit 1
	
	for(i = 0; i < 20 ; i++) {
		SPIM_SpiUartWriteTxData(0xff);
		//res = SPIM_SpiUartReadRxData();
	}
		
	retry = 0;
	com_res = 0;
	res = 0;
	do {
		com_res <<=8;
		com_res |= res;
		
		SPIM_SpiUartWriteTxData(0xff);
		res = SPIM_SpiUartReadRxData();
		
		if(retry++ > 100) {
			break;  	//overtime exit.
		}
	} while(res != 0xFF);
	
	return com_res;
}
#endif

int main()
{
	char i;
	char * Read_buffer;
	int status = 0;
	
	CyGlobalIntEnable;
	
	Read_buffer = malloc(0x200);
	
	assert(Read_buffer);
	
	Clock_1_SetDivider(39);
	
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
	SPIM_Start();
	
	SD_init();

	Clock_1_SetDivider(3);
	
	//MountDisk();
	
	VVDRV_sdcc_dataRead(Read_buffer, 0x200 , 0);
	
    /* CyGlobalIntEnable; */ /* Uncomment this line to enable global interrupts. */
    for(;;)
    {
        /* Place your application code here. */
    }
}

/* [] END OF FILE */
