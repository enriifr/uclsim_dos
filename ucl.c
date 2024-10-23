#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <locale.h>
#include <MMsystem.h>
#include <pthread.h>
#include <unistd.h>
#include <stdbool.h>
#include <time.h>

#define MAX_LEN 1280

#define color_red "\x1b[31m"
#define color_green "\x1b[32m"
#define color_yellow "\x1b[33m"
#define color_blue "\x1b[34m"
#define color_magenta "\x1b[35m"
#define color_cyan "\x1b[36m"
#define color_reset "\x1b[0m"

// Define ENABLE_VIRTUAL_TERMINAL_PROCESSING if not defined
#ifndef ENABLE_VIRTUAL_TERMINAL_PROCESSING
#define ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x0004
#endif
int aggr = 1;
int def = 1;
int att = 1;
int printNextToOther=0;
int ptsTotal=3 ;
int stopSuono=0;
int loading;

int printUnder=0;
int printField=0;
int printNumberSX=0;
int printNumberDX=0;
int playerSCORE=0;
int cpuSCORE=0;
int ballPossPLA=0, ballPossCPU=0, ballPossTOT=0, foulsPLA=0, foulsCPU=0, offsPLA=0, offsCPU=0;
int printHalfT1=0;
int printHalfT2=0;

pthread_t soundThread;
pthread_t loadThread;

void* playSoundError(void* arg) {							//thread sfx errore
    PlaySound(TEXT("sounds/error.wav"),NULL,SND_SYNC);
    return NULL;
}


printHalftimeStats(){
	char *filename;
    FILE *fptr;
    
    system("cls");
	filename = "img/match/halftime.txt";
    fptr = fopen(filename, "r");
    if (fptr == NULL) {
        error1();
        return;
    }
    print_image(fptr);
    fclose(fptr);
	
	switch(playerSCORE){
		case 0:
			filename = "img/match/numbers/0.txt";
			break;
		case 1:
			filename = "img/match/numbers/1.txt";
			break;
		case 2:
			filename = "img/match/numbers/2.txt";
			break;
		case 3:
			filename = "img/match/numbers/3.txt";
			break;
		case 4:
			filename = "img/match/numbers/4.txt";
			break;
		case 5:
			filename = "img/match/numbers/5.txt";
			break;
		case 6:
			filename = "img/match/numbers/6.txt";
			break;
		case 7:
			filename = "img/match/numbers/7.txt";
			break;
		case 8:
			filename = "img/match/numbers/8.txt";
			break;
		case 9:
			filename = "img/match/numbers/9.txt";
			break;
		
	}
    fptr = fopen(filename, "r");
    if (fptr == NULL) {
        error1();
        return;
    	}
    printf(color_red "");
  	printf("\033[500D");
  	printf("\033[46A");
  	printHalfT1=1;
    print_image(fptr);
    printHalfT1=0;
    printf(color_reset"");
    fclose(fptr);
    
    switch(foulsPLA){
    	case 0:
			filename = "img/match/numbers/0.txt";
			break;
		case 1:
			filename = "img/match/numbers/1.txt";
			break;
		case 2:
			filename = "img/match/numbers/2.txt";
			break;
		case 3:
			filename = "img/match/numbers/3.txt";
			break;
		case 4:
			filename = "img/match/numbers/4.txt";
			break;
		case 5:
			filename = "img/match/numbers/5.txt";
			break;
		case 6:
			filename = "img/match/numbers/6.txt";
			break;
		case 7:
			filename = "img/match/numbers/7.txt";
			break;
		case 8:
			filename = "img/match/numbers/8.txt";
			break;
		case 9:
			filename = "img/match/numbers/9.txt";
			break;
	}
    
    fptr = fopen(filename, "r");
    if (fptr == NULL) {
        error1();
        return;
    	}
    printf(color_red "");
  	printf("\033[500D");
  	printf("\033[9B");
  	printHalfT1=1;
    print_image(fptr);
    printHalfT1=0;
    printf(color_reset"");
    fclose(fptr);
    
    switch(offsPLA){
    	case 0:
			filename = "img/match/numbers/0.txt";
			break;
		case 1:
			filename = "img/match/numbers/1.txt";
			break;
		case 2:
			filename = "img/match/numbers/2.txt";
			break;
		case 3:
			filename = "img/match/numbers/3.txt";
			break;
		case 4:
			filename = "img/match/numbers/4.txt";
			break;
		case 5:
			filename = "img/match/numbers/5.txt";
			break;
		case 6:
			filename = "img/match/numbers/6.txt";
			break;
		case 7:
			filename = "img/match/numbers/7.txt";
			break;
		case 8:
			filename = "img/match/numbers/8.txt";
			break;
		case 9:
			filename = "img/match/numbers/9.txt";
			break;
	}
    
    fptr = fopen(filename, "r");
    if (fptr == NULL) {
        error1();
        return;
    	}
    printf(color_red "");
  	printf("\033[500D");
  	printf("\033[11B");
  	printHalfT1=1;
    print_image(fptr);
    printHalfT1=0;
    printf(color_reset"");
    fclose(fptr);
    
    switch(cpuSCORE){
    	case 0:
			filename = "img/match/numbers/0.txt";
			break;
		case 1:
			filename = "img/match/numbers/1.txt";
			break;
		case 2:
			filename = "img/match/numbers/2.txt";
			break;
		case 3:
			filename = "img/match/numbers/3.txt";
			break;
		case 4:
			filename = "img/match/numbers/4.txt";
			break;
		case 5:
			filename = "img/match/numbers/5.txt";
			break;
		case 6:
			filename = "img/match/numbers/6.txt";
			break;
		case 7:
			filename = "img/match/numbers/7.txt";
			break;
		case 8:
			filename = "img/match/numbers/8.txt";
			break;
		case 9:
			filename = "img/match/numbers/9.txt";
			break;
	}
    
    fptr = fopen(filename, "r");
    if (fptr == NULL) {
        error1();
        return;
    	}
    printf(color_yellow "");
  	printf("\033[44A");
  	printf("\033[500D");
  	printHalfT2=1;
    print_image(fptr);
    printHalfT2=0;
    printf(color_reset"");
    fclose(fptr);
    
    switch(foulsCPU){
    	case 0:
			filename = "img/match/numbers/0.txt";
			break;
		case 1:
			filename = "img/match/numbers/1.txt";
			break;
		case 2:
			filename = "img/match/numbers/2.txt";
			break;
		case 3:
			filename = "img/match/numbers/3.txt";
			break;
		case 4:
			filename = "img/match/numbers/4.txt";
			break;
		case 5:
			filename = "img/match/numbers/5.txt";
			break;
		case 6:
			filename = "img/match/numbers/6.txt";
			break;
		case 7:
			filename = "img/match/numbers/7.txt";
			break;
		case 8:
			filename = "img/match/numbers/8.txt";
			break;
		case 9:
			filename = "img/match/numbers/9.txt";
			break;
	}
    
    fptr = fopen(filename, "r");
    if (fptr == NULL) {
        error1();
        return;
    	}
    printf(color_yellow "");
  	printf("\033[500D");
  	printf("\033[9B");
  	printHalfT2=1;
    print_image(fptr);
    printHalfT2=0;
    printf(color_reset"");
    fclose(fptr);
    
    switch(offsCPU){
    	case 0:
			filename = "img/match/numbers/0.txt";
			break;
		case 1:
			filename = "img/match/numbers/1.txt";
			break;
		case 2:
			filename = "img/match/numbers/2.txt";
			break;
		case 3:
			filename = "img/match/numbers/3.txt";
			break;
		case 4:
			filename = "img/match/numbers/4.txt";
			break;
		case 5:
			filename = "img/match/numbers/5.txt";
			break;
		case 6:
			filename = "img/match/numbers/6.txt";
			break;
		case 7:
			filename = "img/match/numbers/7.txt";
			break;
		case 8:
			filename = "img/match/numbers/8.txt";
			break;
		case 9:
			filename = "img/match/numbers/9.txt";
			break;
	}
    
    fptr = fopen(filename, "r");
    if (fptr == NULL) {
        error1();
        return;
    	}
    printf(color_yellow "");
  	printf("\033[500D");
  	printf("\033[11B");
  	printHalfT2=1;
    print_image(fptr);
    printHalfT2=0;
    printf(color_reset"");
    printUnder=0;
    fclose(fptr);
		
}

