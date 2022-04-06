#include "client.h"
#include<commons/log.h>
#include<commons/string.h>
#include<commons/config.h>

int main(void){

	int conexion;
	char * valor;
	char* ip;
	char* puerto;
	t_log* logger;
	t_config* config;

	/* ---------------- LOGGING ---------------- */

	logger = iniciar_logger();

	// Usando el logger creado previamente
	// Escribi: "Hola! Soy un log"


	log_info(logger, "Soy un log");



	/* ---------------- ARCHIVOS DE CONFIGURACION ---------------- */
	config = config_create("/home/utnso/Documentos/tp0-1/client/cliente.config");

	// Usando el config creado previamente, leemos los valores del config y los 
	// dejamos en las variables 'ip', 'puerto' y 'valor'

	// Loggeamos el valor de config

	valor = config_get_string_value(config,"CLAVE");
	ip = config_get_string_value(config,"IP");
	puerto = config_get_string_value(config,"PUERTO");

	log_info(logger, valor);

	leer_consola(logger);

	/*---------------------------------------------------PARTE 3-------------------------------------------------------------*/

	// ADVERTENCIA: Antes de continuar, tenemos que asegurarnos que el servidor esté corriendo para poder conectarnos a él

	// Creamos una conexión hacia el servidor
	conexion = crear_conexion(ip, puerto);


	// Enviamos al servidor el valor de CLAVE como mensaje
	enviar_mensaje(valor,conexion);
	// Armamos y enviamos el paquete
	paquete(conexion);

	terminar_programa(conexion, logger, config);

	/*---------------------------------------------------PARTE 5-------------------------------------------------------------*/
	// Proximamente
}

t_log* iniciar_logger(void){
	return log_create("tp0.log", "tp0", true , LOG_LEVEL_INFO);
}

t_config* iniciar_config(void){
	t_config* nuevo_config;

		return nuevo_config;

}
void leer_consola(t_log* logger){

	char* leido;
		//El primero te lo dejo de yapa

		while(!string_is_empty(leido = readline("> "))){
			log_info(logger, leido);
			free(leido);
		}
		free(leido);
}

void paquete(int conexion)
{
	// Ahora toca lo divertido!
	char* leido;
	t_paquete* paquete = crear_paquete();
	leido = readline("> ");
	// Leemos y esta vez agregamos las lineas al paquete
	while(!(strcmp(leido,"") == 0)){
				agregar_a_paquete(paquete,leido,strlen(leido)+1);
				free(leido);
				leido = readline("> ");
			}
	free(leido);
	enviar_paquete(paquete,conexion);
	// ¡No te olvides de liberar las líneas y el paquete antes de regresar!

	eliminar_paquete(paquete);

}

void terminar_programa(int conexion, t_log* logger, t_config* config)
{
		liberar_conexion(conexion);
		log_destroy(logger);
		config_destroy(config);
}
