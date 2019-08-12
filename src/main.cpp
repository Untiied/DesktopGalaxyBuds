#include "BluetoothMessenger.h"

void AuthenticateBluetoothEnabled(WinBuds::BluetoothMessenger* messenger) {

	if (messenger->IsBluetoothEnabled()) {
		printf("Bluetooth is already enabled!\n");
	}
	else {
		printf("Bluetooth isn't enabled... Attempting to turn it on.\n");
		if (messenger->SetBluetoothState(BluetoothRadioState::On)) {
			printf("Bluetooth Successfully turned on!\n");
		}
	}
}

int main() {
	WinBuds::BluetoothMessenger* messenger = new WinBuds::BluetoothMessenger();

	// Makes sure that bluetooth is ready to go!
	AuthenticateBluetoothEnabled(messenger);
}