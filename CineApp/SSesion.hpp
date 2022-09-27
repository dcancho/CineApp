class SSesion
{

	/*
	* Singleton de la clase SSesion
	* Se encarga de manejar la sesión del usuario y administrar pedidos que realice en su visita. Al finalizar una sesión, ya sea por cierre de sesión o cierre de la aplicación, se debe llamar al método destruir() para liberar la memoria utilizada por el singleton, luego de haber cargado los pedidos en la base de datos.
	*/
	
private:
	SSesion* Sesion;
	SSesion()
	{
		// Inicializar variables
		NombreUsuario = new char[16];
		IDUsuario = 0;
		NombreUsuario = "invitado";
	}
public:
	SSesion* getInstance()
	{
		if (Sesion == nullptr)
		{
			Sesion = new SSesion();
		}
		return Sesion;
	}
	// Variables
	char* NombreUsuario;
	int IDUsuario;
	Lista<Entidad*>* Pedidos = new Lista<Entidad*>();
};