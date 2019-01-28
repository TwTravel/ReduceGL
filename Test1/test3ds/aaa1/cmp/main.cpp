#include <stdio.h>
#include <stdlib.h>
#include "3DS.h"

int main()
{
	t3DModel pModel; //char *strFileName);
	CLoad3DS ModelLoader;
	ModelLoader.Import3DS( &pModel, "Audi_S3.3DS");
	printf("hello world!\n");
	return 1;
}