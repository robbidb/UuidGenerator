#include <iostream>
#include <Windows.h>
#include <Rpc.h>
#include <string.h>

#pragma comment(lib, "Rpcrt4.lib")
using namespace std;


string GenerateGUID();

::string GenerateGUID()
{
    UUID   uuid;                              // The generated UUID
    string sUuid;

    UCHAR* pUuid2String = NULL;
    RPC_STATUS status;

    // Generate a new empty UUID - {00000000-0000-0000-0000-000000000000}
    ZeroMemory(&uuid, sizeof(UUID));


    // Generate a random UUID 
    status = UuidCreate(&uuid);


    // Request windows to convert the UUID into a string
    status = UuidToStringA(&uuid, &pUuid2String);

    // If we get a result from windows convert it to a string.
    if (pUuid2String != NULL)
    {
        sUuid = (char*)pUuid2String;
    }

    // Deallocate memory
    status = RpcStringFreeW((RPC_WSTR*)&pUuid2String);

    return sUuid;
}


int main()
{
    string sNewUuid = GenerateGUID();

    std::cout << sNewUuid;
}
