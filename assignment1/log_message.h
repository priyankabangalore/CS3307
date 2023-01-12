/*
    Name: Priyanka Bangalore
    Student Number: 251078400
    Course: CS3307
    Assessment: Assignment 1
    Due Date: October 4th, 2022 
    File Contents: log_message class' header file
*/

#ifndef LOG_MESSAGE_H_INCLUDED

    #define LOG_MESSAGE_H_INCLUDED

    // include statements
    #include <string>
    #include <iostream>

    // log_message class declarations
    class log_message
    {
        // public methods and attributes
        public:
            log_message(std::string, std::string);
            ~log_message();
            std::string get_message();
            std::string get_timestamp();
        
        // private attributes
        private:
            std::string message;
            std::string timestamp;
    };

#endif
