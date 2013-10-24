
#include "UnitTesting_EApiStorageAreaWrite.h"

using namespace testing;

void Assert_EApiStorageAreaRead(uint32_t offset,const char* test_string){
	std::string ltest_string = test_string;

	char * lBuf = (char * )malloc(ltest_string.length());
	uint32_t result = EApiStorageAreaRead(EAPI_ID_STORAGE_STD,offset,lBuf,ltest_string.length(),ltest_string.length());

	if(result == EAPI_STATUS_SUCCESS){
		std::string ltar = lBuf;
		ASSERT_EQ(ltest_string,ltar);
	}else{
		
		FAIL() << "[ function ] [ EApiStorageAreaRead ] Fail";
	}
	free(lBuf);
}

TEST_F(UnitTesting_EApiStorageAreaWrite , EApiStorageAreaWrite_Try_Write)
{
	std::string * pstr = new std::string(UNIT_TESTING_WRITE_TEST_1);
	setBuffer(*pstr);
	EXPECT_PRED_FORMAT2(AssertEApiStorageAreaWrite,EAPI_ID_STORAGE_STD,0);
	Assert_EApiStorageAreaRead(0,UNIT_TESTING_WRITE_TEST_1);
	delete pstr;
}


TEST_P(UnitTesting_EApiStorageAreaWrite, EApiStorageAreaWrite_Try_Write_All)
{
	const char * test_string = GetParam();
	std::string * pstr = new std::string(test_string);
	setBuffer(*pstr);
	EXPECT_PRED_FORMAT2(AssertEApiStorageAreaWrite,EAPI_ID_STORAGE_STD,0);
	Assert_EApiStorageAreaRead(0,pstr->c_str());
	delete pstr;
}

INSTANTIATE_TEST_CASE_P( EAPI_Unit_testing , UnitTesting_EApiStorageAreaWrite , testing::Values(
	UNIT_TESTING_WRITE_TEST_1 , UNIT_TESTING_WRITE_TEST_2,UNIT_TESTING_WRITE_TEST_3
	) );