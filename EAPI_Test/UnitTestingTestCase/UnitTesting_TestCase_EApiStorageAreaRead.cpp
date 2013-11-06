#include "UnitTesting_EapiStorageAreaRead.h"

using namespace testing;

//test can read success or not
TEST_F(UnitTesting_EapiStorageAreaRead,EapiStorageAreaRead_READ_SUCCESS)
{
		char buff[33] = {0};
		std::string pstr = std::string(UNIT_TESTING_BUFFER1);
		std::string  bpstr;
		uint32_t pBufLen = 32;//_assert_write.length();
		char lpBuf[33];// = (char *)malloc(32);
		memcpy(lpBuf, pstr.c_str() ,32);

		this->set_pbuff(buff);

		EApiLibInitialize();
		ASSERT_EQ(EAPI_STATUS_SUCCESS,EApiStorageAreaWrite(EAPI_ID_STORAGE_STD,0,lpBuf,32));
		EXPECT_PRED_FORMAT2(AssertEapiStorageAreaRead,EAPI_ID_STORAGE_STD,0);
}

//test when write UNIT_TESTING_BUFFER1 in storage ,can read correct or not
TEST_F(UnitTesting_EapiStorageAreaRead,EapiStorageAreaRead_TRY_READ_1)
{
	char buff[33] = {0};

	std::string pstr = std::string(UNIT_TESTING_BUFFER1);
	std::string  bpstr;
	uint32_t pBufLen = 32;//_assert_write.length();
	char lpBuf[33];// = (char *)malloc(32);
	memcpy(lpBuf, pstr.c_str() ,32);

	this->set_pbuff(buff);

	EApiLibInitialize();
	ASSERT_EQ(EAPI_STATUS_SUCCESS,EApiStorageAreaWrite(EAPI_ID_STORAGE_STD,0,lpBuf,32));
	EXPECT_PRED_FORMAT2(AssertEapiStorageAreaRead,EAPI_ID_STORAGE_STD,0);
	bpstr =std::string(buff);
	ASSERT_EQ(bpstr,pstr);
	
}

//test when write UNIT_TESTING_BUFFER2 in storage ,can read correct or not
TEST_F(UnitTesting_EapiStorageAreaRead,EapiStorageAreaRead_TRY_READ_2)
{
	char buff[33] = {0};

	std::string pstr = std::string(UNIT_TESTING_BUFFER2);
	std::string  bpstr;
	uint32_t pBufLen = 32;//_assert_write.length();
	char lpBuf[33];// = (char *)malloc(32);
	memcpy(lpBuf, pstr.c_str() ,32);

	this->set_pbuff(buff);

	EApiLibInitialize();
	ASSERT_EQ(EAPI_STATUS_SUCCESS,EApiStorageAreaWrite(EAPI_ID_STORAGE_STD,0,lpBuf,32));
	EXPECT_PRED_FORMAT2(AssertEapiStorageAreaRead,EAPI_ID_STORAGE_STD,0);
	bpstr =std::string(buff);
	ASSERT_EQ(bpstr,pstr);
}

//test when write UNIT_TESTING_BUFFER3 in storage ,can read correct or not
TEST_F(UnitTesting_EapiStorageAreaRead,EapiStorageAreaRead_TRY_READ_3)
{
	char buff[33] = {0};

	std::string pstr = std::string(UNIT_TESTING_BUFFER3);
	std::string  bpstr;
	uint32_t pBufLen = 32;//_assert_write.length();
	char lpBuf[33];// = (char *)malloc(32);
	memcpy(lpBuf, pstr.c_str() ,32);

	this->set_pbuff(buff);

	EApiLibInitialize();
	ASSERT_EQ(EAPI_STATUS_SUCCESS,EApiStorageAreaWrite(EAPI_ID_STORAGE_STD,0,lpBuf,32));
	EXPECT_PRED_FORMAT2(AssertEapiStorageAreaRead,EAPI_ID_STORAGE_STD,0);
	bpstr =std::string(buff);
	ASSERT_EQ(bpstr,pstr);
}
/*
//test overflow check
TEST(testEapiStorageAreaRead,overflow_check)
{
char buff[33] = {0};
EApiLibInitialize();
ASSERT_EQ(EAPI_STATUS_INVALID_BLOCK_LENGTH,EApiStorageAreaRead(EAPI_ID_STORAGE_STD,0,buff,32,2048));
free(buff);
}


//test ByteCnt>BufLen
TEST(testEapiStorageAreaRead,ByteCnt_bigger_than_BufLen)
{
char buff[33] = {0};
ASSERT_EQ(EAPI_STATUS_INVALID_BLOCK_LENGTH,EApiStorageAreaRead(EAPI_ID_STORAGE_STD,0,buff,32,64));
free(buff);
}*/