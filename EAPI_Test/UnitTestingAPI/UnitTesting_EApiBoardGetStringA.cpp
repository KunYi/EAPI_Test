
#include "UnitTesting_EApiBoardGetStringA.h"


using namespace testing;


AssertionResult UnitTesting_EApiBoardGetStringA::AssertEApiBoardGetStringA(const char* Id_exp,uint32_t Id)
{
	uint32_t pBufLen = UNIT_TESTING_CHAR_LENGTH;
	char * lpBuf = (char *)malloc( pBufLen );
	uint32_t result = EApiBoardGetStringA( Id , lpBuf , &pBufLen );
	Message msg;
	switch(result)
	{
		case EAPI_STATUS_SUCCESS:
			result = 1;
		break;
		case EAPI_STATUS_NOT_INITIALIZED:
		case EAPI_STATUS_MORE_DATA:
		case EAPI_STATUS_UNSUPPORTED:
			msg << getEApiStatus(result);
			result = 0;
		break;
	}
	//msg << lpBuf;

	free(lpBuf);

	return (result) ? AssertionSuccess() : AssertionFailure(msg);
}
