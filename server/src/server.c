#include "server.h"

int main(void)
{
	logger = log_create("log.log", "Servidor", 1, LOG_LEVEL_DEBUG);

	int server_fd = iniciar_servidor();
	log_info(logger, "Servidor listo para recibir al cliente");


	int conexion = crear_conexion(IP2, PUERTO2);

	while(server_escuchar(server_fd, logger));

	return 0;
}

bool server_escuchar(int server_fd, t_log* logger_servidor)
{
	int cliente_fd = esperar_cliente(server_fd);
	if(cliente_fd != -1){

		pthread_t hiloServer;
		args_t* argsAux = malloc(sizeof(args_t));
		argsAux->cliente_fd = cliente_fd;
		argsAux->logger = logger_servidor;
		pthread_create(&hiloServer,NULL,(void*)procesar_conexion,(void*)argsAux);
		pthread_detach(hiloServer);
		return true;
		free(argsAux);
	}

	else return false;

}


void procesar_conexion(void* ars)
{
		void iterator(char* value)
		{
				log_info(logger,"%s", value);
		}

	t_list* lista;
	args_t* argsAux = (args_t* ) ars;
	int cliente_fd = argsAux->cliente_fd;
	t_log* logger = argsAux->logger;

	while (1) {
			op_code cod_op = recibir_operacion(cliente_fd);
			switch (cod_op) {
			case MENSAJE:
				recibir_mensaje(cliente_fd);
				break;
			case PAQUETE:
				lista = recibir_paquete(cliente_fd);
				log_info(logger, "Me llegaron los siguientes valores:\n");
				list_iterate(lista, (void*) iterator);
				break;
			case -1:
				log_error(logger, "el cliente se desconecto.");
				return;
			default:
				log_warning(logger,"Operacion desconocida. No quieras meter la pata");
				break;

			}


	}

	free(argsAux);
	list_destroy(lista);

}


