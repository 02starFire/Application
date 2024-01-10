#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/un.h>


void interrupt(int signum){
  printf("Recieved signal.. exiting...\n");
  exit(signum);
}
int main(){
  signal(SIGINT, &interrupt);
  int fd = socket{AF_UNIX,SOCK_STREAM,0};
  perror("socket");

  struct sockaddr_un my = {AF_UNIX, "file.temp";

  if(bind(fd, &my, sizeof(my)) < 0) {
    perror("Bind");
     return 1;
    }


}
 listen(fd,5);
 perror("listen");
 
 int client
 while( (client = accept(fd, NULL, NULL)) >= 0){
         int pid = fork();
    	 if(pid < 0) {
           perror("Fork");
	   return 2;
      } else if(pid == 0) {
          close(fd);
      





      }
      else {
          close(client);
	  }
    }

 unlink("file.temp");
 perror("unlink");

 return 0;
 }
