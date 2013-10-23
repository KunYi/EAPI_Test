#ifndef EAPI_UNIT_TESTING_H_
#define EAPI_UNIT_TESTING_H_

#pragma once

#include <stdio.h>
#include <stdlib.h>

#include "gtest\gtest.h"

#ifndef _WIN32
#include "include/linux/EApiOs.h"
#else /* _WIN32 */
#include "EApiOs.h"
#endif /* _WIN32 */

#include "EApi.h"
// Other needed includes for system calls etc.

#include "EAPI_Testing_define.h"

class EAPI_Unit_testing :
	public testing::TestWithParam<uint32_t>
{
public:
	virtual void SetUp(void);
	virtual void TearDown(void);

	testing::AssertionResult AssertEApiLibInitialize(const char* status_exp,uint32_t status);
	
	std::string getEApiStatus(uint32_t status);
	std::string getEApiId(uint32_t Id);
private:
	std::string _getEApiStatus(uint32_t status);
	std::string _getEApiId(uint32_t Id);
};
#endif

