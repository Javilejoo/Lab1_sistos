#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>

extern int errno;

int main(int argc, char* argv[]) {
    if (argc < 3) {
        printf("Uso: %s <nombre_archivo> <archivo_destino>\n", argv[0]);
        return 1;
    }

    int fd, sz;
    char* c = (char*)calloc(100, sizeof(char));
    
    if (c == NULL) {
        perror("Error al asignar memoria");
        return 1;
    }

    fd = open(argv[1], O_RDONLY);
    
    if (fd == -1) {
        printf("Error número %d\n", errno);
        perror("Error al abrir el archivo");
        free(c);
        return 1;
    }

    printf("fd = %d\n", fd);

    sz = read(fd, c, 32);
    
    if (sz == -1) {
        perror("Error al leer el archivo");
        close(fd);
        free(c);
        return 1;
    }

    c[sz] = '\0';  

    printf("Se leyeron %d bytes del archivo %s.\n", sz, argv[1]);

    printf("Contenido:\n%s\n", c);
    
    // archivo para escribir
    int fd2 = open(argv[2], O_WRONLY | O_RDONLY);
    if (fd2 == -1) {
      printf("Error número %d\n", errno);
      perror("Error al abrir el archivo");
      close(fd);
      free(c);
      return 1;
    }
    
    int sz2 = write(fd2, c, strlen(c));
    
    if (sz == -1) {
      perror("Error al leer el archivo");
      close(fd);
      close(fd2);
      free(c);
      return 1;
    }

    
    printf("Se escribieron %d bytes en el archivo %s.\n", sz2, argv[2]);
    printf("Contenido de pegame.txt:\n%s\n", c);
    close(fd);
    close(fd2);
    free(c);
    
    return 0;
}

