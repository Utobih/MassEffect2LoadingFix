#include <iostream>
#include <fstream>
#include <regv.h>
#include "resource.h"

using namespace std;

int starting(string game_location){
    system("Color B5");
    cout << "[+] Done! starting step to boost.." << endl;
    string binarie_location = (game_location+"/Binaries/");
    //Getting local disk where are the game
    string disk_loc = game_location.substr(0, 2);
    //creating cmd var with commands
    string l_cmd = (string(" && start /affinity 2 MassEffect2.exe"));
    //creating final command var
    string cmd_f = (disk_loc + string(" && cd \"")+binarie_location+string("\"")+l_cmd);

    //executing cmd
    system(cmd_f.c_str());
    //exiting
    cout << "[+] Done! starting game with loading boost." << endl;
    system("pause");
    return 0;
}

int main(){
    // Checking, and openning config file
    ifstream ifile;
    ifile.open("me2lfc.ini");

    //if file exist
    if (ifile) {
        cout << "[+] Config file found. Getting path.." << endl;
        string game_location;
        getline(ifile,game_location);
        ifile.close();
        starting(game_location);

    } else { //if dont
        cout << "[*] Config file doesn't exist..\n[*] Getting game path from windows reg.." << endl;
        //Getting game location from reg and adding to var
        string game_location = RegRead(HKEY_LOCAL_MACHINE, "Software\\BioWare\\Mass Effect 2", "Path", REG_SZ);
        starting(game_location);
    }
}
