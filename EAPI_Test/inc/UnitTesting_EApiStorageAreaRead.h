#ifndef UNITTESTING_EAPISTORAGEAREAREAD_H_
#define UNITTESTING_EAPISTORAGEAREAREAD_H_
#pragma once
#include "EAPI_Unit_testing.h"

#define UNIT_TESTING_BUFFER1 "123"
#define UNIT_TESTING_BUFFER2 "123456"
#define UNIT_TESTING_BUFFER3 "123456789"

class UnitTesting_EapiStorageAreaRead : 
	public EAPI_Unit_testing
{
public:
	UnitTesting_EapiStorageAreaRead();
	testing::AssertionResult AssertEapiStorageAreaRead(const char* Id_exp,const char* Offset_exp ,uint32_t Id,uint32_t Offset);
	void set_pbuff(char *buff);
private:
	char *pbuff;
};

#endif