void error3x01()					//errore valore non valido
{
	int err3x01;
	system("cls");
	char *filename = "img/errors/3x01/3x01_icon.txt";
    FILE *fptr = NULL;
    pthread_create(&soundThread, NULL, playSoundError, NULL);

    if((fptr = fopen(filename,"r")) == NULL)
    {
		for(err3x01=0;err3x01<150;err3x01++){
			printUnder=1;
			printf("ERROR: illegal value! (3x01)");
			printUnder=0;
			Sleep(100);
		}
        return 1;
    }
	printf(color_red "");
    print_image(fptr);

    fclose(fptr);

    printf(color_reset "");
    
    filename = "img/errors/3x01/3x01_text.txt";
    if((fptr = fopen(filename,"r")) == NULL)
    {
    	Sleep(10000);
        return 1;
    }
    print_image(fptr);

    fclose(fptr);
    pthread_cancel(soundThread);
    pthread_join(soundThread, NULL);
    Sleep(10000);
    return 1;
}

void error1()									//errore file mancanti/corrotti
{
	int err1;
	system("cls");
	char *filename = "img/errors/6x01/6x01_icon.txt";
    FILE *fptr = NULL;
    pthread_create(&soundThread, NULL, playSoundError, NULL);

    if((fptr = fopen(filename,"r")) == NULL)
    {
		for(err1=0;err1<150;err1++){
			printUnder=1;
			printf("ERROR: missing or corrupt game files! (6x01)");
			printUnder=0;
			Sleep(100);
		}
        return 1;
    }
	printf(color_red "");
    print_image(fptr);

    fclose(fptr);

    printf(color_reset "");
    
    filename = "img/errors/6x01/6x01_text.txt";
    if((fptr = fopen(filename,"r")) == NULL)
    {
    	Sleep(10000);
        return 1;
    }
    print_image(fptr);

    fclose(fptr);
    pthread_cancel(soundThread);
    pthread_join(soundThread, NULL);
    Sleep(10000);
    return 1;
}

void printPowerPoints(){
	char *filename;
    FILE *fptr;
    printf(color_yellow "");
    printUnder=1;
	switch(ptsTotal){
		case 0:
			filename = "img/match/setup/setupComplete/sel_0.txt";
	        fptr = fopen(filename, "r");
	        if (fptr == NULL) {
	            error1();
	            return;
	        }
	        print_image(fptr);
	        fclose(fptr);
	        break;
	    case 1:
	    	filename = "img/match/setup/setupComplete/sel_1.txt";
	        fptr = fopen(filename, "r");
	        if (fptr == NULL) {
	            error1();
	            return;
	        }
	        print_image(fptr);
	        fclose(fptr);
	        break;
	    case 2:
	    	filename = "img/match/setup/setupComplete/sel_2.txt";
	        fptr = fopen(filename, "r");
	        if (fptr == NULL) {
	            error1();
	            return;
	        }
	        print_image(fptr);
	        fclose(fptr);
	        break;
	    case 3:
	    	filename = "img/match/setup/setupComplete/sel_3.txt";
	        fptr = fopen(filename, "r");
	        if (fptr == NULL) {
	            error1();
	            return;
	        }
	        print_image(fptr);
	        fclose(fptr);
	        break;
	    case 4:
	    	filename = "img/match/setup/setupComplete/sel_4.txt";
	        fptr = fopen(filename, "r");
	        if (fptr == NULL) {
	            error1();
	            return;
	        }
	        print_image(fptr);
	        fclose(fptr);
	        break;
	    case 5:
	    	filename = "img/match/setup/setupComplete/sel_5.txt";
	        fptr = fopen(filename, "r");
	        if (fptr == NULL) {
	            error1();
	            return;
	        }
	        print_image(fptr);
	        fclose(fptr);
	        break;
	    case 6:
	    	filename = "img/match/setup/setupComplete/sel_6.txt";
	        fptr = fopen(filename, "r");
	        if (fptr == NULL) {
	            error1();
	            return;
	        }
	        print_image(fptr);
	        fclose(fptr);
	        break;
	    case 7:
	    	filename = "img/match/setup/setupComplete/sel_7.txt";
	        fptr = fopen(filename, "r");
	        if (fptr == NULL) {
	            error1();
	            return;
	        }
	        print_image(fptr);
	        fclose(fptr);
	        break;
	    case 8:
	    	filename = "img/match/setup/setupComplete/sel_8.txt";
	        fptr = fopen(filename, "r");
	        if (fptr == NULL) {
	            error1();
	            return;
	        }
	        print_image(fptr);
	        fclose(fptr);
	        break;
	    case 9:
	    	filename = "img/match/setup/setupComplete/sel_9.txt";
	        fptr = fopen(filename, "r");
	        if (fptr == NULL) {
	            error1();
	            return;
	        }
	        print_image(fptr);
	        fclose(fptr);
	        break;
	    default:
	    	error3x01();
	}
	printf(color_reset "");
	printUnder=0;
}

void flushArrowKeysBuffer() {			//fflush per le frecce
    while (GetAsyncKeyState(VK_LEFT) & 0x8000) {
    }

   
    while (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
	}
}

void loadScreen() {  			//caricamento... [THREAD]
    char *filename;
    FILE *fptr;
    system("cls");
    while(loading!=1) {
        filename = "img/loading1.txt";
        fptr = fopen(filename, "r");
        if (fptr == NULL) {
            error1();
            return;
        }
        print_image(fptr);
        fclose(fptr);
        Sleep(1000);
        if(loading==1){
        	break;
		}

        filename = "img/loading2.txt";
        fptr = fopen(filename, "r");
        if (fptr == NULL) {
            error1();
            return;
        }
        print_image(fptr);
        fclose(fptr);
        Sleep(1000);
		if(loading==1){
        	break;
		}
        filename = "img/loading3.txt";
        fptr = fopen(filename, "r");
        if (fptr == NULL) {
            error1();
            return;
        }
        print_image(fptr);
        fclose(fptr);
        Sleep(1000);
		if(loading==1){
        	break;
		}
        filename = "img/loading4.txt";
        fptr = fopen(filename, "r");
        if (fptr == NULL) {
            error1();
            return;
        }
        print_image(fptr);
        fclose(fptr);
        Sleep(1000);
    }
}

