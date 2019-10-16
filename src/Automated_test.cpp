#include "iostream"
#include "../Header/Log.h"
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#define console_Log_Success 501
#define file_Log_Success 502
#define log_type_console 0
#define log_type_file 1

// ##############################################################################################################################################
// ##                TO USE THE Automated TEST CODE UNCOMMENT THE MAIN FUNCTION AND COMMENT THE Manusal_test.cpp TEST MAIN FUNCTION            ##
// ##                                                                                                                                          ##
// ###############################################################################################################################################
struct ClassTest:public testing::Test{
    Log log ;
    void SetUp() {
        //this line used for setting the log object type File or console ## by default the objected is console if you want to set then we have to use log2.SetLogType
        log.SetLogType(Log::File);
        log.Write("TEST MESSAGE LOG");
    }
    void TearDown(){

    }

};

TEST_F(ClassTest, Class_Usage){


    ASSERT_EQ(log_type_file,log.GetLogType());
    //if the operation is successful the function will return 502
    ASSERT_EQ(file_Log_Success,log.Write("Write this to the FILE log"));
    // changing the log type
    log.SetLogType(Log::Console);
    ASSERT_EQ(log_type_console,log.GetLogType());
    //if the operation is successful the function will return 501
    ASSERT_EQ(console_Log_Success,log.Write("Write this to the CONSOLE log"));

}

int main(int argc,char **argv)
{
    testing::InitGoogleTest(&argc,argv);
    RUN_ALL_TESTS();
    return 0;

}


