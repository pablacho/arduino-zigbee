/*
	blablabla librería para zigbee
	
	por Pablo Mantovani
	GTFO
*/

#ifndef	zigbee_h
#define zigbee_h

#include "Arduino.h"

// defines de ZigBee

// Frame types
#define AT_COMMAND                            0x08
#define AT_COMMAND_QUEUE_REGISTER_VALUE       0x09
#define TRANSMIT_REQUEST                      0x10
#define EXPLICIT_ADDRESSING_COMMAND_FRAME     0x11
#define REMOTE_AT_COMMAND                     0x17
#define CREATE_SOURCE_ROUTE                   0x21
#define REGISTER_JOINING_DEVICE               0x24
#define AT_COMMAND_RESPONSE                   0x88
#define MODEM_STATUS                          0x8A
#define TRANSMIT_STATUS                       0x8B
#define EXPLICIT_RX_INDICATOR                 0x91
#define IO_DATA_SAMPLE_RX_INDICATOR           0x92
#define XBEE_SENSOR_READ_INDICATOR            0x95
#define REMOTE_AT_COMMAND_RESPONSE            0x97
#define EXTENDED_MODEM_STATUS                 0x98
#define OVER_THE_AIR_FIRMWARE_UPDATE_STATUS   0xA0
#define ROUTE_RECORD_INDICATOR                0xA1
#define MANY_TO_ONE_ROUTE_REQUEST_INDICATOR   0xA3
#define JOIN_NOTIFICATION_STATUS              0xA5

// comandos
#define ptoD0                 {'D','0'}     
#define ptoD1                 {'D','1'}     
#define ptoD2                 {'D','2'}     
#define ptoD3                 {'D','3'}     
#define ptoD4                 {'D','4'}     
#define ptoD5                 {'D','5'}     
#define ptoD6                 {'D','6'}     
#define ptoP0                 {'P','0'}     
#define ptoP1                 {'P','1'}     
#define ptoP2                 {'P','2'}     
#define resetCMD              {'F','R'}     

// estados
#define digOutLow       0x04
#define digOutHigh      0x05
#define askStatus       0x00

class zBee {
	public:
		zBee(Stream &serial);	// inicializa local en puerto serie
		bool createMsg();
		bool interpretMsg();
		bool sendMsg();
		bool readMsg();
		uint8_t selfMAC[8];
		uint8_t currentMAC[8];
		
	private:
		long _calcChecksum();
		void _mac2Array(unsigned long macHigh, unsigned long macLow, byte answer[]);
		void _clearBuffer();
}

#endif //zigbee_h
