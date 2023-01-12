/*
    Name: Priyanka Bangalore
    Student Number: 251078400
    Course: CS3307
    Assessment: Assignment 1
    Due Date: October 4th, 2022 
    File Contents: log_message class and all necessary methods
*/

#include "log_message.h"

using namespace std;

/*
    @name: log_message
    Constructor for class log_message
    @param: message to be logged
    @param: timestamp of message creation
    @return: 1 being terminated with error and 0 being completed successfully
*/
log_message::log_message(string msg, string time){
    message = msg;
    timestamp = time;
}

/*
    @name: ~log_message
    Destructor for class log_message
    @param: NA
    @return: NA
*/
log_message::~log_message(){
    //cout << "\n Destructor for log_message executed. \n";
}

/*
    @name: get_message()
    Getter for log_message object's message
    @param: NA
    @return: message associated with log_message object
*/
string log_message::get_message(){
    return message;
}

/*
    @name:  get_timestamp()
    Getter for log_message object's timestamp
    @param: NA
    @return: timestamp associated with log_message object
*/
string log_message::get_timestamp(){
    return timestamp;
}
