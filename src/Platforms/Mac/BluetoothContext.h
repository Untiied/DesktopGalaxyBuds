#ifndef BLUETOOTH_CONTEXT_H_
#define BLUETOOTH_CONTEXT_H_

#include "../../Types.h"

namespace WinBuds {
	class BluetoothContext{
	public:
		BluetoothContext();

		~BluetoothContext();

		bool IsBluetoothEnabled();

		bool SetBluetoothState(BluetoothRadioState state);

		void QueryForDevices();
	};
}

#endif // !BLUETOOTH_CONTEXT_H_
