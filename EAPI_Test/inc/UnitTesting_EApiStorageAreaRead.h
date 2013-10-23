#ifndef UNITTESTING_EAPISTORAGEAREAREAD_H_
#define UNITTESTING_EAPISTORAGEAREAREAD_H_
#pragma once
#include "EAPI_Unit_testing.h"

class UnitTesting_EapiStorageAreaRead : 
	public EAPI_Unit_testing
{
public:
	testing::AssertionResult AssertEapiStorageAreaRead(const char* Id_exp,const char* Offset_exp ,uint32_t Id,uint32_t Offset);
}

#endif