#include "UnitTesting_EapiStorageAreaRead.h"

using namespace testing;

//test can read success or not
TEST_F(UnitTesting_EapiStorageAreaRead,EapiStorageAreaRead_READ_SUCCESS)
{
	char buff[33] = {0};
	this->set_pbuff(buff);
	ASSERT_EQ(EAPI_STATUS_SUCCESS,EApiStorageAreaWrite(EAPI_ID_STORAGE_STD,0,UNIT_TESTING_BUFFER1,32));
	EXPECT_PRED_FORMAT2(AssertEapiStorageAreaRead,EAPI_ID_STORAGE_STD,0);
	free(buff);
}

//test when write UNIT_TESTING_BUFFER1 in storage ,can read correct or not
TEST_F(UnitTesting_EapiStorageAreaRead,EapiStorageAreaRead_TRY_READ_1)
{
	char buff[33] = {0};
	this->set_pbuff(buff);
	ASSERT_EQ(EAPI_STATUS_SUCCESS,EApiStorageAreaWrite(EAPI_ID_STORAGE_STD,0,UNIT_TESTING_BUFFER1,32));
	EXPECT_PRED_FORMAT2(AssertEapiStorageAreaRead,EAPI_ID_STORAGE_STD,0);
	ASSERT_EQ(buff,UNIT_TESTING_BUFFER1);
	free(buff);
}

//test when write UNIT_TESTING_BUFFER2 in storage ,can read correct or not
TEST_F(UnitTesting_EapiStorageAreaRead,EapiStorageAreaRead_TRY_READ_2)
{
	char buff[33] = {0};
	this->set_pbuff(buff);
	ASSERT_EQ(EAPI_STATUS_SUCCESS,EApiStorageAreaWrite(EAPI_ID_STORAGE_STD,0,UNIT_TESTING_BUFFER2,32));
	EXPECT_PRED_FORMAT2(AssertEapiStorageAreaRead,EAPI_ID_STORAGE_STD,0);
	ASSERT_EQ(buff,UNIT_TESTING_BUFFER2);
	free(buff);
}

//test when write UNIT_TESTING_BUFFER3 in storage ,can read correct or not
TEST_F(UnitTesting_EapiStorageAreaRead,EapiStorageAreaRead_TRY_READ_3)
{
	char buff[33] = {0};
	this->set_pbuff(buff);
	ASSERT_EQ(EAPI_STATUS_SUCCESS,EApiStorageAreaWrite(EAPI_ID_STORAGE_STD,0,UNIT_TESTING_BUFFER3,32));
	EXPECT_PRED_FORMAT2(AssertEapiStorageAreaRead,EAPI_ID_STORAGE_STD,0);
	ASSERT_EQ(buff,UNIT_TESTING_BUFFER3);
	free(buff);
}

//test overflow check
TEST(testEapiStorageAreaRead,overflow_check)
{
	char buff[33] = {0};
	ASSERT_EQ(EAPI_STATUS_INVALID_BLOCK_LENGTH,EApiStorageAreaRead(EAPI_ID_STORAGE_STD,0,buff,32,2048));
	free(buff);
}


//test ByteCnt>BufLen
TEST(testEapiStorageAreaRead,ByteCnt_bigger_than_BufLen)
{
	char buff[33] = {0};
	ASSERT_EQ(EAPI_STATUS_INVALID_BLOCK_LENGTH,EApiStorageAreaRead(EAPI_ID_STORAGE_STD,0,buff,32,64));
	free(buff);
}