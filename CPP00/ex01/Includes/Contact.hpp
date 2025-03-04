#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <string>
#include <algorithm> 

class Contact
{
    public:
    	std::string    firstName;
    	std::string    lastName;
    	std::string    nickname;
    	std::string    phoneNumber;
    	std::string    darkestSecret;
    	
    	void           get_firstname();
    	void           get_lastname();
    	void           get_nickname();
    	void           get_phone();
    	void           get_secret(); 
    	void           print_firstname();
    	void           print_lastname();
    	void           print_nickname();
};

#endif

/*

Cuando no defines un constructor en Contact, el compilador crea un constructor predeterminado (sin parámetros) 
que simplemente inicializa los miembros de la clase con sus valores predeterminados 
(en este caso, los std::string se inicializan como cadenas vacías).
*/