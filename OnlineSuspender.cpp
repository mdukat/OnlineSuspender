#include <windows.h>
#include <tchar.h>
#include <iostream>

int main()
{
    std::cout << "GTA Online Suspender\n\n";

    std::cout << "Finding GTA Online window handle...\n";
    HWND windowHandle = FindWindow(NULL, _T("Grand Theft Auto V"));

    std::cout << "Getting GTA Online PID... ";
    DWORD threadId = GetWindowThreadProcessId(windowHandle, NULL);
    std::cout << "Thread ID: " << threadId << "\n";

    std::cout << "Getting GTA Online handle...\n";
    HANDLE threadHandle = OpenThread(THREAD_ALL_ACCESS, FALSE, threadId);

    std::cout << "Suspending GTA Online...\n";
    SuspendThread(threadHandle);

    std::cout << "Waiting 8 seconds...\n";
    Sleep(8000);
    std::cout << "Resuming GTA Online...\n";
    ResumeThread(threadHandle);

    std::cout << "Done! Closing in 3 seconds...\n";
    Sleep(3000);
    return 0;
}
