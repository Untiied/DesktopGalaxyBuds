#include "BluetoothContext.h"

WinBuds::BluetoothContext::BluetoothContext()
{
	winrt::init_apartment();
}

WinBuds::BluetoothContext::~BluetoothContext()
{
}

bool WinBuds::BluetoothContext::IsBluetoothEnabled() {
	WinRadio::RadioState radio_state = GetBluetoothRadioState();

	if (radio_state == WinRadio::RadioState::Off)
		return false;

	return true;
}

bool WinBuds::BluetoothContext::SetBluetoothState(BluetoothRadioState state)
{
	WinRadio::Radio bluetooth_radio = GetBluetoothRadio();
	// We take our BluetoothRadioState and cast it to windows's state. 
	// We can do this because our id's follow theirs.
	auto result = bluetooth_radio.SetStateAsync((WinRadio::RadioState)state).get();

	if (result == WinRadio::RadioAccessStatus::Allowed)
		return true;

	return false;
}

void WinBuds::BluetoothContext::QueryForDevices() {

}

///////////////////////////////////////////////////////////////////////////////////// PRIVATE /////////////////////////////////////////////////////////////////

WinRadio::RadioState WinBuds::BluetoothContext::GetBluetoothRadioState()
{
	return GetBluetoothRadio().State();
}

WinRadio::Radio WinBuds::BluetoothContext::GetBluetoothRadio()
{
	auto radios = WinRadio::Radio::GetRadiosAsync().get();

	for (uint32_t i = 0; i < radios.Size(); i++)
	{
		if (radios.GetAt(i).Kind() == WinRadio::RadioKind::Bluetooth) {
			return radios.GetAt(i);
		}
	}

	// @TODO: Add debugging.
	return NULL;
}
