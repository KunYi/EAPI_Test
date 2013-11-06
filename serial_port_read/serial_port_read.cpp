#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	 /*open new serial port*/
   DCB dcb1;
   HANDLE hCom1;
   BOOL fSuccess;
   char *pcCommPort1 = "COM5";
   OVERLAPPED osReader = {0};
   osReader.hEvent = CreateEvent(NULL, TRUE, FALSE, NULL);
   hCom1 = CreateFile( pcCommPort1,
                    GENERIC_READ | GENERIC_WRITE ,
                    0,    // must be opened with exclusive-access
                    NULL, // no security attributes
                    OPEN_EXISTING, // must use OPEN_EXISTING
                    0,    // not overlapped I/O
                    NULL  // hTemplate must be NULL for comm devices
                    );
    if (hCom1 == INVALID_HANDLE_VALUE) 
   {
       // Handle the error.
       printf ("CreateFile failed with error %d.\n", GetLastError());
	   system("pause");
       return (1);
   }

	 fSuccess = GetCommState(hCom1, &dcb1);

   if (!fSuccess) 
   {
      // Handle the error.
      printf ("GetCommState failed with error %d.\n", GetLastError());
	  system("pause");
      return (2);
   }

   COMMTIMEOUTS    CommTimeouts = {0};
	GetCommTimeouts(hCom1, &CommTimeouts);
	//CommTimeouts.ReadIntervalTimeout            = 50000; 
   // CommTimeouts.ReadTotalTimeoutMultiplier     = 2; 
    //CommTimeouts.ReadTotalTimeoutConstant       = 10; 
   // CommTimeouts.WriteTotalTimeoutMultiplier    = 50; 
    //CommTimeouts.WriteTotalTimeoutConstant      = 500; 
	SetCommTimeouts(hCom1, &CommTimeouts);

   dcb1.BaudRate = 9600;     // set the baud rate
   dcb1.ByteSize = 8;             // data size, xmit, and rcv
   dcb1.Parity = NOPARITY;        // no parity bit
   dcb1.StopBits = ONESTOPBIT;    // one stop bit
   //dcb1.fInX = 1;
   //dcb1.fOutX = 0;
   fSuccess = SetCommState(hCom1, &dcb1);
   
   if (!fSuccess) 
   {
      // Handle the error.
      printf ("SetCommState failed with error %d.\n", GetLastError());
	  system("pause");
      return (3);
   }

   printf ("Serial port %s successfully reconfigured.\n", pcCommPort1);
    /*read serial port*/
   DWORD read = 5;
   char buf1[5] ;
   DWORD i;
   while(1)
   {
   if(!ReadFile(hCom1,&buf1,sizeof(buf1),&read,NULL))
	   printf("error reading from input buffer \n");
   for (i=0; i<read; i++)
		printf("%c ", (unsigned char)buf1[i]);
   }
    system("pause");
	return 0;
	
}