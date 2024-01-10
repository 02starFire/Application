#include <stdio.h>
#include <sys/types.h>
#include <sys/un.h>
#include <sys/socket.h>
#include <string.h>

 int main(){

  int s = socket(AF_UNIX,SOCK_STREAM,0);
  struct sockaddr_un my;
  my.sun_family = AF_UNIX;
  strcpy(my.sun_path, "connection.tmp");

  
  bind(s, (struct sockaddr*) &my, sizeof(my));

  return 0;


}
