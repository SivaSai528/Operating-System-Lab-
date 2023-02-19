#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

void typefile (char *filename)
{
   int fd, nread;
   char buf[1024];            // buffer to store data copied from the source
   fd = open (filename, O_RDONLY); // to open in read only format
   if (fd == -1) {                  // fd returns -1 if file is unavailable
   perror (filename);             
   return;
}                         // if available read the file
while ((nread = read (fd, buf, sizeof (buf))) > 0) 
   write (1, buf, nread);     
   close (fd);
}
int main ()
{
	char *files={"A2.txt"};
  typefile (files);
  exit (0);
}
