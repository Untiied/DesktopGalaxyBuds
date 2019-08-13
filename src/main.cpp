#include "BluetoothMessenger.h"
#include <iostream>

void Log(std::string message){
    std::cout << message << std::endl;
}

void AuthenticateBluetoothEnabled(WinBuds::BluetoothMessenger* messenger) {

	if (messenger->IsBluetoothEnabled()) {
        Log("Bluetooth is already enabled!\n");
	}
	else {
		Log("Bluetooth isn't enabled... Attempting to turn it on.\n");
		if (messenger->SetBluetoothState(BluetoothRadioState::On)) {
			Log("Bluetooth Successfully turned on!\n");
		}
	}
}

int main() {
	WinBuds::BluetoothMessenger* messenger = new WinBuds::BluetoothMessenger();

	// Makes sure that bluetooth is ready to go!
	AuthenticateBluetoothEnabled(messenger);
}
