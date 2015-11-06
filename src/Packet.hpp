#pragma once

#include <vector>

using namespace std;

class Packet
{
private:

	int head_size; // Taille de l'entête (en mots de 4 octets)
	bool dont_fragment; // Si true, le paquet ne peut pas être fragmenté
	bool more_fragment; // Si true, le packet suivant existe
	int message_size; // Taille du message (en octets)
	int offset; // Décalage (en mots de 8 octets)

public:

	Packet();
	~Packet();

	/*!
	 * Taille totale du paquet
	 * @return Taille totale en octets
	 */
	int totalSize();

	void setMessageSize(int message_size);

	void setOffset(int offset);
	
	int getHeadSize();

	int getMessageSize();
};