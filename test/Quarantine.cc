//隔离测试
#include "myDB.h"
#include "common.h"
#include "interface.h"
#include "UnitTestCommon.h"
#include <gtest/gtest.h>
using namespace testing;
const string GetQuarantineInfoSuccess="{\"family\":{\"familyID\":\"2\",\"unit\":\"1\",\"Quarantine\":\"0\"},\"result\":0,\"membersList\":[{\"userId\":\"650104000000001111\",\"name\":\"白小龙\"},{\"userId\":\"650104000000001112\",\"name\":\"王俊凯\"},{\"userId\":\"650104000000003333\",\"name\":\"白小骨\"}]}";
const string GetQuarantineInfoNoRegister="{\"result\":1001}";
const string AdminGetQuarantineInfoSuccess="{\"result\":0,\"pageTotal\":1,\"information\":[{\"userId\":\"650104000000001111\",\"name\":\"白小龙\",\"position\":\"1|2\",\"phone\":\"13399991111\",\"beginDate\":\"2020-06-12\",\"endDate\":\"2020-06-27\"}]}";
TEST(TestCase,TestQuarantine){
    EXPECT_EQ(GetQuarantineInfo("user","650104000000003333"),GetQuarantineInfoSuccess);
    EXPECT_EQ(GetQuarantineInfo("user","6501040000000033"),GetQuarantineInfoNoRegister);
    EXPECT_EQ(GetQuarantineInfo("admin","452223199909090066"),AdminGetQuarantineInfoSuccess);
    EXPECT_EQ(GetQuarantineInfo("admin","4522231909090066"),GetQuarantineInfoNoRegister);
}
//测试helpFunc
TEST(TestCase,GenJsonLinearArray){
    vector<vector<string>> cases={{"1","2","3","4","5"},{},{"time","one","two"}};
    vector<string> LinearArrayName={"test","test1",""};
    vector<string> Result={"{\"test\":[\"1\",\"2\",\"3\",\"4\",\"5\"]}","{}","{}"};
    for(int i=0;i<cases.size();++i){
        Document jsonDoc;
        jsonDoc.SetObject();
        Document::AllocatorType& allocator = jsonDoc.GetAllocator();
        StringBuffer ResBuffer;
        Writer<StringBuffer> Writer(ResBuffer);
        GenJsonLinearArray(LinearArrayName[i],cases[i],jsonDoc);
        jsonDoc.Accept(Writer);
        EXPECT_EQ(ResBuffer.GetString(),Result[i]);
    }    
}