
#include "EAPI_Unit_testing.h"

using namespace testing;

void EAPI_Unit_testing::SetUp(void)
{
	uint32_t result = EApiLibInitialize();
}


void EAPI_Unit_testing::TearDown(void)
{
	EApiLibUnInitialize();
}

std::string EAPI_Unit_testing::getEApiId(uint32_t Id)
{
	return _getEApiId(Id);
}

std::string EAPI_Unit_testing::getEApiStatus(uint32_t status)
{
	return _getEApiStatus(status);
}

std::string EAPI_Unit_testing::_getEApiStatus(uint32_t status)
{
	switch(status)
	{
	case EAPI_STATUS_NOT_INITIALIZED:
		return UNIT_TESTING_EAPI_STATUS_NOT_INITIALIZED;
	case EAPI_STATUS_INITIALIZED:
		return UNIT_TESTING_EAPI_STATUS_INITIALIZED;
	case EAPI_STATUS_SUCCESS:
		return UNIT_TESTING_EAPI_STATUS_SUCCESS;
	case EAPI_STATUS_ERROR:
		return UNIT_TESTING_EAPI_STATUS_ERROR;
	case EAPI_STATUS_MORE_DATA:
		return UNIT_TESTING_EAPI_STATUS_MORE_DATA;
	case EAPI_STATUS_UNSUPPORTED:
		return UNIT_TESTING_EAPI_STATUS_UNSUPPORTED;
	}
	return "NULL";
}
std::string EAPI_Unit_testing::_getEApiId(uint32_t Id)
{
	switch(Id)
	{
	case EAPI_ID_BOARD_MANUFACTURER_STR: 
		return UNIT_TESTING_EAPI_ID_BOARD_MANUFACTURER_STR;
	case EAPI_ID_BOARD_NAME_STR: 
		return UNIT_TESTING_EAPI_ID_BOARD_NAME_STR;
	case EAPI_ID_BOARD_SERIAL_STR: 
		return UNIT_TESTING_EAPI_ID_BOARD_SERIAL_STR;
	case EAPI_ID_BOARD_BIOS_REVISION_STR: 
		return UNIT_TESTING_EAPI_ID_BOARD_BIOS_REVISION_STR;
	case EAPI_ID_BOARD_PLATFORM_TYPE_STR: 
		return UNIT_TESTING_EAPI_ID_BOARD_PLATFORM_TYPE_STR;
	}
	return "NULL";
}
AssertionResult EAPI_Unit_testing::AssertEApiLibInitialize(const char* status_exp,uint32_t status)
{
	uint32_t result = EApiLibInitialize();
	Message msg;
	switch(result)
	{
	case EAPI_STATUS_NOT_INITIALIZED:
		msg << "EApiLib Initialize is Fail , EAPI_STATUS : " << this->_getEApiStatus(result) << " ( " << result <<" ) ";
		return (result == status)?AssertionSuccess():AssertionFailure(msg);
	case EAPI_STATUS_INITIALIZED:
		msg << "EApiLib Initialize is Fail , EAPI_STATUS : " << this->_getEApiStatus(result) << " ( " << result <<" ) ";
		return (result == status)?AssertionSuccess():AssertionFailure(msg);
	case EAPI_STATUS_SUCCESS:
		msg << "EApiLib Initialize is Fail , EAPI_STATUS : " << this->_getEApiStatus(result) << " ( " << result <<" ) ";
		return (result == status)?AssertionSuccess():AssertionFailure(msg);
	case EAPI_STATUS_ERROR:
		msg << "EApiLib Initialize is Fail , EAPI_STATUS : " << this->_getEApiStatus(result) << " ( " << result <<" ) ";
		return (result == status)?AssertionSuccess():AssertionFailure(msg);
	}
	return AssertionFailure();
}


TEST_F( EAPI_Unit_testing , EApiLibIsInitialized )
{
	EXPECT_PRED_FORMAT1( AssertEApiLibInitialize , EAPI_STATUS_SUCCESS );
}