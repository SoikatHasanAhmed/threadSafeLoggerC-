////
//// Created by soikat on ২/১০/১৯.
////
// ##############################################################################################################################################
// ##                TO USE THE MANUAL THREAD CODE UNCOMMENT THE MAIN FUNCTION AND COMMENT THE AUTOMATED TEST MAIN FUNCTION                    ##
// ##                                                                                                                                          ##
// ###############################################################################################################################################
#include "../Header/Log.h"


//this line used for setting the log object type File or console ## by default the objected is console if you want to set then we have to use log2.SetLogType
char* log_message1 =" i am from thread 1";
char* log_message2 =" i am from thread 2";
char* log_message3 =" i am from thread 3";
char* log_message4 =" i am from thread 4";
char* log_message5 =" i am from thread 5";
char* log_message6 =" i am from thread 6";
char* log_message7 =" i am from thread 7";
char* log_message8 =" i am from thread 8";
char* log_message9 =" i am from thread 9";
char* log_message10 =" i am from thread 10";


Log log1;
Log lo2;

void test_console_log(const char*  x)
{

    log1.Write(x);
}




    void test_file_log(char*  x)
    {
    lo2.SetLogType(Log::File);
    lo2.Write(x);
}


void File_ths(){
    std::thread th1 (test_file_log,log_message1 );
    std::thread th2 (test_file_log,log_message2);
    std::thread th3 (test_file_log,log_message3 );
    std::thread th4 (test_file_log,log_message4);
    std::thread th5 (test_file_log,log_message5 );
    std::thread th6 (test_file_log,log_message6);
    std::thread th7 (test_file_log,log_message7 );
    std::thread th8 (test_file_log,log_message8);
    std::thread th9 (test_file_log,log_message9 );
    std::thread th10 (test_file_log,log_message10);
    th1.join();
    th2.join();
    th3.join();
    th4.join();
    th5.join();
    th6.join();
    th7.join();
    th8.join();
    th9.join();
    th10.join();


}

void console_ths(){
    std::thread th1 (test_console_log,log_message1 );
    std::thread th2 (test_console_log,log_message2);
    std::thread th3 (test_console_log,log_message3 );
    std::thread th4 (test_console_log,log_message4);
    std::thread th5 (test_console_log,log_message5 );
    std::thread th6 (test_console_log,log_message6);
    std::thread th7 (test_console_log,log_message7 );
    std::thread th8 (test_console_log,log_message8);
    std::thread th9 (test_console_log,log_message9 );
    std::thread th10 (test_console_log,log_message10);

    th1.join();
    th2.join();
    th3.join();
    th4.join();
    th5.join();
    th6.join();
    th7.join();
    th8.join();
    th9.join();
    th10.join();

}


//int main()
//{
//    //file log test code
//    // we can see that 10 thread logging at a same time to log to file or to console
//    File_ths();
//    console_ths();
//
//
//    return 0;
//}