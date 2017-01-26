#pragma once

#include <3ds.h>

#define NETWORK_WLANCOMMID 0x11441850
#define NETWORK_PASSPHRASE "minicraft3ds localplay passphrase"
#define NETWORK_CHANNEL 1

#define NETWORK_RECVBUFSIZE UDS_DEFAULT_RECVBUFSIZE

#define NETWORK_MAXPLAYERS UDS_MAXNODES

//TODO: Every other packet struct should start with a u8 type to match this
typedef struct {
	u8 type;
} packetAnalyze;

typedef struct {
	union {
		packetAnalyze analyze;
		
	};
} networkPacket;

void networkInit();
void networkExit();

bool networkAvailable();

bool networkHost();
void networkScan();
int networkGetScanCount();
bool networkGetScanName(char *name, int pos); //TODO: Name should be long enough to handle all allowed names (char[256])
bool networkConnect(int pos);
void networkDisconnect();

bool networkConnected();

void networkSend(networkPacket *packet, size_t size); //TODO: Should this be a pointer? Calling function needs to cleanup itself
void networkRecieve(); //TODO: Should recieve actually handle all the packets or just return them?
