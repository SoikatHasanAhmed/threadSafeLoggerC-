//
// Created by soikat on ১/১০/১৯.
//

#include "../Header/Log.h"


//Distractor for the class

    Log::~Log()
    {

        {   std::lock_guard<std::mutex> lock{mLogMutex};
            mClosing = true;
        }

        mNotificationVariable.notify_one();
        pthread.join();
    }


    void Log::SetLogType(Log::LogType type)
        {
            m_LogType = type;
        }

    int Log::GetLogType()
        {
            return m_LogType;
        }



    int Log::Write(const char* message){
        //std::cout<<"Log Class Thread id:" <<std::this_thread::get_id()<<std::endl;
        if(m_LogType == Console) {
            try{
                std::lock_guard<std::mutex> lock{mLogMutex};
                mLogQueue.emplace_back([value = std::move(message)] {

                    std::cout << currentDateTime() << "  || [LOG]: " << value << std::endl;

                });
                mNotificationVariable.notify_one();
                return 501;
            }
           catch (...){ return 404;}
        }
        else {
            try {

                std::lock_guard<std::mutex> lock{mLogMutex};
                mLogQueue.emplace_back([value = std::move(message)] {

                    writeFile(value);
                    std::cout << "Log Write to file is Done !! Please check the file at ../logfile/tog.txt"
                              << std::endl;
                });
                mNotificationVariable.notify_one();
                return 502;
            }
            catch (...) { return 404; }
        }
    }


//############################################## Private classes #############################################


    int Log::writeFile (const char* message)
    {
        std::ofstream Log_File;
        Log_File.open ("../logfile/log.txt",std::fstream::app);

        Log_File << currentDateTime();
        Log_File << " || [LOG]:";
        Log_File << message<<std::endl;
        Log_File.close();

    }

       //get current time
     const std::string Log::currentDateTime()
     {
        time_t     now = time(0);
        struct tm  tstruct;
        char       buf[80];
        tstruct = *localtime(&now);
        strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);
        return buf;
     }

    //thread serialize function
    void Log::serialize()
    {
        while(true)
        {
            std::unique_lock<std::mutex> lock{mLogMutex};
            mNotificationVariable.wait(lock,[=]
            {
                return mClosing || !mLogQueue.empty();
            });
            for (const auto &log: mLogQueue)
                log();
            mLogQueue.clear();
            if (mClosing)
                break;
        }
    }




