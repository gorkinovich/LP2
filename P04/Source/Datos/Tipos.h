//----------------------------------------------------------------------
// Gorka Suárez García - Ing. Tec. Inf. de Gestión 2º B.
// Práctica 04 - Grupo 03.
//----------------------------------------------------------------------
#ifndef Datos_TiposH
#define Datos_TiposH


typedef enum
{
	usuario_policia = 0,
	usuario_administrador
} TipoUsuario;


typedef enum
{
	delincuente_lector = 0,
	delincuente_sonnador,
	delincuente_lectorConfidente,
	delincuente_sonnadorConfidente
} TipoDelincuente;


#endif