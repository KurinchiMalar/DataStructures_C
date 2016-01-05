/* 
 * File:   gasStationCircularPath.c
 * Author: kurnagar
 *
 * Created on June 27, 2014, 12:12 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
typedef struct PetrolPump{
    int petrol;
    int nextDistance;
}Pump;
int printPathToTake_CarGasStationEverymile(Pump* pumpArray,int numberOfGasStations){
    int start = 0;
    int loopIdentifier = 0;
    int leftPetrol = 0;
    
    // baseCase ... if at start we dont have sufficient petrol then our start is wrong. move front.
    
    if(pumpArray[start].petrol < pumpArray[start].nextDistance){
        start++;
        loopIdentifier++;
    }
    
    while(1){
        leftPetrol = leftPetrol - pumpArray[start].nextDistance+pumpArray[start].petrol;
        
        if(leftPetrol < 0){
            start++;
            loopIdentifier++;
            leftPetrol = 0;
        }else{
            start = (++start)%numberOfGasStations;
            printf("\n Vehicle start @ station: %d and leftPetrol : %d",start,leftPetrol);
        }
        if(start == loopIdentifier){
            printf("\n Gotta Start at %d", start);
            return start;
        }
    }
}
int main(int argc, char** argv) {
    
    Pump p[]={}
    return (EXIT_SUCCESS);
}

