#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include "flight.h"

int main(){
    Flight list[20];
    
    list[0]=createFlight("1024", "ABC123", createTime(06, 30), createDest("Ninoy Aquino International Airport", 1));
    list[1]=createFlight("6437", "N09M98", createTime(06, 50), createDest("Clark International Airport", 2));
    list[2]=createFlight("8375", "BW6484", createTime(05, 30), createDest("Iloilo International Airport", 2));
    list[3]=createFlight("4976", "09NVY8", createTime(15, 45), createDest("Bantayan Airport", 5));
    list[4]=createFlight("0875", "NCY95F", createTime(20, 20), createDest("Alto Airfield", 6));
    list[5]=createFlight("0793", "N9Y8V5", createTime(17, 20), createDest("Sibulan Airport", 3));
    list[6]=createFlight("5767", "V3N9OJ", createTime(06, 50), createDest("Siquijor Airport", 3));
    list[7]=createFlight("8966", "EV4TN8", createTime(14, 15), createDest("General Santos Airport", 4));
    list[8]=createFlight("8752", "NV46DF", createTime(14, 15), createDest("Ninoy Aquino International Airport", 1));
    list[9]=createFlight("6433", "N986JD", createTime(10, 20), createDest("Hilongos Airport", 5));
    
    // printf("CODE - AIRCRAFT - TIME - DESTINATION\n");
    // for(int i=0; i<10; ++i){
    //     displayFlight(list[i]);
    // }
    
    FILE *fp;
    
    fp=fopen("flights_details.dat", "wb");

	if(fp!=NULL){
        fwrite(list, sizeof(Flight), 10, fp);
	}
    
    fclose(fp);
    
    
    PriorityQueue q;
    q.count=0;
    Flight f;
    
    fp=fopen("flights_details.dat", "rb");

    if(fp!=NULL){
        while(fread(&f, sizeof(Flight), 1, fp)){
            insertFlight(&q, f);
        }
    }
    displayFlights(q);
    fclose(fp);
    printf("\n");
    
    PriorityQueue flights;
    flights.count = 0;
    getFlightsBefore(&q, list[7], &flights);
    displayFlights(flights);
    
    return 0;
}

