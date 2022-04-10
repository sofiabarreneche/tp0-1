/*
 * test.c
 *
 *  Created on: 10 abr. 2022
 *      Author: utnso
 */
#include "test.h"

int main(){

	CU_initialize_registry();
		CU_pSuite prueba = CU_add_suite("Suitedeprueba",NULL,NULL);
		CU_add_test( prueba, "uno", test1);
		CU_add_test( prueba, "dos", test2);
		CU_add_test( prueba, "tres", test3);

		CU_basic_set_mode(CU_BRM_VERBOSE);
		CU_basic_run_tests();
		CU_cleanup_registry();
		return CU_get_error();
}

/*CIUNIT PRUEBA*/

void test1()
{
printf("Soyeltest1!,yprueboque2seaiguala1+1");
CU_ASSERT_EQUAL(1+1,2);
}

void test2()
{
printf("Soyeltest2!,ydoysegmentationfault");
char*ptr=NULL;
*ptr=9;
}

void test3()
{
printf("Soyeltest3!");
}


