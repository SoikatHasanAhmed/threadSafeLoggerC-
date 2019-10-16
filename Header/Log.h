//
// Created by soikat on ১/১০/১৯.
//

#ifndef LOGGER_LOG_H
#define LOGGER_LOG_H
#include "iostream"
#include "chrono"
#include "fstream"
#include "string"
#include "thread"
#include "mutex"
#include "list"
#include "condition_variable"
#include "functional"



class Log
{
public:
    enum LogType
    {
        Console =0,File
    };

private:
    std::list<std::function<void()>>mLogQueue;
    std::mutex mLogMutex;
    std::condition_variable mNotificationVariable;
    bool mClosing = false;
    std:: thread pthread{&Log::serialize,this};
    LogType m_LogType = Console;


//functions
    static int writeFile (const char* message);
    static const std::string currentDateTime();
    void serialize();




public:
    //public functions
    void  SetLogType (LogType type);
    int GetLogType();
    long Get_Thread_id();
    int Write(const char* message);
    ~Log();


};

#endif //LOGGER_LOG_H
