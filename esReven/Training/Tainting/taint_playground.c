#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h> 

#ifdef WIN32   //WINDOWS
	#include <windows.h>
#else          //*NIX
	#include <unistd.h>
#endif

// Sample program to compile and record with esReven
// Please compile it with debug symbols:
// `gcc -o taint_playground taint_playground.c -O0 -g -static`
// `x86_64-w64-mingw32-gcc -o taint_playground.exe taint_playground.c -O0 -g -static`
//

int global;

typedef struct ComplexData
{
	char data[0x100];
	int value;
	char more_data[0x1000 - 0x100 - 1];
} ComplexData;

void init() 
{
	srand(time(NULL));
	global = rand();
}

void flush()
{
	fflush(0);

	// Just flushing not enough: try to make us wait a bit so our window gets
	// refreshed & the printf actually shows up.
#ifdef WIN32
    Sleep(200);
#else
	sleep(0.2);
#endif
}

int get_global()
{
	return global;
}

void simple_case(int value)
{
	printf("simple_case output: %d\n", value);
}

ComplexData* complex_case_init(int value)
{
	ComplexData* data = (ComplexData*)malloc(sizeof(ComplexData));
	data->value = value;
	return data;
}

ComplexData* complex_case_copy(const ComplexData* source)
{
	ComplexData* data = (ComplexData*)malloc(sizeof(ComplexData));
	memcpy(data, source, sizeof(ComplexData));
	return data;
}

void complex_case_transform(ComplexData* data)
{
	data->value /= 2;
}

ComplexData* complex_case_use(const ComplexData* data)
{
	printf("complex_case_use output: %d\n", data->value);
}

int main(int argc, char* argv[]) 
{
	init();

	int global = get_global();
	simple_case(global);

	ComplexData* data = complex_case_init(global);
	ComplexData* copy = complex_case_copy(data);
	complex_case_transform(copy);
	complex_case_use(copy);

	free(data);
	free(copy);

	flush();
	return 0;
}
