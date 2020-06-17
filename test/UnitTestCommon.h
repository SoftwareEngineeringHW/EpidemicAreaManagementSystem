// 单元测试值
#define REG_USER_ID               "452223199909085566"
#define REG_USER_ID_ERR           "650104000000002222"  // 已注册的ID
#define REG_USER_NAME             "观小音"
#define REG_USER_PW               "88776655"
#define REG_USER_PHONE            "13344556677"
#define REG_BUILDING_ID           "3"
#define REG_FAMILY_ID             "2"
#define REG_STATE                 "1"

#define LOGIN_USER_ID             "650104000000002222"
#define LOGIN_USER_ID_ERR         "980808800888008800"  // 未注册的ID
#define LOGIN_USER_PW             "2222222"
#define LOGIN_USER_PW_ERR         "1234567" // 错误的密码

#define MODIFY_EQUIP_ID           "1"
#define MODIFY_EQUIP_ID_ERR       "10000"
#define MODIFY_EQUIP_CHANGE_ADD   "+1"
#define MODIFY_EQUIP_CHANGE_SUB   "-1"
#define MODIFY_EQUIP_CHANGE_ERR   "1"

#define GETAPPLYSTATUS_REJE       "0"
#define GETAPPLYSTATUS_AGGE       "1"
#define GETAPPLYSTATUS_WAIT       "2"
#define GETAPPLYSTATUS_ALL        "3"
#define GETAPPLYSTATUS_ERR        "4"

#define CORRECT_MYSQL             "SELECT * FROM User WHERE userID = '650104000000001111';"
#define ERR_MYSQL                 "SELECT * FROM User WHERE userID = '650104000000001111' || 't'='t';"


// 单元测试结果
#define SUCCESS_JSON        "{\"result\":\"0\"}"

#define REG_ID_ERR          "{\"result\":\"1000\"}"

#define LOGIN_SUCC          "{\"result\":\"0\",\"userName\":\"嫦小娥\"}"
#define LOGIN_ID_ERR        "{\"result\":\"1001\"}"
#define LOGIN_PW_ERR        "{\"result\":\"1002\"}"

#define MODIFY_EQUIPID_ERR "{\"result\":\"1000\"}"
#define MODIFY_EQUIP_LACK   "{\"result\":\"1007\"}"
#define MODIFY_EQUIP_ERR    "{\"result\":\"-2\"}"

#define GETAPPLYSTATUS_REJE_RES       "{\"result\":0,\"pageTotal\":0,\"applyInfo\":[]}"
#define GETAPPLYSTATUS_AGGE_RES       "{\"result\":0,\"pageTotal\":4,\"applyInfo\":[{\"applyID\":\"1\",\"userID\":\"650104000000002222\",\"equipmentName\":\"医用口罩\",\"amount\":\"10\",\"date\":\"2020-06-01\",\"state\":\"1\"},{\"applyID\":\"9\",\"userID\":\"650104000000002222\",\"equipmentName\":\"酒精\",\"amount\":\"3\",\"date\":\"2020-06-11\",\"state\":\"1\"},{\"applyID\":\"10\",\"userID\":\"650104000000002222\",\"equipmentName\":\"酒精\",\"amount\":\"6\",\"date\":\"2020-06-12\",\"state\":\"1\"},{\"applyID\":\"11\",\"userID\":\"650104000000002222\",\"equipmentName\":\"口罩\",\"amount\":\"4\",\"date\":\"2020-06-12\",\"state\":\"1\"}]}"
#define GETAPPLYSTATUS_WAIT_RES       "{\"result\":0,\"pageTotal\":2,\"applyInfo\":[{\"applyID\":\"8\",\"userID\":\"650104000000002222\",\"equipmentName\":\"口罩\",\"amount\":\"2\",\"date\":\"2020-06-05\",\"state\":\"2\"},{\"applyID\":\"12\",\"userID\":\"650104000000002222\",\"equipmentName\":\"酒精\",\"amount\":\"2\",\"date\":\"2020-06-12\",\"state\":\"2\"}]}"
#define GETAPPLYSTATUS_ALL_RES        "{\"result\":0,\"pageTotal\":6,\"applyInfo\":[{\"applyID\":\"1\",\"userID\":\"650104000000002222\",\"equipmentName\":\"医用口罩\",\"amount\":\"10\",\"date\":\"2020-06-01\",\"state\":\"1\"},{\"applyID\":\"8\",\"userID\":\"650104000000002222\",\"equipmentName\":\"口罩\",\"amount\":\"2\",\"date\":\"2020-06-05\",\"state\":\"2\"},{\"applyID\":\"9\",\"userID\":\"650104000000002222\",\"equipmentName\":\"酒精\",\"amount\":\"3\",\"date\":\"2020-06-11\",\"state\":\"1\"},{\"applyID\":\"10\",\"userID\":\"650104000000002222\",\"equipmentName\":\"酒精\",\"amount\":\"6\",\"date\":\"2020-06-12\",\"state\":\"1\"},{\"applyID\":\"11\",\"userID\":\"650104000000002222\",\"equipmentName\":\"口罩\",\"amount\":\"4\",\"date\":\"2020-06-12\",\"state\":\"1\"},{\"applyID\":\"12\",\"userID\":\"650104000000002222\",\"equipmentName\":\"酒精\",\"amount\":\"2\",\"date\":\"2020-06-12\",\"state\":\"2\"}]}"
#define GETAPPLYSTATUS_ERR_RES        "{\"result\":1008}"