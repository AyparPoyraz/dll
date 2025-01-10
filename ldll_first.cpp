
#include <windows.h>
#include <tlhelp32.h>
#include <iostream>


//ListProcesses void

void ListProcesses() {
	//get snapshot
	HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	if (hSnapshot == INVALID_HANDLE_VALUE) {
		std::cerr << "Snapshot Alinamadi" << std::endl;
		return;
	}

	PROCESSENTRY32 pe32;
	pe32.dwSize = sizeof(PROCESSENTRY32);

	if (Process32First(hSnapshot, &pe32)) {
		do {
			std::wcout << L"Process Name: " << pe32.szExeFile << std::endl;
			std::cout << "Process ID: " << pe32.th32ProcessID << std::endl;
			std::cout << "Parent Process ID: " << pe32.th32ParentProcessID << std::endl;
			std::cout << "Thread Count: " << pe32.cntThreads << std::endl;
			std::cout << "-----------------------------" << std::endl;
		} while (Process32Next(hSnapshot, &pe32));
	}else {
		std::cerr << "Snapshot iceriği bos" << std::endl;
	}

	CloseHandle(hSnapshot);
}

int main() {

	ListProcesses();
	return 0;
}
