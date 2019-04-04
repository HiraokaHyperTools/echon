#include <Windows.h>

static HANDLE StdOut;
static HANDLE StdErr;

void WriteStdOut(LPCWSTR text) {
	DWORD written;
	WriteConsoleW(StdOut, text, lstrlenW(text), &written, NULL);
}

void WriteStdErr(LPCWSTR text) {
	DWORD written;
	WriteConsoleW(StdErr, text, lstrlenW(text), &written, NULL);
}

int Run(int argc, WCHAR **argv) {
	if (argc >= 2) {
		for (int x = 1; x < argc; x++) {
			WriteStdOut(argv[x]);
		}
		return 0;
	}
	WriteStdErr(
		L"echon \"Hello world\"\n"
	);
	return 1;
}

void EntryPoint() {
	int argc = 0;
	LPWSTR *argv = CommandLineToArgvW(
		GetCommandLineW(),
		&argc
	);

	StdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	StdErr = GetStdHandle(STD_ERROR_HANDLE);

	int retCode = Run(argc, argv);
	ExitProcess(retCode);
}
