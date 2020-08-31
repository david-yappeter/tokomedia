#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include<math.h>
#include<string.h>

#include "media.h"
#include "email.h"
#include "banking.h"
#include "GlobalVariable.h"

int main(){
	tim = clock();
	
	scanfileuser();
	scanitem();
	scanfilegmail();
	scanfilebank();
	
	website();
	
	return 0;
}
