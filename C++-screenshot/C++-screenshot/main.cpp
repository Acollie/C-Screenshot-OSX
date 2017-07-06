//
//  main.cpp
//  C++-screenshot
//
//  Created by Acollie on 04/07/2017.
//

//TODO
//Make it so user can cancel with another command
//Fix the direcrtory issue
//Lower CPU usage possible quartz

//Some libs are not used yet
#include <iostream>
#include <thread>
#include <stdlib.h>
#include <string>
#include <ctime>
#include <unistd.h>


//Time setup
int Time_interval;
int time_mins;

//Screenshot thread
void Thread(){
    using namespace std;
    string response;
    cout<<"Start thread? y/n \n";
  
    //getting user input to start thread
    cin>>response;
    
    //Turns Time from seconds into nano seconds
    int nano_time=Time_interval*100000;
    int i=0;
    if (response=="y") {
        cout<<"thread started\n ";
       //Infinate loop for screenshot
        while (true) {
          //Pauses thread as set in Timesetup
            usleep(nano_time);
            
            i++;
            string i_string= to_string(i);
            system("ls");
            string system_command="screencapture -x Image"+i_string+".png";
            //Takes Screenshot using terminal
            system((system_command).c_str());
            
            //Reports to user that a screenshot has been taken
            cout<<"Screenshot "+i_string +" taken\n";
        }
    }else{
        //Ends the program
        std::cout<<"program ended";
    }
}


int main(int argc, const char * argv[]) {
    
    using namespace std;
  
    
    cout<<"Please slect number interval in seconds \n";
    cin>>Time_interval;
    
    string string_Time_instal=to_string(Time_interval);
    
    cout<<"Thanks "+string_Time_instal+" was slected";
    
    //Not working right now
    system("cd");
    system("cd Screenshots");

    //Runs the screenshot thread
    Thread();

    



}



