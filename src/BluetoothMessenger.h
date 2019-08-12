#ifndef BLUETOOTH_MESSENGER_H
#define BLUETOOTH_MESSENGER_H

#ifdef _WIN32
#include "Platforms/Windows/BluetoothContext.h"
#elif __APPLE__
#elif __linux__
#endif

#include "Types.h"

namespace WinBuds {

	class BluetoothMessenger {
		public:
			BluetoothMessenger();
			
			~BluetoothMessenger();

			bool IsBluetoothEnabled();

			bool SetBluetoothState(BluetoothRadioState state);

			inline BluetoothContext& GetContext() {
				return *bluetooth_context;
			}
		private:
			BluetoothContext* bluetooth_context;
	};

}

#endif // !BLUETOOTH_MESSENGER_H