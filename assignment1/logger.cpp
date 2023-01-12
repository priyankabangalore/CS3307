/*
    Name: Priyanka Bangalore
    Student Number: 251078400
    Course: CS3307
    Assessment: Assignment 1
    Due Date: October 4th, 2022 
    File Contents: logger class and all necessary methods
*/

#include "logger.h"

using namespace std;
using namespace std::chrono;

/*
    @name: logger()
    Constructor for class logger
    @param: name of app being called
    @return: NA
*/
logger::logger(string name){

    app_name = name;

    // opens database
    status = sqlite3_open("assn1.db", &database);

    //error handler
    if(status != SQLITE_OK){
        cout << "\n Error: cannot open database.";
    }
    else{
        cout << "\n Database opened successfully.";
    }

    // creates table in database
    char cm[100];
    sprintf(cm, "create table if not exists %s (timestamp varchar(255), message varchar(255)); \n", app_name.c_str());
    status = sqlite3_exec(database, cm, NULL, NULL, &err_msg);

    //error handler
    if(status != SQLITE_OK){
        cout << "\n Error: cannot create table.";
        sqlite3_free(err_msg);
    }
    else{
        cout << "\n Table created successfully.";
    }
}

/*
    @name: ~logger()
    Destructor for class logger
    @param: NA
    @return: NA
*/
logger::~logger(){
    sqlite3_close(database);
    //cout << "\n Destructor for logger executed. \n";
}

/*
    @name: write()
    Writes given message to a table created in SQLite database
    @param: message to be written to the table
    @return: void
*/
void logger::write(string msg){

    // gets current date and time when method is called
    system_clock::time_point t = system_clock::now();
    time_t timestamp = system_clock::to_time_t(t);

    // inserts timestamp and message values into the table in the database
    char cm[100];
    sprintf(cm, "insert into %s values (\"%s\",\"%s\"); \n", app_name.c_str(), ctime(&timestamp), msg.c_str());
    status = sqlite3_exec(database, cm, NULL, NULL, &err_msg);

    //error handler
    if(status != SQLITE_OK){
        cout << "\n Error: cannot insert values into table.\n";
        sqlite3_free(err_msg);
    }
    else{
        cout << "\n Table recorded to successfully.\n";
    }
}

/*
    @name: read_all()
    Stores messages and their corresponding timestamps in a vector of type log message
    @param: NA
    @return: vector structure containing objects of time log message, holding messages with their timestamp of creation
*/
vector<log_message> logger::read_all(){

    vector<log_message> messages;
    
    // reads data in table
    char cm[100];
    sprintf(cm, "select * from %s; \n", app_name.c_str());

    sqlite3_stmt *statement;

    status = sqlite3_prepare_v2(database, cm, -1, &statement, 0);

    // error handler
    if(status != SQLITE_OK){
        cout << "\n Error: prepare call failed.";
    }
    
    status = sqlite3_step(statement);

    // error handler
    if(status != SQLITE_OK && status != SQLITE_ROW){
        cout << "\n Error: step call failed.";
    }

    // ensures that the step call is on a row in the table
    while(status == SQLITE_ROW)
    {
        // retrieves timestamp and corresponding message from the current row in table
        string time = (char*) (sqlite3_column_text(statement, 0));
        string msg = (char*) (sqlite3_column_text(statement, 1));
        
        // pushes log_message object with timestamp and message data to a vector
        log_message log_msg_obj(time, msg);
        messages.push_back(log_msg_obj);

        // moves to the next row after completion of previous statements
        status = sqlite3_step(statement);
    }
    
    status = sqlite3_finalize(statement);

    // error handler
    if(status != SQLITE_OK){
        cout << "\n Error: finalize call failed.";
    }
    else{
        cout << "\n Records read successfully. \n";
    }

    sqlite3_close(database);

    return messages;
}
