#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include "arch/x86/include/generated/uapi/asm/unistd_64.h"

/*########### TEST 1 ###########*/
/* Given buffer = NULL & valid / invalid buffer lengths*/
void test1() {
	char *in = NULL;
	char msg[50];
	int errget = 0;
	int errput = 0;

	errput = syscall(__NR_dm510_msgbox_put, in, 10);
	errget = syscall(__NR_dm510_msgbox_get, msg, 50);
	printf("#######################################################################################################################################\n");
	printf("Expected result when buffer = NULL and length is a valid value > 0: \n- For put it is: Invalid argument\n- For get it is: No data available\n");
	if (errget >= 0 && errput >= 0) {
		printf("Message: \"%s\"\n", msg);
		printf("msglen = %d\n", errget);
	} else {
		printf("-----------------ERRORS-----------------\n");
		printf("- Error put: %s\n", strerror((errput * (-1)))); 
		printf("- Error get: %s\n\n", strerror((errget) * (-1))); 
	}

	errput = syscall(__NR_dm510_msgbox_put, in, -50);
	errget = syscall(__NR_dm510_msgbox_get, msg, 50);
	printf("#######################################################################################################################################\n");
	printf("Expected result when buffer = NULL and length is not a valid value < 0: \n- For put it is: Invalid argument\n- For get it is: No data avaiable\n");
	if (errget >= 0 && errput >= 0) {
		printf("Message: \"%s\"\n", msg);
		printf("Msglen = %d\n", errget);
	} else {
		printf("-----------------ERRORS-----------------\n");
		printf("- Error put: %s\n", strerror((errput * (-1)))); 
		printf("- Error get: %s\n\n", strerror((errget * (-1))));
	}
}

/*########## TEST 2 ##########*/
/* Given buffer is valid and invalid / valid buffer lengths*/
void test2() { 
	char* in =  "Hello, world!";
	int errget = 0;
	int errput = 0;
	char msg1[50];
	char msg2[50];
	char msg3[50];
	char msg4[50];
	char msg5[50];

	// Valid buffer & exact buffer length
	errput = syscall(__NR_dm510_msgbox_put, in, 13+1); // 13 length of message + 1 terminating byte
	errget = syscall(__NR_dm510_msgbox_get, msg1, 50);
	printf("#######################################################################################################################################\n");
	printf("Expected result when buffer = \"Hello, world!\" and length is 13 + 1: \n- For put it is: Success\n- For get it is: \"Hello, world!\" and msglen = 14\n");
	if (errget >= 0 && errput >= 0) {
		printf("-----------------RETURNS-----------------\n");
		printf("- Return put: %s\n", strerror(errput));
		printf("- Return get: \"%s\" and msglen: %d\n\n", msg1, errget);
	} else {
		printf("-----------------ERRORS-----------------\n");
		printf("- Error put: %s\n", strerror((errput * (-1)))); 
		printf("- Error get: %s\n\n", strerror((errget * (-1))));
	}

	// Valid buffer & invalid buffer length
	errput = syscall(__NR_dm510_msgbox_put, in, -1);
	errget = syscall(__NR_dm510_msgbox_get, msg2, 50);
	printf("#######################################################################################################################################\n");
	printf("Expected result when buffer = \"Hello, world!\" and length is < 0: \n- For put it is: Invalid arguments\n- For get it is: No data available\n");
	if (errget >= 0 && errput >= 0) {
		printf("- Return put: %s\n", strerror(errput));
		printf("- Return get: \"%s\" and msglen: %d\n\n", msg2, errget);
	} else {
		printf("-----------------ERRORS-----------------\n");
		printf("- Error put: %s\n", strerror((errput * (-1)))); 
		printf("- Error get: %s\n\n", strerror((errget * (-1))));
	}

	// Valid buffer & buffer length greater than message
	errput = syscall(__NR_dm510_msgbox_put, in, 50);
	errget = syscall(__NR_dm510_msgbox_get, msg3, 50);
	printf("#######################################################################################################################################\n");
	printf("Expected result when buffer = \"Hello, world!\" and length is larger than the message length\n- For put it is: Success\n- For get it is: \"Hello, world!\" and msglen = 50\n");
	if (errget >= 0 && errput >= 0) {
		printf("-----------------RETURNS-----------------\n");
		printf("- Return put: %s\n", strerror(errput));
		printf("- Return get: \"%s\" and msglen: %d\n\n", msg3, errget);
	} else {
		printf("-----------------ERRORS-----------------\n");
		printf("return value put: %s\n", strerror(errput* (-1)));
		printf("- Error put: %s\n", strerror((errput * (-1)))); 
		printf("- Error get: %s\n\n", strerror((errget * (-1))));
	}

	// Valid buffer & buffer length less than message 
	errput = syscall(__NR_dm510_msgbox_put, in, 7);
	errget = syscall(__NR_dm510_msgbox_get, msg4, 50);
	printf("#######################################################################################################################################\n");
	printf("Expected result when buffer = \"Hello, world!\" and length less than buffer length\n- For put it is: Success\n- For get it is: \"Hello, \" and msglen = 7\n");
	if (errget >= 0 && errput >= 0) {
		printf("-----------------RETURNS-----------------\n");
		printf("- Return put: %s\n", strerror(errput));
		printf("- Return get: \"%s\" and msglen: %d\n\n", msg4, errget);
	} else {
		printf("-----------------ERRORS-----------------\n");
		printf("return value put: %s\n", strerror(errput* (-1)));
		printf("- Error put: %s\n", strerror((errput * (-1)))); 
		printf("- Error get: %s\n\n", strerror((errget * (-1))));
	}

	// Valid buffer & exact buffer lenght, trying to get message into buffer smaller than its length
	errput = syscall(__NR_dm510_msgbox_put, in, 13);
	errget = syscall(__NR_dm510_msgbox_get, msg5, 5);
	printf("#######################################################################################################################################\n");
	printf("Expected result when buffer = \"Hello, world!\" buffer length equal to message, recieve buffer too small\n- For put it is: Success\n- For get it is: Message too long\n");
	if (errget >= 0 && errput >= 0) {
		printf("-----------------RETURNS-----------------\n");
		printf("- Return put: %s\n", strerror(errput));
		printf("- Return get: \"%s\" and msglen: %d\n\n", msg5, errget);
	} else {
		printf("-----------------ERRORS-----------------\n");
		printf("return value put: %s\n", strerror(errput* (-1)));
		printf("- Error put: %s\n", strerror((errput * (-1)))); 
		printf("- Error get: %s\n\n", strerror((errget * (-1))));
	}
	// removes the message put on the stack
	syscall(__NR_dm510_msgbox_get, msg5, 50);

}

