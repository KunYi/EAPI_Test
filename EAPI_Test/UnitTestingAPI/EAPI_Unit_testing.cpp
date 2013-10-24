
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
	case EAPI_STATUS_INVALID_BLOCK_ALIGNMENT:
		return UNIT_TESTING_EAPI_STATUS_INVALID_BLOCK_ALIGNMENT;
	case EAPI_STATUS_INVALID_BLOCK_LENGTH:
		return UNIT_TESTING_EAPI_STATUS_INVALID_BLOCK_LENGTH;
	case EAPI_STATUS_WRITE_ERROR:
		return UNIT_TESTING_EAPI_STATUS_WRITE_ERROR;
	case EAPI_STATUS_READ_ERROR:
		return UNIT_TESTING_EAPI_STATUS_READ_ERROR;
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