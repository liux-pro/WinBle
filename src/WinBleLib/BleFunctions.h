/*
MIT License

Copyright(c) Derek Goslin 2017

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files(the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions :

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

*/

#ifndef BLEFUNCTIONS_H
#define BLEFUNCTIONS_H

#include <Windows.h>

#include <string>

using namespace std;

/// <summary>
/// Open a handle to a ble device
/// </summary>
/// <param name="interfaceUUID">The interface to open on the ble device</param>
/// <param name="instanceId">The instance Id of the ble device to open a handle to the interface</param>
HANDLE getBleInterfaceHandle(GUID interfaceUUID, wstring instanceId);

/// <summary>
/// Open a handle to an interface of a ble device
/// </summary>
/// <param name="interfaceUUID">The interface to open on the ble device</param>
/// <param name="instanceId">The instance Id of the ble device to open a handle to the interface</param>
HANDLE getBleServiceInterfaceHandle(GUID interfaceUUID, wstring instanceId);

/// <summary>
/// Release an allocated ble interface handle
/// </summary>
void releaseBleInterfaceHandle(HANDLE hInterfaceHandle);

#endif