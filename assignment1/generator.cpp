/*
    Name: Priyanka Bangalore
    Student Number: 251078400
    Course: CS3307
    Assessment: Assignment 1
    Due Date: October 4th, 2022 
    File Contents: generator app implementation (App #1)
*/

#include <signal.h>
#include <unistd.h>
#include "logger.h"

using namespace std;

static volatile int status = 1;

/*
    @name: handler()
    Helper function for handling Ctrl+c termination of generator process
    @param: temporary, unused number
    @return: void
*/
void handler(int unused_temp) {
    status = 0;
}

/*
    @name: main()
    Generates messages to be logged in the table in the database, and sends them to standard output at a random bounded time
    @param: number of command line arguments
    @param: array of command line arguments
    @return: 1 being terminated with an error and 0 being process completed successfully
*/
int main(int argc, char *argv[]){

    std::string app_name = argv[0];

    // error handler
    if(argc == 1){
        throw std::invalid_argument("\n Missing message arguements.");
        return 1;
    }

    app_name.erase(0, 2);

    // ctrl+c termination handler
    signal(SIGINT, handler);

    while (status) {

        srand(time(NULL));
        
        // randomizer for message list index and sleep time
        int num_msg = rand()% (argc-1)+1;
        int num_time = rand()% 10+1;

        cout << "\n Message: " << argv[num_msg];
        std::string msg = argv[num_msg];

        // creates logger object and writes to the table with the app name
        logger logger_obj(app_name);
        logger_obj.write(argv[num_msg]);

        // sleeper until next message is displayed and logged
        sleep(num_time);
    }

    return 0;
}
