
#include "UnitTesting_EApiBoardGetStringA.h"

using namespace testing;

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
																				EAPI_ID_BOARD_SERIAL_STR , EAPI_ID_BOARD_BIOS_REVISION_STR ,
																				EAPI_ID_BOARD_PLATFORM_TYPE_STR
																				) );