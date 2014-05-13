#include <iostream>
#include <stdlib.h>
#include <signal.h>
#include <dlfcn.h>
#include <stdio.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>

using namespace std;

int main(void){

        string command;
        int c;

        while (1){
                cout<<">";
                getline(cin,command);
                c=0;
                if (command == "exit") break;

                if (command == "ls") c=1;

                if (command == "pwd") c=2;

                if (command == "ps") c=3;

                if (command == "kill") c=4;

                switch (c){

                case 1:{
                        DIR *d = opendir(".");
                        if(d){
                                struct dirent *dir;
                                while ((dir=readdir(d))!=NULL)cout<< dir->d_name <<endl; 
                                closedir(d);
                        }
                        break;
                }

                case 2: {
                        cout<<getenv("PWD")<<endl;
                         break;
                }

                case 3:{     
                        system("ps");
                        break;
                }

                case 4:{
                        cout<<"chell: KILL:"<<endl<<"enter PID:"<<endl;
                        int pid, sig;
                        cin>>pid;
                        cout<<"enter signal:"<<endl;
                        cin>>sig;
                        kill(pid, sig);
                        break;
                }

                default:
                        system(command.c_str());

                }
        }
        return 0;
}