void* playSoundMenu(void* arg) {		//thread musica menu
    while (1) {
        PlaySound(TEXT("sounds/menu_FNB-01.wav"), NULL, SND_SYNC);
        if (stopSuono == 1) {
            break;
        }
        PlaySound(TEXT("sounds/menu_FNB-02.wav"), NULL, SND_SYNC);
        if (stopSuono == 1) {
            break;
        }
        PlaySound(TEXT("sounds/menu_FNB-03.wav"), NULL, SND_SYNC);
        if (stopSuono == 1) {
            break;
        }
        PlaySound(TEXT("sounds/menu_FNB-04.wav"), NULL, SND_SYNC);
        if (stopSuono == 1) {
            break;
        }
        PlaySound(TEXT("sounds/menu_FNB-05.wav"), NULL, SND_SYNC);
        if (stopSuono == 1) {
            break;
        }
        PlaySound(TEXT("sounds/menu_FNB-06.wav"), NULL, SND_SYNC);
        if (stopSuono == 1) {
            break;
        }
        PlaySound(TEXT("sounds/menu_FNB-07.wav"), NULL, SND_SYNC);
        if (stopSuono == 1) {
            break;
        }
        PlaySound(TEXT("sounds/menu_FNB-08.wav"), NULL, SND_SYNC);
        if (stopSuono == 1) {
            break;
        }
        PlaySound(TEXT("sounds/menu_FNB-09.wav"), NULL, SND_SYNC);
        if (stopSuono == 1) {
            break;
        }
        PlaySound(TEXT("sounds/menu_FNB-10.wav"), NULL, SND_SYNC);
        if (stopSuono == 1) {
            break;
        }
        Sleep(2000);
        PlaySound(TEXT("sounds/menu_BSST-01.wav"), NULL, SND_SYNC);
        if (stopSuono == 1) {
            break;
        }
        PlaySound(TEXT("sounds/menu_BSST-02.wav"), NULL, SND_SYNC);
        if (stopSuono == 1) {
            break;
        }
        PlaySound(TEXT("sounds/menu_BSST-03.wav"), NULL, SND_SYNC);
        if (stopSuono == 1) {
            break;
        }
        PlaySound(TEXT("sounds/menu_BSST-04.wav"), NULL, SND_SYNC);
        if (stopSuono == 1) {
            break;
        }
        PlaySound(TEXT("sounds/menu_BSST-05.wav"), NULL, SND_SYNC);
        if (stopSuono == 1) {
            break;
        }
        PlaySound(TEXT("sounds/menu_BSST-06.wav"), NULL, SND_SYNC);
        if (stopSuono == 1) {
            break;
        }
        PlaySound(TEXT("sounds/menu_BSST-07.wav"), NULL, SND_SYNC);
        if (stopSuono == 1) {
            break;
        }
        PlaySound(TEXT("sounds/menu_BSST-08.wav"), NULL, SND_SYNC);
        if (stopSuono == 1) {
            break;
        }
        PlaySound(TEXT("sounds/menu_BSST-09.wav"), NULL, SND_SYNC);
        if (stopSuono == 1) {
            break;
        }
        PlaySound(TEXT("sounds/menu_BSST-10.wav"), NULL, SND_SYNC);
        if (stopSuono == 1) {
            break;
        }
        PlaySound(TEXT("sounds/menu_BSST-11.wav"), NULL, SND_SYNC);
        if (stopSuono == 1) {
            break;
        }
        PlaySound(TEXT("sounds/menu_BSST-12.wav"), NULL, SND_SYNC);
        if (stopSuono == 1) {
            break;
        }
        Sleep(2000);
    }
    return NULL;
}

