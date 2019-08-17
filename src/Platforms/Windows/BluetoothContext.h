#ifndef BLUETOOTH_CONTEXT_H_
#define BLUETOOTH_CONTEXT_H_

// Windows specific files.
#include <winrt/Windows.Devices.Bluetooth.h>
#include <winrt/Windows.Devices.Bluetooth.Advertisement.h>
#include <winrt/Windows.Devices.Radios.h>
#pragma comment(lib, "windowsapp")

namespace WinTooth = winrt::Windows::Devices::Bluetooth;
namespace WinRadio = winrt::Windows::Devices::Radios;
//

#include "../../ImplBluetoothContext.h"
#include "../../Types.h"

namespace WinBuds {
	class BluetoothContext : public WinBuds::ImplBluetoothContext {
	public:
		BluetoothContext();

		~BluetoothContext();

		bool IsBluetoothEnabled();

		bool IsBluetoothLESupported();

		bool SetBluetoothState(BluetoothRadioState state);

		void QueryForDevices();
	private:
		WinRadio::RadioState GetBluetoothRadioState();

		WinRadio::Radio GetBluetoothRadio();
	};
}

#endif // !BLUETOOTH_CONTEXT_H_
