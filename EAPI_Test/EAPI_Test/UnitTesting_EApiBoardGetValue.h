#ifndef UNITTESTING_EAOIBOARDGETVALUE_H
#define UNITTESTING_EAOIBOARDGETVALUE_H

#include "EAPI_Unit_testing.h"

class UnitTesting_EApiBoardGetValue :
	public EAPI_Unit_testing
{
public:
	testing::AssertionResult AssertEApiBoardGetValue(const char* Id_exp,uint32_t Id);
};

#endif 