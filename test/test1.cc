// 登录测试
#include "myDB.h"
#include "common.h"
#include "interface.h"
#include "UnitTestCommon.h"
#include <gtest/gtest.h>
using namespace testing;
TEST(testCase, test_login) {
    EXPECT_EQ(login(USER_ID, USER_PW, "0"), LOGIN_SUCC);          // 正确
    EXPECT_EQ(login(USER_ID, USER_PW_ERR, "0"), LOGIN_PW_ERR);    // 密码错误
    EXPECT_EQ(login(USER_ID_ERR, USER_PW, "0"), LOGIN_ID_ERR);    // 请求登录的ID不存在
}