/*########## TEST 3 ##########*/
/* TESTING MULTIPLE MESSAGES */
void test3() {
	char m1[50];
	char m2[50];
	char m3[50];
	char m4[50];
	char m5[50];
	char m6[50];
	char m7[50];
	char m8[50];
	char m9[50];
	char m10[50];
	char m11[50];
	char m12[50];
	char m13[50];
	char m14[50];
	char m15[50];
	char m16[50];
	char m17[50];
	char m18[50];
	char m19[50];
	char m20[50];
	char m21[50];
	char m22[50];

	char *h = "hello";
	char *w = "world";
	char *g = "good";
	char *t = "to"; 
	char *s = "see";
	char *y = "you";
	char *p = "perhaps";
	char *q = "quantum";
	char *m = "mechanics";
	char *a = "are";
	char *i = "inevitably";
	char *c = "consuming";
	char *d = "daylight";
	char *f = "for";
	char *z = "zebras";
	char *b = "before";
	char *e = "ending";
	char *u = "universal";
	char *v = "violent";
	char *n = "nuggets";
	printf("#######################################################################################################################################\n");
	printf("Putting in multiple messages: \"%s\", \"%s\", \"%s\", \"%s\", \"%s\", \"%s\", \"%s\",",n,v,u,e,b,z,f);
	printf("\"%s\", \n\"%s\", \"%s\", \"%s\", \"%s\", \"%s\", \"%s\",  \"%s\", \"%s\", \"%s\",", d,c,i,a,m,q,p,y,s,t); 
	printf("\"%s\",\"%s\", \"%s\" and taking them out:\n", g,w,h);

	printf("----------Expected result----------\n"); 

	printf("\"%s\"\n\"%s\"\n\"%s\"\n\"%s\"\n\"%s\"\n\"%s\"\n\"%s\"\n\"%s\"\n\"%s\"\n\"%s\"\n\"%s\"\n\"%s\"\n\"%s\"\n\"%s\"\n\"%s\"\n\"%s\"\n\"%s\"\n\"%s\"\n\"%s\"\n\"%s\"\n", h,w,g,t,s,y,p,q,m,a,i,c,d,f,z,b,e,u,v,n);

	/* PUTS MESSAGES IN THE MESSAGE BOX */
	syscall(__NR_dm510_msgbox_put, n, 20);
	syscall(__NR_dm510_msgbox_put, v, 20);
	syscall(__NR_dm510_msgbox_put, u, 20);
	syscall(__NR_dm510_msgbox_put, e, 20);
	syscall(__NR_dm510_msgbox_put, b, 20);
	syscall(__NR_dm510_msgbox_put, z, 20);
	syscall(__NR_dm510_msgbox_put, f, 20);
	syscall(__NR_dm510_msgbox_put, d, 20);
	syscall(__NR_dm510_msgbox_put, c, 20);
	syscall(__NR_dm510_msgbox_put, i, 20);
	syscall(__NR_dm510_msgbox_put, a, 20);
	syscall(__NR_dm510_msgbox_put, m, 20);
	syscall(__NR_dm510_msgbox_put, q, 20);
	syscall(__NR_dm510_msgbox_put, p, 20);
	syscall(__NR_dm510_msgbox_put, y, 20);
	syscall(__NR_dm510_msgbox_put, s, 20);
	syscall(__NR_dm510_msgbox_put, t, 20);
	syscall(__NR_dm510_msgbox_put, g, 20);
	syscall(__NR_dm510_msgbox_put, w, 20);
	syscall(__NR_dm510_msgbox_put, h, 20);

	/* GETS MESSAGES FROM THE MESSAGE BOX */
	syscall(__NR_dm510_msgbox_get, m1, 50); 	// hello
	syscall(__NR_dm510_msgbox_get, m2, 50); 	// world
	syscall(__NR_dm510_msgbox_get, m3, 50); 	// good 
	syscall(__NR_dm510_msgbox_get, m4, 50); 	// to
	syscall(__NR_dm510_msgbox_get, m5, 50); 	// see
	syscall(__NR_dm510_msgbox_get, m6, 50); 	// you
	syscall(__NR_dm510_msgbox_get, m7, 50); 	// perhaps
	syscall(__NR_dm510_msgbox_get, m8, 50); 	// quantum 
	syscall(__NR_dm510_msgbox_get, m9, 50); 	// mechanics
	syscall(__NR_dm510_msgbox_get, m10, 50);	// are
	syscall(__NR_dm510_msgbox_get, m11, 50);	// inevitably
	syscall(__NR_dm510_msgbox_get, m12, 50);	// consuming
	syscall(__NR_dm510_msgbox_get, m13, 50);	// daylight
	syscall(__NR_dm510_msgbox_get, m14, 50);	// from
	syscall(__NR_dm510_msgbox_get, m15, 50);	// zebras
	syscall(__NR_dm510_msgbox_get, m16, 50);	// before
	syscall(__NR_dm510_msgbox_get, m17, 50);	// ending
	syscall(__NR_dm510_msgbox_get, m18, 50);	// universal
	syscall(__NR_dm510_msgbox_get, m19, 50);	// violent
	syscall(__NR_dm510_msgbox_get, m20, 50);	// nuggets 

	printf("-----------------RESULTS-----------------\n");
	printf("\"%s\"\n", m1);
	printf("\"%s\"\n", m2);
	printf("\"%s\"\n", m3);
	printf("\"%s\"\n", m4);
	printf("\"%s\"\n", m5);
	printf("\"%s\"\n", m6);
	printf("\"%s\"\n", m7);
	printf("\"%s\"\n", m8);
	printf("\"%s\"\n", m9);
	printf("\"%s\"\n", m10);
	printf("\"%s\"\n", m11);
	printf("\"%s\"\n", m12);
	printf("\"%s\"\n", m13);
	printf("\"%s\"\n", m14);
	printf("\"%s\"\n", m15);
	printf("\"%s\"\n", m16);
	printf("\"%s\"\n", m17);
	printf("\"%s\"\n", m18);
	printf("\"%s\"\n", m19);
	printf( "\"%s\"\n", m20);
}


