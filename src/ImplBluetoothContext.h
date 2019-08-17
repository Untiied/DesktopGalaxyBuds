#ifndef IMPL_BLUETOOTH_CONTEXT_H_
#define IMPL_BLUETOOTH_CONTEXT_H_

#include "Types.h"
namespace WinBuds {
	class ImplBluetoothContext {
	public:
		inline ImplBluetoothContext() {};

		virtual inline ~ImplBluetoothContext() {};

		virtual bool IsBluetoothEnabled() = 0;

		virtual bool IsBluetoothLESupported() = 0;

		virtual bool SetBluetoothState(BluetoothRadioState state) = 0;

		virtual void QueryForDevices() = 0;
	};
}

#endif // !IMPL_BLUETOOTH_CONTEXT_H_