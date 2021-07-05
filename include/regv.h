#ifndef REGV_H_INCLUDED
#define REGV_H_INCLUDED

// CREATED BY: Przemyslaw Zaworski, 2017, github.com/przemyslawzaworski
// MODIFIED BY: Robert Souza Lages, 2021, github.com/Utobih

#include <windows.h>
#include <iostream>
#include <algorithm>

// READ
std::string RegRead (HKEY hkey, LPCTSTR subkey,LPCTSTR name,DWORD type){
	HKEY key;
	TCHAR value[255];
	DWORD value_length = 255;
	RegOpenKey(hkey,subkey,&key);
	RegQueryValueEx(key,name, NULL, &type, (LPBYTE)&value, &value_length);
	RegCloseKey(key);
	std::string final_value = value;
	std::replace( final_value.begin(), final_value.end(), '\\', '/');
	return final_value;
}

// WRITE
void RegWrite (HKEY hkey, LPCTSTR subkey,LPCTSTR name,DWORD type,const char* value){
	HKEY key;
	RegOpenKey(hkey,subkey,&key);
	RegSetValueEx(key, name, 0, type, (LPBYTE)value, strlen(value)*sizeof(char));
	RegCloseKey(key);
}

// DELETE
void RegDelete (HKEY Hkey, LPCTSTR subkey,LPCTSTR name){
	HKEY hkey;
	RegOpenKey(Hkey,subkey,&hkey);
    long lReturn = RegOpenKeyEx( Hkey, subkey,
                             0L,
                             KEY_ALL_ACCESS,
                             &hkey );
    lReturn = RegDeleteValue(hkey,(name));
	RegCloseKey(hkey);
}

#endif // REGV_H_INCLUDED
