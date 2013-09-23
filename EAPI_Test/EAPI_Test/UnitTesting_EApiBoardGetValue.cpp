#include "stdlib.h"
#include "stdio.h"
#include "gtest\gtest.h"
#include "UnitTesting_EApiBoardGetValue.h"

using namespace testing;

AssertionResult UnitTesting_EApiBoardGetValue::AssertEApiBoardGetValue(const char* Id_exp,uint32_t Id)
{
	uint32_t pValueLen = UNIT_TESTING_UINT_LENGTH;
	uint32_t *pValue = (uint32_t *)malloc(pValueLen);
	uint32_t result = EApiBoardGetValue(Id,pValue);
	Message msg;
	switch (result)
	{
	case EAPI_STATUS_SUCCESS: 
		result = 1;
		break;
	case EAPI_STATUS_UNSUPPORTED:
		msg << getEApiStatus(result);
		result = 0;
		break;
	default:
		break;
	}
	return (result) ? AssertionSuccess() : AssertionFailure(msg);;
}