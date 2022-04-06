#ifndef SERVER_H_
#define SERVER_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <commons/log.h>
#include "utils.h"

void iterator(char* value);
void procesar_conexion(void* ars);
bool server_escuchar(int server_fd,t_log* logger_servidor);

#endif /* SERVER_H_ */