void match_setup() {
    int minute = 0;
    int extraTime = 0;
    int selected = 1;
    int selectionDone=0;
    char* filename;
    FILE* fptr;

    filename = "img/match/setup/def1.txt";
    fptr = fopen(filename, "r");
    if (fptr == NULL) {
        error1();
        return;
    }
    print_image(fptr);
    fclose(fptr);
    printf("\033[58A");
    printPowerPoints();
    printUnder=1;
    filename = "img/road2final/continueok.txt";
    printUnder=0;
	fptr = fopen(filename, "r");
	if (fptr == NULL) {
	    error1();
	    return;
	}
	print_image(fptr);
	fclose(fptr);

    while (selectionDone!=1) {
    	//flushArrowKeysBuffer();
        if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {					//tasto freccia DESTRA per DEFENSE
            flushArrowKeysBuffer();
            selected++;
            if (selected >= 4) {
                selected = 3;
            }
            else if (selected==1){
            	ptsTotal--;
            	filename = "img/match/setup/def1.txt";
            	fptr = fopen(filename, "r");
		        if (fptr == NULL) {
		            error1();
		            return;
		        }
		        print_image(fptr);
		        fclose(fptr);
		        printf("\033[58A");
		        printPowerPoints();
		        printUnder=1;
			    filename = "img/road2final/continueok.txt";
			    printUnder=0;
			    fptr = fopen(filename, "r");
			    if (fptr == NULL) {
			        error1();
			        return;
			    }
			    print_image(fptr);
			    fclose(fptr);
			}
			else if (selected==2){
				ptsTotal--;
            	filename = "img/match/setup/def2.txt";
            	fptr = fopen(filename, "r");
		        if (fptr == NULL) {
		            error1();
		            return;
		        }
		        print_image(fptr);
		        fclose(fptr);
		        printf("\033[58A");
		        printPowerPoints();
		        printUnder=1;
			    filename = "img/road2final/continueok.txt";
			    printUnder=0;
			    fptr = fopen(filename, "r");
			    if (fptr == NULL) {
			        error1();
			        return;
			    }
			    print_image(fptr);
			    fclose(fptr);
			}
			else if (selected==3){
				ptsTotal--;
            	filename = "img/match/setup/def3.txt";
            	fptr = fopen(filename, "r");
		        if (fptr == NULL) {
		            error1();
		            return;
		        }
		        print_image(fptr);
		        fclose(fptr);
		        printf("\033[58A");
		        printPowerPoints();
		        printUnder=1;
			    filename = "img/road2final/continueok.txt";
			    printUnder=0;
			    fptr = fopen(filename, "r");
			    if (fptr == NULL) {
			        error1();
			        return;
			    }
			    print_image(fptr);
			    fclose(fptr);
			}
        }
        else if (GetAsyncKeyState(VK_LEFT) & 0x8000) {					//tasto freccia SINISTRA per DEFENSE
        	flushArrowKeysBuffer();
            selected--;
            if (selected < 1) {
                selected = 1;
            }
            else if (selected==1){
            	ptsTotal++;
            	filename = "img/match/setup/def1.txt";
            	fptr = fopen(filename, "r");
		        if (fptr == NULL) {
		            error1();
		            return;
		        }
		        print_image(fptr);
		        fclose(fptr);
		        printf("\033[58A");
		        printPowerPoints();
		        printUnder=1;
			    filename = "img/road2final/continueok.txt";
			    printUnder=0;
			    fptr = fopen(filename, "r");
			    if (fptr == NULL) {
			        error1();
			        return;
			    }
			    print_image(fptr);
			    fclose(fptr);
			}
			else if (selected==2){
				ptsTotal++;
            	filename = "img/match/setup/def2.txt";
            	fptr = fopen(filename, "r");
		        if (fptr == NULL) {
		            error1();
		            return;
		        }
		        print_image(fptr);
		        fclose(fptr);
		        printf("\033[58A");
		        printPowerPoints();
		        printUnder=1;
			    filename = "img/road2final/continueok.txt";
			    printUnder=0;
			    fptr = fopen(filename, "r");
			    if (fptr == NULL) {
			        error1();
			        return;
			    }
			    print_image(fptr);
			    fclose(fptr);
			}
			else if (selected==3){
				ptsTotal++;
            	filename = "img/match/setup/def3.txt";
            	fptr = fopen(filename, "r");
		        if (fptr == NULL) {
		            error1();
		            return;
		        }
		        print_image(fptr);
		        fclose(fptr);
		        printf("\033[58A");
		        printPowerPoints();
		        printUnder=1;
			    filename = "img/road2final/continueok.txt";
			    printUnder=0;
			    fptr = fopen(filename, "r");
			    if (fptr == NULL) {
			        error1();
			        return;
			    }
			    print_image(fptr);
			    fclose(fptr);
			}
        }
        else if (GetAsyncKeyState(VK_RETURN) & 0x8000) {					//tasto INVIO per DEFENSE
        	system("cls");
        	while (GetAsyncKeyState(VK_RETURN) & 0x8000) {
                // clear del buffer tasto invio...
            }
            selectionDone=1;
        }
        
    }
    def=selected;
    selected=1;
    selectionDone=0;
    filename = "img/match/setup/att1.txt";
	fptr = fopen(filename, "r");
    if (fptr == NULL) {
        error1();
        return;
    }
    print_image(fptr);
    fclose(fptr);
    printf("\033[58A");
    printPowerPoints();
    printUnder=1;
    filename = "img/road2final/continueok.txt";
    printUnder=0;
	fptr = fopen(filename, "r");
	if (fptr == NULL) {
	    error1();
	    return;
	}
	print_image(fptr);
	fclose(fptr);
		        
    while (selectionDone!=1) {
    //	flushArrowKeysBuffer();
        if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {					//tasto freccia DESTRA per ATTACK
            flushArrowKeysBuffer();
            selected++;
            if (selected >= 4) {
                selected = 3;
            }
            else if (selected==1){
            	ptsTotal--;
            	filename = "img/match/setup/att1.txt";
            	fptr = fopen(filename, "r");
		        if (fptr == NULL) {
		            error1();
		            return;
		        }
		        print_image(fptr);
		        fclose(fptr);
		        printf("\033[58A");
		        printPowerPoints();
		        printUnder=1;
			    filename = "img/road2final/continueok.txt";
			    printUnder=0;
			    fptr = fopen(filename, "r");
			    if (fptr == NULL) {
			        error1();
			        return;
			    }
			    print_image(fptr);
			    fclose(fptr);
			}
			else if (selected==2){
				ptsTotal--;
            	filename = "img/match/setup/att2.txt";
            	fptr = fopen(filename, "r");
		        if (fptr == NULL) {
		            error1();
		            return;
		        }
		        print_image(fptr);
		        fclose(fptr);
		        printf("\033[58A");
		        printPowerPoints();
		        printUnder=1;
			    filename = "img/road2final/continueok.txt";
			    printUnder=0;
			    fptr = fopen(filename, "r");
			    if (fptr == NULL) {
			        error1();
			        return;
			    }
			    print_image(fptr);
			    fclose(fptr);
			}
			else if (selected==3){
				ptsTotal--;
            	filename = "img/match/setup/att3.txt";
            	fptr = fopen(filename, "r");
		        if (fptr == NULL) {
		            error1();
		            return;
		        }
		        print_image(fptr);
		        fclose(fptr);
		        printf("\033[58A");
		        printPowerPoints();
		        printUnder=1;
			    filename = "img/road2final/continueok.txt";
			    printUnder=0;
			    fptr = fopen(filename, "r");
			    if (fptr == NULL) {
			        error1();
			        return;
			    }
			    print_image(fptr);
			    fclose(fptr);
			}
        }
        else if (GetAsyncKeyState(VK_LEFT) & 0x8000) {					//tasto freccia SINISTRA per ATTACK
        	flushArrowKeysBuffer();
            selected--;
            if (selected < 1) {
                selected = 1;
            }
            else if (selected==1){
            	ptsTotal++;
            	filename = "img/match/setup/att1.txt";
            	fptr = fopen(filename, "r");
		        if (fptr == NULL) {
		            error1();
		            return;
		        }
		        print_image(fptr);
		        fclose(fptr);
		        printf("\033[58A");
		        printPowerPoints();
		        printUnder=1;
			    filename = "img/road2final/continueok.txt";
			    printUnder=0;
			    fptr = fopen(filename, "r");
			    if (fptr == NULL) {
			        error1();
			        return;
			    }
			    print_image(fptr);
			    fclose(fptr);
			}
			else if (selected==2){
				ptsTotal++;
            	filename = "img/match/setup/att2.txt";
            	fptr = fopen(filename, "r");
		        if (fptr == NULL) {
		            error1();
		            return;
		        }
		        print_image(fptr);
		        fclose(fptr);
		        printf("\033[58A");
		        printPowerPoints();
		        printUnder=1;
			    filename = "img/road2final/continueok.txt";
			    printUnder=0;
			    fptr = fopen(filename, "r");
			    if (fptr == NULL) {
			        error1();
			        return;
			    }
			    print_image(fptr);
			    fclose(fptr);
			}
			else if (selected==3){
				ptsTotal++;
            	filename = "img/match/setup/att3.txt";
            	fptr = fopen(filename, "r");
		        if (fptr == NULL) {
		            error1();
		            return;
		        }
		        print_image(fptr);
		        fclose(fptr);
		        printf("\033[58A");
		        printPowerPoints();
		        printUnder=1;
			    filename = "img/road2final/continueok.txt";
			    printUnder=0;
			    fptr = fopen(filename, "r");
			    if (fptr == NULL) {
			        error1();
			        return;
			    }
			    print_image(fptr);
			    fclose(fptr);
			}
        }
        else if (GetAsyncKeyState(VK_RETURN) & 0x8000) {					//tasto INVIO per ATTACK
        	system("cls");
        	while (GetAsyncKeyState(VK_RETURN) & 0x8000) {
                // clear del buffer tasto invio...
            }
            selectionDone=1;
        }
        
    }
    att=selected;
    selected=1;
    selectionDone=0;
    filename = "img/match/setup/aggr1.txt";
	fptr = fopen(filename, "r");
    if (fptr == NULL) {
        error1();
        return;
    }
    print_image(fptr);
    fclose(fptr);
    printf("\033[58A");
    printPowerPoints();
    printUnder=1;
    filename = "img/road2final/continueok.txt";
    printUnder=0;
	fptr = fopen(filename, "r");
	if (fptr == NULL) {
	    error1();
	    return;
	}
	print_image(fptr);
	fclose(fptr);
    while (selectionDone!=1) {
    	//flushArrowKeysBuffer();
        if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {					//tasto freccia DESTRA per AGGRESSIVENESS
            flushArrowKeysBuffer();
            selected++;
            if (selected >= 4) {
                selected = 3;
            }
            else if (selected==1){
            	ptsTotal--;
            	filename = "img/match/setup/aggr1.txt";
            	fptr = fopen(filename, "r");
		        if (fptr == NULL) {
		            error1();
		            return;
		        }
		        print_image(fptr);
		        fclose(fptr);
		        printf("\033[58A");
		        printPowerPoints();
		        printUnder=1;
			    filename = "img/road2final/continueok.txt";
			    printUnder=0;
			    fptr = fopen(filename, "r");
			    if (fptr == NULL) {
			        error1();
			        return;
			    }
			    print_image(fptr);
			    fclose(fptr);
			}
			else if (selected==2){
				ptsTotal--;
            	filename = "img/match/setup/aggr2.txt";
            	fptr = fopen(filename, "r");
		        if (fptr == NULL) {
		            error1();
		            return;
		        }
		        print_image(fptr);
		        fclose(fptr);
		        printf("\033[58A");
		        printPowerPoints();
		        printUnder=1;
			    filename = "img/road2final/continueok.txt";
			    printUnder=0;
			    fptr = fopen(filename, "r");
			    if (fptr == NULL) {
			        error1();
			        return;
			    }
			    print_image(fptr);
			    fclose(fptr);
			}
			else if (selected==3){
				ptsTotal--;
            	filename = "img/match/setup/aggr3.txt";
            	fptr = fopen(filename, "r");
		        if (fptr == NULL) {
		            error1();
		            return;
		        }
		        print_image(fptr);
		        fclose(fptr);
		        printf("\033[58A");
		        printPowerPoints();
		        printUnder=1;
			    filename = "img/road2final/continueok.txt";
			    printUnder=0;
			    fptr = fopen(filename, "r");
			    if (fptr == NULL) {
			        error1();
			        return;
			    }
			    print_image(fptr);
			    fclose(fptr);
			}
        }
        else if (GetAsyncKeyState(VK_LEFT) & 0x8000) {					//tasto freccia SINISTRA per AGGRESSIVENESS
        	flushArrowKeysBuffer();
            selected--;
            if (selected < 1) {
                selected = 1;
            }
            else if (selected==1){
            	ptsTotal++;
            	filename = "img/match/setup/aggr1.txt";
            	fptr = fopen(filename, "r");
		        if (fptr == NULL) {
		            error1();
		            return;
		        }
		        print_image(fptr);
		        fclose(fptr);
		        printf("\033[58A");
		        printPowerPoints();
		        printUnder=1;
			    filename = "img/road2final/continueok.txt";
			    printUnder=0;
			    fptr = fopen(filename, "r");
			    if (fptr == NULL) {
			        error1();
			        return;
			    }
			    print_image(fptr);
			    fclose(fptr);
			}
			else if (selected==2){
				ptsTotal++;
            	filename = "img/match/setup/aggr2.txt";
            	fptr = fopen(filename, "r");
		        if (fptr == NULL) {
		            error1();
		            return;
		        }
		        print_image(fptr);
		        fclose(fptr);
		        printf("\033[58A");
		        printPowerPoints();
		        printUnder=1;
			    filename = "img/road2final/continueok.txt";
			    printUnder=0;
			    fptr = fopen(filename, "r");
			    if (fptr == NULL) {
			        error1();
			        return;
			    }
			    print_image(fptr);
			    fclose(fptr);
			}
			else if (selected==3){
				ptsTotal++;
            	filename = "img/match/setup/aggr3.txt";
            	fptr = fopen(filename, "r");
		        if (fptr == NULL) {
		            error1();
		            return;
		        }
		        print_image(fptr);
		        fclose(fptr);
		        printf("\033[58A");
		        printPowerPoints();
		        printUnder=1;
			    filename = "img/road2final/continueok.txt";
			    printUnder=0;
			    fptr = fopen(filename, "r");
			    if (fptr == NULL) {
			        error1();
			        return;
			    }
			    print_image(fptr);
			    fclose(fptr);
			}
        }
        else if (GetAsyncKeyState(VK_RETURN) & 0x8000) {					//tasto INVIO per AGGRESSIVENESS
        	system("cls");
        	while (GetAsyncKeyState(VK_RETURN) & 0x8000) {
                // clear del buffer tasto invio...
            }
            selectionDone=1;
        }
        
    }
    aggr=selected;
    
	system("cls");
	printUnder=1;
    															//print dei valori selezionati dall'utente e conferma o ri-esecuzione
    filename = "img/match/setup/setupComplete/def_txt_only.txt";
	fptr = fopen(filename, "r");
    if (fptr == NULL) {
        error1();
        return;
    }
    printf("\n\n\n\n");
    print_image(fptr);
    fclose(fptr);
    printf(color_yellow "\033[26A");
    printNextToOther=1;
    switch(def){																		//print punti DEF
    	case 1:
    		filename = "img/match/setup/setupComplete/sel_1.txt";
			fptr = fopen(filename, "r");
		    if (fptr == NULL) {
		        error1();
		        return;
		    }
		    print_image(fptr);
		    fclose(fptr);
		    printf(color_reset "");
		    break;
		case 2:
			filename = "img/match/setup/setupComplete/sel_2.txt";
			fptr = fopen(filename, "r");
		    if (fptr == NULL) {
		        error1();
		        return;
		    }
		    print_image(fptr);
		    fclose(fptr);
		    printf(color_reset "");
		    break;
		case 3:
			filename = "img/match/setup/setupComplete/sel_3.txt";
			fptr = fopen(filename, "r");
		    if (fptr == NULL) {
		        error1();
		        return;
		    }
		    print_image(fptr);
		    fclose(fptr);
		    printf(color_reset "");
		    break;
		default:
			printf(color_reset "");
			error3x01();
			break;
		}
		printNextToOther=0;
    filename = "img/match/setup/setupComplete/att_txt_only.txt";
	fptr = fopen(filename, "r");
    if (fptr == NULL) {
        error1();
        return;
    }
    printf("\n\n\n\n");
    print_image(fptr);
    fclose(fptr);
    printf(color_yellow "\033[26A");
    printNextToOther=1;
    switch(att){																		//print punti ATT
    	case 1:
    		filename = "img/match/setup/setupComplete/sel_1.txt";
			fptr = fopen(filename, "r");
		    if (fptr == NULL) {
		        error1();
		        return;
		    }
		    print_image(fptr);
		    fclose(fptr);
		    printf(color_reset "");
		    break;
		case 2:
			filename = "img/match/setup/setupComplete/sel_2.txt";
			fptr = fopen(filename, "r");
		    if (fptr == NULL) {
		        error1();
		        return;
		    }
		    print_image(fptr);
		    fclose(fptr);
		    printf(color_reset "");
		    break;
		case 3:
			filename = "img/match/setup/setupComplete/sel_3.txt";
			fptr = fopen(filename, "r");
		    if (fptr == NULL) {
		        error1();
		        return;
		    }
		    print_image(fptr);
		    fclose(fptr);
		    printf(color_reset "");
		    break;
		default:
			printf(color_reset "");
			error3x01();
			break;
		}
	printNextToOther=0;
    filename = "img/match/setup/setupComplete/aggr_txt_only.txt";
	fptr = fopen(filename, "r");
    if (fptr == NULL) {
        error1();
        return;
    }
    printf("\n\n\n\n");
    print_image(fptr);
    fclose(fptr);
    printf(color_yellow "\033[26A");
    printNextToOther=1;
    switch(aggr){																		//print punti AGGR
    	case 1:
    		filename = "img/match/setup/setupComplete/sel_1.txt";
			fptr = fopen(filename, "r");
		    if (fptr == NULL) {
		        error1();
		        return;
		    }
		    print_image(fptr);
		    fclose(fptr);
		    printf(color_reset "");
		    break;
		case 2:
			filename = "img/match/setup/setupComplete/sel_2.txt";
			fptr = fopen(filename, "r");
		    if (fptr == NULL) {
		        error1();
		        return;
		    }
		    print_image(fptr);
		    fclose(fptr);
		    printf(color_reset "");
		    break;
		case 3:
			filename = "img/match/setup/setupComplete/sel_3.txt";
			fptr = fopen(filename, "r");
		    if (fptr == NULL) {
		        error1();
		        return;
		    }
		    print_image(fptr);
		    fclose(fptr);
		    printf(color_reset "");
		    break;
		default:
			printf(color_reset "");
			error3x01();
			break;
		}
	printNextToOther=0;
    filename = "img/road2final/continueok.txt";
    fptr = fopen(filename, "r");
    if (fptr == NULL) {
        error1();
        return;
    	}
    	printf("\n\n\n\n\n\n\n");
    print_image(fptr);
    printUnder=0;
    fclose(fptr);
    Sleep(3000);
    matchday();
	}

