﻿#pragma once
#include "Lista.hpp"
#include "Cola.hpp"
#include "Pedido.hpp"
#include "SBaseDatos.hpp"


namespace CineApp {
	/*
		Singleton de la clase SSesion
		Se encarga de manejar la sesión del usuario y administrar pedidos que realice en su visita. Al finalizar una sesión, ya sea por cierre de sesión o cierre de la aplicación, se debe llamar al método FlushData() para liberar la memoria utilizada por el singleton, luego de haber cargado los pedidos en la base de datos.
		Autor: Diego Cancho
		*/
	//Entidad 7
	class SSesion
	{
	public:
		/// <summary>
		///	Obtiene la instancia del singleton.
		/// </summary>
		/// <returns></returns>
		static SSesion* getInstance()
		{
			if (Sesion == nullptr)
			{
				Sesion = new SSesion();
			}
			return Sesion;
		}
		char* NombreUsuario;
		int IDUsuario;
		Cola<Pedido*>* Pedidos = new Cola<Pedido*>();
		bool isLogged;
		/// <summary>
		/// Inicia la sesión del usuario.
		/// </summary>
		/// <param name="nombre"></param>
		void IniciarSesion(char* nombre)
		{
			NombreUsuario = nombre;
			isLogged = true;
		}
		/// <summary>
		///	Libera la memoria utilizada por el singleton.
		/// </summary>
		void CerrarSesion()
		{
			isLogged = false;
			IDUsuario = 0;
			Pedidos = nullptr;
			NombreUsuario = "invitado";
		}
		/// <summary>
		/// Eliminar registros de la base de datos
		/// </summary>
		/// <param name="db"></param>
		void FlushData(SBaseDatos* db)
		{
			//Vaciar datos de Cola "Pedidos" a la base de datos
			while (Pedidos->getCantidad() != 0)
			{
				db->Pedidos->agregaFinal(Pedidos->SacarCola());
			}
		}
	private:
		static SSesion* Sesion;
		SSesion()
		{
			// Inicializar variables
			NombreUsuario = new char[16];
			IDUsuario = 0;
			NombreUsuario = "invitado";
			isLogged = false;
		}
		SSesion(const SSesion& obj) {}
	};

	SSesion* SSesion::Sesion = 0;
}