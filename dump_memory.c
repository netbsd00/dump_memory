#include <stdio.h>

#define D(s...)	printf(s)

typedef unsigned char	UINT8;
typedef	unsigned short	UINT16;

void dump_memory(const UINT8 *data_ptr, const UINT16 size) {
	UINT16 i = 0;

	D("\n\n\n");
	D("==================== DUMP START ====================\n");
	D("start addr = %x, size=%d\n", &data_ptr[0], size);
	D("----------------------------------------\n");

	for(i=0; i<size; i++) {
		if((i % 20) == 0) {
			D("\n%08x : ", &data_ptr[i]);
		}

		D("%02x ", data_ptr[i]);
	}

	D("\n====================  DUMP END  ====================\n");
}

int main() {
	static char buf[128] = {0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x70, 0x71, 0x00};
	static int number = 44123213;

	dump_memory((UINT8 *)buf, 128);
	dump_memory((UINT8 *)&number, sizeof(number));
	
	return 0;
}
