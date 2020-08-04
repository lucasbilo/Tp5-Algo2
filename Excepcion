#ifndef TP5_ALGO2_EXCEPCION_H
#define TP5_ALGO2_EXCEPCION_H

class Mi_excepcion : public std::exception
{
public:
    const char* what() const throw()
    {
        std::cout << "------------------------------------------------------------------" << std::endl;
        return "[-] Error: El archivo que quiere abrir no existe. Por favor intente de nuevo. Nombre del archivo: ";
    }
};

#endif /* TP5_ALGO2_EXCEPCION_H */
