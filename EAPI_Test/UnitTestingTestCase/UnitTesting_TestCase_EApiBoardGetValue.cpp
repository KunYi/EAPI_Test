#include "UnitTesting_EApiBoardGetValue.h"

using namespace testing;

TEST_F(UnitTesting_EApiBoardGetValue,EApiBoardGetValue_ID_GET_EAPI_SPEC_VERSION)
{
	EXPECT_PRED_FORMAT1(AssertEApiBoardGetValue,EAPI_ID_GET_EAPI_SPEC_VERSION);
}


TEST_F(UnitTesting_EApiBoardGetValue,EApiBoardGetValue_ID_BOARD_BOOT_COUNTER_VAL)
{
	EXPECT_PRED_FORMAT1(AssertEApiBoardGetValue,EAPI_ID_BOARD_BOOT_COUNTER_VAL);
}

TEST_F(UnitTesting_EApiBoardGetValue,EApiBoardGetValue_ID_BOARD_RUNNING_TIME_METER_VAL)
{
	EXPECT_PRED_FORMAT1(AssertEApiBoardGetValue,EAPI_ID_BOARD_RUNNING_TIME_METER_VAL);
}

TEST_F(UnitTesting_EApiBoardGetValue,EApiBoardGetValue_ID_BOARD_PNPID_VAL)
{
	EXPECT_PRED_FORMAT1(AssertEApiBoardGetValue,EAPI_ID_BOARD_PNPID_VAL);
}

TEST_F(UnitTesting_EApiBoardGetValue,EApiBoardGetValue_ID_BOARD_PLATFORM_REV_VAL)
{
	EXPECT_PRED_FORMAT1(AssertEApiBoardGetValue,EAPI_ID_BOARD_PLATFORM_REV_VAL);
}

TEST_F(UnitTesting_EApiBoardGetValue,EApiBoardGetValue_ID_BOARD_DRIVER_VERSION_VAL)
{
	EXPECT_PRED_FORMAT1(AssertEApiBoardGetValue,EAPI_ID_BOARD_DRIVER_VERSION_VAL);
}

TEST_F(UnitTesting_EApiBoardGetValue,EApiBoardGetValue_ID_BOARD_LIB_VERSION_VAL)
{
	EXPECT_PRED_FORMAT1(AssertEApiBoardGetValue,EAPI_ID_BOARD_LIB_VERSION_VAL);
}

TEST_F(UnitTesting_EApiBoardGetValue,EApiBoardGetValue_ID_HWMON_CPU_TEMP)
{
	EXPECT_PRED_FORMAT1(AssertEApiBoardGetValue,EAPI_ID_HWMON_CPU_TEMP);
}

TEST_F(UnitTesting_EApiBoardGetValue,EApiBoardGetValue_ID_HWMON_SYSTEM_TEMP)
{
	EXPECT_PRED_FORMAT1(AssertEApiBoardGetValue,EAPI_ID_HWMON_SYSTEM_TEMP);
}

TEST_F(UnitTesting_EApiBoardGetValue,EApiBoardGetValue_ID_HWMON_FAN_CPU)
{
	EXPECT_PRED_FORMAT1(AssertEApiBoardGetValue,EAPI_ID_HWMON_FAN_CPU);
}

TEST_F(UnitTesting_EApiBoardGetValue,EApiBoardGetValue_ID_HWMON_FAN_SYSTEM)
{
	EXPECT_PRED_FORMAT1(AssertEApiBoardGetValue,EAPI_ID_HWMON_FAN_SYSTEM);
}

TEST_F(UnitTesting_EApiBoardGetValue,EApiBoardGetValue_ID_HWMON_VOLTAGE_VCORE)
{
	EXPECT_PRED_FORMAT1(AssertEApiBoardGetValue,EAPI_ID_HWMON_VOLTAGE_VCORE);
}

TEST_F(UnitTesting_EApiBoardGetValue,EApiBoardGetValue_ID_HWMON_VOLTAGE_2V5)
{
	EXPECT_PRED_FORMAT1(AssertEApiBoardGetValue,EAPI_ID_HWMON_VOLTAGE_2V5);
}

TEST_F(UnitTesting_EApiBoardGetValue,EApiBoardGetValue_ID_HWMON_VOLTAGE_3V3)
{
	EXPECT_PRED_FORMAT1(AssertEApiBoardGetValue,EAPI_ID_HWMON_VOLTAGE_3V3);
}

TEST_F(UnitTesting_EApiBoardGetValue,EApiBoardGetValue_ID_HWMON_VOLTAGE_5V)
{
	EXPECT_PRED_FORMAT1(AssertEApiBoardGetValue,EAPI_ID_HWMON_VOLTAGE_5V);
}

TEST_F(UnitTesting_EApiBoardGetValue,EApiBoardGetValue_ID_HWMON_VOLTAGE_12V)
{
	EXPECT_PRED_FORMAT1(AssertEApiBoardGetValue,EAPI_ID_HWMON_VOLTAGE_12V);
}

TEST_F(UnitTesting_EApiBoardGetValue,EApiBoardGetValue_ID_HWMON_VOLTAGE_5VSB)
{
	EXPECT_PRED_FORMAT1(AssertEApiBoardGetValue,EAPI_ID_HWMON_VOLTAGE_5VSB);
}

TEST_F(UnitTesting_EApiBoardGetValue,EApiBoardGetValue_ID_HWMON_VOLTAGE_VBAT)
{
	EXPECT_PRED_FORMAT1(AssertEApiBoardGetValue,EAPI_ID_HWMON_VOLTAGE_VBAT);
}

TEST_F(UnitTesting_EApiBoardGetValue,EApiBoardGetValue_ID_HWMON_CHIPSET_TEMP)
{
	EXPECT_PRED_FORMAT1(AssertEApiBoardGetValue,EAPI_ID_HWMON_CHIPSET_TEMP);
}

/*TEST_P(UnitTesting_EApiBoardGetValue, EApiBoardGetValue_ID_All)
{
	uint32_t n =  GetParam();
    EXPECT_PRED_FORMAT1( AssertEApiBoardGetValue , n );
}*/