/*########## TEST 4 ##########*/
/* TESTING FOR MULTIPLE ACCESS */

void *msgPut(void* input) {
	char *msg = "hello";
	for (int i = 0; i < *((int*) input); i++) {
		int error = syscall(__NR_dm510_msgbox_put, msg, 10);
	}
}

void *msgGet(void* input) {
	char *buff[10];
	for (int i = 0; i < *((int*) input); i++) {
		int error = syscall(__NR_dm510_msgbox_get, buff, 10);
	}
}

int get() {
	char msg[10];
	int res = syscall(__NR_dm510_msgbox_get, msg, 10);
	return res;
}

void test4() {
	printf("#######################################################################################################################################\n");
	printf("Starting 200 threads each putting 1000 messages into the message box both single- and multithreaded and counting the amount of messages in the message box at the end\n");
	int n = 200;	// Threads to spawn
	int mul = 1000;	// amount of puts each thread performs
	pthread_t threads[n];
	for (int i = 0; i < n; i++) {
		pthread_create(&threads[i], NULL, msgPut, &mul);
	}

	for (int i = 0; i < n; i++) {
		pthread_join(threads[i], NULL);
	}
	
	int countm = 0;
	while (get() != -61) {
		countm++;
	}

	char *msg = "hello";
	int res = 0;
	for (int i = 0; i < n*mul; i++) {
		res = syscall(__NR_dm510_msgbox_put, msg, 10);
	}
	
	int counts = 0;
	while (get() != -61) {
		counts++;
	}

	printf("-----------------SINGLETHREADED-----------------\n");
	printf("Messages Expected: %d\nMessages retrieved: %d\n", n*mul, counts);

	printf("-----------------MULTITHREADED-----------------\n");
	printf("Messages Expected: %d\nMessages retrieved: %d\n", n*mul, countm);

}

