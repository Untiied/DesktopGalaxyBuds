#ifndef BLUETOOTH_MESSENGER_H
#define BLUETOOTH_MESSENGER_H

#ifdef _WIN32
#include "Platforms/Windows/BluetoothContext.h"
#elif __APPLE__
#include "Platforms/Mac/BluetoothContext.h"
#elif __linux__
#endif

#include "Types.h"

namespace WinBuds {

	// This class serves as a boiler plate for each of the different bluetooth api's on each system.
	// By having a "messenger" in between all of them, it allows us to rapidly develop.

	class BluetoothMessenger {
		public:
			BluetoothMessenger();
			
			~BluetoothMessenger();

			bool IsBluetoothEnabled();

			bool IsBluetoothLESupported();

			bool SetBluetoothState(BluetoothRadioState state);

			void QueryForDevices();

			inline BluetoothContext& GetContext() {
				return *bluetooth_context;
			}
		private:
			BluetoothContext* bluetooth_context;
	};

}

#endif // !BLUETOOTH_MESSENGER_H
