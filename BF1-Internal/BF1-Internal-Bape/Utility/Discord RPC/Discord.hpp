#ifndef _DISCORD_HPP
#define _DISCORD_HPP

/* Includes for this file */
#include <Windows.h>
#include "Discord/discord_rpc.h"
#include "Discord/discord_register.h"

/* Declare the discord class wrapper */
class DiscordRPC
{
public: // Public methods for this class 
	void Init(const char* api_key);
	void Update(DiscordRichPresence* rpc);
};

#endif // _DISCORD_HPP
