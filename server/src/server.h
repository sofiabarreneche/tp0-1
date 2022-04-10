#ifndef SERVER_H_
#define SERVER_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <commons/log.h>
#include "utils.h"



void procesar_conexion(void* ars);
bool server_escuchar(int ,t_log* );

#endif /* SERVER_H_ */