void printStats(){
	printUnder=1;
	
	char* filename;
    FILE* fptr;
	filename = "img/match/stats.txt";
    fptr = fopen(filename, "r");
    if (fptr == NULL) {
        error1();
        return;
    	}
    printf(color_cyan "");
  	printf("\033[500D");
  	printf("\033[83A");
    print_image(fptr);
    printf(color_reset"");
    fclose(fptr);
	
	switch(playerSCORE){
		case 0:
			filename = "img/match/numbers/0.txt";
			break;
		case 1:
			filename = "img/match/numbers/1.txt";
			break;
		case 2:
			filename = "img/match/numbers/2.txt";
			break;
		case 3:
			filename = "img/match/numbers/3.txt";
			break;
		case 4:
			filename = "img/match/numbers/4.txt";
			break;
		case 5:
			filename = "img/match/numbers/5.txt";
			break;
		case 6:
			filename = "img/match/numbers/6.txt";
			break;
		case 7:
			filename = "img/match/numbers/7.txt";
			break;
		case 8:
			filename = "img/match/numbers/8.txt";
			break;
		case 9:
			filename = "img/match/numbers/9.txt";
			break;
		
	}
    fptr = fopen(filename, "r");
    if (fptr == NULL) {
        error1();
        return;
    	}
    printf(color_red "");
  	printf("\033[500D");
  	printf("\033[67A");
  	printNumberSX=1;
    print_image(fptr);
    printNumberSX=0;
    printf(color_reset"");
    fclose(fptr);
    
    switch(foulsPLA){
    	case 0:
			filename = "img/match/numbers/0.txt";
			break;
		case 1:
			filename = "img/match/numbers/1.txt";
			break;
		case 2:
			filename = "img/match/numbers/2.txt";
			break;
		case 3:
			filename = "img/match/numbers/3.txt";
			break;
		case 4:
			filename = "img/match/numbers/4.txt";
			break;
		case 5:
			filename = "img/match/numbers/5.txt";
			break;
		case 6:
			filename = "img/match/numbers/6.txt";
			break;
		case 7:
			filename = "img/match/numbers/7.txt";
			break;
		case 8:
			filename = "img/match/numbers/8.txt";
			break;
		case 9:
			filename = "img/match/numbers/9.txt";
			break;
	}
    
    fptr = fopen(filename, "r");
    if (fptr == NULL) {
        error1();
        return;
    	}
    printf(color_red "");
  	printf("\033[24D");
  	printf("\033[19B");
  	printNumberSX=1;
    print_image(fptr);
    printNumberSX=0;
    printf(color_reset"");
    fclose(fptr);
    
    switch(offsPLA){
    	case 0:
			filename = "img/match/numbers/0.txt";
			break;
		case 1:
			filename = "img/match/numbers/1.txt";
			break;
		case 2:
			filename = "img/match/numbers/2.txt";
			break;
		case 3:
			filename = "img/match/numbers/3.txt";
			break;
		case 4:
			filename = "img/match/numbers/4.txt";
			break;
		case 5:
			filename = "img/match/numbers/5.txt";
			break;
		case 6:
			filename = "img/match/numbers/6.txt";
			break;
		case 7:
			filename = "img/match/numbers/7.txt";
			break;
		case 8:
			filename = "img/match/numbers/8.txt";
			break;
		case 9:
			filename = "img/match/numbers/9.txt";
			break;
	}
    
    fptr = fopen(filename, "r");
    if (fptr == NULL) {
        error1();
        return;
    	}
    printf(color_red "");
  	printf("\033[24D");
  	printf("\033[16B");
  	printNumberSX=1;
    print_image(fptr);
    printNumberSX=0;
    printf(color_reset"");
    fclose(fptr);
    
    switch(cpuSCORE){
    	case 0:
			filename = "img/match/numbers/0.txt";
			break;
		case 1:
			filename = "img/match/numbers/1.txt";
			break;
		case 2:
			filename = "img/match/numbers/2.txt";
			break;
		case 3:
			filename = "img/match/numbers/3.txt";
			break;
		case 4:
			filename = "img/match/numbers/4.txt";
			break;
		case 5:
			filename = "img/match/numbers/5.txt";
			break;
		case 6:
			filename = "img/match/numbers/6.txt";
			break;
		case 7:
			filename = "img/match/numbers/7.txt";
			break;
		case 8:
			filename = "img/match/numbers/8.txt";
			break;
		case 9:
			filename = "img/match/numbers/9.txt";
			break;
	}
    
    fptr = fopen(filename, "r");
    if (fptr == NULL) {
        error1();
        return;
    	}
    printf(color_yellow "");
  	printf("\033[59A");
  	printf("\033[500D");
  	printNumberDX=1;
    print_image(fptr);
    printNumberDX=0;
    printf(color_reset"");
    fclose(fptr);
    
    switch(foulsCPU){
    	case 0:
			filename = "img/match/numbers/0.txt";
			break;
		case 1:
			filename = "img/match/numbers/1.txt";
			break;
		case 2:
			filename = "img/match/numbers/2.txt";
			break;
		case 3:
			filename = "img/match/numbers/3.txt";
			break;
		case 4:
			filename = "img/match/numbers/4.txt";
			break;
		case 5:
			filename = "img/match/numbers/5.txt";
			break;
		case 6:
			filename = "img/match/numbers/6.txt";
			break;
		case 7:
			filename = "img/match/numbers/7.txt";
			break;
		case 8:
			filename = "img/match/numbers/8.txt";
			break;
		case 9:
			filename = "img/match/numbers/9.txt";
			break;
	}
    
    fptr = fopen(filename, "r");
    if (fptr == NULL) {
        error1();
        return;
    	}
    printf(color_yellow "");
  	printf("\033[500D");
  	printf("\033[19B");
  	printNumberDX=1;
    print_image(fptr);
    printNumberDX=0;
    printf(color_reset"");
    fclose(fptr);
    
    switch(offsCPU){
    	case 0:
			filename = "img/match/numbers/0.txt";
			break;
		case 1:
			filename = "img/match/numbers/1.txt";
			break;
		case 2:
			filename = "img/match/numbers/2.txt";
			break;
		case 3:
			filename = "img/match/numbers/3.txt";
			break;
		case 4:
			filename = "img/match/numbers/4.txt";
			break;
		case 5:
			filename = "img/match/numbers/5.txt";
			break;
		case 6:
			filename = "img/match/numbers/6.txt";
			break;
		case 7:
			filename = "img/match/numbers/7.txt";
			break;
		case 8:
			filename = "img/match/numbers/8.txt";
			break;
		case 9:
			filename = "img/match/numbers/9.txt";
			break;
	}
    
    fptr = fopen(filename, "r");
    if (fptr == NULL) {
        error1();
        return;
    	}
    printf(color_yellow "");
  	printf("\033[500D");
  	printf("\033[16B");
  	printNumberDX=1;
    print_image(fptr);
    printNumberDX=0;
    printf(color_reset"");
    printUnder=0;
    fclose(fptr);
}

