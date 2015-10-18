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

char Read_buffer_1[0x200], padding[20],  Read_buffer_2[0x200];
	
void sys_init() {
	int status = 0;
	//Set SD card clock to 10 MHz.
	Clock_1_SetDivider(39);			//Source clock 400KHz. Divider setting 39 (+ 1)
	
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
	SPIM_Start();
	status = SD_init();
	
	//Not able to init SD card.
	assert(status == 0);
	
	//Boost the SD card clocks to 100 MHz.
	Clock_1_SetDivider(3);			//Source clock 400KHz. Divider setting 3 (+ 1).
}

int main()
{
	int i =0;
	volatile int j = 0, pass = 0, fail = 0;
	
	//Global interrupt enable.
	CyGlobalIntEnable;
	
	sys_init();
	
	//initiate data pattern.
	for (j =0; j < 0x200; j++) {
		Read_buffer_1[j] = (char)j;
	}
	
	//MountDisk();
	for (j =0; j < 100; j++) {
		SD_Sector_Write(Read_buffer_1, j);
		SD_Sector_Read(Read_buffer_2, j);
		
		if (0 == memcmp(Read_buffer_1, Read_buffer_2, 0x200))
			pass++;
		else 
			fail++;
	}
	
    for(;;)
    {
        /* Place your application code here. */
    }
}

/* [] END OF FILE */
