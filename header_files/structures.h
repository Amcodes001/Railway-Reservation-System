#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h> 
#include <unistd.h>
#include <ifaddrs.h>
#include <netdb.h>
#include <string.h>
#include <fcntl.h>
#include <pthread.h>

#define PASS_LENGTH 20

struct account
{
	int id;
	char name[10];
	char pass[PASS_LENGTH];
};

struct train
{
	int tid;
	char train_name[20];
	int train_no;
	int av_seats;
	int last_seatno_used;
};

struct bookings
{
	int bid;
	int type;
	int acc_no;
	int tr_id;
	char trainname[20];
	int seat_start;
	int seat_end;
	int cancelled;
};