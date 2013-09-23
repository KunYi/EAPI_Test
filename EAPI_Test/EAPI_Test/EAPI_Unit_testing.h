#pragma once
#include "gtest\gtest.h"

#define UNIT_TESTING_CHAR_LENGTH 1024

/** *
 **	EApi's Statuses
 ** */
#define UNIT_TESTING_EAPI_STATUS_NOT_INITIALIZED	"EAPI_STATUS_NOT_INITIALIZED"
#define UNIT_TESTING_EAPI_STATUS_INITIALIZED		"EAPI_STATUS_INITIALIZED"
#define UNIT_TESTING_EAPI_STATUS_SUCCESS			"EAPI_STATUS_SUCCESS"
#define UNIT_TESTING_EAPI_STATUS_ERROR				"EAPI_STATUS_ERROR"

#define UNIT_TESTING_EAPI_STATUS_NOT_INITIALIZED	"EAPI_STATUS_NOT_INITIALIZED"
#define UNIT_TESTING_EAPI_STATUS_INVALID_PARAMETER	"EAPI_STATUS_INVALID_PARAMETER"
#define UNIT_TESTING_EAPI_STATUS_UNSUPPORTED		"EAPI_STATUS_UNSUPPORTED"
#define UNIT_TESTING_EAPI_STATUS_MORE_DATA			"EAPI_STATUS_MORE_DATA"

/** *
 **	EApi's IDs
 ** */
#define UNIT_TESTING_EAPI_ID_BOARD_MANUFACTURER_STR		"EAPI_ID_BOARD_MANUFACTURER_STR"
#define UNIT_TESTING_EAPI_ID_BOARD_NAME_STR				"EAPI_ID_BOARD_NAME_STR"
#define UNIT_TESTING_EAPI_ID_BOARD_SERIAL_STR			"EAPI_ID_BOARD_SERIAL_STR"
#define UNIT_TESTING_EAPI_ID_BOARD_BIOS_REVISION_STR	"EAPI_ID_BOARD_BIOS_REVISION_STR"
#define UNIT_TESTING_EAPI_ID_BOARD_PLATFORM_TYPE_STR	"EAPI_ID_BOARD_PLATFORM_TYPE_STR"

class EAPI_Unit_testing :
	public testing::TestWithParam<uint32_t>
{
public:
	virtual void SetUp(void);
	virtual void TearDown(void);

	testing::AssertionResult AssertEApiLibInitialize(const char* status_exp,uint32_t status);
	testing::AssertionResult AssertEApiBoardGetStringA(const char* Id_exp,uint32_t Id);

private:
	std::string _getEApiStatus(uint32_t status);
	std::string _getEApiId(uint32_t Id);
};
class EAPI_Unit_testing_All :
	public EAPI_Unit_testing
{

};

