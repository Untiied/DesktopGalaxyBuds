#ifndef BLUETOOTH_CONTEXT_H_
#define BLUETOOTH_CONTEXT_H_
#include <winrt/Windows.Devices.Bluetooth.h>
#include <winrt/Windows.Devices.Radios.h>
#pragma comment(lib, "windowsapp")

namespace WinTooth = winrt::Windows::Devices::Bluetooth;
namespace WinRadio = winrt::Windows::Devices::Radios;

#include "../../Types.h"

namespace WinBuds {
	class BluetoothContext{
	public:
		BluetoothContext();

		~BluetoothContext();

		bool IsBluetoothEnabled();

		bool SetBluetoothState(BluetoothRadioState state);

		void QueryForDevices();
	private:
		WinRadio::RadioState GetBluetoothRadioState();

		WinRadio::Radio GetBluetoothRadio();
	};
}

#endif // !BLUETOOTH_CONTEXT_H_