void matchday(){
	int codeChrono, addedTime=99, matchTime=0, addedTimeCheck=0, halfNo=1, halfLenght=45;
	int attCPU, defCPU, aggrCPU;
	int ballPOS=0;
	int rand1;
	int randEVENT;
	
	srand(time(NULL));
	
	attCPU=rand() % (3 + 1);
	defCPU=rand() % (3 + 1);
	aggrCPU=rand() % (3 + 1);
	system("cls");
	
	char* filename;
    FILE* fptr;
    
    for (codeChrono=0;codeChrono<=halfLenght;codeChrono++)
		{
			switch (addedTime)
			{
				case 99:
					printf("%d'\n", matchTime);
					break;
				default:
					printf("%d' [+%d']\n",matchTime, addedTime);
			}

			if (codeChrono==halfLenght-1&& addedTimeCheck==0)
			{
				addedTime=rand() % 5+0;
				codeChrono=codeChrono-addedTime;
				addedTimeCheck++;
			}
			
			switch(ballPOS){
				case 0:
					filename = "img/match/pressing.txt";
				    fptr = fopen(filename, "r");
				    if (fptr == NULL) {
				        error1();
				        return;
				    }
				    print_field(fptr);
				    printStats();
				    fclose(fptr);
				    Sleep(500);
				    randEVENT=rand() % (20+1);
				    rand1=rand() % (10 + 1);
				    /*if(randEVENT==19){
				    	filename = "img/match/offside.txt";
					    fptr = fopen(filename, "r");
					    if (fptr == NULL) {
					        error1();
					        return;
					    }
					    print_field(fptr);
					    Sleep(1000);
					    fclose(fptr);
					    break;
					}else */if(randEVENT==20){
						filename = "img/match/ballout.txt";
					    fptr = fopen(filename, "r");
					    if (fptr == NULL) {
					        error1();
					        return;
					    }
					    print_field(fptr);
					    printStats();
					    Sleep(1000);
					    fclose(fptr);
					    break;
					}
				    /*if(rand1<aggr){
				    	filename = "img/match/foul.txt";
					    fptr = fopen(filename, "r");
					    if (fptr == NULL) {
					        error1();
					        return;
					    }
					    print_field(fptr);
					    Sleep(1000);
					    fclose(fptr);
					}else */if (rand1>5){
						if (rand1>def*3){
							ballPOS--;
						}
					}else if (rand1<5){
						if (rand1<att*3){
							ballPOS++;
						}
					}
					break;
				case 1:
					filename = "img/match/attack1.txt";
				    fptr = fopen(filename, "r");
				    if (fptr == NULL) {
				        error1();
				        return;
				    }
				    print_field(fptr);
				    printStats();
				    fclose(fptr);
				    Sleep(500);
				    randEVENT=rand() % (20+1);
				    rand1=rand() % (10 + 1);
				    ballPossTOT++;
					ballPossPLA++;
				    if(randEVENT==19){
				    	filename = "img/match/offside.txt";
				    	offsPLA++;
					    fptr = fopen(filename, "r");
					    if (fptr == NULL) {
					        error1();
					        return;
					    }
					    print_field(fptr);
					    printStats();
					    Sleep(1000);
					    fclose(fptr);
					    ballPOS--;
					    break;
					}else if(randEVENT==20){
						filename = "img/match/ballout.txt";
					    fptr = fopen(filename, "r");
					    if (fptr == NULL) {
					        error1();
					        return;
					    }
					    print_field(fptr);
					    printStats();
					    Sleep(1000);
					    fclose(fptr);
					    break;
					}
				    if(rand1*2<aggr){
				    	foulsCPU++;
				    	filename = "img/match/foul.txt";
					    fptr = fopen(filename, "r");
					    if (fptr == NULL) {
					        error1();
					        return;
					    }
					    print_field(fptr);
					    printStats();
					    Sleep(1000);
					    fclose(fptr);
					}else if (rand1>5){
						if (rand1>def*3){
							ballPOS--;
						}
					}else if (rand1<5){
						if (rand1<att*3){
							ballPOS++;
						}
					}
					break;
				case 2:
					filename = "img/match/attack2.txt";
				    fptr = fopen(filename, "r");
				    if (fptr == NULL) {
				        error1();
				        return;
				    }
				    print_field(fptr);
				    printStats();
				    fclose(fptr);
				    Sleep(500);
				    randEVENT=rand() % (20+1);
				    rand1=rand() % (10 + 1);
				    ballPossTOT++;
					ballPossPLA++;
				    if(randEVENT==19){
				    	filename = "img/match/offside.txt";
				    	offsPLA++;
					    fptr = fopen(filename, "r");
					    if (fptr == NULL) {
					        error1();
					        return;
					    }
					    print_field(fptr);
					    printStats();
					    Sleep(1000);
					    fclose(fptr);
					    ballPOS--;
					    break;
					}else if(randEVENT==20){
						filename = "img/match/ballout.txt";
					    fptr = fopen(filename, "r");
					    if (fptr == NULL) {
					        error1();
					        return;
					    }
					    print_field(fptr);
					    printStats();
					    Sleep(1000);
					    fclose(fptr);
					    break;
					}
				    if(rand1*2<aggr){
				    	foulsCPU++;
				    	filename = "img/match/foul.txt";
					    fptr = fopen(filename, "r");
					    if (fptr == NULL) {
					        error1();
					        return;
					    }
					    print_field(fptr);
					    printStats();
					    Sleep(1000);
					    fclose(fptr);
					}else if (rand1>5){
						if (rand1>def*3){
							ballPOS--;
						}
					}else if (rand1<5){
						if (rand1<att*3){
							ballPOS++;
						}
					}
					break;
				case 3:
					filename = "img/match/attack3.txt";
				    fptr = fopen(filename, "r");
				    if (fptr == NULL) {
				        error1();
				        return;
				    }
				    print_field(fptr);
				    printStats();
				    fclose(fptr);
				    Sleep(500);
				    randEVENT=rand() % (20+1);
				    rand1=rand() % (10 + 1);
				    ballPossTOT++;
					ballPossPLA++;
				    if(randEVENT==19){
				    	filename = "img/match/offside.txt";
				    	offsPLA++;
					    fptr = fopen(filename, "r");
					    if (fptr == NULL) {
					        error1();
					        return;
					    }
					    print_field(fptr);
					    printStats();
					    Sleep(1000);
					    fclose(fptr);
					    ballPOS--;
					    break;
					}else if(randEVENT==20){
						filename = "img/match/ballout.txt";
					    fptr = fopen(filename, "r");
					    if (fptr == NULL) {
					        error1();
					        return;
					    }
					    print_field(fptr);
					    printStats();
					    Sleep(1000);
					    fclose(fptr);
					    break;
					}
				    if(rand1*2<aggr){
				    	foulsCPU++;
				    	filename = "img/match/penalty.txt";
					    fptr = fopen(filename, "r");
					    if (fptr == NULL) {
					        error1();
					        return;
					    }
					    print_field(fptr);
					    printStats();
					    Sleep(3000);
					    fclose(fptr);
					    //matchdayPenalty();									DA IMPLEMENTARE
					}else if (rand1>5){
						if (rand1>def*3){
							ballPOS--;
						}
					}else if (rand1<5){
						if (rand1<att*3){
							ballPOS++;
						}
					}
					break;
				case 4:
					filename = "img/match/goal.txt";
				    fptr = fopen(filename, "r");
				    if (fptr == NULL) {
				        error1();
				        return;
				    }
				    print_field(fptr);
				    printStats();
				    Sleep(3000);
				    fclose(fptr);
				    playerSCORE++;
				    ballPOS=0;
				    break;
				case -1:
					filename = "img/match/defense1.txt";
				    fptr = fopen(filename, "r");
				    if (fptr == NULL) {
				        error1();
				        return;
				    }
				    print_field(fptr);
				    printStats();
				    fclose(fptr);
				    Sleep(500);
				    randEVENT=rand() % (20+1);
				    rand1=rand() % (10 + 1);
				    ballPossTOT++;
					ballPossCPU++;
				    if(randEVENT==19){
				    	filename = "img/match/offside.txt";
				    	offsCPU++;
					    fptr = fopen(filename, "r");
					    if (fptr == NULL) {
					        error1();
					        return;
					    }
					    print_field(fptr);
					    printStats();
					    Sleep(1000);
					    fclose(fptr);
					    ballPOS++;
					    break;
					}else if(randEVENT==20){
						filename = "img/match/ballout.txt";
					    fptr = fopen(filename, "r");
					    if (fptr == NULL) {
					        error1();
					        return;
					    }
					    print_field(fptr);
					    printStats();
					    Sleep(1000);
					    fclose(fptr);
					    break;
					}
				    if(rand1*2<aggrCPU){
				    	foulsPLA++;
				    	filename = "img/match/foul.txt";
					    fptr = fopen(filename, "r");
					    if (fptr == NULL) {
					        error1();
					        return;
					    }
					    print_field(fptr);
					    printStats();
					    Sleep(1000);
					    fclose(fptr);
					}else if (rand1>5){
						if (rand1>def*3){
							ballPOS--;
						}
					}else if (rand1<5){
						if (rand1<att*3){
							ballPOS++;
						}
					}
					break;
				case -2:
					filename = "img/match/defense2.txt";
				    fptr = fopen(filename, "r");
				    if (fptr == NULL) {
				        error1();
				        return;
				    }
				    print_field(fptr);
				    printStats();
				    fclose(fptr);
				    Sleep(500);
				    randEVENT=rand() % (20+1);
				    rand1=rand() % (10 + 1);
				    ballPossTOT++;
					ballPossCPU++;
				    if(randEVENT==19){
				    	filename = "img/match/offside.txt";
				    	offsCPU++;
					    fptr = fopen(filename, "r");
					    if (fptr == NULL) {
					        error1();
					        return;
					    }
					    print_field(fptr);
					    printStats();
					    Sleep(1000);
					    fclose(fptr);
					    ballPOS++;
					    break;
					}else if(randEVENT==20){
						filename = "img/match/ballout.txt";
					    fptr = fopen(filename, "r");
					    if (fptr == NULL) {
					        error1();
					        return;
					    }
					    print_field(fptr);
					    printStats();
					    Sleep(1000);
					    fclose(fptr);
					    break;
					}
				    if(rand1*2<aggrCPU){
				    	foulsPLA++;
				    	filename = "img/match/foul.txt";
					    fptr = fopen(filename, "r");
					    if (fptr == NULL) {
					        error1();
					        return;
					    }
					    print_field(fptr);
					    printStats();
					    Sleep(1000);
					    fclose(fptr);
					}else if (rand1>5){
						if (rand1>def*3){
							ballPOS--;
						}
					}else if (rand1<5){
						if (rand1<att*3){
							ballPOS++;
						}
					}
					break;
				case -3:
					filename = "img/match/defense3.txt";
				    fptr = fopen(filename, "r");
				    if (fptr == NULL) {
				        error1();
				        return;
				    }
				    print_field(fptr);
				    printStats();
				    fclose(fptr);
				    Sleep(500);
				    randEVENT=rand() % (20+1);
				    rand1=rand() % (10 + 1);
				    ballPossTOT++;
					ballPossCPU++;
				    if(randEVENT==19){
				    	filename = "img/match/offside.txt";
				    	offsCPU++;
					    fptr = fopen(filename, "r");
					    if (fptr == NULL) {
					        error1();
					        return;
					    }
					    print_field(fptr);
					    printStats();
					    Sleep(1000);
					    fclose(fptr);
					    ballPOS++;
					    break;
					}else if(randEVENT==20){
						filename = "img/match/ballout.txt";
					    fptr = fopen(filename, "r");
					    if (fptr == NULL) {
					        error1();
					        return;
					    }
					    print_field(fptr);
					    printStats();
					    Sleep(1000);
					    fclose(fptr);
					    break;
					}
				    if(rand1*2<aggrCPU){
				    	foulsPLA++;
				    	filename = "img/match/penalty.txt";
					    fptr = fopen(filename, "r");
					    if (fptr == NULL) {
					        error1();
					        return;
					    }
					    print_field(fptr);
					    printStats();
					    Sleep(3000);
					    fclose(fptr);
					    //matchdayPenalty();									DA IMPLEMENTARE
					}else if (rand1>5){
						if (rand1>def*3){
							ballPOS--;
						}
					}else if (rand1<5){
						if (rand1<att*3){
							ballPOS++;
						}
					}
					break;
				case -4:
					filename = "img/match/goalcpu.txt";
				    fptr = fopen(filename, "r");
				    if (fptr == NULL) {
				        error1();
				        return;
				    }
				    print_field(fptr);
				    printStats();
				    Sleep(3000);
				    fclose(fptr);
				    cpuSCORE++;
				    ballPOS=0;
				    break;
					
				}
			matchTime++;
			Sleep(1000);
			
			
		/*	//DEV INFO
			printf("DIFF %d-%d-%d\nMIN %d'+%d\nSCORE %d-%d",defCPU,attCPU,aggrCPU,matchTime,addedTime,playerSCORE,cpuSCORE);
			Sleep(2000);*/
			}    
		printHalftimeStats();
}

