
// gcc -o bai2 bai2.c
#include <stdio.h> 
#include <stdlib.h>
#include <time.h>
#include <pthread.h> 
#include <semaphore.h> 
#include <unistd.h> 

#define MAX_NUM_FILE 10

sem_t sem_write;
pthread_mutex_t lock_valid_file;
char files_info[MAX_NUM_FILE] ;

FILE *openFile(const char *file_name, const char *mode_of_operation)
{
    return fopen(file_name,mode_of_operation);
}

int writeFile(FILE *stream, const char *format,...)
{
    return fprintf(stream,format);
}

void write_to_file( int n)
{
	int i = 0;
	int ok = 0;
	while(!ok)
	for (i = 0 ; i < n ; i ++)
	{
		pthread_mutex_lock(&lock_valid_file);
		if(files_info[i] == 0)
		{
			files_info[i] = 1;
			ok = 1;
		}
		pthread_mutex_unlock(&lock_valid_file);

		if( ok == 1)
		{

			char nameFile[30];
			sprintf(nameFile ,"NgocNguyen.txt %d" , i);
			FILE *fp  = openFile(nameFile , "a+");

			writeFile(fp , "\n %lu ok %d at %ld", pthread_self(), i, clock());
			sleep(0.1);
			files_info[i] = 0;
			fclose(fp);
			break;
		}
	}
}

void* thread(void* arg) 
{

	int count = 0; 
	while(count < 10)
	{
		write_to_file(1);
		count++;
	}
}

int main() 
{
	pthread_t thread1,thread2;

	pthread_mutex_init(&lock_valid_file, NULL );

	pthread_create(&thread1,NULL,thread , NULL);
	pthread_create(&thread2,NULL,thread , NULL);

	pthread_join(thread1,NULL);
	pthread_join(thread2,NULL);
	pthread_mutex_destroy(&lock_valid_file);
	puts("Ok");
	return 0;

}

