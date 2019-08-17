#include "BluetoothMessenger.h"

WinBuds::BluetoothMessenger::BluetoothMessenger() {
	bluetooth_context = new BluetoothContext();
}

WinBuds::BluetoothMessenger::~BluetoothMessenger()
{
	delete(bluetooth_context);
}

bool WinBuds::BluetoothMessenger::IsBluetoothEnabled()
{
	return bluetooth_context->IsBluetoothEnabled();
}

bool WinBuds::BluetoothMessenger::IsBluetoothLESupported()
{
	return bluetooth_context->IsBluetoothLESupported();
}

bool WinBuds::BluetoothMessenger::SetBluetoothState(BluetoothRadioState state)
{
	return bluetooth_context->SetBluetoothState(state);
}

void WinBuds::BluetoothMessenger::QueryForDevices()
{
	bluetooth_context->QueryForDevices();
}

