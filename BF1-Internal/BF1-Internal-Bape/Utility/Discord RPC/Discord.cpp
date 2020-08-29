/* Includes for this file */
#include "Discord.hpp"

/* Implementation for discordRPC initialize */
void DiscordRPC::Init(const char* api_key)
{
	/* Create the event handler */
	DiscordEventHandlers handle;

	/* Cleat the EventHandle */
	memset(&handle, 0, sizeof(handle));

	/* Initialize the event handler with our api key */
	Discord_Initialize(api_key, &handle, 1, NULL);
}

/* Implementation for discordRPC update */
void DiscordRPC::Update(DiscordRichPresence* rpc)
{
	/* Update the discord presence*/
	Discord_UpdatePresence(rpc);
}