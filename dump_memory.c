#include <stdio.h>
#include <stdint.h>

#define D(s...)	printf(s)

typedef unsigned char	UINT8;
typedef	unsigned short	UINT16;

void memory_dump32(const void *memory, size_t size)
{
    const uint32_t *data = (const uint32_t *)memory;
    size_t num_elements = size / 4; // 4바이트 단위로 계산

    printf("Address          Data\n");
    printf("-------------------------------------------------------------\n");

    for (size_t i = 0; i < num_elements; i++)
    {
        if (i % 4 == 0)
        { // 4개씩 출력
            printf("0x%08X  ", (unsigned int)((uintptr_t)data + i * 4));
        }

        printf("%08X ", data[i]);

        if ((i + 1) % 4 == 0 || i == num_elements - 1)
        {
            printf("\n");
        }
    }
}

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
