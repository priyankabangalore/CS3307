/*
    Name: Priyanka Bangalore
    Student Number: 251078400
    Course: CS3307
    Assessment: Assignment 1
    Due Date: October 4th, 2022 
    File Contents: logger class' header file
*/

#ifndef LOGGER_H_INCLUDED

    #define LOGGER_H_INCLUDED

    //include statements
    #include <vector>
    #include <stdio.h>
    #include <sqlite3.h> 
    #include <iostream>
    #include <chrono>
    #include <string>
    #include <ctime>
    #include <sstream>
    #include "log_message.h"

    // logger class declarations
    class logger
    {
        // public methods and attributes
        public:
            logger(std::string);
            ~logger();
            void write(std::string);
            std::vector<log_message> read_all();

            sqlite3 *database;

        // private attributes
        private:
            std::string app_name;
            char *err_msg;
            int status;
    };

#endif
