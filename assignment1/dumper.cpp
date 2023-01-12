/*
    Name: Priyanka Bangalore
    Student Number: 251078400
    Course: CS3307
    Assessment: Assignment 1
    Due Date: October 4th, 2022 
    File Contents: dumper app implementation (App #2)
*/

#include "logger.h"

using namespace std;

/*
    @name: main()
    Dumps all messages and timestamps from provided app's table into standard output
    @param: number of command line arguments
    @param: array of command line arguments
    @return: 1 being terminated with an error and 0 being process completed successfully
*/
int main(int argc, char *argv[]){

    std::string app_name = argv[1];

    // invalid arguement handlers
    if(argc == 1){
        throw std::invalid_argument("\n Missing app name arguement.");
        return 1;
    }
    else if(argc > 2){
        throw std::invalid_argument("\n Too many arguments; only one app name per Dumper call.");
        return 1;
    }

    vector<log_message> messages;
    string timestamp;
    string msg;

    // creates object of type logger and reads everything in the table with provided app name
    logger logger_obj(app_name);
    messages = logger_obj.read_all();

    cout << "\n Data pulled from records: \n";

    // prints to standard output the contents of the table with the app name
    for(int i = 0; i < messages.size(); i++){
        timestamp = messages.at(i).get_timestamp();
        msg = messages.at(i).get_message();
        cout << timestamp << ": " << msg;
    }

    return 0;
}
