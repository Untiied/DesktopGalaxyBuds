#include "BluetoothMessenger.h"
#include <iostream>

void Log(std::string message){
    std::cout << message + "\n" << std::endl;
}

void AuthenticateBluetoothEnabled(WinBuds::BluetoothMessenger* messenger) {

	if (messenger->IsBluetoothEnabled()) {
        Log("Bluetooth is already enabled!");
	}
	else {
		Log("Bluetooth isn't enabled... Attempting to turn it on.");
		if (messenger->SetBluetoothState(BluetoothRadioState::On)) {
			Log("Bluetooth Successfully turned on!");
		}
		else {
			Log("Error attempting to activate Bluetooth. Either manually start Bluetooth, or try again.");
		}
	}
}

int main() {
	WinBuds::BluetoothMessenger messenger;

	// Makes sure that bluetooth is ready to go!
	AuthenticateBluetoothEnabled(&messenger);

	Log(std::string("Adapter supports BluetoothLE: ").append(messenger.IsBluetoothLESupported() ? "True" : "False"));

	messenger.QueryForDevices();
}
