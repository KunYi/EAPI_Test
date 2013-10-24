#ifndef UNITTESTING_EAPISTORAGEAREAWRITE_H_
#define UNITTESTING_EAPISTORAGEAREAWRITE_H_
#pragma once
#include <iostream>
#include "EAPI_Unit_testing.h"
#define UNIT_TESTING_WRITE_TEST_1 "UNIT_TESTING_WRITE_TEST_1"
#define UNIT_TESTING_WRITE_TEST_2 "UNIT_TESTING_WRITE_TEST_2"
#define UNIT_TESTING_WRITE_TEST_3 "UNIT_TESTING_WRITE_TEST_3"
class UnitTesting_EApiStorageAreaWrite :
	 public EAPI_Unit_testing , public testing::WithParamInterface<const char *>
{
public:
	testing::AssertionResult AssertEApiStorageAreaWrite(const char* Id_exp , const char * offset_exp , uint32_t Id , uint32_t offset);
	void setBuffer(std::string );
private:
	std::string _assert_write;
};
#endif
