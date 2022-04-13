#ifndef UTILS_H_
#define UTILS_H_

#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<unistd.h>
#include<netdb.h>
#include<commons/log.h>
#include<commons/collections/list.h>
#include"../../client/src/utils.h"
#include<string.h>
#include<assert.h>
#include<pthread.h>
#include<stdbool.h>
#include"../../client/src/client.h"

#define IP "127.0.0.1"
#define PUERTO "4444"

#define IP2 "127.0.0.2"
#define PUERTO2 "4445"

typedef enum
{
	MENSAJE,
	PAQUETE
}op_code;

typedef struct
{
	int cliente_fd;
	t_log* logger;
}args_t;

t_log* logger;

void* recibir_buffer(int*, int);
int iniciar_servidor2(void);
int iniciar_servidor(void);
int esperar_cliente(int);
t_list* recibir_paquete(int);
void recibir_mensaje(int);
int recibir_operacion(int);

#endif /* UTILS_H_ */