void road2final(){
	int pressed=0;
	
	system("cls");
	char* filename;
    FILE* fptr;
    filename = "img/road2final/r16.txt";
    fptr = fopen(filename, "r");
    if (fptr == NULL) {
        error1();
        return;
    }
    Sleep(3000);
    print_image(fptr);
    fclose(fptr);
    PlaySound(TEXT("sounds/next_game.wav"),NULL,SND_SYNC);
    Sleep(1500);
    filename = "img/road2final/continueok.txt";
    fptr = fopen(filename, "r");
    if (fptr == NULL) {
        error1();
        return;
    }
    print_image(fptr);
    fclose(fptr);
   /* while(pressed=0){
	    if (GetAsyncKeyState(VK_RETURN) & 0x8000){
	    		pressed=1;
				match_setup();
			}
    	
	}*/
	Sleep(3000);
	match_setup();
}

void menu() {				//menu!!!
	int menuSelection;
	int selectInProgress=1;
    pthread_create(&soundThread, NULL, playSoundMenu, NULL);

    char* filename;
    FILE* fptr;
    filename = "img/menu/uclfinal.txt";
    fptr = fopen(filename, "r");
    if (fptr == NULL) {
        error1();
        return;
    }
    print_image(fptr);
    fclose(fptr);
    menuSelection=0;
	
	while(selectInProgress==1){
	    if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
	    	flushArrowKeysBuffer();
	        menuSelection++;
	        if(menuSelection>1)
	        {
	        	menuSelection=0;
			}
	        switch(menuSelection){
	        	case 0:
	        		filename = "img/menu/uclfinal.txt";
				    fptr = fopen(filename, "r");
				    if (fptr == NULL) {
				        error1();
				        return;
					    }
				    print_image(fptr);
				    fclose(fptr);
				    break;
				case 1:
					filename = "img/menu/road2final.txt";
				    fptr = fopen(filename, "r");
				    if (fptr == NULL) {
				        error1();
				        return;
					    }
				    print_image(fptr);
				    fclose(fptr);
				    break;
			}
	    }
	    else if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
	    	flushArrowKeysBuffer();
	        menuSelection--;
	        if(menuSelection<0)
	        {
	        	menuSelection=1;
			}
	        switch(menuSelection){
	        	case 0:
	        		filename = "img/menu/uclfinal.txt";
				    fptr = fopen(filename, "r");
				    if (fptr == NULL) {
				        error1();
				        return;
					    }
				    print_image(fptr);
				    fclose(fptr);
				    break;
				case 1:
					filename = "img/menu/road2final.txt";
				    fptr = fopen(filename, "r");
				    if (fptr == NULL) {
				        error1();
				        return;
					    }
				    print_image(fptr);
				    fclose(fptr);
				    break;
			}
	    }
	    else if (GetAsyncKeyState(VK_RETURN) & 0x8000){
			selectInProgress=0;
		}
	}
	
	loading=0;
    pthread_create(&loadThread, NULL, loadScreen, NULL);
    stopSuono = 1;
    pthread_cancel(soundThread);
    pthread_join(soundThread, NULL);
    
    loading=1;
    pthread_join(loadThread, NULL);
    
    switch(menuSelection){
    	case 0:
    		//
    		break;
    	case 1:
    		road2final();
    		break;
	}
    return;

}

