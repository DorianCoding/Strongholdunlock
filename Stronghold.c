#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <signal.h>
FILE *f;
FILE *fcopy;
//Closing files by hand before exiting in case of system error
void intHandler() {
	if (f!=NULL) fclose(f);
	if (fcopy!=NULL) fclose(fcopy);
	exit(EXIT_FAILURE);
}
int main(int argc, char *argv[]) {
	signal(SIGINT, intHandler);
	signal(SIGTERM, intHandler);
//No file was given exiting
if (argc<2) {
	printf("No file given, type command file to edit the file. Give the path to crusader.cfg located in Documents.\n");
	return 1;
}
char file[255];
if (snprintf(file,250,"%s",argv[1])>249) { //Check for buffer overflows
	printf("Pathname must not exceeded 250 characters.\n");
	return 1;
}
f = fopen(file, "r+b" ); //Open the so-called file if possible, else exit.
if (f==NULL) {
	printf("Error reading file. Error: %s\n",strerror(errno));
	return 1;
}
int c;
strcat(file,".old");
fcopy = fopen(file,"w+b"); //Create the copy
if (fcopy==NULL) {
	fclose(f);
	printf("Error making a copy\n");
	return 1;
}
// Read contents from file
    c = fgetc(f);
    while (c != EOF)
    {
        fputc(c, fcopy);
        c = fgetc(f);
    }
fclose(fcopy);
int first_mission=0x342; //Change byte to their number (342 byte to 50 and 422 byte to 1e)
char first_byte=0x32;
int second_mission=0x422;
char second_byte=0x1e;
fseek( f, first_mission, SEEK_SET );
fwrite( &first_byte, sizeof( first_byte ), 1, f );
fseek( f, second_mission, SEEK_SET );
fwrite( &second_byte, sizeof( second_byte ), 1, f );
fclose( f );
}
