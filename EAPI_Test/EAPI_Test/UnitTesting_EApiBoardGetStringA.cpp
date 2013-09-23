#include <stdio.h>
#include <stdlib.h>

#include "gtest\gtest.h"

#ifndef _WIN32
#include "include/linux/EApiOs.h"
#else /* _WIN32 */
#include "include/winnt/EApiOs.h"
#endif /* _WIN32 */

#include "include/EApi.h"
// Other needed includes for system calls etc.

#include "EAPI_Unit_testing.h"

#include "UnitTesting_EApiBoardGetStringA.h"

#include "EAPI_Testing_define.h"

using namespace testing;


AssertionResult UnitTesting_EApiBoardGetStringA::AssertEApiBoardGetStringA(const char* Id_exp,uint32_t Id){

	uint32_t pBufLen = UNIT_TESTING_CHAR_LENGTH;
	char * lpBuf = (char *)malloc( pBufLen );
	uint32_t result = EApiBoardGetStringA( Id , lpBuf , &pBufLen );
	Message msg;
	switch(result)
	{
		case EAPI_STATUS_SUCCESS:
		break;
		case EAPI_STATUS_MORE_DATA:
		break;
		case EAPI_STATUS_UNSUPPORTED:
		break;
	}
	msg << lpBuf;

	free(lpBuf);
	return AssertionSuccess();
}
TEST_F(UnitTesting_EApiBoardGetStringA , EApiBoardGetStringA_ID_BoardManufacturer)
{
	EXPECT_PRED_FORMAT1(AssertEApiBoardGetStringA,EAPI_ID_BOARD_MANUFACTURER_STR);
}
TEST_F(UnitTesting_EApiBoardGetStringA , EApiBoardGetStringA_ID_BoardName)
{
	EXPECT_PRED_FORMAT1(AssertEApiBoardGetStringA,EAPI_ID_BOARD_NAME_STR);
}
TEST_F(UnitTesting_EApiBoardGetStringA , EApiBoardGetStringA_ID_BoardSerial)
{
	EXPECT_PRED_FORMAT1(AssertEApiBoardGetStringA,EAPI_ID_BOARD_SERIAL_STR);
}
TEST_F(UnitTesting_EApiBoardGetStringA , EApiBoardGetStringA_ID_BoardRevision)
{
	EXPECT_PRED_FORMAT1(AssertEApiBoardGetStringA,EAPI_ID_BOARD_BIOS_REVISION_STR);
}
TEST_F(UnitTesting_EApiBoardGetStringA , EApiBoardGetStringA_ID_BoardPlatformType)
{
	EXPECT_PRED_FORMAT1(AssertEApiBoardGetStringA,EAPI_ID_BOARD_PLATFORM_TYPE_STR);
}

TEST_P(UnitTesting_EApiBoardGetStringA, EApiBoardGetStringA_ID_All)
{
	uint32_t n =  GetParam();
    EXPECT_PRED_FORMAT1( AssertEApiBoardGetStringA , n );
}

INSTANTIATE_TEST_CASE_P( EAPI_Unit_testing , UnitTesting_EApiBoardGetStringA , testing::Values( 
																				EAPI_ID_BOARD_MANUFACTURER_STR , EAPI_ID_BOARD_NAME_STR , 
																				EAPI_ID_BOARD_SERIAL_STR , EAPI_ID_BOARD_BIOS_REVISION_STR
																				) );