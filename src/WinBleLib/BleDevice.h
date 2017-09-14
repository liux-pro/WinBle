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

#ifndef BLEDEVICE_H
#define BLEDEVICE_H

using namespace std;

#include <Rpc.h>
#include <BluetoothAPIs.h>

#include <list>
#include <string>

#include "BleGattService.h"

/// <summary>
/// Represents a paired connected bluetooth low energy device
/// </summary>
class BleDevice
{
	private:
		HANDLE hBleDevice = nullptr;

		wstring deviceInstanceId;

		BleDeviceContext deviceContext;

		list<BleGattService*> bleGattServices;

		USHORT gattServiceCount = 0;

		PBTH_LE_GATT_SERVICE pGattServiceBuffer = nullptr;
	
		static HANDLE getBleDeviceHandle(wstring deviceInstanceId);

		static PBTH_LE_GATT_SERVICE getGattServices(HANDLE hBleDeviceHandle, 
			USHORT * pGattServiceCount);

	public:
		/// <summary>
		/// Constructs an instance of a <see cref="BleDevice"/>
		/// </summary>
		/// <param name="deviceInstanceId">The device instance name</param>
		BleDevice(wstring deviceInstanceId);

		/// <summary>
		/// Destructor
		/// </summary>
		~BleDevice();

		/// <summary>
		/// Gets the device instance name
		/// </summary>
		wstring getDeviceIntstanceId();

		typedef list<BleGattService*> BleGattServices;

		/// <summary>
		/// Get the list of <see cref="BleGattServices"/>
		/// </summary>
		const BleGattServices& getBleGattServices();
};
#endif