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
void sdCommandAndResponse(char cmd, uint32 param);
inline void  sdSendCommand(char cmd, uint32 param);
char sdCrc7(char* chr, char cnt, char crc);
inline uint8 sdReadResp(char * buffer, int length);
inline void sdReadResp_nBytes(char * buff, uint32 nBytes);
uint32 VVDRV_sdcc_dataRead(void * Read_buffer, uint32 length ,uint32  sec_num);
char SD_init();
/* [] END OF FILE */