void* playSound(void* arg) {							//thread musica intro
    PlaySound(TEXT("sounds/anthem.wav"),NULL,SND_SYNC);
    return NULL;
}

void print_image(FILE *fptr);

int main(void)						//intro
{
	pthread_create(&soundThread, NULL, playSound, NULL);
	
	
	
    // Enable ANSI escape sequences in Windows Command Prompt
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwMode = 0;
    GetConsoleMode(hOut, &dwMode);
    SetConsoleMode(hOut, dwMode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);
    
    

    char *filename = "img/image.txt";
    FILE *fptr = NULL;

    if((fptr = fopen(filename,"r")) == NULL)
    {
        error1();
        return 1;
    }
	printf(color_cyan "");
    print_image(fptr);

    fclose(fptr);

    printf(color_reset "");
    
    pthread_join(soundThread, NULL);
    
    Sleep(2000);
    
    menu();
    
    return 0;
}
	int intro=1;		//debug 0

void print_image(FILE *fptr)						//script print txt
{ 

    char read_string[MAX_LEN];

    while(fgets(read_string,sizeof(read_string),fptr) != NULL){
    	if(printNextToOther==1){
    		printf("\033[145C");
		}
		if(printNumberSX==1){
			printf("\033[7C");
		} else if (printNumberDX==1){
			printf("\033[42C");
		}else if(printHalfT1==1){
			printf("\033[25C");
		}else if(printHalfT2==1){
			printf("\033[160C");
		}
        printf("%s",read_string);
        if(intro==1){
        	Sleep(100);
		}
    }
    intro=0;
}                             

void print_field(FILE *fptr)						//script print campo
{ 
    char read_string[MAX_LEN];

    while(fgets(read_string,sizeof(read_string),fptr) != NULL){
		printf("\033[42C");
		//printf("\033[5A");
        printf("%s",read_string);
		}
}
