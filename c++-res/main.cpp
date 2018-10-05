#include <cstdio>
#include <windows.h>
#include "resources.h"

void LoadFileInResource(int name, int type, DWORD& size, const char*& data) {
  HMODULE handle = ::GetModuleHandle(NULL);
  HRSRC rc = ::FindResource(handle, MAKEINTRESOURCE(name), MAKEINTRESOURCE(type));
  HGLOBAL rcData = ::LoadResource(handle, rc);
  size = ::SizeofResource(handle, rc);
  data = static_cast<const char*>(::LockResource(rcData));
}

int main(int argc, char** argv) {
	DWORD size = 0;
	const char* data = NULL;
	LoadFileInResource(IDR_MYFILE, RESTYPE_RAW, size, data);
	/* Access bytes in data - here's a simple example involving text output*/
	// The text stored in the resource might not be NULL terminated.
	// copying to new buffer is needed only to NULL terminate the string.
	char* buffer = new char[size+1];
	::memcpy(buffer, data, size);
	buffer[size] = 0; // NULL terminator
	::printf("Contents of text file: %s\n", buffer); // Print as ASCII text
	delete[] buffer;
	return 0;
}
