#ifndef UNITTESTING_EAPIBOARDGETSTRINGA_H_
#define UNITTESTING_EAPIBOARDGETSTRINGA_H_
#pragma once
#include "EAPI_Unit_testing.h"
class UnitTesting_EApiBoardGetStringA :
	public EAPI_Unit_testing
{
public:
	testing::AssertionResult AssertEApiBoardGetStringA(const char* Id_exp,uint32_t Id);
};
#endif