/*########## TEST 5 ##########*/
/* TESTING FOR MULTIPLE ACCESS */
// puts 100 messages into the message box and prints it along with what thread it belongs to
void *putMsg(void *input) {
	for (int i = 0; i < 100; i++) {
		int error = syscall(__NR_dm510_msgbox_put, (char*) input, 10);
		printf("%s put: %s\n", (char*) input, (char*) input);
	}
}

// gets 100 messages from the message box and prints it along with what thread it belongs to
void *getMsg(void *input) {
	char *buff[10];
	for (int i = 0; i < 100; i++) {
		int error = syscall(__NR_dm510_msgbox_get, buff, 10);
		printf("%s get: %s\n", (char*) input, (char*) buff);
	}
}

void test5() {
	printf("#######################################################################################################################################\n");
	printf("Expected result if the concurrency strategy is working is that no thread will be interrupted\n");
	printf("-----------------RESULTS-----------------\n");
	char *msg1 = "First";
	char *msg2 = "Second";
	char *msg3 = "Third";

	pthread_t thread1;
	pthread_t thread2;
	pthread_t thread3;
	pthread_t thread4;
	pthread_t thread5;
	pthread_t thread6;

	// creates threads
	pthread_create(&thread1, NULL, putMsg, msg1); // put thread
	pthread_create(&thread2, NULL, getMsg, msg1); // get thread
	pthread_create(&thread3, NULL, putMsg, msg2); // put thread
	pthread_create(&thread4, NULL, getMsg, msg2); // get thread
	pthread_create(&thread5, NULL, putMsg, msg3); // put thread
	pthread_create(&thread6, NULL, getMsg, msg3); // get thread

	// waits for threads to finish
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	pthread_join(thread3, NULL);
	pthread_join(thread4, NULL);
	pthread_join(thread5, NULL);
	pthread_join(thread6, NULL);
}


void clearMB() {
	char msg[100];
	int error = syscall(__NR_dm510_msgbox_get, msg, 100);
	while (error != -61) {
		error = syscall(__NR_dm510_msgbox_get, msg, 100);
	}
}

int main(int argc, char** argv) {
	if (argc < 2) { return -1; }
	clearMB();
	int arg = atoi(argv[1]);
	if (arg == 1) {
		test1(); // testing for when the buffer is invalid / NULL and given legnth of buffer vaires
	} else if (arg == 2) {
		test2(); // testing for when buffer is valid but given length of buffer isn't
	} else if (arg == 3) {
		test3(); // testing for putting multiple messages into the message box and getting them again
	} else if (arg == 4) {
		test4(); // testing for when there are multiple threads putting messages into message box at the same time
	} else if (arg == 5) {
		test5(); // testing for when multiple threads try to put and get messeges at the same time
	}
	return 0;
}
