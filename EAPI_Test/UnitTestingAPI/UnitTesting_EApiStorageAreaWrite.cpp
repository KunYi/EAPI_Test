
#include "UnitTesting_EApiStorageAreaWrite.h"


using namespace testing;


AssertionResult UnitTesting_EApiStorageAreaWrite::AssertEApiStorageAreaWrite(const char* Id_exp , const char * offset_exp,uint32_t Id , uint32_t offset)
{
	uint32_t pBufLen = 32;//_assert_write.length();
	char lpBuf[33];// = (char *)malloc(32);
	memcpy(lpBuf,_assert_write.c_str(),32);
	uint32_t result = EApiStorageAreaWrite( Id , offset , lpBuf , pBufLen);
	Message msg;
	switch(result)
	{
		case EAPI_STATUS_SUCCESS:
			result = 1;
		break;
		case EAPI_STATUS_NOT_INITIALIZED:
		case EAPI_STATUS_INVALID_PARAMETER:
		case EAPI_STATUS_INVALID_BLOCK_ALIGNMENT:
		case EAPI_STATUS_INVALID_BLOCK_LENGTH:
		case EAPI_STATUS_WRITE_ERROR:
		case EAPI_STATUS_MORE_DATA:
		case EAPI_STATUS_UNSUPPORTED:
			msg << getEApiStatus(result);
			result = 0;
		break;
	}
	//free(lpBuf);
	return (result) ? AssertionSuccess() : AssertionFailure(msg);
}

void UnitTesting_EApiStorageAreaWrite::setBuffer(std::string str)
{
	_assert_write = str;
}