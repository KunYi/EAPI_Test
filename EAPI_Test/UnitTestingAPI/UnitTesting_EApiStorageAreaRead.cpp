#include "UnitTesting_EapiStorageAreaRead.h"

using namespace testing;

UnitTesting_EapiStorageAreaRead::UnitTesting_EapiStorageAreaRead()
{
	pbuff = NULL;
}

AssertionResult UnitTesting_EapiStorageAreaRead::AssertEapiStorageAreaRead(const char* Id_exp,const char* Offset_exp,uint32_t Id,uint32_t Offset)
{
	uint32_t BufLen = UNIT_TESTING_SMC_MAX_BYTES_READ;
	uint32_t ByteCnt = UNIT_TESTING_SMC_MAX_BYTES_READ;
	uint32_t result = EApiStorageAreaRead(Id,Offset,pbuff,BufLen,ByteCnt);
	Message msg;
	switch(result)
	{
		case EAPI_STATUS_SUCCESS:
			result = 1;
		break;
		case EAPI_STATUS_NOT_INITIALIZED:
		case EAPI_STATUS_MORE_DATA:
		case EAPI_STATUS_INVALID_BLOCK_LENGTH:
		case EAPI_STATUS_READ_ERROR:
		case EAPI_STATUS_UNSUPPORTED:
			msg << getEApiStatus(result);
			result = 0;
		break;
	}

	return (result) ? AssertionSuccess() : AssertionFailure(msg);
}

void UnitTesting_EapiStorageAreaRead::set_pbuff(char *buff)
{
	pbuff = buff;
}