// 登录测试
#include "myDB.h"
#include "common.h"
#include "interface.h"
#include "UnitTestCommon.h"
#include <gtest/gtest.h>
using namespace testing;

// 用户注册
TEST(testCase, test_userRegister) {
    EXPECT_EQ(userRegister(REG_USER_ID, REG_USER_NAME, 
                           REG_USER_PW, REG_USER_PHONE, 
                           REG_BUILDING_ID, REG_FAMILY_ID, REG_STATE), SUCCESS_JSON); // 正确   
    EXPECT_EQ(userRegister(REG_USER_ID_ERR, REG_USER_NAME, 
                           REG_USER_PW, REG_USER_PHONE, 
                           REG_BUILDING_ID, REG_FAMILY_ID, REG_STATE), REG_ID_ERR); // 该ID已注册
}

// 管理员注册
TEST(testCase, test_adminRegister) {
    EXPECT_EQ(adminRegister(REG_ADMIN_ID, REG_ADMIN_NAME, REG_ADMIN_PWD, REG_ADMIN_PHONE, REG_ADMIN_BUILDING), SUCCESS_JSON); // 正确   
    EXPECT_EQ(adminRegister(REG_ADMIN_ID_ERR, REG_ADMIN_NAME, REG_ADMIN_PWD, REG_ADMIN_PHONE, REG_ADMIN_BUILDING), REG_ID_ERR); // 该ID已注册
}

// 登录
TEST(testCase, test_login) {
    EXPECT_EQ(login(LOGIN_USER_ID, LOGIN_USER_PW, "0"), LOGIN_SUCC);       // 正确
    EXPECT_EQ(login(LOGIN_USER_ID, LOGIN_USER_PW_ERR, "0"), LOGIN_PW_ERR); // 密码错误
    EXPECT_EQ(login(LOGIN_USER_ID_ERR, LOGIN_USER_PW, "0"), LOGIN_ID_ERR); // 请求登录的ID不存在
}

// 管理员修改物资库存
TEST(testCase, test_modifyEquipment) {
    EXPECT_EQ(modifyEquipment(MODIFY_EQUIP_ID, MODIFY_EQUIP_CHANGE_ADD), SUCCESS_JSON); // 增加物资成功
    EXPECT_EQ(modifyEquipment(MODIFY_EQUIP_ID, MODIFY_EQUIP_CHANGE_SUB), SUCCESS_JSON); // 减少物资成功
    EXPECT_EQ(modifyEquipment(MODIFY_EQUIP_ID_ERR, MODIFY_EQUIP_CHANGE_SUB), MODIFY_EQUIPID_ERR); // 物资ID未注册
    EXPECT_EQ(modifyEquipment(MODIFY_EQUIP_ID, MODIFY_EQUIP_CHANGE_SUB_MUCH), MODIFY_EQUIP_LACK); // 物资短缺
    EXPECT_EQ(modifyEquipment(MODIFY_EQUIP_ID, MODIFY_EQUIP_CHANGE_ERR), MODIFY_EQUIP_ERR); // 物资调整格式错误
}

// 人民获取自己申请的物资的情况 getApplyStatus
TEST(testCase, test_getApplyStatus) {
    EXPECT_EQ(getApplyEquipment(LOGIN_USER_ID_ERR, GETAPPLYSTATUS_REJE), GETAPPLYSTATUS_ID_ERR); // 用户ID未注册
    EXPECT_EQ(getApplyEquipment(LOGIN_USER_ID, GETAPPLYSTATUS_REJE), GETAPPLYSTATUS_REJE_RES); // 查询被拒绝的物资申请
    EXPECT_EQ(getApplyEquipment(LOGIN_USER_ID, GETAPPLYSTATUS_AGGE), GETAPPLYSTATUS_AGGE_RES); // 查询被通过的物资申请
    EXPECT_EQ(getApplyEquipment(LOGIN_USER_ID, GETAPPLYSTATUS_WAIT), GETAPPLYSTATUS_WAIT_RES); // 查询未处理的物资申请
    EXPECT_EQ(getApplyEquipment(LOGIN_USER_ID, GETAPPLYSTATUS_ALL), GETAPPLYSTATUS_ALL_RES); //查询所有物资申请
    EXPECT_EQ(getApplyEquipment(LOGIN_USER_ID, GETAPPLYSTATUS_ERR), GETAPPLYSTATUS_ERR_RES); // 不合法的请求
}

// mysql防注入
TEST(testCase, test_mysql) {
    ASSERT_TRUE(CheckSQL(CORRECT_MYSQL)); // 未被注入的sql
    ASSERT_FALSE(CheckSQL(ERR_MYSQL)); // 被注入的sql
}